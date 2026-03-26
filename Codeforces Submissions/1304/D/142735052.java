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
        BShortestAndLongestLIS solver = new BShortestAndLongestLIS();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class BShortestAndLongestLIS {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            char[] arr = in.next().toCharArray();
            int[] a1 = new int[n];
            int[] a2 = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                a1[i] = n - i;
                a2[i] = i + 1;
            }
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] == '>') continue;
                int j = i;
                while (j < n - 1 && arr[j] == '<') {
                    j++;
                }
                reverse(a1, i, j);
                i = j - 1;
            }
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] == '<') continue;
                int j = i;
                while (j < n - 1 && arr[j] == '>') j++;
                reverse(a2, i, j);
                i = j - 1;
            }
            out.println(a1);
            out.println(a2);
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
}

