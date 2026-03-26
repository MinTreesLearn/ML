/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 *
 * @author is2ac
 */
public class D_CF {

    public static void main(String[] args) {
        Long X = (long)(1e9+1);
        FastScanner58 fs = new FastScanner58();
        PrintWriter pw = new PrintWriter(System.out);
        //int t = fs.ni();
        int t = 1;
        // for (int tc = 0; tc < t; tc++) {
        for (int tc = 0; tc < t; tc++) {
           int n = fs.ni();
           int m = 2;
           long[] x = new long[n];
           long[] y = new long[n];
           for (int i = 0; i < n; i++) {
               x[i] = fs.nl();
               y[i] = fs.nl();
           }
           if (n%2==1) {
               pw.println("NO");
               continue;
           }
           boolean flag = true;
           for (int i = 0; i < n/2; i++) {
               int j = i + n/2;
               if ((x[(j+1)%n]-x[j])*-1 != x[i+1]-x[i]) flag = false;
               if ((y[(j+1)%n]-y[j])*-1 != y[i+1]-y[i]) flag = false;
           }
           if (flag) {
               pw.println("YES");
           } else {
               pw.println("NO");
           }
        }
        pw.close();
    }
    public static long dis(int i, int j, long[] x, long[] y) {
        return (long)Math.pow(Math.abs(x[i]-x[j]),2) + (long)Math.pow(Math.abs(y[i]-y[j]),2);
    }
    public static long gcd(long n1, long n2) {
        if (n2 == 0) {
            return n1;
        }
        return gcd(n2, n1 % n2);
    }
}
class UnionFind18 {

    int[] id;

    public UnionFind18(int size) {
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

class FastScanner58 {

    BufferedReader br;
    StringTokenizer st;

    public FastScanner58() {
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

class UnionFind17 {

    int[] id;

    public UnionFind17(int size) {
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
