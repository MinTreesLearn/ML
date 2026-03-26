import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        long max = 0;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        long[] ans = new long[n];
        for (int i = 0; i < n; i++) {
            if (tm.containsKey(b[i] - i)) ans[i] += ans[tm.get(b[i] - i)];
            ans[i] += b[i];
            tm.put(b[i] - i, i);
            max = Math.max(max, ans[i]);
        }
        in.out.println(max);
        in.out.close();
    }
}


class segment_tree {
    int jopa;
    int[] a;
    int[] max;

    public segment_tree(int jopa, int[] a) {
        this.jopa = jopa;
        this.a = a;
        max = new int[jopa * 4];
        Arrays.fill(max, -1);
    }

    void set(int v, int tl, int tr, int ind, int val) {
        if (tr < ind || ind < tl) return;
        if (tl == tr && ind == tl) {
            a[ind] = val;
            max[v] = val;
            return;
        }
        int tm = (tl + tr) >> 1;
        set(v * 2, tl, tm, ind, val);
        set(v * 2 + 1, tm + 1, tr, ind, val);
        max[v] = Math.max(max[v * 2], max[v * 2 + 1]);
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (tr < l || r < tl) return -1;
        if (l <= tl && tr <= r) {
            return max[v];
        }
        int tm = (tl + tr) >> 1;
        return Math.max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
    }
}


class FastScanner {

    StringTokenizer st = new StringTokenizer("");
    BufferedReader br;
    PrintWriter out;


    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }


    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
