import java.io.*;
import java.util.*;

public class CF1307E extends PrintWriter {
	CF1307E() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1307E o = new CF1307E(); o.main(); o.flush();
	}

	static final int MD = 1000000007;
	int cnt_; long sum;
	int n, m;
	int[] ss, ii, jj;
	int[] ll, rr, lr, w2;
	void update(int h, int x) {
		Arrays.fill(ll, 0); Arrays.fill(rr, 0); Arrays.fill(lr, 0);
		for (int h_ = 0; h_ < m; h_++) {
			if (h_ == h)
				continue;
			int s_ = ss[h_], i_ = ii[h_], j_ = jj[h_];
			if (i_ < x)
				ll[s_]++;
			if (j_ > x)
				rr[s_]++;
			if (i_ < x && j_ > x)
				lr[s_]++;
		}
		int cnt; long ways;
		if (h == -1) {
			cnt = 0;
			ways = 1;
			for (int s = 0; s < n; s++)
				if (rr[s] > 0) {
					cnt++;
					ways = ways * rr[s] % MD;
				}
		} else {
			Arrays.fill(w2, 0);
			int s = ss[h];
			for (int h_ = 0; h_ < m; h_++) {
				int s_ = ss[h_];
				if (s_ == s)
					continue;
				int i_ = ii[h_], j_ = jj[h_];
				if (i_ < x) {
					int r = rr[s_];
					if (j_ > x)
						r--;
					if (r > 0)
						w2[s_] += r;
				}
			}
			cnt = rr[s] == 0 ? 1 : 2;
			ways = rr[s] == 0 ? 1 : rr[s];
			for (int s_ = 0; s_ < n; s_++) {
				if (s_ == s)
					continue;
				if (w2[s_] > 0) {
					cnt += 2;
					ways = ways * w2[s_] % MD;
				} else if (ll[s_] + rr[s_] - lr[s_] > 0) {
					cnt++;
					ways = ways * (ll[s_] + rr[s_]) % MD;
				}
			}
		}
		if (cnt_ < cnt) {
			cnt_ = cnt;
			sum = ways;
		} else if (cnt_ == cnt)
			sum += ways;
	}
	void main() {
		n = sc.nextInt();
		m = sc.nextInt();
		int[] ss_ = new int[n];
		for (int i = 0; i < n; i++)
			ss_[i] = sc.nextInt() - 1;
		ss = new int[m]; ii = new int[m]; jj = new int[m];
		for (int h = 0; h < m; h++) {
			int s = sc.nextInt() - 1;
			int k = sc.nextInt();
			int i, j, a;
			for (i = 0, a = 0; i < n; i++)
				if (ss_[i] == s && ++a == k)
					break;
			for (j = n - 1, a = 0; j >= 0; j--)
				if (ss_[j] == s && ++a == k)
					break;
			ss[h] = s; ii[h] = i; jj[h] = j;
		}
		ll = new int[n]; rr = new int[n]; lr = new int[n]; w2 = new int[n];
		update(-1, -1);
		for (int h = 0; h < m; h++)
			if (ii[h] < n)
				update(h, ii[h]);
		sum %= MD;
		println(cnt_ + " " + sum);
	}
}
