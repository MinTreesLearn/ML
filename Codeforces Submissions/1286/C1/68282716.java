import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
import java.io.UncheckedIOException;
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
        C1MadhouseEasyVersion solver = new C1MadhouseEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class C1MadhouseEasyVersion {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            // out.setBoolLabel(LightWriter.BoolLabel.YES_NO_FIRST_UP);
            out.enableAutoFlush();
            int n = in.ints();
            char[] p1 = guess(in, out, 1, n);
            if (n == 1) {
                out.ans('!').ans(String.valueOf(p1)).ln();
                return;
            }
            char[] p2 = guess(in, out, 1, n - 1);

            int[] cnt = new int[26];
            for (int i = 0; i < n; i++) cnt[p1[i] - 'a']++;
            for (int i = 0; i < n - 1; i++) cnt[p2[i] - 'a']--;
            char[] ans = new char[n];
            for (int i = 0; i < 26; i++) if (cnt[i] > 0) ans[n - 1] = (char) (i + 'a');
            for (int i = 0; i < n / 2; i++) {
                if (ans[n - i - 1] != p1[n - i - 1]) ArrayUtil.swap(p1, i, n - i - 1);
                ans[i] = p1[i];
                if (ans[i] != p2[i]) ArrayUtil.swap(p2, i, n - i - 2);
                ans[n - i - 2] = p2[n - i - 2];
            }

            out.ans('!').ans(String.valueOf(ans)).ln();
        }

        private static char[] guess(LightScanner in, LightWriter out, int from, int to) {
            int n = to - from + 1;
            if (n == 0) return new char[0];

            out.ans('?').ans(from).ans(to).ln();
            int n2 = (n + 1) / 2;
            int[][] cnt = new int[26][n + 1];
            for (int i = 0; i < n * (n + 1) / 2; i++) {
                char[] s = in.string().toCharArray();
                if (s.length < n2) continue;
                for (char c : s) cnt[c - 'a'][s.length]++;
            }
            for (int i = n2; i < n; i++) {
                for (int j = 0; j < 26; j++) {
                    cnt[j][i] -= cnt[j][i + 1];
                }
            }
            for (int i = n; i >= n2 + 1; i--) {
                for (int j = 0; j < 26; j++) {
                    cnt[j][i] -= cnt[j][i - 1];
                }
            }

            char[] ans = new char[n];
            for (int i = 0; i < n; i++) {
                int ref = Math.max(n - i, i + 1);
                for (int j = 0; j < 26; j++) {
                    if (cnt[j][ref] > 0) {
                        cnt[j][ref]--;
                        ans[i] = (char) ('a' + j);
                        break;
                    }
                }
            }
            return ans;
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

        public void enableAutoFlush() {
            autoflush = true;
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

        public LightWriter ans(char c) {
            if (!breaked) {
                print(' ');
            }
            return print(c);
        }

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' ');
            }
            return print(s);
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

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static void swap(char[] a, int x, int y) {
            char t = a[x];
            a[x] = a[y];
            a[y] = t;
        }

    }
}

