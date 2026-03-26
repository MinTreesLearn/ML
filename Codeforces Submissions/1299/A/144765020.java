import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        AAnuHasAFunction solver = new AAnuHasAFunction();
        solver.solve(1, in, out);
        out.close();
    }

    static class AAnuHasAFunction {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[] bits = new int[32];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 32; j++) {
                    if ((a[i] & (1 << j)) > 0) {
                        bits[j]++;
                    }
                }
            }
//        out.println(bits);
            int max = -1;
            for (int j = 31; j >= 0; j--) {
                if (bits[j] == 1) {
                    max = j;
                    break;
                }
            }
//        out.println(max);
            int[] ans = new int[n];
            if (max == -1) {
                ans = a;
            } else {
                int first = -1;
                for (int i = 0; i < n; i++) {
                    if ((a[i] & (1 << max)) > 0) {
                        first = a[i];
                        break;
                    }
                }
//            out.println(first,"first");
                int j = 1;
                if (max != -1 && first != -1) {
                    ans[0] = first;
                    for (int i = 0; i < n; i++) {
                        if (a[i] != first && first != 0) {
                            ans[j++] = a[i];
                        }
                    }
                } else {
                    Arrays.sort(a);
                    out.println(a);
                }

            }

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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}

