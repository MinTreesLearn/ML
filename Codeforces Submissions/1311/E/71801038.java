import java.io.*;
import java.util.*;

public class CF1311E extends PrintWriter {
	CF1311E() { super(System.out); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1311E o = new CF1311E(); o.main(); o.flush();
	}

	void main() {
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int s = sc.nextInt();
			int[] kk = new int[n];
			if (s > n * (n - 1) / 2) {
				println("NO");
				continue;
			}
			for (int d = 0, k = n; d < n && k > 0; d++)
				while (k > 0 && kk[d] < 1 << d) {
					k--; kk[d]++;
					s -= d;
				}
			if (s < 0) {
				println("NO");
				continue;
			}
			println("YES");
			while (s > 0)
				for (int d = 1; d + 1 < n && s > 0; d++)
					while (s > 0 && kk[d + 1] + 1 <= (kk[d] - 1) * 2) {
						s--; kk[d + 1]++; kk[d]--;
					}
			for (int d = 1, i = 1, j = 2; d < n; d++) {
				int i_ = j;
				while (kk[d]-- > 0) {
					print(i + " "); j++;
					if (kk[d]-- > 0) {
						print(i + " "); j++;
					}
					i++;
				}
				i = i_;
			}
			println();
		}
	}
}
