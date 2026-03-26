// Coached by rainboy
import java.io.*;
import java.util.*;

public class CF1295F extends PrintWriter {
	CF1295F() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1295F o = new CF1295F(); o.main(); o.flush();
	}

	static final int MD = 998244353;
	int x_, y_;
	void gcd_(int a, int b) {
		if (b == 0) {
			x_ = 1; y_ = 0;
		} else {
			gcd_(b, a % b);
			int t = x_ - a / b * y_; x_ = y_; y_ = t;
		}
	}
	int inv(int a) {
		gcd_(a, MD);
		if (x_ < 0)
			x_ += MD;
		return x_;
	}
	void main() {
		int n = sc.nextInt();
		int[] ll = new int[n], rr = new int[n], xx = new int[n * 2];
		int[] vv = new int[n + 1]; long v = 1;
		for (int i = 1; i <= n; i++)
			vv[i] = inv(i);
		for (int i = 0; i < n; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt() + 1;
			xx[i << 1    ] = ll[i] = l;
			xx[i << 1 | 1] = rr[i] = r;
			v = v * inv(r - l) % MD;
		}
		Arrays.sort(xx);
		int m = 0;
		for (int i = 0; i < n * 2; i++)
			if (m == 0 || xx[m - 1] != xx[i])
				xx[m++] = xx[i];
		int[][] dp = new int[n + 1][m]; dp[0][m - 1] = 1;
		for (int i = 0; i < n; i++)
			for (int j = m - 1; j > 0; j--) {
				int x = dp[i][j];
				if (x == 0)
					continue;
				for (int j_ = j - 1; j_ >= 0; j_--) {
					int l = xx[j_], r = xx[j_ + 1];
					long c = 1;
					for (int i_ = i; i_ < n && ll[i_] <= l && r <= rr[i_]; i_++) {
						// i_ - i + 1 balls in r - l urns
						// choose(i_ - i + 1 + r - l - 1, i_ - i + 1)
						c = c * (i_ - i + r - l) % MD * vv[i_ - i + 1] % MD;
						dp[i_ + 1][j_] = (int) ((dp[i_ + 1][j_] + x * c) % MD);
					}
				}
			}
		long ans = 0;
		for (int j = 0; j < m - 1; j++)
			ans += dp[n][j];
		println(ans % MD * v % MD);
	}
}
