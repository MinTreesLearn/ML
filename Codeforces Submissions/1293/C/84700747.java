import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
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
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CNEKOsMazeGame solver = new CNEKOsMazeGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class CNEKOsMazeGame {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[][] mat = new int[2][n];
            HashSet<String> locks = new HashSet<>();
            while (q-- > 0) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                mat[x][y] ^= 1;
                int nx = x ^ 1;
                for (int i = -1; i <= 1; i++) {
                    int ny = y + i;
                    if (!isValid(nx, ny, n)) {
                        continue;
                    }
                    if (mat[nx][ny] == 1 && mat[x][y] == 1) {
                        String s = getLockString(x, y, nx, ny);
                        locks.add(s);
                    } else if (mat[x][y] == 0) {
                        String s1 = getLockString(x, y, nx, ny);
                        String s2 = getLockString(nx, ny, x, y);
                        locks.remove(s1);
                        locks.remove(s2);
                    }
                }
                if (locks.size() > 0) {
                    out.println("No");
                } else {
                    out.println("Yes");
                }
            }
        }

        String getLockString(int x1, int y1, int x2, int y2) {
            return x1 + "," + y1 + "-" + x2 + "," + y2;
        }

        boolean isValid(int x, int y, int n) {
            return x >= 0 && x <= 1 && y >= 0 && y < n;
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
            for (int i = 0; i < objects.length; ++i) {
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

