// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1293D extends PrintWriter {
	CF1293D() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1293D o = new CF1293D(); o.main(); o.flush();
	}

	static final int N = 64;
	void main() {
		long x0 = sc.nextLong();
		long y0 = sc.nextLong();
		long ax = sc.nextLong();
		long ay = sc.nextLong();
		long bx = sc.nextLong();
		long by = sc.nextLong();
		long xs = sc.nextLong();
		long ys = sc.nextLong();
		long t = sc.nextLong();
		long[] xx = new long[N];
		long[] yy = new long[N];
		int n = 0;
		for (long x = x0, y = y0; x <= xs + t && y <= ys + t; x = x * ax + bx, y = y * ay + by) {
			xx[n] = x; yy[n] = y;
			n++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				out:
					for (int k = j; k < n; k++) {
						long x = xs, y = ys, s = 0;
						for (int h = j; h >= i; h--) {
							long d = Math.abs(x - xx[h]) + Math.abs(y - yy[h]);
							if ((s += d) > t)
								continue out;
							x = xx[h]; y = yy[h];
						}
						for (int h = j + 1; h <= k; h++) {
							long d = Math.abs(x - xx[h]) + Math.abs(y - yy[h]);
							if ((s += d) > t)
								continue out;
							x = xx[h]; y = yy[h];
						}
						ans = Math.max(ans, k - i + 1);
					}
		println(ans);
	}
}
