import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class C1316D {
    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var target = new int[n + 1][n + 1];
        var blocks = new ArrayList<Integer>();
        var starts = new HashMap<Integer, List<Integer>>();
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                var h = hash(n, x, y);
                var x1 = scanner.nextInt();
                var y1 = scanner.nextInt();
                int h1 = hash(n, x1, y1);
                target[x][y] = h1;
                if (x == x1 && y == y1) {
                    blocks.add(h1);
                } else if (x1 >= 1) {
                    starts.compute(h1, (k, v) -> {
                        if (v == null) {
                            v = new ArrayList<>();
                        }
                        v.add(h);
                        return v;
                    });
                }
            }
        }
        var ans = new char[n + 1][n + 1];
        var valid = true;
        // 最起码，所有starts的终点的终点都是自己
        for (Integer t : starts.keySet()) {
            if (t < 0) {
                valid = false;
                break;
            }
            var xy = dehash(t, n);
            if (target[xy[0]][xy[1]] != t) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            writer.println("INVALID");
        } else {
            // 首先，所有的blocks要能够走到到自己的所有出发点。
            for (Integer block : blocks) {
                bfs(block, ans, n, target);
                if (!allStartsReach(block, starts, ans, n)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                writer.println("INVALID");
            } else {
                // 其次所有的(-1,-1)不能是孤立的。
                if (!fillInfinite(ans, n)) {
                    writer.println("INVALID");
                } else {
                    writer.println("VALID");
                    for (int x = 1; x <= n; x++) {
                        writer.println(Arrays.copyOfRange(ans[x], 1, n + 1));
                    }
                }
            }
        }

        scanner.close();
        writer.flush();
        writer.close();
    }

    private static boolean fillInfinite(char[][] ans, int n) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (ans[x][y] == 0) {
                    var q = new LinkedList<int[]>();
                    q.add(new int[]{x, y});
                    {
                        for (int i = 0; i < 4; i++) {
                            var x1 = x + dx[i];
                            var y1 = y + dy[i];
                            if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= n && ans[x1][y1] == 0) {
                                q.add(new int[]{x1, y1});
                                ans[x][y] = dn[i];
                                ans[x1][y1] = dn[3 - i];
                                break;
                            }
                        }
                    }
                    if (q.size() < 2) {
                        return false;
                    }
                    while (!q.isEmpty()) {
                        var xy = q.poll();
                        for (int i = 0; i < 4; i++) {
                            var x1 = xy[0] + dx[i];
                            var y1 = xy[1] + dy[i];
                            if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= n && ans[x1][y1] == 0) {
                                ans[x1][y1] = dn[3 - i];
                                q.add(new int[]{x1, y1});
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    private static boolean allStartsReach(Integer block, HashMap<Integer, List<Integer>> starts, char[][] ans, int n) {
        List<Integer> ss = starts.get(block);
        if (ss == null) {
            return true;
        }
        for (Integer start : ss) {
            var xy = dehash(start, n);
            if (ans[xy[0]][xy[1]] == 0) {
                return false;
            }
        }
        return true;
    }

    static int[] dx = new int[]{1, 0, 0, -1};
    static int[] dy = new int[]{0, 1, -1, 0};
    static char[] dn = new char[]{'D', 'R', 'L', 'U'};

    private static void bfs(int block, char[][] ans, int n, int[][] target) {
        var q = new LinkedList<int[]>();
        {
            var xy = dehash(block, n);
            ans[xy[0]][xy[1]] = 'X';
            q.add(xy);
        }
        while (!q.isEmpty()) {
            var xy = q.poll();
            for (int i = 0; i < 4; i++) {
                var x1 = xy[0] + dx[i];
                var y1 = xy[1] + dy[i];
                if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= n && target[x1][y1] == block && ans[x1][y1] == 0) {
                    ans[x1][y1] = dn[3 - i];
                    q.add(new int[]{x1, y1});
                }
            }
        }
    }

    private static int[] dehash(int block, int n) {
        return new int[]{block / (n + 1), block % (n + 1)};
    }

    private static int hash(int n, int x, int y) {
        return x * (n + 1) + y;
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
