import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            boolean flag = m == 0;
            if (n < 3 && !flag) {
                out.print(-1);
                return;
            }
            int maxTries = r(n);
            if (maxTries < m && !flag) {
                out.print(-1);
                return;
            }
            int[] a = new int[n];
            if (maxTries == m) {
                for (int i = 0; i < a.length; i++) {
                    a[i] = i + 1;
                }
            } else {
                int p = 1;
                int len = -1;
                for (int i = 3; i <= 5000; i++) {
                    if (p <= m) {
                        len = i;
                    } else {
                        break;
                    }
                    p = i / 2 + p;
                }
                for (int i = 0; i < len; i++) {
                    a[i] = i + 1;
                }
                int countOf3 = m - r(len);
                if (len >= 0 && countOf3 != 0) {
                    a[len] = a[len - countOf3] + a[len - countOf3 - 2];
                    len++;
                }
                if (len == -1) {
                    a[0] = 1;
                    if (n > 1) a[1] = 2;
                    len = 1;
                }
                int chislo = 1000_000_000;
                int kones = n - 1;
                for (int k = len; k < n; k++) {
                    a[kones] = chislo;//a[k - 1] + a[k - 2] + 1;
                    chislo -= a[len - 1] + 1;
                    kones--;
                }
                // m
            }
            for (int i = 0; i < a.length; i++) {
                out.print(a[i] + " ");
            }

        }

        int r(int n) {
            if (n < 3) {
                return -1;
            }
            if (n == 3) {
                return 1;
            }
            return r(n - 1) + (n - 1) / 2;
        }

    }
}

