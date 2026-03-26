import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jaynil
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EConstructTheBinaryTree solver = new EConstructTheBinaryTree();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class EConstructTheBinaryTree {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int d = in.nextInt();
            int tot = (n * (n - 1)) / 2;
            PriorityQueue<int[]> highest = new PriorityQueue<>((x, y) -> x[1] - y[1]);
            PriorityQueue<int[]> lowest = new PriorityQueue<>((x, y) -> y[1] - x[1]);
            if (d > tot) {
                out.println("NO");
                return;
            }
            //p d c
            int a[][] = new int[n][4];
            for (int i = 0; i < n; i++) {
                a[i][0] = i - 1;
                a[i][1] = i;
                a[i][2] = 1;
                a[i][3] = i;
                highest.add(a[i]);
                lowest.add(a[i]);
            }
            a[n - 1][2] = 0;
            while (highest.size() > 0 && lowest.size() > 0 && tot - d > 0) {
                int[] h = highest.poll();
                if (h[2] == 2) continue;
                int[] l = lowest.poll();
                if (l[2] > 0) {
                    highest.add(h);
                    continue;
                }
                if (tot - l[1] + 1 + h[1] >= d) {
                    tot = tot - l[1] + 1 + h[1];
                    h[2]++;
                    a[l[0]][2]--;
                    l[1] = h[1] + 1;
                    l[0] = h[3];
                    highest.add(l);
                    highest.add(h);
                } else {
                    lowest.add(l);
                }
            }
            if (tot == d) {
                out.println("YES");
                for (int i = 1; i < n; i++) {
                    out.print((a[i][0] + 1) + " ");
                }
                out.println();
            } else {
                out.println("NO");
//            out.println(tot);
//            out.println(highest.size());
//            out.println(lowest.size());
//            for(int i=1;i<n;i++){
//                out.print((a[i][0]+1) + " ");
//            }
                out.println();
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

