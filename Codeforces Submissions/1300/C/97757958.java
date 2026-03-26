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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] no = new int[n];
            int[] val = new int[40];
            for (int i = 0; i < n; ++i) {
                int k = in.nextInt();
                no[i] = k;
                int j = 0;
                while (k > 0) {
                    val[j] += k % 2;
                    k /= 2;
                    j++;
                }
            }
            int mval = 0;
            int res = 0;
            for (int i = 0; i < n; ++i) {
                int k = no[i];
                int v = 0, j = 0, j2 = 1;
                while (k > 0) {
                    if (k % 2 == 1 && val[j] == 1) {
                        v += j2;
                    }
                    j2 *= 2;
                    k /= 2;
                    j++;
                }
                if (v > mval) {
                    res = i;
                    mval = v;
                }
            }
            int result = no[res];
            out.print(no[res]);
            for (int i = 0; i < n; ++i) {
                if (i != res) {
                    out.print(" ");
                    out.print(no[i]);
                    result = (result | no[i]) - no[i];
                }
            }
            //out.print(" " +result);
        }

    }
}

