import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Random;
import java.util.HashMap;
import java.io.BufferedOutputStream;
import java.util.HashSet;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.stream.LongStream;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.io.Writer;
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
        FKuroniAndThePunishment solver = new FKuroniAndThePunishment();
        solver.solve(1, in, out);
        out.close();
    }

    static class FKuroniAndThePunishment {
        private static final Random rand = new Random();

        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints();
            long[] a = in.longs(n);
            Set<Long> cand = new HashSet<>();
            for (int i = 0; i < 20; i++) {
                long x = a[rand.nextInt(n)];
                if (x == 1) continue;
                cand.addAll(IntMath.primeFactorize(x - 1).keySet());
                cand.addAll(IntMath.primeFactorize(x).keySet());
                cand.addAll(IntMath.primeFactorize(x + 1).keySet());
            }
            long ans = n;
            for (long x : cand) {
                long t = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] <= x) t += x - a[i];
                    else {
                        long r = a[i] % x;
                        t += Math.min(r, x - r);
                    }
                }
                ans = Math.min(ans, t);
            }
            out.ans(ans).ln();
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

        public long longs() {
            return Long.parseLong(string());
        }

        public long[] longs(int length) {
            return IntStream.range(0, length).mapToLong(x -> longs()).toArray();
        }

    }

    static final class IntMath {
        private IntMath() {
        }

        public static Map<Long, Integer> primeFactorize(long p) {
            Map<Long, Integer> factor = new HashMap<>();
            if ((p & 1) == 0) {
                int c = 0;
                do {
                    c++;
                    p >>= 1;
                } while ((p & 1) == 0);
                factor.put(2L, c);
            }
            for (long i = 3; i * i <= p; i += 2) {
                if (p % i == 0) {
                    int c = 0;
                    do {
                        c++;
                        p /= i;
                    } while ((p % i) == 0);
                    factor.put(i, c);
                }
            }
            if (p > 1) {
                factor.put(p, 1);
            }
            return factor;
        }

    }

    static interface Verified {
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

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' ');
            }
            return print(s);
        }

        public LightWriter ans(long l) {
            return ans(Long.toString(l));
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

