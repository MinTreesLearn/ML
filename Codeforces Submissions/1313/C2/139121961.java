import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        C2SkyscrapersHardVersion solver = new C2SkyscrapersHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class C2SkyscrapersHardVersion {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.nextIntArray(n);
            int[] b = Arrays.copyOf(arr, n);
            reverse(b, 0, n - 1);
            long[] t1 = calc(arr);
            long[] t2 = calc(b);
            long ans = 0;
            int ind = -1;
            for (int i = 0; i < n; i++) {
                long t = t1[i];
                t += t2[n - i - 1];
                t -= arr[i];
                if (t > ans) {
                    ans = t;
                    ind = i;
                }
            }
//        out.println(ind);
            int[] fans = new int[n];
            int m = arr[ind];
            for (int i = ind; i >= 0; i--) {
                fans[i] = Math.min(m, arr[i]);
                m = Math.min(m, arr[i]);
            }
            m = arr[ind];
            for (int i = ind; i < n; i++) {
                fans[i] = Math.min(m, arr[i]);
                m = Math.min(m, arr[i]);
            }
            out.println(fans);
        }

        void reverse(int[] arr, int i, int j) {
            while (i < j) {
                swap(arr, i++, j--);
            }
        }

        void swap(int[] arr, int i, int j) {
            if (i != j) {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }

        long[] calc(int[] arr) {
            int n = arr.length;
            long[] narr = new long[n];
            int[] temp = nsv(arr);
            Arrays.fill(narr, -1);
            for (int i = 0; i < n; i++) {
                if (temp[i] == -1) {
                    narr[i] = (long) (i + 1) * arr[i];
                } else {
                    narr[i] = (long) (i - temp[i]) * arr[i] + narr[temp[i]];
                }
            }
            return narr;
        }

        int[] nsv(int[] a) {
            int n = a.length;
            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                int j = i - 1;
                while (j != -1 && a[j] >= a[i]) {
                    j = p[j];
                }
                p[i] = j;
            }
            return p;
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

