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
        DDrEvilUnderscores solver = new DDrEvilUnderscores();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDrEvilUnderscores {
        int n;
        int[] arr;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            arr = in.nextIntArray(n);
            ArrayList<Integer> list = new ArrayList<>();
            for (int a : arr) list.add(a);
            out.println(rec(29, list));
        }

        int rec(int bit, ArrayList<Integer> list) {
            if (bit < 0) return 0;
            ArrayList<Integer> zero = new ArrayList<>();
            ArrayList<Integer> one = new ArrayList<>();
            for (int a : list) {
                if (((1 << bit) & a) != 0) one.add(a);
                else zero.add(a);
            }
            if (one.size() == 0) return rec(bit - 1, zero);
            if (zero.size() == 0) return rec(bit - 1, one);
            return (1 << bit) + Math.min(rec(bit - 1, zero), rec(bit - 1, one));
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

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

