import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Scanner;
import java.util.Deque;
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
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            //in.next();
            int[] num = new int[n];
            for (int i = 0; i < n; ++i) {
                num[i] = in.nextInt();
            }
            //in.next();
            int w = Integer.max(m - k - 1, 0);
            MinStack ms = new MinStack();
            for (int i = 0; i < w; ++i) {
                ms.add(i, Integer.max(num[i], num[n - m + i]));
            }
            int best = 0;
            for (int i = w; i < m; ++i) {
                ms.add(i, Integer.max(num[i], num[n - m + i]));
                best = Integer.max(best, ms.getMin());
                ms.rem(i - w);
            }
            out.println(best);
        }

        private class MinStack {
            Deque<Integer> val = new LinkedList<>();
            Deque<Integer> idx = new LinkedList<>();

            void add(int i, int v) {
                while (!val.isEmpty() && val.peekLast() >= v) {
                    val.pollLast();
                    idx.pollLast();
                }
                val.add(v);
                idx.add(i);
            }

            void rem(int i) {
                if (idx.peekFirst() == i) {
                    idx.pollFirst();
                    val.pollFirst();
                }
            }

            int getMin() {
                return val.peekFirst();
            }

        }

    }
}

