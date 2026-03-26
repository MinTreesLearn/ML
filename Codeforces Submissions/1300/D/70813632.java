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
 * @author Ribhav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DAerodynamic solver = new DAerodynamic();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAerodynamic {
        public void solve(int testNumber, FastReader s, PrintWriter out) {
            int n = s.nextInt();
            DAerodynamic.coordinate[] arr = new DAerodynamic.coordinate[n];

            for (int i = 0; i < n; i++) {
                arr[i] = new DAerodynamic.coordinate(s.nextInt(), s.nextInt());
            }

            if (n % 2 != 0) {
                out.println("No");
                return;
            }

            int next = n / 2;
            double midX = ((arr[0].x + arr[next].x) * 1.0) / 2.0;
            double midY = ((arr[0].y + arr[next].y) * 1.0) / 2.0;
            boolean ok = true;
            for (int i = 1; i < next; i++) {
                if (((arr[i].x + arr[i + next].x) * 1.0) / 2.0 != midX) {
                    ok = false;
                    break;
                }

                if (((arr[i].y + arr[i + next].y) * 1.0) / 2.0 != midY) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                out.println("YES");
            } else {
                out.println("No");
            }

        }

        private static class coordinate {
            int x;
            int y;

            public coordinate(int x, int y) {
                this.x = x;
                this.y = y;
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
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

