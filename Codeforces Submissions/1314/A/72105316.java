import java.io.*;
import java.util.*;



public class longwei {
    static class pub {
        int a;
        int t;

        public pub(int a, int t) {
            this.a = a;
            this.t = t;
        }
    }

    static class cmp implements Comparator<pub> {
        public int compare(pub a, pub b) {
            if (a.a == b.a)
                if(a.t == b.t)return  0;
                else
                return a.t > b.t ? -1 : 1;
            return a.a < b.a ? -1 : 1;
        }
    }

    static class cmp2 implements Comparator<pub> {
        public int compare(pub a, pub b) {
            if (a.t == b.t)
                if(a.a == b.a)return  0;
                else
                return a.a > b.a ? -1 : 1;
            return a.t > b.t ? -1 : 1;
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner lw = new Scanner(System.in);
        int n;
        n = lw.nextInt();
        pub[] p = new pub[n];
        for (int i = 0; i < n; i++)
            p[i] = new pub(lw.nextInt(), 0);
        for (int i = 0; i < n; i++)
            p[i].t = lw.nextInt();
        Arrays.sort(p, 0, n, new cmp());
        int now = 0;
        TreeSet<Integer> s = new TreeSet<Integer>();
        for (int i = 0; i < n; i++) {
            now = Math.max(now, p[i].a);
            s.add(now);
            now++;
        }
        Arrays.sort(p, 0, n, new cmp2());
        long res = 0;
        int c;
        //long ww = 99999999*99999999;
        for (int i = 0; i < n; i++) {
            c = s.ceiling(p[i].a);
            res += (c - p[i].a) * (long)p[i].t;
            s.remove(c);
        }
        System.out.println(res);
    }
}