import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        DFillTheBag solver = new DFillTheBag();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class DFillTheBag {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long n = in.nextLong();
            int m = in.nextInt();
            int[] arr = in.nextIntArray(m);
            long sum = 0;
            for (int a : arr) sum += a;
            if (sum < n) {
                out.println(-1);
                return;
            }
            long[] f = new long[64];
            for (int i = 0; i < 32; i++) {
                for (int a : arr) {
                    if ((a & (1 << i)) != 0) f[i]++;
                }
            }
            int ans = 0;
            for (int i = 0; i <= 60; i++) {
                if (((1L << i) & n) != 0) {
                    if (f[i] > 0) {
                        f[i]--;
                    } else {
                        for (int j = i + 1; j <= 60; j++) {
                            if (f[j] > 0) {
                                ans += j - i;
                                f[j]--;
                                for (int k = j - 1; k >= i; k--) {
                                    f[k]++;
                                }
                                break;
                            }
                        }
                    }
                }
                f[i + 1] += f[i] / 2;
            }
            out.println(ans);
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

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
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

        public void println(int i) {
            writer.println(i);
        }

    }
}

