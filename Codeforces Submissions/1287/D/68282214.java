import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
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
        PrintWriter out = new PrintWriter(outputStream);
        DNumbersOnTree solver = new DNumbersOnTree();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNumbersOnTree {
        int MAXN = 200005;
        PrintWriter out;
        InputReader in;
        ArrayList<Integer>[] tree = new ArrayList[MAXN];
        int[] in_t = new int[MAXN];
        int[] out_t = new int[MAXN];
        int[] C = new int[MAXN];
        int[] par = new int[MAXN];
        int timer = 0;
        ArrayList<Integer> dfs_order = new ArrayList<>();

        void dfs(int v, int p) {
            in_t[v] = timer++;
            dfs_order.add(v);
            for (int u : tree[v]) {
                if (u != p)
                    dfs(u, v);
            }
            out_t[v] = timer - 1;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.out = out;
            this.in = in;
            int n = ni();
            int i = 0;
            for (i = 0; i < n; i++)
                tree[i] = new ArrayList<>();
            int[] deg = new int[n];
            int root = -1;
            for (i = 0; i < n; i++) {
                par[i] = ni() - 1;
                C[i] = ni();
                if (par[i] == -1) {
                    root = i;
                    continue;
                }
                tree[par[i]].add(i);
                tree[i].add(par[i]);
                deg[i]++;
                deg[par[i]]++;
            }
            if (n == 1) {
                if (C[0] > 0) {
                    pn("NO");
                    return;
                }
                pn("YES");
                pn(1);
                return;
            }
            dfs(root, -1);
            Queue<Integer> qu = new LinkedList<>();
            boolean[] vis = new boolean[n];
            for (i = 0; i < n; i++) {
                if (deg[i] == 1 && i != root) {
                    qu.add(i);
                    vis[i] = true;
                }
            }
            int val = 1;
            int[] ans = new int[n];
            boolean ok = true;
            ArrayList<Integer> done = new ArrayList<>();
            TreeSet<Integer> tset = new TreeSet<>();
            int mx = 0;
            while (qu.size() > 0) {
                int curr = qu.poll();
                //pn(curr);
                if (out_t[curr] - in_t[curr] < C[curr]) {
                    ok = false;
                    break;
                }
                if (out_t[curr] == in_t[curr]) {
                    ans[curr] = mx + 1;
                } else {
                    int[] already = new int[out_t[curr] - in_t[curr]];
                    int p = 0;
                    for (i = in_t[curr] + 1; i <= out_t[curr]; i++, p++)
                        already[p] = ans[dfs_order.get(i)];
                    Arrays.sort(already);
                    int hola = out_t[curr] - in_t[curr] == C[curr] ? mx + 1 : already[C[curr]];
                    ans[curr] = hola;
                    for (int x : done) {
                        if (ans[x] >= hola)
                            ans[x]++;
                    }
                }
                for (i = 0; i < n; i++)
                    mx = Math.max(mx, ans[i]);
                done.add(curr);
                if (curr == root)
                    continue;
                deg[par[curr]]--;
                if (deg[par[curr]] <= 1) {
                    qu.add(par[curr]);
                }
            }
            if (!ok) {
                pn("NO");
            } else {
                for (i = 0; i < n; i++) {
                    tset.add(ans[i]);
                }
                pn("YES");
                for (int x : ans)
                    p(x + " ");
            }
        }

        int ni() {
            return in.nextInt();
        }

        void pn(long zx) {
            out.println(zx);
        }

        void pn(String zx) {
            out.println(zx);
        }

        void p(Object o) {
            out.print(o);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new UnknownError();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}

