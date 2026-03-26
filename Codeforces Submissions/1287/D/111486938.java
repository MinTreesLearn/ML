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
	boolean[] used;
	void append(int i, int j) {
		int o = eo[i]++;
		if (o >= 2 && (o & o - 1) == 0)
			ej[i] = Arrays.copyOf(ej[i], o << 1);
		ej[i][o] = j;
	}
	boolean dfs(int i) {
		int c = cc[i];
		sz[i] = 1;
		for (int a = 1; a <= n; a++)
			if (!used[a] && c-- == 0) {
				used[a] = true;
				aa[i] = a;
				for (int o = eo[i]; o-- > 0; ) {
					int j = ej[i][o];
					if (!dfs(j))
						return false;
					sz[i] += sz[j];
				}
				return cc[i] < sz[i];
			}
		return false;
	}
	void main() {
		n = sc.nextInt();
		eo = new int[n]; ej = new int[n][2];
		cc = new int[n]; sz = new int[n]; aa = new int[n];
		used = new boolean[n + 1];
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
