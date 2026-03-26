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

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
        }
        int ans = 0;
        int[] s = new int[n + 1];
        long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i - 1];
            for (int j = i; j >= 0; j--) {
                long v = (sum - j) % h;
                s[j] = s[j] + (v >= l && v <= r ? 1 : 0);
                if (j > 0) {
                    s[j] = Math.max(s[j - 1] + (v >= l && v <= r ? 1 : 0), s[j]);
                }
                ans = Math.max(ans, s[j]);
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
