import java.util.*;
import java.io.*;

public class E626 {
    static long mod = (long) 1e9 + 7;
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(); int m = sc.nextInt();
            ArrayList<Integer> [] adj = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
            long [] c = new long[n + 1];
            for (int i = 1; i <= n; i++) c[i] = sc.nextLong();
            for (int i = 0; i < m; i++) {
                int left = sc.nextInt(); int right = sc.nextInt();
                adj[right].add(left);
            }
            long ans = 0;
            for (int i = 1; i <= n; i++) Collections.sort(adj[i]);
            long [] hash = new long[n + 1];
            Arrays.fill(hash, -1);
            for (int i = 1; i <= n; i++) if (adj[i].size() > 0) hash[i] = hash(adj[i]);
            Map<Long, Long> map = new HashMap<>();
            for (int i = 1; i <= n; i++) {
                if (hash[i] != -1) map.put(hash[i], map.getOrDefault(hash[i], 0L) + c[i]);
            }
            for (Long l: map.values()) ans = gcd(ans, l);
            out.println(ans);
        }
        out.close();
    }

    static long hash(ArrayList<Integer> a) {
        long pow = 1; long res = 0;
        for (int i = 0; i < a.size(); i++) {
            res = (res + (pow * a.get(i)) % mod) % mod;
            pow = (pow * 998244353) % mod;
        }
        return res;
    }

    static long gcd(long a, long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }


    }

}