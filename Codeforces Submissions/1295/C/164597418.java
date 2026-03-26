import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve(new InputReader(System.in), new PrintWriter(System.out));
    }

    private void solve(InputReader in, PrintWriter pw) {
        int tt = in.nextInt();
        while (tt-- > 0) {
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();

            int n = s.length;
            int m = t.length;
            final int INF = 0x3f3f3f3f;
            int[][] f = new int[n + 1][26];
            for (int i = 0; i < 26; i++) {
                f[n][i] = INF;
            }

            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < 26; j++) {
                    if ((char) (j + 'a') == s[i]) {
                        f[i][j] = i;
                    } else {
                        f[i][j] = f[i + 1][j];
                    }
                }
            }

            int ans = 1, pos = 0;
            for (int i = 0; i < m; i++) {
                if (pos == n) {
                    ans++;
                    pos = 0;
                }
                if (f[pos][t[i] - 'a'] == INF) {
                    ans++;
                    pos = 0;
                    if (f[pos][t[i] - 'a'] == INF) {
                        ans = INF;
                        break;
                    }
                }
                pos = f[pos][t[i] - 'a'] + 1;
            }
            pw.println(ans >= INF ? -1 : ans);
        }
        pw.close();
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

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

    public String nextLine() {
        String str;
        try {
            str = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return str;
    }

    public boolean hasNext() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String nextLine = null;
            try {
                nextLine = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (nextLine == null)
                return false;
            tokenizer = new StringTokenizer(nextLine);
        }
        return true;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}