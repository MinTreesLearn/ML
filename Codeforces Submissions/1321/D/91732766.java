// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1321D extends PrintWriter {
	CF1321D() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1321D o = new CF1321D(); o.main(); o.flush();
	}

	int[] eo; int[][] ej;
	int[] fo; int[][] fj;
	int[] dd;
	void init(int n) {
		eo = new int[n]; ej = new int[n][2];
		fo = new int[n]; fj = new int[n][2];
		dd = new int[n];
	}
	void append(int[] oo, int[][] oj, int i, int j) {
		int o = oo[i]++;
		if (o >= 2 && (o & o - 1) == 0)
			oj[i] = Arrays.copyOf(oj[i], o << 1);
		oj[i][o] = j;
	}
	void main() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		init(n);
		while (m-- > 0) {
			int i = sc.nextInt() - 1;
			int j = sc.nextInt() - 1;
			append(eo, ej, i, j);
			append(fo, fj, j, i);
		}
		int k = sc.nextInt();
		int[] ii = new int[k];
		for (int h = 0; h < k; h++)
			ii[h] = sc.nextInt() - 1;
		int[] qu = new int[n]; int head = 0, cnt = 0;
		Arrays.fill(dd, n);
		int t = ii[k - 1];
		dd[t] = 0; qu[head + cnt++] = t;
		while (cnt > 0) {
			int i = qu[head++]; cnt--;
			int d = dd[i] + 1;
			for (int o = 0; o < fo[i]; o++) {
				int j = fj[i][o];
				if (dd[j] == n) {
					dd[j] = d; qu[head + cnt++] = j;
				}
			}
		}
		int kmin = 0, kmax = 0;
		for (int h = 0; h + 1 < k; h++) {
			int i = ii[h], j = ii[h + 1];
			if (dd[i] == dd[j] + 1) {
				m = 0;
				for (int o = 0; o < eo[i]; o++) {
					j = ej[i][o];
					if (dd[i] == dd[j] + 1)
						m++;
				}
				if (m >= 2)
					kmax++;
			} else {
				kmin++;
				kmax++;
			}
		}
		println(kmin + " " + kmax);
	}
}
