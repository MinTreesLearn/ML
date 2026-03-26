import java.util.*;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mod = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(sol.solutionn(l, r, arr, mod));


    }
}
class Solution {
    int l, r, mod;
    int n;
    int[] arr;
    int[][] dp;
    public int solutionn(int l_, int r_, int[] arr_, int mod_) {
        n = arr_.length; l = l_; r = r_; arr = arr_; mod = mod_;
        dp = new int[n][mod + 1];
        for (int i = 0; i < n; i ++) Arrays.fill(dp[i], -1);
        return dfs(0, 0);

    }
    private int dfs(int i, int sum) {
        int ans = 0;
        if (i > 0 && sum >= l && sum <= r) ans ++;
        if (i == n) return ans;
        if (dp[i][sum] != -1) return dp[i][sum];
        ans += Math.max(dfs(i + 1, (sum + arr[i]) % mod), dfs(i + 1, (sum + arr[i] - 1) % mod));
        dp[i][sum] = ans;
        return ans;
    }
}