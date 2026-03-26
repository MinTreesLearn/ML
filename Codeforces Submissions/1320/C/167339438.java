import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E1320C {
    static long INF = (long) 1e18;
    static int A = (int) 1e6;

    public static void main(String[] args) {
        FastIO io = new FastIO();
        int n = io.nextInt();
        int m = io.nextInt();
        int p = io.nextInt();

        //addition, cost
        int[][] weapons = new int[n][2];
        //w, a
        int[][] monsters = new int[p][3];
        for (int i = 0; i < n; i++) weapons[i] = new int[]{io.nextInt(), io.nextInt()};
        SegmentTree st = new SegmentTree(A + 2);
        long[] initTree = new long[A + 2];
        Arrays.fill(initTree, -INF);
        for (int i = 0; i < m; i++) {
            int addition = io.nextInt();
            int cost = io.nextInt();
            initTree[addition] = Math.max(initTree[addition], -cost);
        }

        for (int i = 0; i < p; i++)
            monsters[i] = new int[]{io.nextInt(), io.nextInt(), io.nextInt()};

        for (int i = 0; i <= A; i++) st.update(1, i, i, initTree[i]);

        Arrays.sort(monsters, (a, b) -> a[0] - b[0]);
        Arrays.sort(weapons, (a, b) -> a[0] - b[0]);
        long ans = -INF;
        for (int i = 0, j = 0; i < n; i++) {
            for (; j < p && monsters[j][0] < weapons[i][0]; j++) {
                st.update(1, monsters[j][1] + 1, A + 1, monsters[j][2]);
            }
            long localAns = st.query(1, 0, A) - weapons[i][1];
            ans = Math.max(ans, localAns);
        }
        io.println(ans);


        io.close();
    }


    private static class SegmentTree {

        int[] hi, lo;
        long[] modTree, tree;
        static long treeId = -INF;
        static int modId = 0;

        public SegmentTree(int n) {
            this.hi = new int[4 * n + 1];
            this.lo = new int[4 * n + 1];
            this.modTree = new long[4 * n + 1];
            this.tree = new long[4 * n + 1];

            init(1, 0, n - 1);
        }

        private void init(int i, int from, int to) {
            lo[i] = from;
            hi[i] = to;
            if (from == to) return;
            int mid = (from + to) >> 1;
            init(i << 1, from, mid);
            init((i << 1) + 1, mid + 1, to);
        }

        private long get(int i) {
            return modTree[i] + tree[i];
        }

        private void prop(int i) {
            modTree[2 * i] = modToMod(modTree[2 * i], modTree[i]);
            modTree[2 * i + 1] = modToMod(modTree[2 * i + 1], modTree[i]);
            modTree[i] = modId;
        }

        private long modToMod(long a, long b) {
            return a + b;
        }

        private long valueToValue(long a, long b) {
            return Math.max(a, b);
        }


        private void fix(int i) {
            tree[i] = valueToValue(get(2 * i), get(2 * i + 1));
        }

        private void update(int i, int l, int r, long value) {
            if (lo[i] >= l && hi[i] <= r) {
                modTree[i] = modToMod(modTree[i], value);
                return;
            }

            if (lo[i] > r || hi[i] < l) return;

            prop(i);
            update(2 * i, l, r, value);
            update(2 * i + 1, l, r, value);
            fix(i);
        }

        private long query(int i, int l, int r) {
            if (lo[i] >= l && hi[i] <= r) return get(i);
            if (lo[i] > r || hi[i] < l) return treeId;

            prop(i);
            long lTree = query(2 * i, l, r);
            long rTree = query(2 * i + 1, l, r);
            fix(i);

            return valueToValue(lTree, rTree);
        }

    }

    private static class FastIO extends PrintWriter {
        private final InputStream stream;
        private final byte[] buf = new byte[1 << 16];
        private int curChar, numChars;

        // standard input
        public FastIO() {
            this(System.in, System.out);
        }

        public FastIO(InputStream i, OutputStream o) {
            super(o);
            stream = i;
        }

        // file input
        public FastIO(String i, String o) throws IOException {
            super(new FileWriter(o));
            stream = new FileInputStream(i);
        }

        // throws InputMismatchException() if previously detected end of file
        private int nextByte() {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars == -1) return -1; // end of file
            }
            return buf[curChar++];
        }

        // to read in entire lines, replace c <= ' '
        // with a function that checks whether c is a line break
        public String next() {
            int c;
            do {
                c = nextByte();
            } while (c <= ' ');
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = nextByte();
            } while (c > ' ');
            return res.toString();
        }

        public int nextInt() { // nextLong() would be implemented similarly
            int c;
            do {
                c = nextByte();
            } while (c <= ' ');
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = nextByte();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = 10 * res + c - '0';
                c = nextByte();
            } while (c > ' ');
            return res * sgn;
        }

        public long nextLong() { // nextLong() would be implemented similarly
            int c;
            do {
                c = nextByte();
            } while (c <= ' ');
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = nextByte();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = 10 * res + c - '0';
                c = nextByte();
            } while (c > ' ');
            return res * sgn;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }


}
