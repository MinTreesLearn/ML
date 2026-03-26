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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            if (k > (4 * n * m - 2 * n - 2 * m)) {
                out.println("NO");
                return;
            }
            out.println("YES");
            int cr = 0, st = 0;
            StringBuilder sb = new StringBuilder();
            if (n == 1) {
                if (k < m) {
                    out.println("1\n" + k + " R");
                }
                out.println("2\n" + (m - 1) + " R");
                out.println(k - (m - 1) + " L");
                return;
            }
            if (k < n) {
                out.println(1);
                out.println(k + " D\n");
                return;
            }
            sb.append((n - 1) + " D\n");
            if (k <= 2 * (n - 1)) {
                out.println(2);
                out.println((n - 1) + " D");
                out.println(k - n + 1 + " U");
                return;
            }
            sb.append((n - 1) + " U\n");
            k -= 2 * (n - 1);
            st = 2;
            for (int i = 1; i < m; ++i) {
                if (3 * (n - 1) >= k) {
                    if (k / 3 > 0) {
                        sb.append(k / 3 + " RDL\n");
                        st += 1;
                        k -= k / 3 * 3;
                    }
                    if (k > 0) {
                        st++;
                        k--;
                        sb.append("1 R\n");
                    }
                    if (k > 0) {
                        st++;
                        k--;
                        sb.append("1 D\n");
                    }
                    break;
                }
                st++;
                sb.append((n - 1) + " RDL\n");
                k -= 3 * (n - 1);
                st++;
                k--;
                sb.append("1 R\n");
                if (k == 0) {
                    break;
                }
                st++;
                if (k < n) {
                    sb.append(k + " U\n");
                    k = 0;
                    break;
                }
                sb.append(n - 1 + " U\n");
                k -= n - 1;
            }
            if (k > 0) {
                st++;
                sb.append(k + " L\n");
            }
            out.println(st);
            out.println(sb.toString());
        }

    }
}

