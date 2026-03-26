// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1323B extends PrintWriter {
	CF1323B() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1323B o = new CF1323B(); o.main(); o.flush();
	}

	int[] qu = new int[600];
	void count(int[] aa, int n, int[] kk) {
		for (int i = 0, l = 0; i <= n; i++)
			if (i == n || aa[i] == 0) {
				if (l > 0)
					kk[l]++;
				l = 0;
			} else
				l++;
		int cnt = 0;
		for (int l = 1; l <= n; l++)
			if (kk[l] > 0) {
				qu[cnt++] = l;
				qu[cnt++] = kk[l];
			}
		for (int l_ = 1; l_ <= n; l_++) {
			int k_ = 0;
			for (int h = 0; h < cnt; h += 2) {
				int l = qu[h], k = qu[h + 1];
				if (l_ <= l)
					k_ += (l - l_ + 1) * k;
			}
			kk[l_] = k_;
		}
	}
	void main() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		int[] aa = new int[n];
		for (int i = 0; i < n; i++)
			aa[i] = sc.nextInt();
		int[] bb = new int[m];
		for (int j = 0; j < m; j++)
			bb[j] = sc.nextInt();
		int[] ka = new int[n + 1];
		count(aa, n, ka);
		int[] kb = new int[m + 1];
		count(bb, m, kb);
		long ans = 0;
		for (int la = 1; la <= k && la <= n; la++)
			if (k % la == 0) {
				int lb = k / la;
				if (lb <= m)
					ans += (long) ka[la] * kb[lb];
			}
		println(ans);
	}
}
