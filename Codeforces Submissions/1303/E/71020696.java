import java.io.*;
import java.util.*;

public class CF1303E extends PrintWriter {
	CF1303E() { super(System.out); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1303E o = new CF1303E(); o.main(); o.flush();
	}

	static final int A = 26;
	void main() {
		int[] ii = new int[A];
		int t = sc.nextInt();
		while (t-- > 0) {
			byte[] ss = sc.next().getBytes();
			byte[] tt = sc.next().getBytes();
			int n = ss.length;
			int m = tt.length;
			for (int i = 0; i < n; i++)
				ss[i] -= 'a';
			for (int i = 0; i < m; i++)
				tt[i] -= 'a';
			int[][] next = new int[n][A];
			Arrays.fill(ii, n);
			for (int i = n - 1; i >= 0; i--) {
				ii[ss[i]] = i;
				for (int a = 0; a < A; a++)
					next[i][a] = ii[a];
			}
			int[][] dp = new int[m + 1][m + 1];
			boolean yes = false;
			for (int l = 0; l <= m; l++) {
				for (int i = 0; i <= l; i++)
					for (int j = l; j <= m; j++)
						dp[i][j] = n + 1;
				dp[0][l] = 0;
				for (int i = 0; i <= l; i++)
					for (int j = l; j <= m; j++) {
						int h = dp[i][j];
						if (h >= n)
							continue;
						if (i < l)
							dp[i + 1][j] = Math.min(dp[i + 1][j], next[h][tt[i]] + 1);
						if (j < m)
							dp[i][j + 1] = Math.min(dp[i][j + 1], next[h][tt[j]] + 1);
					}
				if (dp[l][m] <= n) {
					yes = true;
					break;
				}
			}
			println(yes ? "YES" : "NO");
		}
	}
}
