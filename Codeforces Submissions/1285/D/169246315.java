import java.io.*;
import java.util.ArrayList;
import java.util.InputMismatchException;

public class E1285D {


    public static void main(String[] args) {
        FastIO io = new FastIO();
        int n = io.nextInt();
        ArrayList<Integer> l = new ArrayList<>();
        for (int i = 0; i < n; i++) l.add(io.nextInt());
        int ans = dc(30, l);
        io.println(ans);
        io.close();
    }

    static int dc(int p, ArrayList<Integer> l) {
        if (p == -1) return 0;


        ArrayList<Integer> zeroList = new ArrayList<>();
        ArrayList<Integer> oneList = new ArrayList<>();
        for (int v : l) {
            if (((v >> p) & 1) == 1) oneList.add(v);
            else zeroList.add(v);


        }
        int ans;
        if (zeroList.size() == 0) ans = dc(p - 1, oneList);
        else if (oneList.size() == 0) ans = dc(p - 1, zeroList);
        else ans = Math.min(dc(p - 1, oneList), dc(p - 1, zeroList)) | (1 << p);
        return ans;

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
                if (c < '0' || c > '9') throw new InputMismatchException();
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
                if (c < '0' || c > '9') throw new InputMismatchException();
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
