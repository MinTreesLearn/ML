import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.AbstractCollection;
import java.util.Scanner;
import java.util.LinkedList;

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
            int[] arr = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                arr[i] = in.nextInt();
            }
            LinkedList<TaskD.Val> stack = new LinkedList<>();
            stack.push(new TaskD.Val(arr[0], 1));
            for (int i = 1; i < n; ++i) {
                int count = 1;
                double sum = 0.;

                while (!stack.isEmpty()) {
                    TaskD.Val val = stack.peek();
                    if ((sum + val.getSum() + arr[i]) / (count + val.cnt) > val.val) {
                        break;
                    }
                    count += val.cnt;
                    sum += val.getSum();
                    stack.pop();
                }
                double newVal = (sum + arr[i]) / count;
                stack.push(new TaskD.Val(newVal, count));
            }
            while (!stack.isEmpty()) {
                TaskD.Val val = stack.pollLast();
                for (int i = 0; i < val.cnt; ++i) {
                    out.println(val.val);
                }
            }
        }

        private static class Val {
            double val;
            int cnt;

            Val(double v, int c) {
                val = v;
                cnt = c;
            }

            public double getSum() {
                return val * cnt;
            }

        }

    }
}

