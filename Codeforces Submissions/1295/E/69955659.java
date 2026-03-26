import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author KharYusuf
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EPermutationSeparation solver = new EPermutationSeparation();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPermutationSeparation {
        public void solve(int testNumber, FastReader s, PrintWriter w) {
            int n = s.nextInt();
            int[] pos = new int[n], a = new int[n];
            long[] pre = new long[n];
            for (int i = 0; i < n; i++) pos[s.nextInt() - 1] = i;
            for (int i = 0; i < n; i++) {
                pre[i] = a[i] = s.nextInt();
                if (i > 0) pre[i] += pre[i - 1];
            }
            segtreeLazy seg = new segtreeLazy(n);
            seg.build(pre);
            long ans = seg.query(0, n - 2);
            for (int i = 0; i < n; i++) {
                int cur = pos[i];
                seg.modify(0, cur - 1, a[cur]);
                seg.modify(cur, n - 1, -a[cur]);
                ans = Math.min(ans, seg.query(0, n - 2));
            }
            w.println(ans);
        }

        class segtreeLazy {
            int n;
            long[] t;
            long[] lazy;

            segtreeLazy(int n) {
                this.n = n;
                t = new long[n << 2];
                lazy = new long[n << 2];
            }

            void build(long[] a) {
                buildUtil(0, n - 1, a, 1);
            }

            void modify(int l, int r, long val) {
                if (l > r) return;
                modifyUtil(0, n - 1, l, r, val, 1);
            }

            long query(int l, int r) {
                if (l > r) throw new RuntimeException("Out of Range");
                return queryUtil(0, n - 1, l, r, 1);
            }

            void buildUtil(int s, int e, long[] a, int n) {
                if (s == e) {
                    t[n] = a[s];
                    return;
                }
                int mid = s + e >> 1;
                buildUtil(s, mid, a, n << 1);
                buildUtil(mid + 1, e, a, n << 1 | 1);
                t[n] = Math.min(t[n << 1], t[n << 1 | 1]);
            }

            void modifyUtil(int s, int e, int qs, int qe, long val, int n) {
                if (lazy[n] != 0) {
                    t[n] += lazy[n];
                    if (s != e) {
                        lazy[n << 1] += lazy[n];
                        lazy[n << 1 | 1] += lazy[n];
                    }
                    lazy[n] = 0;
                }
                if (s > qe || e < qs) return;
                if (s >= qs && e <= qe) {
                    t[n] += val;
                    if (s != e) {
                        lazy[n << 1] += val;
                        lazy[n << 1 | 1] += val;
                    }
                    return;
                }
                int mid = s + e >> 1;
                modifyUtil(s, mid, qs, qe, val, n << 1);
                modifyUtil(mid + 1, e, qs, qe, val, n << 1 | 1);
                t[n] = Math.min(t[n << 1], t[n << 1 | 1]);
            }

            long queryUtil(int s, int e, int qs, int qe, int n) {
                if (lazy[n] != 0) {
                    t[n] += lazy[n];
                    if (s != e) {
                        lazy[n << 1] += lazy[n];
                        lazy[n << 1 | 1] += lazy[n];
                    }
                    lazy[n] = 0;
                }
                if (s > qe || e < qs) return Long.MAX_VALUE;
                if (s >= qs && e <= qe) return t[n];
                int mid = s + e >> 1;
                return Math.min(queryUtil(s, mid, qs, qe, n << 1), queryUtil(mid + 1, e, qs, qe, n << 1 | 1));
            }

        }

    }

    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private FastReader.SpaceCharFilter filter;

        public FastReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {

            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {

                curChar = 0;

                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }

            return buf[curChar++];
        }

        public int nextInt() {

            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;

            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();

                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public boolean isSpaceChar(int c) {

            if (filter != null)
                return filter.isSpaceChar(c);

            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

