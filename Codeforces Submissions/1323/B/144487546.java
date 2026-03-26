import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Manav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BCountSubrectangles solver = new BCountSubrectangles();
        solver.solve(1, in, out);
        out.close();
    }

    static class BCountSubrectangles {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            long k = in.nextLong();
            int[] a = in.nextIntArray(n), b = in.nextIntArray(m);
            long[] row = new long[n + 1], col = new long[m + 1];
            for (int i = 0; i < n; i++) {
                if (a[i] == 1) {
                    int j = i;
                    while (j < n && a[j] == 1) {
                        j++;
                    }
                    int count = j - i;
                    for (int l = 1; l <= count; l += 1) {
                        row[l] += (count - l + 1);
                    }
                    i = j - 1;
                }
            }
            for (int i = 0; i < m; i++) {
                if (b[i] == 1) {
                    int j = i;
                    while (j < m && b[j] == 1) {
                        j++;
                    }
                    int count = j - i;
                    for (int l = 1; l <= count; l += 1) {
                        col[l] += (count - l + 1);
                    }
                    i = j - 1;
                }
            }
            long ans = 0;
            for (long i = 1; i * i <= k; i += 1) {
                if (k % i == 0) {
                    long p = i, q = k / i;
                    if (p <= n && q <= m) {

                        ans += row[(int) p] * col[(int) q];
//                    out.println(p,q,ans);
                    }
                    if (q <= n && p <= m && p != q) {
                        ans += row[(int) q] * col[(int) p];
//                    out.println(q,p,ans);
                    }
                }
            }
//        out.println(row);
//        out.println(col);
            out.println(ans);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}

