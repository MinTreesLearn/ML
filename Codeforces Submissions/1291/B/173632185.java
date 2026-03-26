
// 17-05 //
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class C {
    static class SGTree {
        int seg[];

        SGTree(int n) {
            seg = new int[n];
        }

        void build(int idx, int low, int high, int a[]) {
            if (low == high) {
                seg[idx] = a[low];
                return;
            }
            int mid = (low + high) / 2;
            build(2 * idx + 1, low, mid, a);
            build(2 * idx + 2, mid + 1, high, a);
            seg[idx] = Math.min(seg[2 * idx + 1], seg[2 * idx + 2]);
        }

        int query(int idx, int low, int high, int l, int r) { // min value query
            // no overlap
            if (l > high || r < low) {
                return inf;
            }
            // complete overlap
            if (l <= low && r >= high) {
                return seg[idx];
            }
            // partial overlap
            int mid = (low + high) / 2;
            int left = query(2 * idx + 1, low, mid, l, r);
            int right = query(2 * idx + 2, mid + 1, high, l, r);
            return Math.min(left, right);
        }
    }

    static int par[], rank[];

    static void union(int a, int b) {
        if (rank[a] > rank[b]) {
            rank[a]++;
            par[b] = par[a];
        } else {
            rank[b]++;
            par[a] = par[b];
        }
    }

    static int get(int a) {
        if (a == par[a])
            return a;
        return par[a] = get(par[a]);
    }

    static String temp;
    static char s[], t[];
    static int n, m;
    static int dp[][][];
    static List<Integer> g[];
    static boolean is[], vis[];

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int tt = sc.nextInt();
        o: while (tt-- > 0) {
            n = sc.nextInt();
            int a[] = sc.readArray(n);
            int idx = n - 1;
            for (int i = 0; i < n; i++) {
                if (a[i] < i) {
                    idx = i - 1;
                    break;
                }
            }
            if (idx == -1 || idx == n - 1) {
                System.out.println("YES");
                continue o;
            }
            for (int i = idx + 1; i < n; i++) {
                if (a[i] < n - i - 1) {
                    System.out.println("NO");
                    continue o;
                }
            }
            if (a[idx] <= a[idx + 1] && a[idx + 1] == n - idx - 2) {
                System.out.println("NO");
                continue o;
            }
            System.out.println("YES");
        }
    }

    static class pp implements Comparable<pp> {
        int a;
        int b;

        pp(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public int compareTo(pp o) {
            return this.a - o.a;
        }
    }

    static class Scanner {
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

    static void sort(int[] a) {
        int n = a.length;
        Random r = new Random();
        for (int i = 0; i < a.length; i++) {
            int oi = r.nextInt(n), temp = a[i];
            a[i] = a[oi];
            a[oi] = temp;
        }
        Arrays.sort(a);
    }

    static final int M = 1_000_000_007;
    static final int inf = Integer.MAX_VALUE;
    static final int ninf = inf + 1;
}
