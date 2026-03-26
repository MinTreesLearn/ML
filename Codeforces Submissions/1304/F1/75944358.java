import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class F {

    static int n, m, k;
    static int[][] ani; // animals

    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();
        ani = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ani[i][j] = scanner.nextInt();
            }
        }
//        System.out.println(watch(1, 1, 1));
        writer.println(solve());

        scanner.close();
        writer.flush();
        writer.close();
    }

    private static int solve() {
        dfsCache = new int[n + 1][m + 1];
        for (var i = 1; i <= n; i++) {
            Arrays.fill(dfsCache[i], -1);
        }
        var ans = 0;
        for (int start = 1; start + k - 1 <= m; start++) {
            ans = Math.max(ans, dfs(2, start) + range(1, start, start + k - 1));
        }
        return ans;
    }

    static int[][] dfsCache;

    private static int dfs(int row, int lastStart) {
        if (row > n) {
            return 0;
        }
        if (dfsCache[row][lastStart] >= 0) {
            return dfsCache[row][lastStart];
        }
        var ans = 0;
        // TODO 2020/4/9: 这里m太大，两层搜索就受不了
//        for (int thisStart = 1; thisStart + k - 1 <= m; thisStart++) {
//            var ans1 = dfs(row + 1, thisStart)
//                    + watch(row, lastStart, thisStart);
//            ans = Math.max(ans, ans1);
//        }
        var lastEnd = lastStart + k - 1;
        // no intersection
        {
            int ans0 = leftMax(row, lastStart - 1);
            ans = Math.max(ans, ans0 + range(row, lastStart, lastEnd));
        }
        {
            int ans0 = rightMax(row, lastEnd + 1);
            ans = Math.max(ans, ans0 + range(row, lastStart, lastEnd));
        }
        // intersected
        for (int thisStart = Math.max(1, lastStart - k + 1);
                thisStart <= lastEnd && thisStart + k - 1 <= m; thisStart++) {
            var ans1 = dfs(row + 1, thisStart)
                    + watch(row, lastStart, thisStart);
            ans = Math.max(ans, ans1);
        }
        return dfsCache[row][lastStart] = ans;
    }

    static int[][] rightMaxCache;
    static int[] rightMaxAlready;

    private static int rightMax(int row, int minStart) {
        if (minStart + k - 1 > m) {
            return 0;
        }
        if (rightMaxCache == null) {
            rightMaxCache = new int[n + 1][m + 2];
            rightMaxAlready = new int[n + 1];
            Arrays.fill(rightMaxAlready, m - k + 2);
            for (int i = 1; i <= n; i++) {
                Arrays.fill(rightMaxCache[i], -1);
                rightMaxCache[i][m - k + 2] = 0;
            }
        }
//        System.out.println("row = " + row + ", minStart = " + minStart);
        if (rightMaxCache[row][minStart] >= 0) {
            return rightMaxCache[row][minStart];
        }
        var ans0 = rightMaxCache[row][rightMaxAlready[row]];
        for (int start = rightMaxAlready[row] - 1; start >= minStart; start--) {
            if (rightMaxCache[row][start] >= 0) {
                continue;
            }
            var end = start + k - 1;
            var ans1 = dfs(row + 1, start) + range(row, start, end);
            rightMaxCache[row][start] = Math.max(rightMaxCache[row][start + 1], ans1);
            ans0 = Math.max(ans0, ans1);
        }
        rightMaxAlready[row] = minStart;
        assert ans0 == rightMaxCache[row][minStart];
        return ans0;
    }

    static int[][] leftMaxCache;
    static int[] leftMaxAlready;

    private static int leftMax(int row, int maxEnd) {
        var maxStart = maxEnd - k + 1;
        if (maxStart <= 0) {
            return 0;
        }
        if (leftMaxCache == null) {
            leftMaxCache = new int[n + 1][m + 1];
            leftMaxAlready = new int[n + 1];
            Arrays.fill(leftMaxAlready, 0);
            for (int i = 1; i <= n; i++) {
                Arrays.fill(leftMaxCache[i], -1);
                leftMaxCache[i][0] = 0;
            }
        }
        if (leftMaxCache[row][maxStart] >= 0) {
            return leftMaxCache[row][maxStart];
        }
        var ans0 = leftMaxCache[row][leftMaxAlready[row]];
//        leftMaxCache[row][k - 1] = 0;
        for (int start = leftMaxAlready[row] + 1; start <= maxStart; start++) {
            var end = start + k - 1;
            if (leftMaxCache[row][start] >= 0) {
                continue;
            }
            var ans1 = dfs(row + 1, start) + range(row, start, end);
            leftMaxCache[row][start] = Math.max(leftMaxCache[row][start - 1], ans1);
            ans0 = Math.max(ans0, ans1);
        }
        leftMaxAlready[row] = maxStart;
//        System.out.println("row = " + row + ", maxEnd = " + maxEnd);
        assert ans0 == leftMaxCache[row][maxStart];
//        return ans0;
        return leftMaxCache[row][maxStart];
    }

    private static int watch(int row, int start1, int start2) {
//        System.out.println("row = " + row + ", start1 = " + start1 + ", start2 = " + start2);
        if (start1 > start2) {
            return watch(row, start2, start1);
        }
        var end2 = start2 + k - 1;
        if (start1 <= 0) {
            return range(row, start2, end2);
        }
        var end1 = start1 + k - 1;
        if (end2 < start1 || end1 < start2) {
            return range(row, start1, end1) + range(row, start2, end2);
        }
        return range(row, start1, end1) + range(row, start2, end2)
                - range(row, start2, Math.min(end1, end2));
    }

    static int[][] rangeCache;

    private static int range(int row, int start, int end) {
        if (start <= 0 || start > end) {
            return 0;
        }
        if (rangeCache == null) {
            rangeCache = new int[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                rangeCache[i][0] = 0;
                for (int j = 1; j <= m; j++) {
                    rangeCache[i][j] = rangeCache[i][j - 1] + ani[i][j];
                }
            }
        }
        debug("range(%d,%d)=%d", start, end, rangeCache[row][end] - rangeCache[row][start - 1]);
        return rangeCache[row][end] - rangeCache[row][start - 1];
    }

    static final boolean DEBUG = false;

    private static void debug(String fmt, Object... args) {
        if (DEBUG) {
            System.out.println(String.format(fmt, args));
        }
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
