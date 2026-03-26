// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1287C extends PrintWriter {
	CF1287C() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1287C o = new CF1287C(); o.main(); o.flush();
	}

	int sum(int[] aa, int n) {
		int s = 0;
		for (int i = 0; i < n; i++)
			s += aa[i];
		return s;
	}
	void reverse(int[] aa, int n) {
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			int tmp = aa[i]; aa[i] = aa[j]; aa[j] = tmp;
		}
	}
	int solve(int k, int[] qu, int cnt) {
		int ans = 0;
		while (k > 0 && cnt > 0) {
			ans++;
			if (k >= qu[cnt - 1])
				k -= qu[--cnt];
			else
				k = 0;
		}
		return ans;
	}
	int solve_(int k0, int[] qu1, int cnt1, int[] qu11, int cnt11) {
		Arrays.sort(qu1, 0, cnt1);
		Arrays.sort(qu11, 0, cnt11);
		int ans;
		if (cnt1 >= 1 && k0 <= qu1[cnt1 - 1])
			ans = 1;
		else if (cnt1 == 2 && k0 <= qu1[0] + qu1[1])
			ans = 2;
		else {
			ans = k0 * 2;
			int s = sum(qu11, cnt11);
			if (k0 <= s)
				ans = Math.min(ans, solve(k0, qu11, cnt11) * 2);
			if (cnt1 >= 1 && k0 - qu1[0] <= s)
				ans = Math.min(ans, 1 + solve(k0 - qu1[0], qu11, cnt11) * 2);
			if (cnt1 == 2 && k0 - qu1[1] <= s)
				ans = Math.min(ans, 1 + solve(k0 - qu1[1], qu11, cnt11) * 2);
			if (cnt1 == 2 && k0 - qu1[0] - qu1[1] <= s)
				ans = Math.min(ans, 2 + solve(k0 - qu1[0] - qu1[1], qu11, cnt11) * 2);
		}
		return ans;
	}
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
		if (k0 + k1 == n) {
			println(n == 1 ? 0 : 1);
			return;
		}
		int[] qu00 = new int[n]; int cnt00 = 0;
		int[] qu11 = new int[n]; int cnt11 = 0;
		int[] qu01 = new int[n]; int cnt01 = 0;
		int[] qu0 = new int[2]; int cnt0 = 0;
		int[] qu1 = new int[2]; int cnt1 = 0;
		int ans = 0, i_ = -1;
		for (int i = 0; i < n; i++) {
			if (pp[i] == -1)
				continue;
			int g = i - i_ - 1;
			if (g > 0) {
				if (pp[i] == 0) {
					if (i_ == -1)
						qu0[cnt0++] = g;
					else if (pp[i_] == pp[i])
						qu00[cnt00++] = g;
					else
						qu01[cnt01++] = g;
				} else {
					if (i_ == -1)
						qu1[cnt1++] = g;
					else if (pp[i_] == pp[i])
						qu11[cnt11++] = g;
					else
						qu01[cnt01++] = g;
				}
			}
			if (i_ != -1 && pp[i_] != pp[i])
				ans++;
			i_ = i;
		}
		if (k0 + k1 == 0) {
			println(ans);
			return;
		}
		int g = n - i_ - 1;
		if (g > 0) {
			if (pp[i_] == 0)
				qu0[cnt0++] = g;
			else
				qu1[cnt1++] = g;
		}
		if ((k0 -= sum(qu00, cnt00) + sum(qu0, cnt0)) >= 0) {
			if ((k0 -= sum(qu01, cnt01)) > 0)
				ans += solve_(k0, qu1, cnt1, qu11, cnt11);
		} else if ((k1 -= sum(qu11, cnt11) + sum(qu1, cnt1)) >= 0) {
			if ((k1 -= sum(qu01, cnt01)) > 0)
				ans += solve_(k1, qu0, cnt0, qu00, cnt00);
		}
		println(ans);
	}
}
