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
        DSameGCDs solver = new DSameGCDs();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class DSameGCDs {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long a = in.nextLong(), m = in.nextLong();
            long g = gcd(a, m);
            a /= g;
            m /= g;

            long ans = countCoprime(m, a + m) - countCoprime(m, a - 1);
            out.println(ans - 1);

        }

        public static long gcd(long a, long b) {
            return b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b);
        }

        static long countCoprime(long n, long r) {
            ArrayList<Long> primes = new ArrayList<>();
            for (long i = 2; i * i <= n; ++i)
                if (n % i == 0) {
                    primes.add(i);
                    while (n % i == 0) n /= i;
                }
            if (n > 1)
                primes.add(n);
            long sum = 0, size = primes.size();
            for (long msk = 1L, end = 1L << size; msk < end; ++msk) {
                long mult = 1, bits = 0;
                for (int i = 0; i < size; ++i)
                    if ((msk & 1L << i) != 0) {
                        ++bits;
                        mult *= primes.get(i);
                    }
                if (bits % 2 == 1)
                    sum += r / mult;
                else
                    sum -= r / mult;
            }

            return r - sum;
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

        public long nextLong() {
            return Long.parseLong(next());
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

