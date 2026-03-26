import java.io.*;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.function.Predicate;

public class E1296E2 {
    public static void main(String[] args) {
        FastIO io = new FastIO();
        int n = io.nextInt();
        ArrayList<Integer> l = new ArrayList<>();
        char[] s = io.next().toCharArray();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int val = s[i];
            int up = firstTrue(0, l.size() - 1, (x) -> val >= l.get(x));
            if (up == l.size()) l.add(val);
            l.set(up, val);
            ans[i] = up + 1;
        }
        io.println(l.size());
        for (int v : ans) io.print(v + " ");

        io.close();
    }

    public static int firstTrue(int lo, int hi, Predicate<Integer> test) {
        hi++;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (test.test(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
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
