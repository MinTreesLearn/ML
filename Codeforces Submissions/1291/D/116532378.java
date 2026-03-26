/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 *
 * @author is2ac
 */
public class D_CF {
    public static boolean fail;
    public static int id;
    public static void main(String[] args) throws IOException {
        FastScanner58 fs = new FastScanner58();
        //Reader fs = new Reader();
        PrintWriter pw = new PrintWriter(System.out);
        //int t = fs.ni();
        int t = 1;
        for (int tc = 0; tc < t; tc++) {
            String s = fs.next();
            int n = s.length();
            int q = fs.ni();
            int[][] a = new int[n][26];
            for (int i = 0; i < n; i++) {
                a[i][s.charAt(i)-'a']++;
            }
            for(int i = 1; i < n; i++) {
                for (int j = 0; j < 26; j++) {
                    a[i][j] += a[i-1][j];
                }
            }
            for (int i = 0; i < q; i++) {
                int l = fs.ni()-1, r = fs.ni()-1;
                int c = 0;
                int let = 0, max = (int)(-1e9);
                boolean flag = true;
                for (int j = 0; j < 26; j++) {
                    let = a[r][j];
                    if (l>0) let -= a[l-1][j];
                    if (let>0) c++;
                    max = Math.max(max,let);
                }
                if (c==2) {
                    if (s.charAt(l)==s.charAt(r)) {
                        pw.println("No");
                    } else {
                        pw.println("Yes");
                    }
                } else if (c>2 || l==r) {
                    pw.println("Yes");
                } else {
                    pw.println("No");
                }
            }
            for (int i = 0; i < n; i++) {
                //pw.println(Arrays.toString(a[i]));
            }
        }
        pw.close();
    }
    public static long gcd(long n1, long n2) {
        if (n2 == 0) {
            return n1;
        }
        return gcd(n2, n1 % n2);
    }
}

class BIT16 {

    int[] bit;

    public BIT16(int size) {
        bit = new int[size];
    }

    public void update(int ind, int delta) {
        while (ind < bit.length) {
            bit[ind] += delta;
            ind = ind + (ind & (-1 * ind));
        }
    }

    public int sum(int ind) {
        int s = 0;
        while (ind > 0) {
            s += bit[ind];
            ind = ind - (ind & (-1 * ind));
        }
        return s;
    }

    public int query(int l, int r) {
        return sum(r) - sum(l);
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

class Reader {

    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
        byte[] buf = new byte[64];
        int cnt = 0, c;
        while ((c = read()) != -1) {
            if (c == '\n') {
                break;
            }
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int ni() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) {
            return -ret;
        }
        return ret;
    }

    public long nextLong() throws IOException {
        long ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) {
            return -ret;
        }
        return ret;
    }

    public double nextDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (c == '.') {
            while ((c = read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }
        if (neg) {
            return -ret;
        }
        return ret;
    }

    private void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) {
            buffer[0] = -1;
        }
    }

    private byte read() throws IOException {
        if (bufferPointer == bytesRead) {
            fillBuffer();
        }
        return buffer[bufferPointer++];
    }

    public void close() throws IOException {
        if (din == null) {
            return;
        }
        din.close();
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
