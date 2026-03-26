import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class C1322C_1 {

    static long modulo1 = (long) 1e9;
    static long modulo2 = (long) 1e7;

    public static void main(String[] args) throws IOException {
        var scanner = new BufferedScanner();
        var t = scanner.nextInt();
        var writer = new BufferedWriter(new PrintWriter(System.out));
        for (int i = 0; i < t; i++) {
            var n = scanner.nextInt();
            var m = scanner.nextInt();
            var c = new long[n + 1];
            for (int j = 1; j <= n; j++) {
                c[j] = scanner.nextLong();
            }
            var connectedToRight = new HashMap<Integer, List<Integer>>();
            for (int j = 0; j < m; j++) {
                var u = scanner.nextInt();
                var v = scanner.nextInt();
                connectedToRight.compute(v, (k, l) -> {
                    if (l == null) {
                        l = new ArrayList<>();
                    }
                    l.add(u);
                    return l;
                });
            }
            var hash1 = new long[n + 1];
            var hash2 = new long[n + 1];
            for (var entry : connectedToRight.entrySet()) {
                var right = entry.getKey();
                var lefts = entry.getValue();
                lefts.sort(Integer::compareTo);
                for (Integer left : lefts) {
                    hash1[right] = hash(hash1[right], n + 1, left, modulo1);
                    hash2[right] = hash(hash2[right], n + 1, left, modulo2);
                }
            }
            var rights = new ArrayList<>(connectedToRight.keySet());
            rights.sort(Comparator.comparingLong(j -> hash1[(int) j]).thenComparingLong(j -> hash2[(int) j]));
            var j= -1;
            var h1 = -1L;
            var h2 = -1L;
            var ans = 0L;
            for (Integer right : rights) {
                if (hash1[right] == h1 && hash2[right] == h2) {
                    c[j] += c[right];
                } else {
                    if (h1 >= 0) {
                        ans = gcd(ans, c[j]);
                    }
                    j = right;
                    h1 = hash1[right];
                    h2 = hash2[right];
                }
            }
            if (h1 >= 0) {
                ans = gcd(ans, c[j]);
            }
//            System.out.println(ans);
            writer.write(String.valueOf(ans));
            writer.newLine();
        }
        writer.flush();
        writer.close();
    }

    private static long gcd(long a, long b) {
        if (a > b) {
            return gcd(b, a);
        }
        while (b > 0) {
            long tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    private static long hash(long acc, int r, int x, long modulo) {
        return (acc * r + x) % modulo;
    }

    public static class BufferedScanner {
        BufferedReader br;
        StringTokenizer st;

        public BufferedScanner(Reader reader) {
            br = new BufferedReader(reader);
        }

        public BufferedScanner() {
            this(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }

}
