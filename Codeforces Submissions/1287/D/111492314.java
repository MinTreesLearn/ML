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
	int[] zz, ll, rr, xx, yy; int u_, l_, r_, $;
	Random rand = new Random();
	int node(int x) {
		int u = ++$;
		zz[u] = rand.nextInt();
		xx[u] = x; yy[u] = 1;
		return u;
	}
	void pul(int u) {
		yy[u] = 1 + yy[ll[u]] + yy[rr[u]];
	}
	void split(int u, int x) {
		if (u == 0) {
			u_ = l_ = r_ = 0;
			return;
		}
		if (xx[u] < x) {
			split(rr[u], x);
			rr[u] = l_; l_ = u;
		} else if (xx[u] > x) {
			split(ll[u], x);
			ll[u] = r_; r_ = u;
		} else {
			u_ = u; l_ = ll[u]; r_ = rr[u];
			ll[u] = rr[u] = 0;
		}
		pul(u);
	}
	int merge(int u, int v) {
		if (u == 0)
			return v;
		if (v == 0)
			return u;
		int w;
		if (zz[u] <= zz[v]) {
			rr[u] = merge(rr[u], v);
			w = u;
		} else {
			ll[v] = merge(u, ll[v]);
			w = v;
		}
		pul(w);
		return w;
	}
	void add(int x) {
		split(u_, x);
		u_ = merge(l_, merge(node(x), r_));
	}
	void remove(int x) {
		split(u_, x);
		u_ = merge(l_, r_);
	}
	void build() {
		zz = new int[1 + n]; ll = new int[1 + n]; rr = new int[1 + n];
		xx = new int[1 + n]; yy = new int[1 + n];
		for (int a = 1; a <= n; a++)
			add(a);
	}
	int query(int c) {
		if (c > yy[u_])
			return n + 1;
		for (int u = u_, v; ; u = v) {
			v = ll[u];
			int y = yy[v] + 1;
			if (c == y)
				return xx[u];
			if (c > y) {
				c -= y;
				v = rr[u];
			}
		}
	}
	boolean dfs(int i) {
		int a = query(cc[i] + 1);
		if (a > n)
			return false;
		remove(a);
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
