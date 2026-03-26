// package TreeQueries;

import java.util.*;
import java.io.*;

public class addEdge {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        FastReader sc = new FastReader();
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = 1;
        // t = sc.nextInt();
        while (t-- != 0) {
            int n = sc.nextInt();
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i <= n; i++)
                adj.add(new ArrayList<Integer>());
            for (int i = 0; i < n - 1; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            int level[] = new int[n + 1];
            int limit = (int) (Math.log(n) / Math.log(2));
            int parent[][] = new int[n + 1][limit + 1];

            dfs(1, 0, 0, adj, level, parent);

            for (int i = 1; i <= limit; i++) {
                for (int j = 1; j <= n; j++) {
                    int x = parent[j][i - 1];
                    parent[j][i] = parent[x][i - 1];
                }
            }

            int q = sc.nextInt();
            for (int i = 0; i < q; i++) {
                int k = 5;
                int qur[] = new int[k];
                for (int j = 0; j < k; j++) {
                    qur[j] = sc.nextInt();
                }
                int withoutedge = getDist(qur[2], qur[3], parent, level);
                int d2 = getDist(qur[2], qur[0], parent, level) + 1 + getDist(qur[1], qur[3], parent, level);
                int d3 = getDist(qur[3], qur[0], parent, level) + 1 + getDist(qur[1], qur[2], parent, level);
                // System.out.println`(withoutedge + " " + d2 + " " + d3);
                int withedge = Math.min(d2, d3);
                int ans = Integer.MAX_VALUE;
                
                if (withedge % 2 == qur[4] % 2) {
                    ans = withedge;
                }
                if (withoutedge % 2 == qur[4] % 2) {
                    ans = Math.min(ans, withoutedge);
                }
                if (ans <= qur[4]) {
                    w.write("YES\n");
                } else {
                    w.write("NO\n");
                }
                // int a=sc.nextInt();
                // int b=sc.nextInt();
                // System.out.println(getDist(a, b, parent, level));
                // w.write(ans+"\n");
            }

            w.flush();
        }
        w.close();
    }

    private static int getDist(int a, int b, int[][] parent, int[] level) {
        if (level[a] > level[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        int diff = level[b] - level[a];
        int ans = 0;
        while (diff > 0) {
            int log = (int) (Math.log(diff) / Math.log(2));
            b = parent[b][log];
            diff -= (1 << log);
            ans += (1 << log);
        }
        if(a==b)return ans;
        for(int i=parent[0].length-1;i>=0;i--){
            if(parent[b][i] != parent[a][i]){
                a = parent[a][i];
                b = parent[b][i];
                ans += (1 << (i + 1));
            }
        }
        return ans+2;
    }

    private static void dfs(int i, int p, int l, ArrayList<ArrayList<Integer>> adj, int[] level, int[][] parent) {
        parent[i][0] = p;
        level[i] = l;
        for (int nbr : adj.get(i)) {
            if (nbr == p)
                continue;
            dfs(nbr, i, l + 1, adj, level, parent);
        }
    }

}