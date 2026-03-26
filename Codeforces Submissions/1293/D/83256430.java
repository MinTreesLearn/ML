/**
 * @author egaeus
 * @mail sebegaeusprogram@gmail.com
 * @veredict Not sended
 * @url <https://codeforces.com/problemset/problem/CFD>
 * @category ?
 * @date 9/06/2020
 **/

import java.io.*;
import java.util.*;

import static java.lang.Integer.*;
import static java.lang.Math.*;

public class CFD {

    static long X0, Y0, AX, AY, BX, BY, XS, YS, T;

    public static void main(String args[]) throws Throwable {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for (String ln; (ln = in.readLine()) != null && !ln.equals(""); ) {
            StringTokenizer st = new StringTokenizer(ln);
            X0 = Long.parseLong(st.nextToken());
            Y0 = Long.parseLong(st.nextToken());
            AX = Long.parseLong(st.nextToken());
            AY = Long.parseLong(st.nextToken());
            BX = Long.parseLong(st.nextToken());
            BY = Long.parseLong(st.nextToken());
            st = new StringTokenizer(in.readLine());
            XS = Long.parseLong(st.nextToken());
            YS = Long.parseLong(st.nextToken());
            T = Long.parseLong(st.nextToken());
            ArrayList<long[]> list = new ArrayList<>();
            list.add(new long[]{X0, Y0});
            for (; ; ) {
                long x0 = list.get(list.size() - 1)[0], y0 = list.get(list.size() - 1)[1];
                long[] n = new long[]{AX * x0 + BX, AY * y0 + BY};
                boolean ws = false;
                for (long[] a : list)
                    if (Math.abs(n[0] - a[0]) + Math.abs(n[1] - a[1]) <= 10000000000000000L)
                        ws = true;
                list.add(n);
                if(!ws) break;
            }
            int max = 0;
            for (int i = 0; i < list.size(); i++)
                max = Math.max(max, f(i, list));
            System.out.println(max);
        }
    }

    static int f(int p, ArrayList<long[]> list) {
        long t = T;
        int s = 0;
        if (Math.abs(list.get(p)[0] - XS) + Math.abs(list.get(p)[1] - YS) <= t) {
            t -= Math.abs(list.get(p)[0] - XS) + Math.abs(list.get(p)[1] - YS);
            s++;
            for (int i = p - 1; i >= 0; i--) {
                long dist = Math.abs(list.get(i)[0] - list.get(i + 1)[0]) + Math.abs(list.get(i)[1] - list.get(i + 1)[1]);
                if (dist <= t) {
                    t -= dist;
                    s++;

                } else break;
            }
            if (p < list.size() - 1) {
                long dist = Math.abs(list.get(p + 1)[0] - list.get(0)[0]) + Math.abs(list.get(p + 1)[1] - list.get(0)[1]);
                if (dist <= t) {
                    t -= dist;
                    s++;
                    for (int i = p + 2; i < list.size(); i++) {
                        dist = Math.abs(list.get(i)[0] - list.get(i - 1)[0]) + Math.abs(list.get(i)[1] - list.get(i - 1)[1]);
                        if (dist <= t) {
                            t -= dist;
                            s++;

                        } else break;
                    }
                }
            }
        }
        return s;
    }
}
