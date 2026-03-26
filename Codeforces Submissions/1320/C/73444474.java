import java.io.*;
import java.util.*;

/*
Прокрастинирую
*/

public class Main {

    static FastReader in;
    static PrintWriter out;
    static Random rand = new Random();
    static final int INF = (int) (1e9 + 10);
    static final int MOD = (int) (1e9 + 7);
    static final int N = (int) (1e6 + 6);
    static final int LOGN = 62;
    static int n, m, p;
    static int[][] a, b;

    static class Monster {
        int x, y, z;

        Monster(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    static class SegTree {
        int size;
        long[] t_max, t_add;

        SegTree(long[] arr) {
            size = arr.length;
            t_max = new long[size * 4];
            t_add = new long[size * 4];
            build(arr);
        }

        void push(int v) {
            if (t_add[v] != 0) {
                t_max[v * 2 + 1] += t_add[v];
                t_add[v * 2 + 1] += t_add[v];
                t_max[v * 2 + 2] += t_add[v];
                t_add[v * 2 + 2] += t_add[v];
                t_add[v] = 0;
            }
        }
        void pull(int v) {
            t_max[v] = Math.max(t_max[v * 2 + 1], t_max[v * 2 + 2]);
        }

        void build(int v, int tl, int tr, long[] arr) {
            if (tl == tr) {
                t_max[v] = arr[tl];
                return;
            }
            int tm = (tl + tr) / 2;
            build(v * 2 + 1, tl, tm, arr);
            build(v * 2 + 2, tm + 1, tr, arr);
            pull(v);
        }
        void build(long[] arr) {
            build(0, 0, size - 1, arr);
        }

        long maxOn(int v, int tl, int tr, int l, int r) {
            if (l > tr || r < tl) return -INF;
            if (l <= tl && tr <= r) {
                return t_max[v];
            }
            push(v);
            int tm = (tl + tr) / 2;
            return Math.max(maxOn(v * 2 + 1, tl, tm, l, r),
                    maxOn(v * 2 + 2, tm + 1, tr, l, r));
        }
        long maxOn(int l, int r) {
            return maxOn(0, 0, size - 1, l, r);
        }

        void addOn(int v, int tl, int tr, int l, int r, int val) {
            if (l > tr || r < tl)return;
            if (l <= tl && tr <= r) {
                t_max[v] += val;
                t_add[v] += val;
                return;
            }
            push(v);
            int tm = (tl + tr) / 2;
            addOn(v * 2 + 1, tl, tm, l, r, val);
            addOn(v * 2 + 2, tm + 1, tr, l, r, val);
            pull(v);
        }
        void addOn(int l, int r, int val) {
            addOn(0, 0, size - 1, l, r, val);
        }
    }

    static int upperBound(int[][] arr, int x) {
        int lb = 0, rb = arr.length;
        while (lb < rb) {
            int mb = (lb + rb) / 2;
            if (arr[mb][0] <= x) {
                lb = mb + 1;
            } else {
                rb = mb;
            }
        }
        return lb;
    }

    static void solve() {
        n = in.nextInt();
        m = in.nextInt();
        p = in.nextInt();

        a = new int[n][2];
        for (int i = 0; i < n; i++) {
            a[i][0] = in.nextInt();
            a[i][1] = in.nextInt();
        }
        Arrays.sort(a, (a1, a2) -> Integer.compare(a1[0], a2[0]));

        b = new int[m][2];
        for (int i = 0; i < m; i++) {
            b[i][0] = in.nextInt();
            b[i][1] = in.nextInt();
        }
        Arrays.sort(b, (b1, b2) -> Integer.compare(b1[0], b2[0]));
        long[] arr = new long[m];
        for (int i = 0; i < m; i++) arr[i] = -b[i][1];
        SegTree st = new SegTree(arr);

        Monster[] monsters = new Monster[p];
        for (int i = 0; i < p; i++) {
            monsters[i] = new Monster(in.nextInt(), in.nextInt(), in.nextInt());
        }
        Arrays.sort(monsters, (m1, m2) -> Integer.compare(m1.x, m2.x));

        long ans = 10L * -INF;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < p && monsters[j].x < a[i][0]) {
                st.addOn(upperBound(b, monsters[j].y), m - 1, monsters[j].z);
                j++;
            }
            ans = Math.max(ans, st.maxOn(0, m - 1) - a[i][1]);
        }

        out.println(ans);
    }

    public static void main(String[] args) throws FileNotFoundException {
        in = new FastReader(System.in);
//        in = new FastReader(new FileInputStream("connect.in"));
        out = new PrintWriter(System.out);
//        out = new PrintWriter(new FileOutputStream("connect.out"));


        int q = 1;
//        q = in.nextInt();

        while (q-- > 0) {
            solve();
        }

        out.close();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        FastReader(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        Integer nextInt() {
            return Integer.parseInt(next());
        }

        Long nextLong() {
            return Long.parseLong(next());
        }

        Double nextDouble() {
            return Double.parseDouble(next());
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(nextLine());
            }
            return st.nextToken();
        }

        String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }
    }
}