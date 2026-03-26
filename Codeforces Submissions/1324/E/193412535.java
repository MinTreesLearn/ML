import java.io.*;
import java.util.StringTokenizer;

/**
 * * @author zhengnaishan
 * * @date 2023/2/13 9:21
 */
public class CF1324 {

    public static void main(String[] args) {

        Kattio io = new Kattio();
        int n = io.nextInt();
        int h = io.nextInt();
        int l = io.nextInt();
        int r = io.nextInt();
        int[][] s = new int[n + 1][n + 1];
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
        }
        int ans = 0;
        long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i - 1];
            long v = sum % h;
            s[i][0] = s[i - 1][0] + (v >= l && v <= r ? 1 : 0);
            ans = Math.max(ans, s[i][0]);
            for (int j = i; j > 0; j--) {
                v = (sum - j) % h;
                s[i][j] = s[i - 1][j] + (v >= l && v <= r ? 1 : 0);
                s[i][j] = Math.max(s[i - 1][j - 1] + (v >= l && v <= r ? 1 : 0), s[i][j]);
                ans = Math.max(ans, s[i][j]);
            }
        }
        io.println(ans);
        io.flush();
    }


    public static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;

        // 标准 IO
        public Kattio() {
            this(System.in, System.out);
        }

        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }

        // 文件 IO
        public Kattio(String intput, String output) throws IOException {
            super(output);
            r = new BufferedReader(new FileReader(intput));
        }

        // 在没有其他输入时返回 null
        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) {
            }
            return null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}
