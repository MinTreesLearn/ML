import java.util.*;
import java.io.*;
public class E83
{
    public static void main(String [] args)
    {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt(); int [] a = new int [n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        int [][] dp = new int [n][n];
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (len == 1) {
                    dp[i][j] = a[i]; continue;
                }
                for (int k = i; k < j; k++) {
                    if (dp[i][k] > 0 && dp[k+1][j] == dp[i][k]) {
                        dp[i][j] = dp[i][k] + 1;
                    }
                }
            }
        }
        int [] min = new int [n];
        Arrays.fill(min, Integer.MAX_VALUE);
        min[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = -1; j < i; j++) {
                int cont = -1;
                if (j == -1) {
                    cont = 0;
                } else {
                    cont = min[j];
                }
                if (dp[j+1][i] > 0) {
                    min[i] = Math.min(min[i], 1 + cont);
                } else {
                    min[i] = Math.min(min[i], cont + i - j);
                }
            }
        }
        out.println(min[n-1]);

        out.close();
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

        String nextLine(){
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