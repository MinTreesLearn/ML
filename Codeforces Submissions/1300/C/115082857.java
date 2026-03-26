

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
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 *
 * @author is2ac
 */
public class C_CF {

    public static void main(String[] args) {
        FastScanner57 fs = new FastScanner57();
        PrintWriter pw = new PrintWriter(System.out);
        //int t = fs.ni();
        int t = 1;
        for (int tc = 0; tc < t; tc++) {
            int n = fs.ni();
            int[] a = fs.intArray(n);
            int[] b = new int[32];
            int ind = 0, m = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 32; j++) {
                    if (((1<<j)&a[i])>0) {
                        b[j]++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                int x = a[i];
                for (int j = 0; j < 32; j++) {
                    if (((1<<j)&a[i])>0 && b[j]!=1) x -= (1<<j);
                }
                if (x>m) {
                    m = x;
                    ind = i;
                }
            }
            pw.print(a[ind] + " ");
            for (int i = 0; i < n; i++) {
                if (i!=ind) pw.print(a[i] + " ");
            }
        }
        pw.close();

    }

    public static int a(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i][0] == -1) {
                return i;
            }
        }
        return -1;
    }

    public static int b(int[][] arr, int p, UnionFind16 uf) {
        for (int i = 0; i < arr.length; i++) {
            if (uf.find(p) == uf.find(i) && arr[i][1] == -1) {
                return i;
            }
        }
        return -1;
    }

    public static int gcd(int n1, int n2) {
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
