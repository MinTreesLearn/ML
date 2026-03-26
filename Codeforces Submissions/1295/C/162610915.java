
//   * * * 2100 * * *   //
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class A {

    static class pair implements Comparable<pair> {
        int a;
        int b;

        pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public int compareTo(pair o) {
            return this.a - o.a;
        }
    }

    static int n, m;
    static String str, ttr;
    static char s[], t[];
    static int dp[];

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int tt = sc.nextInt();
        while (tt-- > 0) {
            str = sc.nextLine();
            ttr = sc.nextLine();
            s = str.toCharArray();
            t = ttr.toCharArray();
            n = s.length;
            m = t.length;
            HashSet<Character> set = new HashSet<>();
            for (char x : s) {
                set.add(x);
            }
            boolean can = true;
            for (char x : t) {
                if (!set.contains(x)) {
                    can = false;
                    break;
                }
            }
            if (!can) {
                System.out.println(-1);
                continue;
            }
            HashMap<Character, TreeSet<Integer>> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                map.putIfAbsent(s[i], new TreeSet<Integer>());
                map.get(s[i]).add(i);
            }
            int j = -1;
            int cnt = 1;
            for (int i = 0; i < m; i++) {
                Integer temp = map.get(t[i]).ceiling(j + 1); // returns the value of element greater than or equal to
                                                             // given
                // value or if not exists return null
                if (temp == null) {
                    cnt++;
                    temp = map.get(t[i]).first();
                    j = temp;
                } else {
                    j = temp;
                }
            }
            System.out.println(cnt);
        }
    }

    static void sort(int[] a) {
        // ruffle
        int n = a.length;
        Random r = new Random();
        for (int i = 0; i < a.length; i++) {
            int oi = r.nextInt(n), temp = a[i];
            a[i] = a[oi];
            a[oi] = temp;
        }

        // then sort
        Arrays.sort(a);
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String str = "";

        String nextLine() {
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    static long gcd(long n, long l) {
        if (l == 0)
            return n;
        return gcd(l, n % l);
    }

    static void sieveOfEratosthenes(int n, ArrayList<Integer> al) {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true)
                al.get(i);
        }
    }

    static final int mod = 1_000_000_000 + 7;
    static final int max_val = 2147483647;
    static final int min_val = max_val + 1;

    static long fastPow(long base, long exp) {
        if (exp == 0)
            return 1;
        long half = fastPow(base, exp / 2);
        if (exp % 2 == 0)
            return mul(half, half);
        return mul(half, mul(half, base));
    }

    static long mul(long a, long b) {
        return a * b % mod;
    }

    static int nCr(int n, int r) {
        return fact(n) / (fact(r) *
                fact(n - r));
    }

    static int fact(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }

    // a -> z == 97 -> 122

    // String.format("%.9f", ans) ,--> to get upto 9 decimal places , (ans is
    // double)
}
