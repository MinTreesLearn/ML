import java.util.*;
import java.io.*;
public class cf1316e {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        //@todo Audience
        st = new StringTokenizer(br.readLine());
        pair[] A = new pair[N];
        for (int i = 0; i < N; i++) {
            A[i] = new pair(i, Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(A);

        //@todo Skill matrix
        int[][] skill = new int[N][P];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < P; j++) {
                skill[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        long[][] dp = new long[N + 1][(1 << P)];
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dp[i], -1);
        }

        dp[0][0] = 0;

        for (int i = 1; i <= N; i++) {
            int ind = A[i - 1].idx;
            for (int m = 0; m < (1 << P); m++) {

                //@todo Count number of bits in M.
                int bits = 0;
                for (int j = 0; j < P; j++) {
                    if ((m & (1 << j)) > 0) {
                        bits++;
                    }
                }


                int c = i - 1 - bits;
                //@todo Audience is not full.
                if (c < K) {
                    if (dp[i - 1][m] != -1) {
                        dp[i][m] = dp[i - 1][m] + A[i - 1].val;
                    }
                } else {
                    if (dp[i - 1][m] != -1) {
                        dp[i][m] = dp[i - 1][m];
                    }
                }

                //@TODO Put in the team
                for (int j = 0; j < P; j++) {
                    if ((m & (1 << j)) > 0 && (dp[i - 1][m ^ (1 << j)]) != -1) {
                        dp[i][m] = Math.max(dp[i][m], dp[i - 1][m ^ (1 << j)] + skill[ind][j]);
                    }
                }
            }
        }
        System.out.println(dp[N][(1<< P)- 1]);
    }

    static class pair implements Comparable<pair> {
        int idx, val;

        public pair(int idx, int val) {
            this.idx = idx;
            this.val = val;
        }

        public int compareTo(pair other) {
            return other.val - val;
        }
    }
}
