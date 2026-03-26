// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1287C extends PrintWriter {
	CF1287C() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1287C o = new CF1287C(); o.main(); o.flush();
	}

	static final int INF = 0x3f3f3f3f;
	void main() {
		int n = sc.nextInt();
		int[] pp = new int[n];
		int k0 = 0, k1 = 0;
		for (int i = 0; i < n; i++) {
			int p = sc.nextInt();
			if (p == 0)
				pp[i] = -1;
			else if ((pp[i] = p % 2) == 0)
				k0++;
			else
				k1++;
		}
		k0 = n / 2 - k0;
		k1 = (n + 1) / 2 - k1;
		int[][][] dp = new int[k0 + 1][k1 + 1][2];
		int[][][] dq = new int[k0 + 1][k1 + 1][2];
		for (int h0 = 0; h0 <= k0; h0++)
			for (int h1 = 0; h1 <= k1; h1++)
				dp[h0][h1][0] = dp[h0][h1][1] = INF;
		dp[0][0][0] = dp[0][0][1] = 0;
		for (int i = 0; i < n; i++) {
			int p = pp[i];
			for (int h0 = 0; h0 <= k0; h0++)
				for (int h1 = 0; h1 <= k1; h1++)
					if (p == -1) {
						dq[h0][h1][0] = h0 > 0 ? Math.min(dp[h0 - 1][h1][0], dp[h0 - 1][h1][1] + 1) : INF;
						dq[h0][h1][1] = h1 > 0 ? Math.min(dp[h0][h1 - 1][1], dp[h0][h1 - 1][0] + 1) : INF;
					} else {
						dq[h0][h1][p] = Math.min(dp[h0][h1][p], dp[h0][h1][p ^ 1] + 1);
						dq[h0][h1][p ^ 1] = INF;
					}
			int[][][] tmp = dp; dp = dq; dq = tmp;
		}
		println(Math.min(dp[k0][k1][0], dp[k0][k1][1]));
	}
}
