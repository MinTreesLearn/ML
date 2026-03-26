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
        CNewYearAndPermutation solver = new CNewYearAndPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class CNewYearAndPermutation {
        int mod = 1000000007;
        long[] fact = new long[2_000_001];
        long[] invfact = new long[2_000_001];

        public void solve(int testNumber, InputReader in, OutputWriter out) {

            int n = in.nextInt(), m = in.nextInt();
            mod = m;
            precompFacts();
            long ans = 0;
            for (int i = 1; i <= n; i++) {
                long c = n - i + 1;
                long f = fact[i];
                long rem = fact[n - i + 1];
                ans = add(ans, mul(c, mul(f, rem)));
            }
            out.println(ans);
        }

        long add(long a, long b) {
            return (a + b) % mod;
        }

        long mul(long a, long b) {
            return (a * b) % mod;
        }

        long exp(long base, long exp) {
            if (exp == 0) return 1;
            long half = exp(base, exp / 2);
            if (exp % 2 == 0) return mul(half, half);
            return mul(half, mul(half, base));
        }

        void precompFacts() {
            fact[0] = invfact[0] = 1;
            for (int i = 1; i < fact.length; i++) fact[i] = mul(fact[i - 1], i);
            invfact[fact.length - 1] = exp(fact[fact.length - 1], mod - 2);
            for (int i = invfact.length - 2; i >= 0; i--)
                invfact[i] = mul(invfact[i + 1], i + 1);
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

