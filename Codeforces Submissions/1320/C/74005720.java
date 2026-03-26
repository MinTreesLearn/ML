import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class C1320C {

    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var m = scanner.nextInt();
        var p = scanner.nextInt();
        var a = new int[n];
        var ca = new int[n];
        var orderA = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            ca[i] = scanner.nextInt();
            orderA[i] = i;
        }
        Arrays.sort(orderA, Comparator.comparingInt(i -> a[i]));
        var b = new int[m];
        var cb = new int[m];
        var orderB = new Integer[m];
        for (int i = 0; i < m; i++) {
            b[i] = scanner.nextInt();
            cb[i] = scanner.nextInt();
            orderB[i] = i;
        }
        Arrays.sort(orderB, Comparator.comparingInt(i -> b[i]));
        var x = new int[p];
        var y = new int[p];
        var z = new int[p];
        var orderX = new Integer[p];
        for (int i = 0; i < p; i++) {
            x[i] = scanner.nextInt();
            y[i] = scanner.nextInt();
            z[i] = scanner.nextInt();
            orderX[i] = i;
        }
        Arrays.sort(orderX, Comparator.comparingInt(i -> x[i]));

        var acc = new long[4 * m]; // acc[i,j]表示范围i到j的累计
        var max = new long[4 * m]; // max[i,j]表示范围i到j区间内acc的最大值
        Arrays.fill(max, UNTOUCHED);
        for (int ib : orderB) {
            var j = orderB[ib];
            update(acc, max, 0, 0, m - 1, ib, ib, -cb[j]);
        }
        var ix = 0;
        var ans = UNTOUCHED;
        for (var i : orderA) {
            var k = 0;
            while (ix < p && x[(k = orderX[ix])] < a[i]) {
                var startJ = searchFirstGreater(b, orderB, y[k]);
                update(acc, max, 0, 0, m - 1, startJ, m - 1, z[k]);
                ix++;
            }
            ans = Math.max(ans, max[0] - ca[i]);
        }
        writer.println(ans);

        scanner.close();
        writer.flush();
        writer.close();
    }

    static final long UNTOUCHED = Long.MIN_VALUE;

    private static int searchFirstGreater(int[] a, Integer[] order, int key) {
        var low = 0;
        var high = a.length - 1;
        var ans = Integer.MAX_VALUE;
        while (low <= high) {
            var mid = (low + high) >>> 1;
            if (a[order[mid]] <= key) {
                low = mid + 1;
            } else {
                high = mid - 1;
                ans = Math.min(ans, mid);
            }
        }
        return ans;
    }

    private static void update(long[] acc, long[] max, int index, int low, int high, int targetLow, int targetHigh,
            int inc) {
        if (targetHigh < low || high < targetLow || targetLow > targetHigh) {
            return;
        }
        if (targetLow <= low && high <= targetHigh) {
            acc[index] += inc;
            if (max[index] == UNTOUCHED) {
                max[index] = 0;
            }
            max[index] += inc;
            return;
        }
        if (low < high) {
            var leftIndex = (index << 1) + 1;
            var rightIndex = leftIndex + 1;
            var mid = (low + high) >>> 1;
            update(acc, max, leftIndex, low, mid, targetLow, targetHigh, inc);
            update(acc, max, rightIndex, mid + 1, high, targetLow, targetHigh, inc);
            max[index] = Math.max(max[index], Math.max(max[leftIndex], max[rightIndex]) + acc[index]);
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
