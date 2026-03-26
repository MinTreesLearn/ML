// practice with rainboy
import java.io.*;
import java.util.*;

public class CF1288E extends PrintWriter {
	CF1288E() { super(System.out); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1288E o = new CF1288E(); o.main(); o.flush();
	}

	int[] ft;
	void update(int i, int n, int x) {
		while (i < n) {
			ft[i] += x;
			i |= i + 1;
		}
	}
	int query(int i) {
		int x = 0;
		while (i >= 0) {
			x += ft[i];
			i &= i + 1; i--;
		}
		return x;
	}
	void main() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] ii = new int[m];
		for (int h = 0; h < m; h++)
			ii[h] = sc.nextInt() - 1;
		int[] imin = new int[n];
		int[] imax = new int[n];
		for (int i = 0; i < n; i++)
			imin[i] = imax[i] = i;
		for (int h = 0; h < m; h++)
			imin[ii[h]] = 0;
		int[] hh = new int[n];
		Arrays.fill(hh, m);
		for (int h = m - 1; h >= 0; h--)
			hh[ii[h]] = h;
		ft = new int[m];
		for (int i = n - 1; i >= 0; i--) {
			imax[i] += query(hh[i] - 1);
			update(hh[i], m, 1);
		}
		Arrays.fill(ft, 0);
		Arrays.fill(hh, m);
		for (int h = m - 1; h >= 0; h--) {
			int i = ii[h];
			imax[i] = Math.max(imax[i], query(hh[i] - 1));
			update(hh[i], m, -1);
			hh[i] = h;
			update(hh[i], m, 1);
		}
		for (int i = 0; i < n; i++)
			println((imin[i] + 1) + " " + (imax[i] + 1));
	}
}
