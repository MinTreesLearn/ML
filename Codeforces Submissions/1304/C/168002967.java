
// 20:18 ; 2'50" ; %%I02V2L4L //
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class E {

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

    static int a[][];
    static int n;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int tt = sc.nextInt();
        o: while (tt-- > 0) {
            n = sc.nextInt();
            int m = sc.nextInt();
            a = new int[n][3];
            for (int i = 0; i < n; i++) {
                a[i][0] = sc.nextInt();
                a[i][1] = sc.nextInt();
                a[i][2] = sc.nextInt();
            }
            int prev = 0;
            int mx = m;
            int mi = m;
            for (int i = 0; i < n; i++) {
                mx += a[i][0] - prev;
                mi -= a[i][0] - prev;
                if (mi > a[i][2] || mx < a[i][1]) {
                    System.out.println("NO");
                    continue o;
                }
                mx = Math.min(mx, a[i][2]);
                mi = Math.max(mi, a[i][1]);
                prev = a[i][0];
            }
            System.out.println("YES");
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

    // a -> z == 97 -> 122

    // String.format("%.9f", ans) ,--> to get upto 9 decimal places , (ans is
    // double)
}
