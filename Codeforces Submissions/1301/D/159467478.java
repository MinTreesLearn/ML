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
        DTimeToRun solver = new DTimeToRun();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTimeToRun {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            if (k > 4 * n * m - 2 * n - 2 * m) {
                out.println("NO");
                return;
            }
            out.println("YES");
            if (m == 1) {
                out.println(k);
                int min = Math.min(k, n - 1);
                k -= min;
                for (int i = 0; i < min; i++) {
                    out.println("1 D");
                }
                min = Math.min(k, n - 1);
                if (k != 0) {
                    for (int i = 0; i < min; i++) {
                        out.println("1 U");
                    }
                }
                return;
            }
            ArrayList<String> ans = new ArrayList<>();
            int id = -1;
            for (int i = 0; i < n - 1; i++) {
                int val = 4 * (m - 1) + 1;
                if (val <= k) {
                    id = i;
                    k -= val;
                    ans.add("" + (m - 1) + " RDU");
                    ans.add("" + (m - 1) + " L");
                    ans.add("1 D");
                } else {
                    break;
                }
            }
            if (k != 0) {
                int min = Math.min(k, m - 1);
                ans.add("" + min + " R");
                k -= min;
            }

            id++;
            if (k != 0) {
                int min = Math.min(k, m - 1);
                ans.add("" + min + " L");
                k -= min;
            }

            if (id != n - 1) {
                if (k > 0) {
                    k -= 1;
                    ans.add("1 D");
                }
                if (k != 0) {
                    int min = Math.min(k, m - 1);
                    ans.add("" + min + " R");
                    k -= min;
                }

                if (k != 0) {
                    int min = Math.min(k, m - 1);
                    ans.add("" + min + " L");
                    k -= min;
                }
            }
            if (k > 0) {
                int min = Math.min(k, n - 1);
                ans.add("" + min + " U");
            }
            out.println(ans.size());
            for (String s : ans) out.println(s);

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

        public void println(int i) {
            writer.println(i);
        }

    }
}

