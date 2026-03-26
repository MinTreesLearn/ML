import java.io.*;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class MainE {

    static int N;
    static int[] A;

    public static void main(String[] args) {
        var sc = new FastScanner(System.in);
        N = sc.nextInt();
        A = sc.nextIntArray(N);

        System.out.println(solve());
    }

    private static int solve() {
        // [L, R)
        var merged = new int[N][N+1];
        for (int i = 0; i < N; i++) {
            merged[i][i+1] = A[i];
        }
        for (int w = 2; w <= N; w++) {
            for (int l = 0; l < N-w+1; l++) {
                int r = l+w;
                int lr = -1;
                for (int m = l+1; m < r; m++) {
                    if( merged[l][m] != -1 && merged[l][m] == merged[m][r] ) {
                        lr = merged[l][m]+1;
                    }
                }
                merged[l][r] = lr;
            }
        }

        var len = new int[N][N+1];
        for (int i = 0; i < N; i++) {
            len[i][i+1] = 1;
        }
        for (int w = 2; w <= N; w++) {
            for (int l = 0; l < N-w+1; l++) {

                int r = l+w;
                int lr = Integer.MAX_VALUE;
                if( merged[l][r] != -1 ) {
                    len[l][r] = 1;
                    continue;
                }
                for (int m = l+1; m < r; m++) {
                    lr = Math.min(lr, len[l][m] + len[m][r]);
                }
                len[l][r] = lr;
            }
        }

        return len[0][N];
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            var a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        int[] nextIntArray(int n, int delta) {
            var a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt() + delta;
            return a;
        }

        long[] nextLongArray(int n) {
            var a = new long[n];
            for (int i = 0; i < n; i++) a[i] = nextLong();
            return a;
        }
    }

    static void writeLines(int[] as) {
        var pw = new PrintWriter(System.out);
        for (var a : as) pw.println(a);
        pw.flush();
    }

    static void writeLines(long[] as) {
        var pw = new PrintWriter(System.out);
        for (var a : as) pw.println(a);
        pw.flush();
    }

    static void writeSingleLine(int[] as) {
        var pw = new PrintWriter(System.out);
        for (var i = 0; i < as.length; i++) {
            if (i != 0) pw.print(" ");
            pw.print(as[i]);
        }
        pw.println();
        pw.flush();
    }

    static void debug(Object... args) {
        var j = new StringJoiner(" ");
        for (var arg : args) {
            if (arg == null) j.add("null");
            else if (arg instanceof int[]) j.add(Arrays.toString((int[]) arg));
            else if (arg instanceof long[]) j.add(Arrays.toString((long[]) arg));
            else if (arg instanceof double[]) j.add(Arrays.toString((double[]) arg));
            else if (arg instanceof Object[]) j.add(Arrays.toString((Object[]) arg));
            else j.add(arg.toString());
        }
        System.err.println(j.toString());
    }
}
