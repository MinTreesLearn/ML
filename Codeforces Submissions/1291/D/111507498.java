// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1291D extends PrintWriter {
	CF1291D() { super(System.out); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1291D o = new CF1291D(); o.main(); o.flush();
	}

	static final int A = 26;
	void main() {
		byte[] cc = sc.next().getBytes();
		int n = cc.length;
		int[][] kk = new int[A][n + 1];
		for (int i = 1; i <= n; i++) {
			int a = cc[i - 1] - 'a';
			kk[a][i] = 1;
		}
		for (int a = 0; a < A; a++)
			for (int i = 1; i <= n; i++)
				kk[a][i] += kk[a][i - 1];
		int q = sc.nextInt();
		while (q-- > 0) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			if (l == r || cc[l - 1] != cc[r - 1]) {
				println("Yes");
				continue;
			}
			int cnt = 0;
			for (int a = 0; a < A; a++)
				if (kk[a][r] != kk[a][l - 1])
					cnt++;
			println(cnt > 2 ? "Yes" : "No");
		}
	}
}
