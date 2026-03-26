import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DThreeIntegers solver = new DThreeIntegers();
        solver.solve(1, in, out);
        out.close();
    }

    static class DThreeIntegers {
        ArrayList<Integer>[] d;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            d = new ArrayList[20001];
            for (int i = 0; i <= 20000; i++) {
                d[i] = findDiv(i);
            }
            int t = in.nextInt();
            while (t-- > 0) {
                int[] f = new int[3];
                int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
                int ans = Integer.MAX_VALUE;
                for (int i = 1; i <= 20000; i++) {
//                out.println(d[i]);
                    int c1 = 0, a1 = 0;
                    int val = Math.abs(b - i);
                    if (c <= i) {
                        val += Math.abs(i - c);
                        c1 = i;
                    } else {
                        val += Math.min(c % i, i - (c % i));
                        if (c % i < i - (c % i)) {
                            c1 = c - (c % i);
                        } else {
                            c1 = c + (i - (c % i));
                        }
                    }
                    if (a >= i) {
                        val += a - i;
                        a1 = i;
                    } else {
                        int id = LowerBound(d[i], a);
                        if (id >= d[i].size()) {
                            val += Math.abs(a - d[i].get(id - 1));
                            a1 = d[i].get(id - 1);
                        } else {
                            int v = d[i].get(id);
                            if (id - 1 >= 0) {
                                val += Math.min(Math.abs(a - v), Math.abs(a - d[i].get(id - 1)));
                                if (Math.abs(a - v) > Math.abs(a - d[i].get(id - 1))) {
                                    a1 = d[i].get(id - 1);
                                } else {
                                    a1 = v;
                                }
                            } else {
                                val += Math.abs(a - v);
                                a1 = v;
                            }
                        }
                    }
                    if (val < ans) {
                        f[0] = a1;
                        f[1] = i;
                        f[2] = c1;
                    }
                    ans = Math.min(ans, val);
                }
                out.println(ans);
                out.println(f);
            }

        }

        int LowerBound(ArrayList<Integer> a, int x) { // first element greater or equal to x
            int l = -1, r = a.size();
            while (l + 1 < r) {
                int m = (l + r) >>> 1;
                if (a.get(m) >= x) r = m;
                else l = m;
            }
            return r;
        }

        ArrayList<Integer> findDiv(int N) {
            //gens all divisors of N
            ArrayList<Integer> ls1 = new ArrayList<Integer>();
            ArrayList<Integer> ls2 = new ArrayList<Integer>();
            for (int i = 1; i <= (int) (Math.sqrt(N) + 0.00000001); i++)
                if (N % i == 0) {
                    ls1.add(i);
                    ls2.add(N / i);
                }
            Collections.reverse(ls2);
            for (int b : ls2)
                if (b != ls1.get(ls1.size() - 1))
                    ls1.add(b);
            return ls1;
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
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

        public void println(int i) {
            writer.println(i);
        }

    }
}

