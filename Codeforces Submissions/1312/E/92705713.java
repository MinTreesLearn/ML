import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) throws Exception {
		int n = i();
		int[] a = a(n);
		int[][] reduce = new int[n][n];
		for (int i = 0; i < n; i++) {
			reduce[i][i] = a[i];
		}
		for (int l = 2; l <= n; l++) {
			for (int i = 0; i + l - 1 < n; i++) {
				int j = i + l - 1;
				for (int k = i; k < j; k++) {
					if (reduce[i][k] != 0 && reduce[k + 1][j] != 0 && reduce[i][k] == reduce[k + 1][j]) {
						reduce[i][j] = reduce[i][k] + 1;
						break;
					}
				}
			}
		}

		int[] ans = new int[n];
		for (int i = 0; i < n; i++) {
			ans[i] = i + 1;
			for (int j = 0; j <= i; j++) {
				if (reduce[j][i] > 0) {
					ans[i] = Math.min(j == 0 ? 1 : ans[j - 1] + 1, ans[i]);
				}
			}
		}

		out.println(ans[n - 1]);
		
		finish();
	}

	static BufferedReader in;
	static StringTokenizer st = new StringTokenizer("");
	static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static {
		try {
			in = new BufferedReader(new FileReader("test.in"));
		} catch (Exception e) {
			in = new BufferedReader(new InputStreamReader(System.in));
		}
	}
	static void check() throws Exception {
		while (!st.hasMoreTokens()) st = new StringTokenizer(in.readLine());
	}
	static int i() throws Exception {check(); return Integer.parseInt(st.nextToken());}
	static String s() throws Exception {check(); return st.nextToken();}
	static double d() throws Exception {check(); return Double.parseDouble(st.nextToken());}
	static long l() throws Exception {check(); return Long.parseLong(st.nextToken());}
	static int[] a(int n) throws Exception {check(); int[] b = new int[n]; for (int i = 0; i < n; i++) b[i] = i(); return b;}
	static void finish(boolean b, Object o) {if (b) finish(o);}
	static void finish(Object o) {out.println(o); finish();}
	static void finish() {out.close(); System.exit(0);}
}
