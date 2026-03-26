import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        int[][] a = new int[n + 1][m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                a[i][j] = in.nextInt();
        int[][] pre = new int[n + 1][m];
        for(int i = 0; i < n; ++i)
            pre[i][0] = a[i][0];
        for(int i = 0; i < n; ++i)
            for(int j = 1; j < m; ++j)
                pre[i][j] = a[i][j] + pre[i][j - 1];
        int[] dp = new int[m];
        int[] pmx = new int[m];
        int[] smx = new int[m];
        for(int i = 0; i <= m - k; ++i) {
            int j = i + k - 1;
            dp[i] = pre[0][j] + pre[1][j];
            if(i != 0) 
                dp[i] -= pre[0][i - 1] + pre[1][i - 1];
        }
        pmx[0] = dp[0];
        smx[m - 1] = dp[m - 1];
        for(int i = 1; i < m; ++i)
            pmx[i] = Math.max(pmx[i - 1], dp[i]);
        for(int i = m - 2; i >=0 ; --i)
            smx[i] = Math.max(smx[i + 1], dp[i]);
        for(int i = 1; i < n; ++i) {
            int[] ndp = new int[m];
            for(int j = 0; j <= m - k; ++j) {
                int nj = j + k - 1;
                int num = pre[i][nj] + pre[i + 1][nj];
                if(j != 0)
                    num -= pre[i][j - 1] + pre[i + 1][j - 1];
                ndp[j] = num;
                int add = 0;
                if(j - k >= 0)
                    add = pmx[j - k];
                if(j + k < m)
                    add = Math.max(add, smx[j + k]);
                ndp[j] += add;
                int r = Math.min(j + k - 1, m - k);
                for(int pos = Math.max(0, j - k + 1); pos <= r; ++pos) {
                    int val = dp[pos] + num;
                    int R = Math.min(pos, j) + k;
                    for(int jj = Math.max(pos, j); jj < R; ++jj)
                        val -= a[i][jj];
                    ndp[j] = Math.max(ndp[j], val);
                }
            }
            for(int j = 0; j < m; ++j)
                dp[j] = ndp[j];
            pmx[0] = dp[0];
            smx[m - 1] = dp[m - 1];
            for(int j = 1; j < m; ++j)
                pmx[j] = Math.max(pmx[j - 1], dp[j]);
            for(int j = m - 2; j >= 0; --j)
                smx[j] = Math.max(smx[j + 1], dp[j]);
        }
        int ans = 0;
        for(int i = 0; i < m; ++i)
            ans = Math.max(ans, dp[i]);
        System.out.println(ans);
    }
}