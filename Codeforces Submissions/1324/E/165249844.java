import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve(new InputReader(System.in), new PrintWriter(System.out));
    }

    private void solve(InputReader in, PrintWriter pw) {
        int tt = 1;
//        int tt = in.nextInt();
        while (tt-- > 0) {
            int n = in.nextInt();
            int h = in.nextInt();
            int l = in.nextInt();
            int r = in.nextInt();
            int[] a = in.nextArray(n);

            // f[i][j]代表已经睡了i次且恰好早睡j次时好睡眠的次数
            int[][] f = new int[n + 1][n + 1];
            for (int i = 0; i <= n; i++) {
                Arrays.fill(f[i], Integer.MIN_VALUE);
            }
            f[0][0] = 0;
            for (int i = 0, sum = 0; i < n; i++) {
                sum += a[i];
                for (int j = 0; j <= n; j++) {
                    f[i + 1][j] = max(f[i + 1][j], f[i][j] + check((sum - j) % h, l, r));
                    if (j < n) {
                        f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + check((sum - (j + 1)) % h, l, r));
                    }
                }
            }
            int maxv = 0;
            for (int i = 0; i <= n; i++) {
                maxv = max(maxv, f[n][i]);
            }
            pw.println(maxv);
        }
        pw.close();
    }

    private int check(int x, int l, int r) {
        if (x >= l && x <= r) {
            return 1;
        }
        return 0;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private int lcm(int a, int b) {
        return a / gcd(a, b) * b;
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

    public int[] nextArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        return a;
    }
}