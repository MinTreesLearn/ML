// practice with kaiboy
import java.io.*;
import java.util.*;

public class CF1285D extends PrintWriter {
	CF1285D() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		CF1285D o = new CF1285D(); o.main(); o.flush();
	}

	int[] aa;
	int solve(int l, int r, int h) {
		if (l == r || h == -1)
			return 0;
		int m = l;
		while (m < r && (aa[m] & 1 << h) == 0)
			m++;
		if (m == l || m == r)
			return solve(l, r, h - 1);
		return Math.min(solve(l, m, h - 1), solve(m, r, h - 1)) | 1 << h;
	}
	void main() {
		int n = sc.nextInt();
		aa = new int[n];
		for (int i = 0; i < n; i++)
			aa[i] = sc.nextInt();
		aa = Arrays.stream(aa).boxed().sorted().mapToInt($->$).toArray();
		println(solve(0, n, 29));
	}
}
