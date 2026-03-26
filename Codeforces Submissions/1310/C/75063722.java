import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;


public class C1310C_2 {
    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var m = scanner.nextInt();
        var k = scanner.nextLong();
        var s = scanner.next().toCharArray();
//        var n = 1000;
//        var m = 800;
//        var k = (long) 1e18;
//        var sb = new StringBuilder();
//        for (int i = 0; i < n; i++) {
//            sb.append((char) (Math.random() * 3 + 'a'));
//        }
//        var s = sb.toString().toCharArray();
        var t = System.nanoTime();
        writer.println(solve(n, m, k, s));
//        System.out.println((System.nanoTime() - t) / 1e9);

        scanner.close();
        writer.flush();
        writer.close();
    }

    static final long K_MAX = (long) 1e18;

    private static String solve(int n, int m, long k, char[] s) {
        var lcp = lcp(n, s);
        var subs = subs(n, s, lcp);
        var low = 0;
        var high = subs.size() - 1;
        var found = -1;
        while (low <= high && found < 0) {
            var mid = (low + high) >>> 1;
            var gte = countGte(n, s, m, subs.get(mid), lcp);
            var countFrom = gte[1] + 1;
            var countTo = gte[1] + gte[0];
//            System.out.println(subs.get(mid) + " " + Arrays.toString(gte));
            if (countFrom <= k && k <= countTo) {
                found = mid;
            } else if (countTo < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }
        return new String(s, subs.get(found).from, subs.get(found).len);
    }

    static int compare(int from1, int len1, int from2, int len2, int[][] lcp, char[] s) {
        var common = lcp[from1][from2];
        if (common >= len1 || common >= len2) {
            return Integer.compare(len1, len2); // 谁长谁大
        } else {
            return Character.compare(s[from1 + common], s[from2 + common]);
        }
    }

    private static long[] countGte(int n, char[] s, int m, Sub minS, int[][] lcp) {
        int minSLen = minS.len;
        var dp0 = new long[m + 1][n + 1];
        var dp1 = new long[m + 1][n + 1];
        dp0[0][0] = 0; // 长度为0划分为0个部分，其中至少一个等于minS的划分数为0。
        dp1[0][0] = 1; // 长度为0划分为0个部分，其中所有都大于minS的划分数为1。
        for (int parts = 1; parts <= m; parts++) {
            var change = new HashMap<Integer, List<Integer>>();
            var dp0Acc = new long[]{0, 0}; // [0]:small sum; [1]:large count
            var dp1Acc = new long[]{0, 0}; // [0]:small sum; [1]:large count
            for (int len = parts; len <= n; len++) {
                int start = len - 1;
                // 前面开始的子串，到这一步可能有几个变化：一直是minS前缀（长度可能是0）的，变大于、等于、小于minS了。
                // 先把当前这个加进去
                if (compare(start, len - start, minS.from, minS.len, lcp, s) > 0) {
                    // 第1位就大于minS的，无论怎么延长都会一直大于minS，所以后面的len+x(x>=0)都会用到
                    add(dp0Acc, dp0[parts - 1][start]);
                    add(dp1Acc, dp1[parts - 1][start]);
                } else {
                    var common = min(lcp[start][minS.from], minS.len);
                    var changePos = common == minSLen ? start + common - 1
                                                      : start + common;
                    change.compute(changePos, (k, v) -> {
                        if (v == null) {
                            v = new ArrayList<>();
                        }
                        v.add(start);
                        return v;
                    });
                }
                var equalStarts = new ArrayList<Integer>();
                for (Integer startToChange : change.getOrDefault(start, List.of())) {
                    int compare = compare(startToChange, len - startToChange, minS.from, minS.len, lcp, s);
                    if (compare == 0) {
                        add(dp0Acc, dp0[parts - 1][startToChange], dp1[parts - 1][startToChange]);
                        equalStarts.add(startToChange);
                    } else if (compare > 0) {
                        add(dp0Acc, dp0[parts - 1][startToChange]);
                        add(dp1Acc, dp1[parts - 1][startToChange]);
                    }
                }
                dp0[parts][len] = translate(dp0Acc);
                dp1[parts][len] = translate(dp1Acc);
                for (Integer equalStart : equalStarts) {
                    // 相等只在当前len有用
                    minus(dp0Acc, dp0[parts - 1][equalStart], dp1[parts - 1][equalStart]);
                    // len+1就可能变大或者变小
                    change.compute(start + 1, (k, v) -> {
                        if (v == null) {
                            v = new ArrayList<>();
                        }
                        v.add(equalStart);
                        return v;
                    });
                }
            }
        }
        return new long[]{dp0[m][n], dp1[m][n]};
    }

    private static int min(int... a) {
        var ans = Integer.MAX_VALUE;
        for (int x : a) {
            ans = Math.min(ans, x);
        }
        return ans;
    }

    private static long translate(long[] acc) {
        return acc[0] > K_MAX || acc[1] > 0 ? K_MAX + 1 : acc[0];
    }

    private static void minus(long[] acc, long... a) {
        for (long x : a) {
            if (x > K_MAX) {
                acc[1]--;
            } else {
                acc[0] -= x;
            }
        }
    }

    static void add(long[] sum, long... a) {
        for (long x : a) {
            if (x > K_MAX) {
                sum[1]++;
            } else {
                sum[0] += x;
            }
        }
    }

    private static List<Sub> subs(int n, char[] s, int[][] lcp) {
        var t = System.nanoTime();
        var tmp = new ArrayList<Sub>();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                tmp.add(new Sub(i, j, s, lcp));
            }
        }
//        System.out.println("sub collect: " + (System.nanoTime() - t) / 1e9);
        t = System.nanoTime();
        var ans = tmp.stream().distinct().sorted(Comparator.reverseOrder()).collect(Collectors.toList());
//        System.out.println("sub distinct and sort: " + (System.nanoTime() - t) / 1e9);
        return ans;
    }

    static class Sub implements Comparable<Sub> {
        final int from;
        final int to;
        final int len;
        final char[] s;
        final int[][] lcp;
        int hash;

        Sub(int from, int to, char[] s, int[][] lcp) {
            this.from = from;
            this.to = to;
            this.s = s;
            this.lcp = lcp;
            len = to - from + 1;
        }

        @Override
        public int compareTo(Sub o) {
            return compare(from, len, o.from, o.len, lcp, s);
        }

        @Override
        public String toString() {
            return "Sub{" +
                    "from=" + from +
                    ", to=" + to +
                    ", len=" + len +
                    ", s=" + Arrays.toString(s) +
                    ", sub=" + new String(s, from, len) +
                    '}';
        }

        @Override
        public int hashCode() {
            int h = hash;
            if (h == 0 && len > 0) {
                for (int i = from; i <= to; i++) {
                    h = 31 * h + (s[i] & 0xff);
                }
                hash = h;
            }
            return h;
        }


        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            } else if (this == obj) {
                return true;
            } else if (getClass() != obj.getClass()) {
                return false;
            }
            Sub o = (Sub) obj;
            if (len == o.len) {
                for (int i = 0; i < len; i++) {
                    if (s[from + i] != s[o.from + i]) {
                        return false;
                    }
                }
                return true;
            } else {
                return false;
            }
        }
    }

    private static int[][] lcp(int n, char[] s) {
        var ans = new int[n + 1][n + 1];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    ans[i][j] = ans[i + 1][j + 1] + 1;
                } else {
                    ans[i][j] = 0;
                }
            }
        }
        return ans;
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
