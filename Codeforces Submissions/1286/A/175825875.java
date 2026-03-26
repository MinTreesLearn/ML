import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

/**
 * * @author zhengnaishan
 * * @date 2022/10/13 9:44
 */
public class CF1286 {

    public static void main(String[] args) {
        Kattio io = new Kattio();
        int n = io.nextInt();
        int[] a = new int[n];
        int j = (n + 1) / 2, o = n / 2;//表示奇数个数，偶数个数
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
            if (a[i] != 0) {
                if (a[i] % 2 == 0) {
                    o--;
                } else {
                    j--;
                }
            }
        }
        int[][][] f = new int[2][j + 1][o + 1];//当前面的数是奇数/偶数时， 使用j个奇数/k个偶数最少不同对
        for (int i = 0; i < 2; i++) {
            for (int l = 0; l <= j; l++) {
                for (int m = 0; m <= o; m++) f[i][l][m] = Integer.MAX_VALUE;
            }
        }
        f[0][0][0] = f[1][0][0] = 0;
        for (int i = 0; i < n; i++) {
            int ai = a[i];
            int[][][] nf = new int[2][j + 1][o + 1];
            for (int l = j; l >= 0; l--) {
                for (int m = o; m >= 0; m--) {//前面用了 l个奇数  m个偶数
                    nf[0][l][m] = nf[1][l][m] = Integer.MAX_VALUE;
                    if (f[0][l][m] != Integer.MAX_VALUE) {//前面一个数是奇数
                        if (a[i] != 0 && a[i] % 2 == 0) {//当前是偶数
                            nf[1][l][m] = Math.min(nf[1][l][m], f[0][l][m] + 1);
                        } else if (a[i] != 0 && a[i] % 2 == 1) {//当前数是奇数
                            nf[0][l][m] = Math.min(nf[0][l][m], f[0][l][m]);
                        }
                        if (ai == 0 && l < j) {//当前数置为奇数
                            nf[0][l + 1][m] = Math.min(nf[0][l + 1][m], f[0][l][m]);
                        }
                        if (ai == 0 && m < o) {//当前数置为偶数
                            nf[1][l][m + 1] = Math.min(nf[1][l][m + 1], f[0][l][m] + 1);
                        }
                    }
                    if (f[1][l][m] != Integer.MAX_VALUE) {//前面一个数是偶数
                        if (a[i] != 0 && ai % 2 == 0) {//当前是偶数
                            nf[1][l][m] = Math.min(nf[1][l][m], f[1][l][m]);
                        } else if (ai != 0 && ai % 2 == 1) {//当前是奇数
                            nf[0][l][m] = Math.min(nf[0][l][m], f[1][l][m] + 1);
                        }
                        if (ai == 0 && l < j) {//将当前数置为奇数
                            nf[0][l + 1][m] = Math.min(nf[0][l + 1][m], f[1][l][m] + 1);
                        }
                        if (ai == 0 && m < o) {//将当前数置为偶数
                            nf[1][l][m + 1] = Math.min(nf[1][l][m + 1], f[1][l][m]);
                        }
                    }
                }
            }
            f = nf;
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= j; i++) {
            for (int l = 0; l <= o; l++) {
                ans = Math.min(ans, f[0][i][l]);
                ans = Math.min(ans, f[1][i][l]);
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
