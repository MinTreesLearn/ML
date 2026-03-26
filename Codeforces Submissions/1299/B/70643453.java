import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
import java.util.HashSet;
import java.io.UncheckedIOException;
import java.util.Objects;
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
        BAerodinamicheskii solver = new BAerodinamicheskii();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAerodinamicheskii {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints();
            HashSet<Vec2l> ps = new HashSet<>();
            long gx = 0, gy = 0;
            long[] x = new long[n], y = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.longs();
                y[i] = in.longs();
                gx += x[i];
                gy += y[i];
                x[i] *= n;
                y[i] *= n;
                ps.add(new Vec2l(x[i], y[i]));
            }
            gx *= 2;
            gy *= 2;
            for (int i = 0; i < n; i++) {
                if (!ps.contains(new Vec2l(gx - x[i], gy - y[i]))) {
                    out.noln();
                    return;
                }
            }
            out.yesln();
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
        private LightWriter.BoolLabel boolLabel = LightWriter.BoolLabel.YES_NO_FIRST_UP;

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

        public LightWriter ans(boolean b) {
            return ans(boolLabel.transfer(b));
        }

        public LightWriter yesln() {
            return ans(true).ln();
        }

        public LightWriter noln() {
            return ans(false).ln();
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

        public enum BoolLabel {
            YES_NO_FIRST_UP("Yes", "No"),
            YES_NO_ALL_UP("YES", "NO"),
            YES_NO_ALL_DOWN("yes", "no"),
            Y_N_ALL_UP("Y", "N"),
            POSSIBLE_IMPOSSIBLE_FIRST_UP("Possible", "Impossible"),
            POSSIBLE_IMPOSSIBLE_ALL_UP("POSSIBLE", "IMPOSSIBLE"),
            POSSIBLE_IMPOSSIBLE_ALL_DOWN("possible", "impossible"),
            FIRST_SECOND_FIRST_UP("First", "Second"),
            FIRST_SECOND_ALL_UP("FIRST", "SECOND"),
            FIRST_SECOND_ALL_DOWN("first", "second"),
            ALICE_BOB_FIRST_UP("Alice", "Bob"),
            ALICE_BOB_ALL_UP("ALICE", "BOB"),
            ALICE_BOB_ALL_DOWN("alice", "bob"),
            ;
            private final String positive;
            private final String negative;

            BoolLabel(String positive, String negative) {
                this.positive = positive;
                this.negative = negative;
            }

            private String transfer(boolean f) {
                return f ? positive : negative;
            }

        }

    }

    static class Vec2l implements Comparable<Vec2l> {
        public long x;
        public long y;

        public Vec2l(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vec2l vec2i = (Vec2l) o;
            return x == vec2i.x &&
                    y == vec2i.y;
        }

        public int hashCode() {
            return Objects.hash(x, y);
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        public int compareTo(Vec2l o) {
            if (x == o.x) {
                return Long.compare(y, o.y);
            }
            return Long.compare(x, o.x);
        }

        public Vec2l clone() throws CloneNotSupportedException {
            return (Vec2l) super.clone();
        }

    }
}

