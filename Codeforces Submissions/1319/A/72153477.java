import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int cnt = 0;
        boolean[] b = new boolean[n];
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (in.nextInt() == 1) {
                b[i] = true;
                cnt1++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (in.nextInt() == 1) {
                cnt2++;
                if (b[i]) cnt++;
            }
        }
        if (cnt == cnt1) in.out.println(-1);
        else in.out.println((cnt2 - cnt) / (cnt1 - cnt) + 1);
        in.out.close();
    }
}


class point implements Comparator<point> {
    int a, b;

    public point(int a, int b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public int compare(point o1, point o2) {
        return 2 * Integer.compare(o1.a, o2.a) + Integer.compare(o1.b, o2.b);
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
