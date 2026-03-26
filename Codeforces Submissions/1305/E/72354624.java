import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedOutputStream;
import java.io.UncheckedIOException;
import java.util.List;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.Comparator;
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
        EKuroniAndTheScoreDistribution solver = new EKuroniAndTheScoreDistribution();
        solver.solve(1, in, out);
        out.close();
    }

    static class EKuroniAndTheScoreDistribution {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            long start = System.currentTimeMillis();
            int n = in.ints();
            long m = in.longs();
            List<Long> added = new ArrayList<>();
            Map<Long, Integer> map = new HashMap<>();
            for (long cur = 1; 0 < m && added.size() < n && System.currentTimeMillis() - start < 900; cur++) {
                int p = map.getOrDefault(cur, 0);
                if (p > m) continue;
                m -= p;
                for (long x : added) map.merge(x + cur, 1, Integer::sum);
                added.add(cur);
            }
            if (m == 0) {
                long min = 1;
                while (added.contains(min)) min++;

                long max = 1_000_000_000;
                while (added.size() < n) {
                    added.add(max);
                    max -= min;
                }
            } else if (added.size() != n || m > 0) {
                out.ans(-1).ln();
                return;
            }
            added.sort(Comparator.naturalOrder());
            for (long x : added) out.ans(x);
            out.ln();
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

        public LightWriter ans(int i) {
            return ans(Integer.toString(i));
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

