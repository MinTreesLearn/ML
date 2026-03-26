import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
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
        EObtainAPermutation solver = new EObtainAPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class EObtainAPermutation {
        int n;
        int m;
        int[][] arr;
        int[][] f;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            arr = in.nextIntMatrix(n, m);
            f = new int[n][m];
            int k = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    f[i][j] = k++;
                }
            }
            int ans = 0;
            for (int i = 0; i < m; i++) {
//            out.println(i,val(i));
                ans += val(i);
            }
            out.println(ans);
        }

        int val(int c) {
            int[] dis = new int[n];
            HashMap<Integer, Integer> index = new HashMap<>();
            for (int i = 0; i < n; i++) {
                index.put(f[i][c], i);
            }
            for (int i = 0; i < n; i++) {
                int x = arr[i][c];
                if (!index.containsKey(x)) continue;
                int id = index.get(x);
                if (id <= i) {
                    dis[i - id]++;
                } else {
                    dis[n - (id - i)]++;
                }
            }
            int ans = n;
            for (int i = n - 1; i >= 0; i--) {
                if (dis[i] == 0) continue;
                ans = Math.min(ans, i + n - dis[i]);
            }
            return ans;
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

        public int[][] nextIntMatrix(int rows, int cols) {
            int[][] matrix = new int[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextInt();
            return matrix;
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

