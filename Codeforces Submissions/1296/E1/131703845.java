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
        E1StringColoringEasyVersion solver = new E1StringColoringEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1StringColoringEasyVersion {
        static int n;
        static char[] arr;
        static int[] ans;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            arr = in.next().toCharArray();
            ans = new int[n];
            Arrays.fill(ans, -1);
            if (pos(n - 1)) {
                out.println("YES");
                for (int i = 0; i < n; i++) out.print(ans[i]);
            } else {
                out.println("NO");
            }
        }

        static boolean pos(int ind) {
            if (ind == -1) return true;

            if (ans[ind] == -1) {
                int last = -1;
                for (int i = 0; i < ind; i++) {
                    if (ans[i] == -1) continue;
                    if (arr[i] > arr[ind] && last == -1) last = ans[i];
                    else if (arr[i] > arr[ind]) {
                        if (ans[i] != last) return false;
                    }
                }
                if (last == -1) {
                    ans[ind] = 0;
                    for (int i = 0; i < ind; i++) {
                        if (arr[i] > arr[ind]) ans[i] = 1;
                    }

                } else {
                    ans[ind] = 1 - last;
                    for (int i = 0; i < ind; i++) {
                        if (arr[i] > arr[ind]) ans[i] = last;
                    }
                }
                return pos(ind - 1);
            } else {
                int c = 1 - ans[ind];
                for (int i = 0; i < ind; i++) {
                    if (ans[i] == -1) continue;
                    if (arr[i] > arr[ind] && ans[i] != c) return false;
                }
                for (int i = 0; i < ind; i++) {
                    if (arr[i] > arr[ind]) ans[i] = c;
                }
                return pos(ind - 1);
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
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

        public void print(int i) {
            writer.print(i);
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

