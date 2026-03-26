import java.io.*;
import java.util.Scanner;
import java.util.*;
 
public class Solution {
    static int mod = (int) 1e9 + 7;
    static Kattio io = new Kattio();
    static int h = (int) 1e5 * 2 + 2;
 
    public static void main(String[] args) {
        int n = io.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = io.nextInt();
        }
 
        new Solution().solve(n, arr);
        io.close();
    }
 
    public void solve(int n, int[] arr) {
        int len = (n + 1) / 2;
        int[][] dp = new int[len + 2][2];
        for (int[] t : dp) {
            t[0] = Integer.MAX_VALUE / 2;
            t[1] = Integer.MAX_VALUE / 2;
        }
        dp[0] = new int[]{0, 0};

        for (int i = 0; i < n; i++) {
            int[][] dp1 = new int[len + 2][2];
            for (int[] t : dp1) {
                t[0] = Integer.MAX_VALUE / 2;
                t[1] = Integer.MAX_VALUE / 2;
            }

            for (int odd = 0; odd <= len; odd++) {
                if (arr[i] == 0) {
                    if (odd > 0)
                        dp1[odd][0] = Math.min(dp[odd - 1][0], dp[odd - 1][1] + 1); 
                    dp1[odd][1] = Math.min(dp[odd][0] + 1, dp[odd][1]);
                } else if (arr[i] % 2 == 0) {
                    dp1[odd][1] = Math.min(dp[odd][0] + 1, dp[odd][1]); 
                } else {
                    if (odd > 0)
                        dp1[odd][0] = Math.min(dp[odd - 1][0], dp[odd - 1][1] + 1);
                }
            }
            dp = dp1;
        }   

        // for (int i = 0; i < n; i++) {
        //     int[][] dp1 = new int[len + 2][2];
        //     Arrays.fill(dp1, Integer.MAX_VALUE / 2);

        //     for (int odd = 0; odd <= len; odd++) {
        //         if (arr[i] == 0) {
        //             if (odd > 0)
        //                 dp1[odd][0] = Math.min(dp[odd - 1][0], dp[odd - 1][1] + 1); 
        //             dp1[odd][1] = Math.min(dp[odd][0] + 1, dp[odd][1]);
        //         } else if (arr[i] % 2 == 0) {
        //             dp1[odd][1] = Math.min(dp[odd][0] + 1, dp[odd][1]); 
        //         } else {
        //             if (odd > 0)
        //                 dp1[odd][0] = Math.min(dp[odd - 1][0], dp[odd - 1] + 1);
        //         }
        //         // if v == 0 {
        //         //     f[i+1][j][1] = min(f[i][j][0]+1, f[i][j][1])
        //         //     if j > 0
        //         //         f[i+1][j][0] = min(f[i][j-1][0], f[i][j-1][1]+1)
        //         // } else if v % 2 == 0 {
        //         //     if j > 0 
        //         //         f[i+1][j][0] = min(f[i][j-1][0], f[i][j-1][1]+1)
        //         // } else {
        //         //     f[i+1][j][1] = min(f[i][j][0]+1, f[i][j][1])
        //         // }

        //         // if v == 0 {
        //         //     f[j][1] = min(f[j][1], f[j][0]+1)
        //         //     if (j > 0) 
        //         //         f[j][0] = min(f[j-1][0], f[j-1][1]+1)
        //         //     else 
        //         //         f[j][0] = 1e9
        //         // } else if v % 2 == 0 {
        //         //     f[j][1] = 1e9
        //         //     if (j > 0) 
        //         //         f[j][0] = min(f[j-1][0], f[j-1][1]+1)
        //         //     else 
        //         //         f[j][0] = 1e9
        //         // } else if v % 2 == 1 {
        //         //     f[j][1] = min(f[j][1], f[j][0]+1)
        //         //     f[j][0] = 1e9
        //         // }
        //     }
        // }    

        io.println(Math.min(dp[len][0], dp[len][1]));
    }
 
    public int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
 
    public int countbit(long n) {
        int count = 0;
        for (int i = 0; i < 64; i++) {
            if (((1L << i) & n) != 0) count++;
        }
        return count;
    }
 
    public int firstbit(int n) {
        for (int i = 31; i >= 0; i--) {
            if (((1 << i) & n) != 0) return i;
        }
        return -1;
    }
}
 
 
class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
    // 标准 IO
    public Kattio() { this(System.in, System.out); }
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
        } catch (Exception e) {}
        return null;
    }
    public int nextInt() { return Integer.parseInt(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public long nextLong() { return Long.parseLong(next()); }
}