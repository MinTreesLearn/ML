/**
 * @author egaeus
 * @mail sebegaeusprogram@gmail.com
 * @veredict Not sended
 * @url <https://codeforces.com/problemset/problem/CFC>
 * @category ?
 * @date 9/06/2020
 **/

import java.io.*;
import java.util.*;

import static java.lang.Integer.*;
import static java.lang.Math.*;

public class CFC {
    public static void main(String args[]) throws Throwable {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for (String ln; (ln = in.readLine()) != null && !ln.equals(""); ) {
            StringBuilder sb = new StringBuilder();
            StringTokenizer st = new StringTokenizer(ln);
            int N = parseInt(st.nextToken()), Q = parseInt(st.nextToken());
            int sqrt = (int) Math.sqrt(N);
            int T = N / sqrt + (N % sqrt == 0 ? 0 : 1);
            boolean[][] arr = new boolean[2][N];
            boolean[][] canArrive = new boolean[2][N];
            boolean[] isBlocked = new boolean[T];
            //Arrays.fill(canArrive, true);
            for (boolean[] a : arr)
                Arrays.fill(a, true);
            for (boolean[] a : canArrive)
                Arrays.fill(a, true);
            for (int q = 0; q < Q; q++) {
                st = new StringTokenizer(in.readLine());
                int u = parseInt(st.nextToken()) - 1, v = parseInt(st.nextToken()) - 1;
                arr[u][v] = !arr[u][v];
                int p = v / sqrt;
                int j = sqrt * p;
                for (; j < sqrt * (p + 1) && j < N; j++) {
                    if (j == sqrt * p) {
                        canArrive[0][j] = arr[0][j];
                        canArrive[1][j] = arr[1][j];
                    } else {
                        canArrive[0][j] = arr[0][j] && (canArrive[0][j - 1] ||
                                (canArrive[1][j - 1] && arr[1][j]));
                        canArrive[1][j] = arr[1][j] && (canArrive[1][j - 1] ||
                                (canArrive[0][j - 1] && arr[0][j]));
                    }
                }
                isBlocked[p] = !canArrive[0][j - 1] && !canArrive[1][j - 1];
                boolean ws = true;
                for (int i = 0; i < T && ws; i++)
                    if (isBlocked[i])
                        ws = false;
                    else {
                        if (i == 0 || (canArrive[0][i * sqrt] && canArrive[0][i * sqrt - 1])
                                || (canArrive[1][i * sqrt] && canArrive[1][i * sqrt - 1])) ;
                        else
                            ws = false;
                    }
                //System.out.println(ws);
                sb.append(ws ? "Yes" : "No").append("\n");
            }
            System.out.print(new String(sb));
        }
    }
}

