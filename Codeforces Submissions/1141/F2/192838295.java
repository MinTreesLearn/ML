import java.util.*;
import java.io.*;

public class Main {

    void solve() {
        int n = in.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = in.nextInt();
        }
        HashMap<Long, List<int[]>> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            long sum = 0l;
            for (int j = i; j <= n; j++) {
                sum += arr[j];
                map.computeIfAbsent(sum, k -> new ArrayList<>()).add(new int[] {i, j});
            }
        }
        List<int[]> ans = new ArrayList<>();
        for (List<int[]> x : map.values()) {
            List<int[]> cur = x;
            cur.sort((a, b) -> a[1] - b[1]);
            List<int[]> temp = new ArrayList<>();
            int prev = 0;
            for (int[] y : cur) {
                if (y[0] > prev) {
                    temp.add(y);
                    prev = y[1];
                }
            }
            if (temp.size() > ans.size()) {
                ans = temp;
            }
        }
        out.println(ans.size());
        for (int[] x : ans) {
            out.println(x[0] + " " + x[1]);
        }
    }

    FastScanner in;

    PrintWriter out;

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;

        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }

}