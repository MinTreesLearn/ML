import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
        EWaterBalance solver = new EWaterBalance();
        solver.solve(1, in, out);
        out.close();
    }

    static class EWaterBalance {
        private static final double EPS = 1e-12;
        private static final Comparator<Double> EPS_COMPARATOR = (x, y) -> {
            if (x + EPS < y) {
                return -1;
            } else if (x - EPS > y) {
                return 1;
            } else {
                return 0;
            }
        };

        public void solve(int testNumber, FastReader s, PrintWriter out) {
            var n = s.nextInt();
            var a = s.nextLongArray(n);

            var sum = new long[n + 1];
            sum[0] = 0;
            for (var i = 1; i <= n; i++) {
                sum[i] = sum[i - 1] + a[i - 1];
            }

            var q = new int[n + 1];
            var top = 0;
            for (var i = 1; i <= n; i++) {
                while (top > 0) {
                    var j = q[top];
                    var k = q[top - 1];
                    double topAvg = (double) (sum[j] - sum[k]) / (j - k);
                    double nowAvg = (double) (sum[i] - sum[k]) / (i - k);
                    if (EPS_COMPARATOR.compare(topAvg, nowAvg) >= 0) {
                        top--;
                    } else {
                        break;
                    }
                }

                q[++top] = i;
            }

            var ans = new double[n];
            for (var i = 1; i <= top; i++) {
                var j = q[i];
                var k = q[i - 1];
                double avg = (double) (sum[j] - sum[k]) / (j - k);
                for (var l = k + 1; l <= j; l++) {
                    ans[l - 1] = avg;
                }
            }

            out.println(EWaterBalance.arrays.printArr(ans));
        }

        private static class arrays {
            static StringBuilder printArr(double[] arr) {
                StringBuilder ans = new StringBuilder();
                for (int i = 0; i < arr.length; i++) {
                    ans.append(arr[i] + " ");
                }
                return ans;
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

        public long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; ++i) array[i] = nextLong();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

