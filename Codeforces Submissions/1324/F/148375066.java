import java.io.*;
import java.util.*;

public class MaximumWhiteSubtree {
    static int[] result;
    static int[] dp;
    static List<List<Integer>> G;
    static int[] A;
    public static void dfs1(int cur, int par) {
        dp[cur] = A[cur];
        for (int nxt : G.get(cur)) {
            if (nxt != par) {
                dfs1(nxt, cur);
                dp[cur] += Math.max(0, dp[nxt]);
            }
        }
    }
    public static void dfs2(int cur, int par) {
        result[cur] = dp[cur];
        for (int nxt : G.get(cur)) {
            if (nxt != par) {
                dp[cur] -= Math.max(0, dp[nxt]);
                dp[nxt] += Math.max(0, dp[cur]);
                dfs2(nxt, cur);
                dp[nxt] -= Math.max(0, dp[cur]);
                dp[cur] += Math.max(0, dp[nxt]);
            }
        }
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader(System.in);
        PrintWriter writer = new PrintWriter(System.out, false);
        int N = reader.nextInt();
        A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = reader.nextInt();
            if (A[i] == 0) A[i] = -1;
        }
        G = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            G.add(new ArrayList<>());
        }
        for (int i = 0; i < N - 1; i++) {
            int u = reader.nextInt() - 1;
            int v = reader.nextInt() - 1;
            G.get(u).add(v);
            G.get(v).add(u);
        }
        dp = new int[N];
        result = new int[N];
        dfs1(0, -1);
        dfs2(0, -1);
        for (int i = 0; i < N; i++) {
            writer.print(result[i] + " ");
        }
        writer.close();
        System.exit(0);
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
        public String nextLine() {
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}