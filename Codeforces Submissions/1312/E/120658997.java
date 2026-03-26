import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.in;
import static java.lang.System.out;

public class SolutionE extends Thread {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                                            InputStreamReader(in));
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
            return parseInt(next());
        }

        long nextLong() {
            return parseLong(next());
        }

        double nextDouble() {
            return parseDouble(next());
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

    private static final FastReader scanner = new FastReader();
    private static final PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        new Thread(null, new SolutionE(), "Main", 1 << 28).start();
    }

    public void run() {
        solve();
        out.close();
    }

    private static void solve() {
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int[][] dp = new int[n][n+1];

        for (int size = 1; size <= n; size++) {
            for (int l = 0; l < n; l++) {
                if (l + size > n) {
                    break;
                }
                int r = l + size;

                dp[l][r] = -1;
                if (size == 1) {
                    dp[l][r] = a[l];
                    continue;
                }


                for (int j = l+1; j < r; j++) {
                    if (dp[l][j] == dp[j][r] && dp[l][j] != -1) {
                        dp[l][r] = dp[l][j] + 1;
                    }
                }
            }
        }

        int[] dp2 = new int[n+1];

        for (int i = 1; i <= n; i++) {
            int minValue = 2000;

            if (dp[0][i] != -1) {
                minValue = 1;
            }
            for (int j = 1; j < i; j++) {
                if (dp[j][i] != -1) {
                    int value = 1 + dp2[j];
                    minValue = Math.min(minValue, value);
                }
            }
            dp2[i] = minValue;
        }

        out.println(dp2[n]);
    }
}