import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    TreeSet<Integer>[] ts;

    boolean has_three_diff(int l, int r) {
        int cnt = 0;
        for (int i = 0; i < ts.length; i++) {
            if (ts[i].ceiling(l) != null) {
                if (ts[i].ceiling(l) <= r) cnt++;
            }
        }
        if (cnt > 2) return true;
        return false;
    }

    void run() throws IOException {
        char[] a = next().toCharArray();
        ts = new TreeSet[26];
        for (int i = 0; i < ts.length; i++) {
            ts[i] = new TreeSet<>();
        }
        for (int i = 0; i < a.length; i++) {
            ts[a[i] - 'a'].add(i);
        }
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int l = nextInt() - 1;
            int r = nextInt() - 1;
            if (l == r || a[l] != a[r] || has_three_diff(l, r)) {
                pw.println("Yes");
            } else {
                pw.println("No");
            }
        }
        pw.close();
    }

    class Point {
        long x, y;

        public Point(long a, long b) {
            x = a;
            y = b;
        }
    }

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    //BufferedReader br = new BufferedReader(new FileReader("qual.in"));

    StringTokenizer st = new StringTokenizer("");
    PrintWriter pw = new PrintWriter(System.out);
    //PrintWriter pw = new PrintWriter("qual.out");

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public Main() throws FileNotFoundException {
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    long mod = Integer.MAX_VALUE;

}