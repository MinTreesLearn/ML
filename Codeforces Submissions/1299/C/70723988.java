import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.io.BufferedOutputStream;
import java.io.UncheckedIOException;
import java.util.Vector;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        LightWriter out = new LightWriter(outputStream);
        CWaterBalance solver = new CWaterBalance();
        solver.solve(1, in, out);
        out.close();
    }

    static class CWaterBalance {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints();
            Stack<CWaterBalance.Node> stack = new Stack<>();
            for (int i = 0; i < n; i++) {
                CWaterBalance.Node node = new CWaterBalance.Node(1, in.ints());
                while (!stack.isEmpty() && stack.peek().compareTo(node) > 0) {
                    node.merge(stack.pop());
                }
                stack.push(node);
            }
            for (CWaterBalance.Node node : stack) {
                for (int i = 0; i < node.length(); i++) {
                    out.ans(node.value(), 12).ln();
                }
            }
        }

        private static class Node implements Comparable<CWaterBalance.Node> {
            int count;
            long sum;

            Node(int count, long sum) {
                this.count = count;
                this.sum = sum;
            }

            int length() {
                return count;
            }

            double value() {
                return sum / (double) length();
            }

            public int compareTo(CWaterBalance.Node o) {
                return Long.compare(sum * o.length(), o.sum * length());
            }

            void merge(CWaterBalance.Node o) {
                this.count += o.count;
                this.sum += o.sum;
            }

        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

    }

    static class LightWriter implements AutoCloseable {
        private final Writer out;
        private boolean autoflush = false;
        private boolean breaked = true;

        public LightWriter(Writer out) {
            this.out = out;
        }

        public LightWriter(OutputStream out) {
            this(new OutputStreamWriter(new BufferedOutputStream(out), Charset.defaultCharset()));
        }

        public LightWriter print(char c) {
            try {
                out.write(c);
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length());
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter ans(double x, int n) {
            if (!breaked) {
                print(' ');
            }
            if (x < 0) {
                print('-');
                x = -x;
            }
            x += Math.pow(10, -n) / 2;
            print(Long.toString((long) x)).print('.');
            x -= (long) x;
            for (int i = 0; i < n; i++) {
                x *= 10;
                print((char) ('0' + ((int) x)));
                x -= (int) x;
            }
            return this;
        }

        public LightWriter ln() {
            print(System.lineSeparator());
            breaked = true;
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        public void close() {
            try {
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

    }
}

