import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int m = in.nextInt();
        int[] sh = new int[n];
        int[] cnt = new int[n];
        ArrayList<Integer>[] a = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            a[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            a[to].add(from);
        }
        int k = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < k; i++) {
            p[i] = in.nextInt() - 1;
        }
        boolean[] used = new boolean[n];
        ArrayDeque<Integer> deq = new ArrayDeque<>();
        deq.add(p[k - 1]);
        used[p[k - 1]] = true;
        while (!deq.isEmpty()) {
            int v = deq.pollFirst();
            for (int to : a[v]) {
                if (!used[to]) {
                    sh[to] = sh[v] + 1;
                    used[to] = true;
                    deq.add(to);
                } else {
                    if (sh[to] == sh[v] + 1) {
                        cnt[to]++;
                    }
                }
            }
        }
        int min = 0;
        int max = 0;
        for (int i = 1; i < k; i++) {
            if (sh[p[i - 1]] != sh[p[i]] + 1) {
                min++;
                max++;
            } else {
                if (cnt[p[i - 1]] != 0) max++;
            }
        }
        in.out.println(min + " " + max);
        in.out.close();
    }
}

class FastScanner {

    StringTokenizer st = new StringTokenizer("");
    BufferedReader br;
    PrintWriter out;


    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }


    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
