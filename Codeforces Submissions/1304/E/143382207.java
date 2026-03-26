import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        E1TreesAndQueries solver = new E1TreesAndQueries();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1TreesAndQueries {
        int[][] par;
        int n;
        int m;
        ArrayList<Integer>[] g;
        int[] dist;
        boolean[] vis;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            pre(in);
            par = new int[n + 1][20];
            dfs(1, 0, 0);
            int q = in.nextInt();
            while (q-- > 0) {
                int x = in.nextInt(), y = in.nextInt(), a = in.nextInt(), b = in.nextInt(), k = in.nextInt();
                int l1 = lca(a, b);
                int d1 = dist[a] + dist[b] - 2 * dist[l1];
                if (d1 == k || (k > d1 && (k - d1) % 2 == 0)) {
                    out.println("YES");
                    continue;
                }
                int xda = dist[x] + dist[a] - 2 * dist[lca(x, a)], yda = dist[y] + dist[a] - 2 * dist[lca(y, a)];
                int xdb = dist[x] + dist[b] - 2 * dist[lca(x, b)], ydb = dist[y] + dist[b] - 2 * dist[lca(y, b)];
//            int xdy= dist[x]+dist[y]-2*dist[lca(x,y)];
                int d2 = xda + 1 + ydb, d3 = yda + 1 + xdb;
                if (d2 == k || d3 == k || (k > d2 && (k - d2) % 2 == 0) || (k > d3 && (k - d3) % 2 == 0)) {
                    out.println("YES");
                } else {
                    out.println("NO");
                }
            }
        }

        void dfs(int nn, int pp, int d) {
            dist[nn] = d;
            par[nn][0] = pp;
            for (int i = 1; i <= 19; i++) {
                par[nn][i] = par[par[nn][i - 1]][i - 1];
            }
            for (int a : g[nn]) {
                if (a == pp) continue;
                dfs(a, nn, d + 1);
            }
        }

        int lca(int u, int v) {
            if (dist[u] < dist[v]) {
                u ^= v;
                v ^= u;
                u ^= v;
            }
            int d = dist[u] - dist[v];
            for (int i = 19; i >= 0; i--) {
                if (((1 << i) & d) != 0) {
                    u = par[u][i];
                }
            }
            if (u == v) return u;
            for (int i = 19; i >= 0; i--) {
                if (par[u][i] != par[v][i]) {
                    u = par[u][i];
                    v = par[v][i];
                }
            }
            return par[u][0];
        }

        void pre(InputReader in) {
            n = in.nextInt();
            m = n - 1;
            g = new ArrayList[n + 1];
            dist = new int[n + 1];
            vis = new boolean[n + 1];
            for (int i = 0; i <= n; i++) g[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt(), b = in.nextInt();
                g[a].add(b);
                g[b].add(a);
            }
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

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

    }
}

