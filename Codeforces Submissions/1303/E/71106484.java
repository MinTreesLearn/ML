import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        EEraseSubsequences solver = new EEraseSubsequences();
        solver.solve(1, in, out);
        out.close();
    }

    static class EEraseSubsequences {
        short[][][] dp;
        int n;
        int m;
        char[] arr1;
        char[] arr2;

        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int t1 = in.nextInt();
            outer:
            while (t1-- > 0) {
                String str1 = in.nextString();
                String str2 = in.nextString();
                n = str1.length();
                m = str2.length();
                arr1 = str1.toCharArray();
                arr2 = str2.toCharArray();
                dp = new short[n][m + 1][m + 1];

                for (int i = 0; i < n; i++)
                    for (int j = 0; j <= m; j++)
                        Arrays.fill(dp[i][j], (short) -2);

                for (int i = n - 1; i >= 0; i--)
                    for (int j = m; j >= 0; j--)
                        for (int k = m; k >= 0; k--)
                            func(i, j, k);

                for (int i = 0; i < m; i++) {
                    if (func(0, 0, i) >= i) {
                        out.println("YES");
                        continue outer;
                    }
                }

                out.println("NO");

            }
        }

        private short func(int pos1, int pos2, int pos3) {
            if (pos1 == n)
                return (short) (pos3 == m ? pos2 : -1);

            if (pos2 == m && pos3 == m)
                return (short) pos2;

            if (dp[pos1][pos2][pos3] != -2)
                return dp[pos1][pos2][pos3];

            short val = func(pos1 + 1, pos2, pos3);

            if (pos2 != m && arr1[pos1] == arr2[pos2])
                val = max(val, func(pos1 + 1, pos2 + 1, pos3));

            if (pos3 != m && arr1[pos1] == arr2[pos3])
                val = max(val, func(pos1 + 1, pos2, pos3 + 1));

            return dp[pos1][pos2][pos3] = val;
        }

        private short max(short a, short b) {
            return a > b ? a : b;
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

        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
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

