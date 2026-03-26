/**
 * ******* Created  on 25/2/20 8:03 PM*******
 */

import java.io.*;
import java.util.*;

public class ED81E implements Runnable {

    private static final int MAX = 2*(int) (1E5 + 5);
    private static final int MOD = (int) (1E9 + 7);
    private static final long Inf = (long) (1E14 + 10);
    int n;
    private void solve() throws IOException {
        n = reader.nextInt();
        int[] p = new int[MAX];
        int[] rp = new int[MAX];
        int[] a = new int[MAX];

        for(int i=0;i<n;i++){
            p[i] = reader.nextInt();
            p[i]--;
            rp[p[i]]=i;
        }
        for(int i=0;i<n;i++)
            a[i] = reader.nextInt();
        b[0] = a[0];
        for(int i=1;i<n;i++)
            b[i] = a[i] + b[i-1];
        build(0,0,n);
        long res = b[0];
        for(int i = 0; i < n; ++i){
            int pos = rp[i];
            upd(pos, n, -a[pos]);
            upd(0, pos, a[pos]);
            res = Math.min(res, get(0, n - 1));

        }

        writer.println(res);
    }
    long[] b = new long[MAX];
    long[] t = new long[4*MAX];
    long[] add = new long[4*MAX];
    private void build(int v, int l, int r) {
        if(r-l ==1){
            t[v] = b[l];
            return;
        }
        int mid = (l+r)/2;
        build(v*2 +1, l, mid);
        build(2*v+2, mid,r);
        t[v] = Math.min(t[2*v+1], t[2*v+2]);
    }
    void push(int v, int l, int r){
        if(add[v] != 0){
            if(r - l > 1)
                for(int i = v+v+1; i < v+v+3; ++i){
                    add[i] += add[v];
                    t[i] += add[v];
                }
            add[v] = 0;
        }
    }

    void upd(int v, int l, int r, int L, int R, int x){
        if(L >= R) return;
        if(l == L && r == R){
            add[v] += x;
            t[v] += x;
            push(v, l, r);
            return;
        }

        push(v, l, r);
        int mid = (l + r) / 2;
        upd(v * 2 + 1, l, mid, L, Math.min(mid, R), x);
        upd(v * 2 + 2, mid, r, Math.max(mid, L), R, x);

        t[v] = Math.min(t[v * 2 + 1], t[v * 2 + 2]);
    }

    void upd(int l, int r, int x){
        upd(0, 0, n, l, r, x);
    }

    long get(int v, int l, int r, int L, int R){
        if(L >= R) return Inf;

        push(v, l, r);
        if(l == L && r == R)
            return t[v];

        int mid = (l + r) / 2;
        return Math.min(get(v * 2 + 1, l, mid, L, Math.min(R, mid)),
                get(v * 2 + 2, mid, r, Math.max(L, mid), R));
    }

    long get(int l, int r){
        return get(0, 0, n, l, r);
    }
    public static void main(String[] args) throws IOException {
        try (Input reader = new StandardInput(); PrintWriter writer = new PrintWriter(System.out)) {
            new ED81E().run();
        }
    }

    StandardInput reader;
    PrintWriter writer;

    @Override
    public void run() {
        try {
            reader = new StandardInput();
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    interface Input extends Closeable {
        String next() throws IOException;

        default int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        default long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        default double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        default int[] readIntArray() throws IOException {
            return readIntArray(nextInt());
        }

        default int[] readIntArray(int size) throws IOException {
            int[] array = new int[size];
            for (int i = 0; i < array.length; i++) {
                array[i] = nextInt();
            }
            return array;
        }

        default long[] readLongArray(int size) throws IOException {
            long[] array = new long[size];
            for (int i = 0; i < array.length; i++) {
                array[i] = nextLong();
            }
            return array;
        }
    }

    private static class StandardInput implements Input {
        private final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        private StringTokenizer stringTokenizer;

        @Override
        public void close() throws IOException {
            reader.close();
        }

        @Override
        public String next() throws IOException {
            if (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                stringTokenizer = new StringTokenizer(reader.readLine());
            }
            return stringTokenizer.nextToken();
        }
    }
}
