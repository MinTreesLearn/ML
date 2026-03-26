import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class E {
    private static final boolean DEBUG = false;

    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var m = scanner.nextInt();
        var q = scanner.nextInt();
//        var n = 500;
//        var m = 500;
//        var q = 1;
        var s = new int[n][m];
        for (int i = 0; i < n; i++) {
            var ss = scanner.next().toCharArray();
            for (int j = 0; j < m; j++) {
                s[i][j] = C2I.get(ss[j]);
//                s[i][j] = (int) (Math.random() * 4) + 1;
            }
        }
        var logo = new int[n][m];
        var t = System.nanoTime();
        prepare(n, m, s, logo);
        log("prepare: %.2f", (System.nanoTime() - t) / 1e9);
        for (int i = 0; i < q; i++) {
            var r1 = scanner.nextInt() - 1;
            var c1 = scanner.nextInt() - 1;
            var r2 = scanner.nextInt() - 1;
            var c2 = scanner.nextInt() - 1;
            writer.println(query(n, m, s, r1, c1, r2, c2, logo));
        }

        scanner.close();
        writer.flush();
        writer.close();
    }

    /**
     * @param logo logo[r][c], logo size with left upper corner at (r,c)
     */
    private static void prepare(int n, int m, int[][] s, int[][] logo) {
        var t = System.nanoTime();
        colorCount = preAreaAcc(1, 4, 1, n, m, s);
        log("color count: %.2f", (System.nanoTime() - t) / 1e9);
        t = System.nanoTime();
        // for every (r,c) at most one size of logo exists
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (s[r][c] == 1) {
                    var redSize = maxRedSize(r, c, n, m, s);
//                    log("redSize(%d,%d)=%d", r, c, redSize);
                    if (redSize == 0) {
                        continue;
                    }
                    if (isSquare(2, r, c + redSize, redSize, s)
                            && isSquare(3, r + redSize, c, redSize, s)
                            && isSquare(4, r + redSize, c + redSize, redSize, s)) {
                        logo[r][c] = redSize * 2;
                    }
                }
            }
        }
        log("logo: %.2f", (System.nanoTime() - t) / 1e9);
        t = System.nanoTime();
        // prepare logo count
        logoCount = preAreaAcc(2, Math.min(n, m), 2, n, m, logo);
        log("logo count: %.2f", (System.nanoTime() - t) / 1e9);
    }

    private static int maxRedSize(int r, int c, int n, int m, int[][] s) {
        if (s[r][c] != 1) {
            return 0;
        }
        var low = 1;
        var high = Math.min(n - r, m - c);
        var ans = 0;
        while (low <= high) {
            var mid = (low + high) / 2;
            if (isSquare(1, r, c, mid, s)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    private static int[][][] preAreaAcc(int typeLow, int typeHigh, int typeInc, int n, int m, int[][] s) {
//        var ans = new int[typeHigh + 1][n + 1][m + 1];
        var ans = new int[typeHigh + 1][][];
        for (var type = typeLow; type <= typeHigh; type += typeInc) {
            ans[type] = new int[n + 1][m + 1];
        }
        for (var r = n - 1; r >= 0; r--) {
            for (var type = typeLow; type <= typeHigh; type += typeInc) {
                ans[type][r][m] = ans[type][r + 1][m];
            }
            for (var c = m - 1; c >= 0; c--) {
                for (var type = typeLow; type <= typeHigh; type += typeInc) {
                    ans[type][r][c] = ans[type][r + 1][c]
                            + ans[type][r][c + 1]
                            - ans[type][r + 1][c + 1];
                    if (type == s[r][c]) {
                        ans[type][r][c]++;
                    }
                }
            }
        }
        return ans;
    }

    private static void log(String fmt, Object... a) {
        if (DEBUG) {
            System.out.println(String.format(fmt, a));
        }
    }

    private static int query(int n, int m, int[][] s, int r1, int c1, int r2, int c2, int[][] logo) {
        // 索引区域内的logo左上角？
        // 如何快速去掉不在区域内的？
        // 当找到某一种尺寸的logo之后，接下来就要找更长的
        // 【重要】logo往内缩一圈还是logo。
        // 所以，如果一个矩形包含的最大logo边长是L，那么这个矩形也包含1..L的logo。
        // 所以，可以用二分查找。
        return cleverQuery(r1, c1, r2, c2);
//        return bfQuery(n, m, s, r1, c1, r2, c2, logo);
    }

    private static int cleverQuery(int r1, int c1, int r2, int c2) {
        // 这里要对半径进行二分查找，因为半径才是连续的，直径差是2。
        var low = 1;
        var high = Math.min(r2 - r1 + 1, c2 - c1 + 1) / 2;
        var ans = 0;
        while (low <= high) {
            var mid = (low + high) / 2;
            if (exists(mid * 2, r1, c1, r2 - mid * 2 + 1, c2 - mid * 2 + 1)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans * ans * 4;
    }

    static int[][][] logoCount;

    private static boolean exists(int size, int r1, int c1, int r2, int c2) {
        var a = logoCount[size];
        var area = a[r1][c1] - a[r2 + 1][c1] - a[r1][c2 + 1] + a[r2 + 1][c2 + 1];
        return area > 0;
    }

    private static int bfQuery(int n, int m, int[][] s, int r1, int c1, int r2, int c2, int[][] logo) {
        var ans = 0;
        for (var r = r1; r <= r2; r++) {
            for (var c = c1; c <= c2; c++) {
                if (logo[r][c] > 0 && r + logo[r][c] - 1 <= r2 && c + logo[r][c] - 1 <= c2) {
                    ans = Math.max(ans, logo[r][c]);
                }
            }
        }
        return ans * ans;
    }

    private static boolean isSquare(int color, int r, int c, int size, int[][] s) {
        if (r + size - 1 >= s.length || c + size - 1 >= s[0].length) {
            return false;
        }
        return area(color, r, c, size) == size * size;
    }

    static int[][][] colorCount; // areaAcc[color][r][c], [(r,c)..(n-1,m-1)]中color的个数

    private static int area(int color, int r, int c, int size) {
        var a = colorCount[color];
        return a[r][c] - a[r + size][c] - a[r][c + size] + a[r + size][c + size];
    }

    static final Map<Character, Integer> C2I = Map.of('R', 1, 'G', 2, 'Y', 3, 'B', 4);

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

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }

    static long gcd(long a, long b) {
        if (a < b) {
            return gcd(b, a);
        }
        while (b > 0) {
            long tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    static long inverse(long a, long m) {
        long[] ans = extgcd(a, m);
        return ans[0] == 1 ? (ans[1] + m) % m : -1;
    }

    private static long[] extgcd(long a, long m) {
        if (m == 0) {
            return new long[]{a, 1, 0};
        } else {
            long[] ans = extgcd(m, a % m);
            long tmp = ans[1];
            ans[1] = ans[2];
            ans[2] = tmp;
            ans[2] -= ans[1] * (a / m);
            return ans;
        }
    }

    private static List<Integer> primes(double upperBound) {
        var limit = (int) Math.sqrt(upperBound);
        var isComposite = new boolean[limit + 1];
        var primes = new ArrayList<Integer>();
        for (int i = 2; i <= limit; i++) {
            if (isComposite[i]) {
                continue;
            }
            primes.add(i);
            int j = i + i;
            while (j <= limit) {
                isComposite[j] = true;
                j += i;
            }
        }
        return primes;
    }


}
