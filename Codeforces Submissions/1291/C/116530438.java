

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;

/**
 *
 * @author is2ac
 */
public class C_CF {

    public static void main(String[] args) {
        FastScanner57 fs = new FastScanner57();
        PrintWriter pw = new PrintWriter(System.out);
        int t = fs.ni();
        //int t = 1;
        for (int tc = 0; tc < t; tc++) {
            int n = fs.ni();
            int m = fs.ni()-1, k = fs.ni();
            int[] a = fs.intArray(n);
            k = Math.min(m, k);
            int l = 0, r = n-1-k;
            int res = (int)(-1e9);
            m -= k;
            while (r<n) {
                int cur = (int)(1e9);
                int ll = l, rr = r-m;
                while (rr<=r) {
                    cur = Math.min(cur,Math.max(a[ll],a[rr]));
                    rr++;
                    ll++;
                }
                res = Math.max(res,cur);
                r++;
                l++;
            }
            pw.println(res);
        }
        pw.close();

    }

    public static String print(int[] b) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < b.length; i++) {
            sb.append(b[i]);
        }
        return sb.toString();
    }

    public static int recur(int ind, int p, int[] a, Integer[][] dp) {
        if (ind == a.length) {
            return 0;
        }
        int n = (int) (1e9);
        if (dp[ind][p] != null) {
            return dp[ind][p];
        }
        for (int i = 0; i < 3; i++) {
            int c = 1;
            if (i == a[ind]) {
                c--;
            }
            if (i == p) {
                continue;
            }
            n = Math.min(n, recur(ind + 1, i, a, dp) + c);
        }
        return dp[ind][p] = n;
    }

    public static void sort(long[] a) {
        List<Long> list = new ArrayList();
        for (int i = 0; i < a.length; i++) {
            list.add(a[i]);
        }
        Collections.sort(list);
        for (int i = 0; i < a.length; i++) {
            a[i] = list.get(i);
        }
    }

    public static long gcd(long n1, long n2) {
        if (n2 == 0) {
            return n1;
        }
        return gcd(n2, n1 % n2);
    }

}

class UnionFind16 {

    int[] id;

    public UnionFind16(int size) {
        id = new int[size];
        for (int i = 0; i < size; i++) {
            id[i] = i;
        }
    }

    public int find(int p) {
        int root = p;
        while (root != id[root]) {
            root = id[root];
        }
        while (p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }

    public void union(int p, int q) {
        int a = find(p), b = find(q);
        if (a == b) {
            return;
        }
        id[b] = a;
    }
}

class FastScanner57 {

    BufferedReader br;
    StringTokenizer st;

    public FastScanner57() {
        br = new BufferedReader(new InputStreamReader(System.in), 32768);
        st = null;
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

    int ni() {
        return Integer.parseInt(next());
    }

    int[] intArray(int N) {
        int[] ret = new int[N];
        for (int i = 0; i < N; i++) {
            ret[i] = ni();
        }
        return ret;
    }

    long nl() {
        return Long.parseLong(next());
    }

    long[] longArray(int N) {
        long[] ret = new long[N];
        for (int i = 0; i < N; i++) {
            ret[i] = nl();
        }
        return ret;
    }

    double nd() {
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
}
