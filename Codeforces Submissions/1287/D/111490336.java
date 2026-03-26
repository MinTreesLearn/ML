// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1287D extends PrintWriter {
	CF1287D() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1287D o = new CF1287D(); o.main(); o.flush();
	}

	int n;
	int[] eo; int[][] ej;
	int[] cc, sz, aa;
	void append(int i, int j) {
		int o = eo[i]++;
		if (o >= 2 && (o & o - 1) == 0)
			ej[i] = Arrays.copyOf(ej[i], o << 1);
		ej[i][o] = j;
	}
	int[] st; int n_;
	void pul(int i) {
		st[i] = st[i << 1] + st[i << 1 | 1];
	}
	void build() {
		n_ = 1;
		while (n_ <= n)
			n_ <<= 1;
		st = new int[n_ * 2];
		for (int i = 1; i <= n; i++)
			st[n_ + i] = 1;
		for (int i = n_ - 1; i > 0; i--)
			pul(i);
	}
	void update(int i, int x) {
		st[i += n_] += x;
		while (i > 1)
			pul(i >>= 1);
	}
	int query_(int c) {
		if (c > st[1])
			return n + 1;
		int i = 1;
		while (i < n_) {
			i <<= 1;
			if (c > st[i]) {
				c -= st[i];
				i |= 1;
			}
		}
		return i - n_;
	}
	boolean dfs(int i) {
		int a = query_(cc[i] + 1);
		if (a > n)
			return false;
		update(a, -1);
		aa[i] = a;
		sz[i] = 1;
		for (int o = eo[i]; o-- > 0; ) {
			int j = ej[i][o];
			if (!dfs(j))
				return false;
			sz[i] += sz[j];
		}
		return cc[i] < sz[i];
	}
	void main() {
		n = sc.nextInt();
		eo = new int[n]; ej = new int[n][2];
		cc = new int[n]; sz = new int[n]; aa = new int[n];
		build();
		int r = -1;
		for (int j = 0; j < n; j++) {
			int i = sc.nextInt() - 1;
			int c = sc.nextInt();
			if (i == -1)
				r = j;
			else
				append(i, j);
			cc[j] = c;
		}
		if (dfs(r)) {
			println("YES");
			for (int i = 0; i < n; i++)
				print(aa[i] + " ");
			println();
		} else
			println("NO");
	}
}
