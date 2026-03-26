import java.io.*;
import java.util.*;

public class Main {
    static class SegTree {
        int[] t;
        int n;
        SegTree(int[] a) {
            this.n = a.length;
            this.t = new int[4 * this.n];
            build(a, 1, 0, this.n - 1);
        }
        void build(int[] a, int v, int tl, int tr) {
            if(tl == tr) 
                t[v] = a[tl];
            else {
                int tm = (tl + tr) / 2;
                build(a, 2 * v, tl, tm);
                build(a, 2 * v + 1, tm + 1, tr);
                t[v] = t[2 * v] + t[2 * v + 1];
            }
        }
        int query(int v, int l, int r, int tl, int tr) { 
            if(l > r)
                return 0;
            if(l == tl && r == tr)
                return t[v];
            int tm = (tl + tr) / 2;
            return query(2 * v, l, Math.min(tm, r), tl, tm) +
                    query(2 * v + 1, Math.max(tm + 1, l), r, tm + 1, tr);
        }
        int query(int l, int r) {
            return query(1, l, r, 0, n - 1);
        }
        void update(int pos, int add, int v, int tl, int tr) {
            if(tl == tr)
                t[v] += add;
            else {
                int tm = (tl + tr) / 2;
                if(pos <= tm) 
                    update(pos, add, 2 * v, tl, tm);
                else 
                    update(pos, add, 2 * v + 1, tm + 1, tr);
                t[v] = t[2 * v] + t[2 * v + 1];
            }
        }
        void update(int pos, int val) {
            update(pos, val, 1, 0, n - 1);
        }
    } 
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        int[] ans = new int[n];
        int[] pos = new int[n];
        int[] cnt = new int[n + m];
        boolean[] mi = new boolean[n];
        for(int i = 0; i < n; ++i) {
            pos[i] = m + i;
            ans[i] = i;
            cnt[m + i] = 1;
        }
        SegTree t = new SegTree(cnt);
        for(int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            mi[x] = true;
            ans[x] = Math.max(ans[x], t.query(0, pos[x]));
            t.update(pos[x], -1);
            pos[x] = m - i - 1;
            t.update(pos[x], 1);
        }
        for(int i = 0; i < n; ++i)
            ans[i] = Math.max(ans[i], t.query(0, pos[i]));
        for(int i = 0; i < n; ++i)
            System.out.println((mi[i] ? 1 : (i + 1)) + " " + ans[i]);
    }
}