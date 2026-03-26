import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        E2StringColoringHardVersion solver = new E2StringColoringHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E2StringColoringHardVersion {
        static int n;
        static char[] arr;
        static int[] ans;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            arr = in.next().toCharArray();
            ans = new int[n];
            int color = 1;
            int[] last = new int[26];
            for (int i = 0; i < n; i++) {
                last[arr[i] - 'a'] = i;
            }
            Arrays.fill(ans, 1);
            TreeSet<Integer>[] list = new TreeSet[100];
            for (int i = 0; i < 100; i++) {
                list[i] = new TreeSet<>();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (list[j].higher(arr[i] - 'a') == null) {
                        ans[i] = j;
                        list[j].add(arr[i] - 'a');
                        break;
                    }
                }
            }
            int sz = 0;
            TreeSet<Integer> set = new TreeSet<>();
            for (int a : ans) set.add(a);
            out.println(set.size());
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

