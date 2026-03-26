import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class teambuilding {

    static class Node implements Comparable<Node>{
        int ind;
        int v;
        Node(int ind, int v){
            this.ind = ind;
            this.v = v;
        }
        public int compareTo(Node s){
            if(v != s.v) return s.v - v;
            return ind - s.ind;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        Node[] ar = new Node[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) ar[i] = new Node(i, Integer.parseInt(st.nextToken()));
        long[][] vs = new long[n][p];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < p; j++) {
                vs[i][j] = Long.parseLong(st.nextToken());
            }
        }
        Arrays.sort(ar);
        long[][] dp = new long[(1 << p)][n];
        for (int i = 0; i < (1 << p); i++) for (int j = 0; j < n; j++) dp[i][j] = -1;
        dp[0][0] = ar[0].v;
        for (int i = 0; i < p; i++) dp[(1 << i)][0] = vs[ar[0].ind][i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < (1 << p); j++) {
                if(dp[j][i - 1] == -1) continue;
                int onecount = Integer.bitCount(j);
//                System.out.println(j + " " + onecount);
                if(k - (i - onecount + 1) >= 0){
                    dp[j][i] = Math.max(dp[j][i - 1] + ar[i].v, dp[j][i]);
                } else {
                    dp[j][i] = Math.max(dp[j][i], dp[j][i - 1]);
                }
                for (int l = 0; l < p; l++) {
                    //i is the current one to choose, j is the bitmask, l is the position
                    if((j >> l) % 2 == 1) continue;
                    dp[(j | (1 << l))][i] = Math.max(dp[j][i - 1] + vs[ar[i].ind][l], dp[(j | (1 << l))][i]);
                }
            }
        }
        System.out.println(dp[(1 << p) - 1][n - 1]);
    }
}
