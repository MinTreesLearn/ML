
/**
 * @author egaeus
 * @mail sebegaeusprogram@gmail.com
 * @veredict Not sended
 * @url <https://codeforces.com/problemset/problem/1287/C>
 * @category ?
 * @date 16/06/2020
 **/

import java.io.*;
import java.util.*;

import static java.lang.Integer.*;
import static java.lang.Math.*;

public class CF1287C {
    static int ODD, EVEN;
    static int[] arr;
    static int N;

    public static void main(String args[]) throws Throwable {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for (String ln; (ln = in.readLine()) != null && !ln.equals(""); ) {
            StringTokenizer st = new StringTokenizer(ln);
            N = parseInt(st.nextToken());
            arr = new int[N];
            boolean[] T = new boolean[N + 1];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < N; i++) {
                arr[i] = parseInt(st.nextToken());
                T[arr[i]] = true;
            }
            ODD = 0;
            EVEN = 0;
            for (int i = 1; i <= N; i++)
                if (!T[i]) {
                    if (i % 2 == 0)
                        EVEN++;
                    else ODD++;
                }
            mem = new int[N][3][ODD + 1][EVEN + 1];
            for (int[][][] a : mem)
                for (int[][] b : a)
                    for (int[] c : b)
                        Arrays.fill(c, -1);
            System.out.println(f(0, -1, ODD, EVEN));
        }
    }

    static int mem[][][][];

    static int f(int p, int last, int odd, int even) {
        if (odd < 0)
            return N;
        if (even < 0)
            return N;
        if (p == N)
            return 0;
        if (mem[p][last + 1][odd][even] >= 0)
            return mem[p][last + 1][odd][even];
        int min = N;
        if (arr[p] == 0)
            min = Math.min(f(p + 1, 1, odd - 1, even) + (last == 0 ? 1 : 0),
                    f(p + 1, 0, odd, even - 1) + (last == 1 ? 1 : 0));
        else
            min = f(p + 1, arr[p] % 2, odd, even) + (last != arr[p] % 2 && last >= 0 ? 1 : 0);
        return mem[p][last + 1][odd][even] = min;
    }
}
