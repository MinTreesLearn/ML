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
        ARemoveAdjacent solver = new ARemoveAdjacent();
        solver.solve(1, in, out);
        out.close();
    }

    static class ARemoveAdjacent {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            char[] arr = in.next().toCharArray();
            ArrayList<Character> list = new ArrayList<>();
            for (char c : arr) list.add(c);
            boolean[] vis = new boolean[n];
            for (char c = 'z'; c >= 'b'; c--) {
                char last = c;
                int lid = -1;
                for (int i = 0; i < n; i++) {
                    if (vis[i]) continue;
                    if (lid != -1 && arr[i] == arr[lid] + 1 && arr[i] == c) {
                        vis[i] = true;
                    } else {
                        lid = i;
                    }
                }
                lid = -1;
                for (int i = n - 1; i >= 0; i--) {
                    if (vis[i]) continue;
                    if (lid != -1 && arr[i] == arr[lid] + 1 && arr[i] == c) {
                        vis[i] = true;
                    } else {
                        lid = i;
                    }
                }
            }
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (vis[i]) c++;
            }
            out.println(c);
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

