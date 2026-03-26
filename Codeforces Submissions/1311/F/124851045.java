import java.io.*;
import java.util.*;

public class Main {
        static class segtree{
                long[] t; 
                int n;
                public segtree(int[] a) {
                    this.n = a.length;
                    this.t = new long[4 * this.n];
                    Arrays.fill(this.t, 0);
                    build(a, 1, 0, this.n-1);
                }
                public segtree(int n) {
                        this.n = n;
                        this.t = new long[4 * n];
                        Arrays.fill(this.t, 0);
                }
                public void build(int[] a, int v, int tl, int tr) {
                        if(tl == tr)
                                t[v] = a[tl];
                        else {
                                int tm = (tl + tr) / 2;
                                build(a, 2 * v, tl, tm);
                                build(a, 2 * v + 1, tm + 1, tr);
                                t[v] = t[2 * v] + t[2 * v + 1];
                        }
                }
                public long query(int v, int tl, int tr, int l, int r) {
                        if(l > r)
                                return 0;
                        if(l == tl && r == tr)
                                return t[v];
                        int tm = (tl + tr) / 2;
                        return query(2 * v, tl, tm, l, Math.min(r, tm)) + 
                                query(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r);
                }
                public long query(int l, int r){
                        return query(1, 0, n - 1, l, r);
                }
                public void update(int pos, int val, int v, int tl, int tr) {
                        if(tl == tr)
                                t[v] += val;
                        else {
                                int tm = (tl + tr) / 2;
                                if(pos <= tm)
                                        update(pos, val, 2 * v, tl, tm);
                                else
                                        update(pos, val, 2 * v + 1, tm + 1 ,tr);
                                t[v] = t[2 * v] + t[2 * v + 1];
                        }
                }
                public void update(int pos, int val) {
                        update(pos, val, 1, 0, n - 1);
                }
        }
        static class pair {
                int x, y;
                public pair(int x, int y) {
                        this.x = x;
                        this.y = y;
                }
        }
        public static void main(String args[]) throws Exception {
                Scanner in = new Scanner(System.in);
                int n = in.nextInt();
                int[] x = new int[n];
                int[] v = new int[n];
                pair a[] = new pair[n];
                for(int i = 0; i < n; ++i)
                        x[i] = in.nextInt();
                for(int i = 0; i < n; ++i){
                        v[i] = in.nextInt();
                        a[i] = new pair(x[i], v[i]);
                }
                ArrayList<pair> list = new ArrayList<>();
                for(int i = 0; i < n; ++i)
                        list.add(a[i]);
                Collections.sort(list, new Comparator<pair>() {
                        @Override public int compare(pair a, pair b) {
                                return a.x - b.x;
                        }
                });
                for(int i = 0; i < n; ++i)
                        a[i] = list.get(i);
                ArrayList<Integer> speed = new ArrayList<>();
                for(int i = 0; i < n; ++i)
                        speed.add(v[i]);
                Collections.sort(speed);
                for(int i = 0; i < n; ++i)
                        v[i] = speed.get(i);
                ArrayList<Integer> uniq = new ArrayList<>();
                for(int i = 0, j = 0; i < n; i = j) {
                        while(j < n && v[i] == v[j]) ++j;
                        uniq.add(v[i]);
                }
                int k = uniq.size();
                v = new int[k];
                for(int i = 0; i < k; ++i)
                        v[i] = uniq.get(i);
                long ans = 0;
                segtree cnt = new segtree(k);
                segtree sumx = new segtree(k);
                for(int i = 0; i < n; ++i) {
                        int pos = Arrays.binarySearch(v, a[i].y);
                        ans += cnt.query(0, pos) * a[i].x - sumx.query(0,pos);
                        cnt.update(pos, 1);
                        sumx.update(pos, a[i].x);
                }
                System.out.println(ans);
        }
}