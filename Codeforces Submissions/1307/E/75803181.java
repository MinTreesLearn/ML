import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class E {
    public static void main(String[] args) {
        var scanner = new BufferedScanner();
        var writer = new PrintWriter(new BufferedOutputStream(System.out));

        var n = scanner.nextInt();
        var m = scanner.nextInt();
        var s = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            s[i] = scanner.nextInt();
        }
        var f = new int[m + 1];
        var h = new int[m + 1];
        for (int i = 1; i <= m; i++) {
            f[i] = scanner.nextInt();
            h[i] = scanner.nextInt();
        }
        var ans = solve(n, m, s, f, h);
        writer.println(ans[0] + " " + ans[1]);

        scanner.close();
        writer.flush();
        writer.close();
    }

    static final int MODULO = (int) (1e9 + 7);

    static class IntList extends ArrayList<Integer> {}

    private static int[] solve(int n, int m, int[] s, int[] f, int[] h) {
        var sleepL = new int[m + 1];
        var sleepR = new int[m + 1];
        var byFH = new HashMap<Integer, Integer>() {
            public Integer get(int f, int h) {
                return get(hash(f, h));
            }

            void put(int f, int h, int i) {
                put(hash(f, h), i);
            }

            private int hash(int f, int h) {
                return f * (n + 1) + h;
            }
        };
        for (int i = 1; i <= m; i++) {
            byFH.put(f[i], h[i], i);
        }
        {
            var countS = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                countS[s[i]]++;
                var cow = byFH.get(s[i], countS[s[i]]);
                if (cow != null) {
                    sleepL[cow] = i;
                }
            }
            Arrays.fill(countS, 0);
            for (int i = n; i >= 1; i--) {
                countS[s[i]]++;
                var cow = byFH.get(s[i], countS[s[i]]);
                if (cow != null) {
                    sleepR[cow] = i;
                }
            }
        }
        var bySweet = new HashMap<Integer, List<Integer>>();
        for (int i = 1; i <= m; i++) {
            bySweet.putIfAbsent(f[i], new ArrayList<>());
            bySweet.get(f[i]).add(i);
        }
        var sweets = bySweet.keySet().stream().mapToInt(i -> i).toArray();
        var maxCows = Integer.MIN_VALUE;
        var maxWays = Long.MIN_VALUE;
        // first==0表示左边不选；first一定要用在左边，这样避免计数重复
        for (int first = 0; first <= m; first++) {
            var leftStart = 1;
            var leftEnd = sleepL[first]; // increasing
            var rightStart = leftEnd + 1; // increasing
            var rightEnd = n;
            if (first != 0 && (sleepL[first] < leftStart || sleepL[first] > leftEnd)) {
                continue;
            }
            var cows = 0;
            var ways = 1L;
            var lefts = new int[n + 1];
            var rights = new int[n + 1];
            var boths = new int[n + 1];
            for (int i = 1; i <= m; i++) {
                var t = 0;
                if (sleepL[i] >= leftStart && sleepL[i] <= leftEnd) {
                    lefts[f[i]]++;
                    t++;
                }
                if (i == first) {
                    continue;
                }
                if (sleepR[i] >= rightStart && sleepR[i] <= rightEnd) {
                    rights[f[i]]++;
                    t++;
                }
                if (t == 2) {
                    boths[f[i]]++;
                    lefts[f[i]]--;
                    rights[f[i]]--;
                }
            }
            for (int sweet : sweets) {
//                var left = 0L;
//                var right = 0L;
//                var both = 0L;
//                for (var i : bySweetL[sweet]) {
//                    var t = 0;
//                    if (sleepL[i] >= leftStart && sleepL[i] <= leftEnd) {
//                        left++;
//                        t++;
//                    }
//                    if (i == first) { // first一定在左边
//                        continue;
//                    }
//                    if (sleepR[i] >= rightStart && sleepR[i] <= rightEnd) {
//                        right++;
//                        t++;
//                    }
//                    if (t == 2) {
//                        both++;
//                        left--;
//                        right--;
//                    }
//                }
                var left = lefts[sweet];
                var right = rights[sweet];
                var both = boths[sweet];
                if (sweet == f[first]) {
                    left = 1; // left被first占据了
                }
                if (left + right + both == 0) {
                    continue;
                }
                long thisWays;
                if (sweet == f[first]) {
                    thisWays = right + both;
                } else {
                    // 尝试任意放两个
                    thisWays = left * (right + both) + both * (right + both - 1);
                }
                if (thisWays > 0) {
                    cows += 2;
                    ways = (ways * thisWays) % MODULO;
                    continue;
                }
                cows++;
                // 放一个的方案
                thisWays = left + right + both * 2;
                ways = (ways * thisWays) % MODULO;
            }
            if (cows > maxCows) {
                maxCows = cows;
                maxWays = ways;
            } else if (cows == maxCows && cows > 0) {
                maxWays = (maxWays + ways) % MODULO;
            }
        }
        return new int[]{maxCows, (int) maxWays};
    }

    private static void check(boolean predicate, String fmt, Object... args) {
        if (!predicate) {
            throw new RuntimeException(String.format(fmt, args));
        }
    }

    /**
     * @param a  ascending ordered array
     * @param k  key to find
     * @param ks key function
     * @param gt true for gt/gte, false for lt/lte
     * @param e  true for equal, false for unequal
     * @return min i for gt/gte, max i for lt/lte
     */
    private static int binarySearch(int[] a, int k, int[] ks, boolean gt, boolean e) {
        var l = 0;
        var r = a.length - 1;
        var ans = gt ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        while (l <= r) {
            var m = (l + r) / 2;
            var km = ks[a[m]];
            if (gt) { // find min i that a[i]>=/>k
                if (e && km >= k || km > k) {
                    ans = Math.min(ans, m);
                    r = m - 1;
                } else { // a[m]</<=k
                    l = m + 1;
                }
            } else { // find max i that a[i]<=/<k
                if (e && km <= k || km < k) {
                    ans = Math.max(ans, m);
                    l = m + 1;
                } else { // a[m]>/>=k
                    r = m - 1;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? Integer.MIN_VALUE : ans;
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
