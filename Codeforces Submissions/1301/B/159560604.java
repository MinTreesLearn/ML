import java.util.*;
import java.io.*;

public class B1301 {
    final boolean DEBUG = true;

    final int INF = Integer.MAX_VALUE;
    final long LINF = Long.MAX_VALUE;

    FastScanner sc;
    PrintWriter out;

    int n;
    int[] a;
    ArrayList<Integer> inds;

    void solve() throws Exception {
        n = sc.nextInt();
        inds = new ArrayList<Integer>();
        a = new int[n];

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();

            if (x == -1)    inds.add(i);
            else            a[i] = x;
        }

        int lo = -1;
        int hi = 1_000_000_000;

        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;

            if (calc(mid) < calc(mid+1)) {
                hi = mid; 
            } else {
                lo = mid;
            }
        }

        out.println(calc(lo+1) + " " + (lo+1));
    }

    int calc(int k) {
        for (var i: inds)
            a[i] = k;

        int m = -INF;

        for (int i = 0; i < n-1; i++)
            m = Math.max(m, Math.abs(a[i] - a[i+1]));

        return m;
    }

    void run() throws Exception {
        Locale.setDefault(Locale.US);
        sc = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        int t = sc.nextInt();
        for (; t > 0; t--) {
            solve();
        }

        out.close();
        sc.close();
    }

    void log(Object... objs) {
        if (!DEBUG)
            return;

        var sb = new StringBuilder();
        for (var x: objs)
            sb.append(x.toString()).append(" ");

        out.println(sb);
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream in) throws Exception {
        	br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
				    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
        	return Long.parseLong(next());
        }

        float nextFloat() {
        	return Float.parseFloat(next());
        }

        double nextDouble() {
        	return Double.parseDouble(next());
        }

        String nextLine() {
            String line = "";
            try {
                line = br.readLine();
            } catch (Exception e) {
                e.printStackTrace();
            }

            return line;
        }

        void close() throws Exception {
        	br.close();
        }
    }

    public static void main(String[] arg) throws Exception {
        new B1301().run();
    }
}