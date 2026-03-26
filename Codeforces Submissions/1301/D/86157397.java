import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DTimeToRun solver = new DTimeToRun();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTimeToRun {
        public void solve(int testNumber, FastReader s, PrintWriter out) {
            int n = s.nextInt();
            int m = s.nextInt();
            int k = s.nextInt();

            if (k > (4 * n * m) - (2 * n) - (2 * m)) {
                out.println("NO");
                return;
            }

            out.println("YES");
            ArrayList<DTimeToRun.pair> list = new ArrayList<>();

            if (n == 1) {
                if (k >= m - 1) {
                    list.add(new DTimeToRun.pair(m - 1, "R"));
                    k -= (m - 1);
                    list.add(new DTimeToRun.pair(k, "L"));
                } else {
                    list.add(new DTimeToRun.pair(k, "R"));
                }
            } else if (m == 1) {
                if (k >= n - 1) {
                    list.add(new DTimeToRun.pair(n - 1, "D"));
                    k -= (n - 1);
                    list.add(new DTimeToRun.pair(k, "U"));
                } else {
                    list.add(new DTimeToRun.pair(k, "D"));
                }
            } else {
                for (int i = 0; i < n && k > 0; i++) {
                    if (k >= m - 1) {
                        list.add(new DTimeToRun.pair(m - 1, "R"));
                        k -= (m - 1);
                    } else {
                        list.add(new DTimeToRun.pair(k, "R"));
                        k = 0;
                    }

                    if (k == 0) {
                        break;
                    }

                    if (i == 0) {
                        if (k >= m - 1) {
                            list.add(new DTimeToRun.pair(m - 1, "L"));
                            k -= (m - 1);
                        } else {
                            list.add(new DTimeToRun.pair(k, "R"));
                            k = 0;
                        }
                    } else {
                        if (k >= 3 * (m - 1)) {
                            list.add(new DTimeToRun.pair(m - 1, "UDL"));
                            k = k - (3 * (m - 1));
                        } else {
                            if (k >= 3) {
                                list.add(new DTimeToRun.pair(k / 3, "UDL"));
                            }
                            k %= 3;
                            if (k == 2) {
                                list.add(new DTimeToRun.pair(1, "UD"));
                            } else if (k == 1) {
                                list.add(new DTimeToRun.pair(1, "U"));
                            }
                            k = 0;
                        }
                    }

                    if (k == 0) {
                        break;
                    }

                    if (i == n - 1) {
                        if (k >= n - 1) {
                            list.add(new DTimeToRun.pair(n - 1, "U"));
                            k -= (n - 1);
                        } else {
                            list.add(new DTimeToRun.pair(k, "U"));
                            k = 0;
                        }
                    } else {
                        if (k >= 1) {
                            list.add(new DTimeToRun.pair(1, "D"));
                            k--;
                        }
                    }
                }
            }

            out.println(list.size());
            out.println(DTimeToRun.arrayLists.print(list));


        }

        private static class pair {
            int val;
            String str;

            public pair(int val, String str) {
                this.val = val;
                this.str = str;
            }

            public String toString() {
                return this.val + " " + this.str;
            }

        }

        private static class arrayLists {
            static StringBuilder print(ArrayList<?> list) {
                StringBuilder ans = new StringBuilder();
                for (Object curr : list) {
                    ans.append(curr.toString()).append("\n");
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

