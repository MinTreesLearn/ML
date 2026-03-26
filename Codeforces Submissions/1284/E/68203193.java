import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
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
        ENewYearAndCastleConstruction solver = new ENewYearAndCastleConstruction();
        solver.solve(1, in, out);
        out.close();
    }

    static class ENewYearAndCastleConstruction {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            int n = in.ints();
            Vec2l[] points = new Vec2l[n];
            for (int i = 0; i < n; i++) points[i] = new Vec2l(in.longs(), in.longs());
            long ans = n * (n - 1L) * (n - 2L) * (n - 3L) * (n - 4L) / 24;

            for (int t = 0; t < n; t++) {
                int m = 0;
                Vec2l[] angles = new Vec2l[n - 1];
                {
                    Vec2l now = points[t];
                    for (int i = 0; i < n; i++) {
                        if (i != t) {
                            angles[m] = new Vec2l(points[i].x - now.x, points[i].y - now.y);
                            m++;
                        }
                    }
                    Arrays.sort(angles, Vec2l::compareToByAngle);
                }
                //System.out.println(Arrays.stream(angles).map(angle -> Double.toString(Math.atan2(angle.y, angle.x))).collect(Collectors.joining(", ")));

                int hi = 0;
                for (int j = 0; j < m; j++) {
                    while (hi < j + m && (hi <= j || angles[j].det(angles[hi % m]) > 0)) {
                        hi++;
                    }
                    int cnt = hi - j;
                    ans -= (cnt - 1L) * (cnt - 2L) * (cnt - 3L) / 6;
                }
            }
            out.ans(ans).ln();
        }

    }

    static class Vec2l implements Comparable<Vec2l> {
        public long x;
        public long y;

        public Vec2l(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public long det(Vec2l other) {
            return x * other.y - other.x * y;
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

        public int compareToByAngle(Vec2l o) {
            if ((y >= 0) != (o.y >= 0)) {
                return y >= 0 ? 1 : -1;
            } else {
                return Long.compare(0, x * o.y - o.x * y);
            }
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
}

