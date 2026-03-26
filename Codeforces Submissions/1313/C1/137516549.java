// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1313C2 extends PrintWriter {
	CF1313C2() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1313C2 o = new CF1313C2(); o.main(); o.flush();
	}

	void main() {
		int n = sc.nextInt();
		int[] aa = new int[n + 2];
		for (int i = 1; i <= n; i++)
			aa[i] = sc.nextInt();
		long[] dp = new long[n + 2];
		long[] dq = new long[n + 2];
		int[] pp = new int[n + 2]; pp[0] = -1;
		int[] qq = new int[n + 2]; qq[n + 1] = n + 2;
		int[] qu = new int[n + 2];
		int cnt = 0;
		qu[cnt++] = 0;
		for (int p, i = 1; i <= n; i++) {
			while (aa[p = qu[cnt - 1]] >= aa[i])
				cnt--;
			qu[cnt++] = i;
			pp[i] = p;
			dp[i] = dp[p] + (long) (i - p) * aa[i];
		}
		cnt = 0;
		qu[cnt++] = n + 1;
		for (int q, i = n; i >= 1; i--) {
			while (aa[q = qu[cnt - 1]] >= aa[i])
				cnt--;
			qu[cnt++] = i;
			qq[i] = q;
			dq[i] = dq[q] + (long) (q - i) * aa[i];
		}
		int h = 0;
		for (int i = 1; i <= n; i++)
			if (h == 0 || dp[h] + dq[h] - aa[h] < dp[i] + dq[i] - aa[i])
				h = i;
		for (int i = h; i >= 1; ) {
			int a = aa[i];
			int p = pp[i];
			while (i != p) {
				aa[i] = a;
				i--;
			}
		}
		for (int i = h; i <= n; ) {
			int a = aa[i];
			int q = qq[i];
			while (i != q) {
				aa[i] = a;
				i++;
			}
		}
		for (int i = 1; i <= n; i++)
			print(aa[i] + " ");
		println();
	}
}
