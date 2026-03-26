import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.LinkedList;
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
        FThreePathsOnATree solver = new FThreePathsOnATree();
        solver.solve(1, in, out);
        out.close();
    }

    static class FThreePathsOnATree {
        int n;
        int m;
        ArrayList<Integer>[] g;
        int[] dist;
        boolean[] vis;
        int[] par;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            pre(in);
            int[] d1 = bfs(0);
            int v1 = 0;
            for (int i = 1; i < n; i++) {
                if (d1[i] > d1[v1]) {
                    v1 = i;
                }
            }
            int[] d2 = bfs(v1);
            int v2 = 0;
            for (int i = 1; i < n; i++) {
                if (d2[i] > d2[v2]) {
                    v2 = i;
                }
            }
            vis = new boolean[n];
            path(v1, v2);
            for (int i = 0; i < n; i++) {
                if (vis[i]) dfs(i, -1, 0);
            }

            int v3 = 0;
            for (int i = 0; i < n; i++) {
                if (dist[i] > dist[v3]) {
                    v3 = i;
                }
            }
            int tot = dist[v3] + d2[v2];
            if (v3 == v1 || v3 == v2) {
                for (int i = 0; i < n; i++) {
                    if (i != v1 && i != v2) {
                        v3 = i;
                        break;
                    }
                }
            }
            out.println(tot);
            out.println(v1 + 1, v2 + 1, v3 + 1);
        }

        void dfs(int nn, int pp, int d) {
            dist[nn] = d;
            for (int a : g[nn]) {
                if (a == pp || vis[a]) continue;
                dfs(a, nn, d + 1);
            }
        }

        void path(int u, int v) {
            vis[v] = true;
            if (v == u) {
                return;
            }
            path(u, par[v]);
        }

        int[] bfs(int u) {
            int[] d = new int[n];
            par = new int[n];
            par[u] = -1;
            Arrays.fill(d, Integer.MAX_VALUE);
            Queue<Integer> q = new LinkedList<>();
            d[u] = 0;
            q.add(u);
            while (!q.isEmpty()) {
                int p = q.poll();
                for (int a : g[p]) {
                    if (d[p] + 1 < d[a]) {
                        par[a] = p;
                        d[a] = d[p] + 1;
                        q.add(a);
                    }
                }
            }
            return d;
        }

        void pre(InputReader in) {
            n = in.nextInt();
            m = n - 1;
            g = new ArrayList[n];
            dist = new int[n];
            vis = new boolean[n];
            for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
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

        public void println(int i) {
            writer.println(i);
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

