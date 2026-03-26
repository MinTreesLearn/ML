import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class C1310D {
    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var k = scanner.nextInt();
        var f = new int[n][n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j][1] = scanner.nextInt();
            }
            f[i][i][1] = Integer.MAX_VALUE;
        }
        var mid = new int[n][n][k + 1][2];
        for (int k0 = 2; k0 <= k; k0++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    f[i][j][k0] = Integer.MAX_VALUE;
                    if (i == j && k0 % 2 == 1) {
                        continue;
                    }
                    for (int m = 0; m < n; m++) {
                        for (int k1 = 1; k1 < k0; k1++) {
                            int part1 = f[i][m][k1];
                            if (part1 == Integer.MAX_VALUE) {
                                continue;
                            }
                            var k2 = k0 - k1;
                            int part2 = f[m][j][k2];
                            if (part2 == Integer.MAX_VALUE) {
                                continue;
                            }
                            if (part1 + part2 < f[i][j][k0] && noOddCycle2(i, j, m, k1, k2, mid)) {
                                f[i][j][k0] = part1 + part2;
                                mid[i][j][k0] = new int[]{m, k1};
                            }
//                            f[i][j][k0] = Math.min(f[i][j][k0], part1 + part2);
                        }
                    }
                }
            }
        }
        writer.println(f[0][0][k]);
//        printPath(0, 0, k, mid);
//        System.out.println(1);

        scanner.close();
        writer.flush();
        writer.close();
    }

    private static boolean noOddCycle(int i, int j, int m, int k1, int k2, int[][][][] mid) {
        var path = new ArrayList<Integer>();
        collectPath(i, m, k1, mid, path);
        collectPath(m, j, k2, mid, path);
        path.add(j);
        var latest = new HashMap<Integer, Integer>();
        for (int index = 0; index < path.size(); index++) {
            var each = path.get(index);
            var prev = latest.get(each);
            if (prev == null) {
                latest.put(each, index);
            } else {
                if (((index - prev) & 1) != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean noOddCycle2(int i, int j, int m, int k1, int k2, int[][][][] mid) {
        var path1 = new ArrayList<Integer>();
        collectPath(i, m, k1, mid, path1);
        var latest = new HashMap<Integer, Integer>();
        for (int index = 0; index < path1.size(); index++) {
            var each = path1.get(index);
            latest.put(each, index);
        }
        var path2 = new ArrayList<Integer>();
        collectPath(m, j, k2, mid, path2);
        path2.add(j);
        for (int index = 0; index < path2.size(); index++) {
            var each = path2.get(index);
            var prev = latest.get(each);
            if (prev != null && ((index + k1 - prev) & 1) != 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * 如果k1是偶数，那么path1和path2中相同点所处的index的奇偶性要相同相同；否则要不同。
     * <p>
     * 可以用80位二进制数来表示路径上的出现点的下标奇偶性。
     */
    private static boolean noOddCycle3(int i, int j, int m, int k1, int k2, int[][][][] mid) {
        var path1 = new ArrayList<Integer>();
        collectPath(i, m, k1, mid, path1);
        var latest = new HashMap<Integer, Integer>();
        for (int index = 0; index < path1.size(); index++) {
            var each = path1.get(index);
            latest.put(each, index);
        }
        var path2 = new ArrayList<Integer>();
        collectPath(m, j, k2, mid, path2);
        path2.add(j);
        for (int index = 0; index < path2.size(); index++) {
            var each = path2.get(index);
            var prev = latest.get(each);
            if (prev != null && ((index + k1 - prev) & 1) != 0) {
                return false;
            }
        }
        return true;
    }

    static Map<Integer, List<Integer>> paths = new HashMap<>();

    private static void collectPath(int i, int j, int k, int[][][][] mid, List<Integer> path) {
        if (k == 1) {
            path.add(i);
            return;
        }
        var hash = (i * 81 + j) * 81 + k;
        var cache = paths.get(hash);
        if (cache != null) {
            path.addAll(cache);
            return;
        }
        var m = mid[i][j][k][0];
        var k1 = mid[i][j][k][1];
        var k2 = k - k1;
        var part = new ArrayList<Integer>();
        collectPath(i, m, k1, mid, part);
        collectPath(m, j, k2, mid, part);
        paths.put(hash, part);
        path.addAll(part);
    }

    private static void printPath(int i, int j, int k, int[][][][] mid) {
//        System.out.println(i + " " + j + " " + k);
        if (k == 1) {
            System.out.print((i + 1) + "->");
            return;
        }
        var m = mid[i][j][k][0];
        var k1 = mid[i][j][k][1];
        var k2 = k - k1;
        printPath(i, m, k1, mid);
        printPath(m, j, k2, mid);
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
