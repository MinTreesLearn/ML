import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    List<List<Integer>> g;

    int[][] parent;
    int[][] size;

    long[][] dp;

    int find_size(int v, int p) {
        if (size[p][v] != 0) {
            return size[p][v];
        }
        size[p][v] = 1;
        for (int u : g.get(v)) {
            if (u == p) continue;
            size[p][v] += find_size(u, v);
        }
        return size[p][v];
    }

    void find_parent(int root, int v, int p) {
        parent[v][root] = p;
        for (int u : g.get(v)) {
            if (u == p) continue;
            find_parent(root, u, v);
        }
    }

    void find_dp(int u, int v) {
        if (dp[u][v] != -1) return;
        find_dp(parent[u][v], v);
        find_dp(parent[v][u], u);
        dp[u][v] = size[parent[u][v]][u] * size[parent[v][u]][v] + Math.max(dp[parent[u][v]][v], dp[parent[v][u]][u]);
    }

    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            g.add(new ArrayList<>());
        }
        for (int i = 1; i < n; ++i) {
            int u = in.nextInt() - 1, v = in.nextInt() - 1;
            g.get(u).add(v);
            g.get(v).add(u);
        }

        parent = new int[n][n];
        for (int i = 0; i < n; ++i) {
            find_parent(i, i, -1);
        }

        size = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int v : g.get(i)) {
                find_size(i, v);
            }
        }

        dp = new long[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dp[i], -1);
        }
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                find_dp(i, j);
            }
        }

        long answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                answer = Math.max(answer, dp[i][j]);
            }
        }
        out.println(answer);
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Main().solve(in, out);
        out.flush();
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
    }
}
