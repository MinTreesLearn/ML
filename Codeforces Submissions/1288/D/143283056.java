import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.Objects;
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
        DMinimaxProblem solver = new DMinimaxProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMinimaxProblem {
        int n;
        int m;
        int[][] arr;
        int id1;
        int id2;
        int p;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            arr = in.nextIntMatrix(n, m);
            p = (int) Math.pow(2, m) - 1;
            int lo = 0;
            int hi = (int) 1e9;
            id1 = -1;
            id2 = -1;
            int ans = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (check(mid)) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            out.println(id1, id2);
        }

        boolean check(int mid) {
            TreeSet<Pair> set = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                int mask = 0;
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] >= mid) mask |= (1 << j);
                }
                set.add(new Pair(mask, i));
            }
            for (Pair a : set) {
                for (Pair b : set) {
                    if ((a.a | b.a) == p) {
                        id1 = a.b + 1;
                        id2 = b.b + 1;
                        return true;
                    }
                }
            }
            return false;
        }

        class Pair implements Comparable<Pair> {
            int a;
            int b;

            Pair(int a, int b) {
                this.a = a;
                this.b = b;
            }

            public int hashCode() {
                return Objects.hash(a, b);
            }

            public boolean equals(Object obj) {
                Pair that = (Pair) obj;
                return a == that.a && b == that.b;
            }

            public String toString() {
                return "[" + a + ", " + b + "]";
            }

            public int compareTo(Pair v) {
                return a - v.a;
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
}

