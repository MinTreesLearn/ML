import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
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
        ETeamBuilding solver = new ETeamBuilding();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETeamBuilding {
        int n;
        int p;
        int k;
        int[] arr;
        int[][] s;
        long[][] dp;
        ArrayList<Pair> list;
        long[] psum;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            p = in.nextInt();
            k = in.nextInt();
            arr = in.nextIntArray(n);
            s = in.nextIntMatrix(n, p);
            dp = new long[n][1 << p];
            list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int a = arr[i];
                list.add(new Pair(a, i));
            }
            Collections.sort(list, Collections.reverseOrder());
            psum = new long[n];
            psum[0] = list.get(0).a;
            for (int i = 1; i < n; i++) {
                psum[i] = psum[i - 1] + list.get(i).a;
            }
            for (long[] r : dp) Arrays.fill(r, -1);
            out.println(rec(0, 0));
//        for(long[] r:dp) out.println(r);
        }

        long rec(int i, int mask) {
            if (i >= n) return 0;
            if (dp[i][mask] != -1) return dp[i][mask];
//
            long ans = 0;
            if (i + 1 - Integer.bitCount(mask) <= k) {
                ans = Math.max(ans, rec(i + 1, mask) + list.get(i).a);
            } else {
                ans = Math.max(ans, rec(i + 1, mask));
            }
            for (int j = 0; j < p; j++) {
                if (((1 << j) & mask) != 0) continue;
                ans = Math.max(ans, s[list.get(i).b][j] + rec(i + 1, mask | (1 << j)));
            }


            return dp[i][mask] = ans;
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

        public void println(long i) {
            writer.println(i);
        }

    }
}

