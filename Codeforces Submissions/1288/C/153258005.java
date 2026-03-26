import java.io.*;
import java.util.*;

public class CF_1288C {
	static long MOD = 1000000007;
	public static void main(String[] args) throws IOException {
		Kattio io = new Kattio();
		int n = io.nextInt();
		int m = io.nextInt();

		long[][] dp1 = new long[n+1][m];
		long[][] dp2 = new long[n+1][m];
		for (int i=1; i<=n; i++) {
			dp1[i][0] = 1;
			dp2[i][0] = 1;
		}
		for (int k=1; k<m; k++) {
			for (int i=1; i<=n; i++) {
				for (int j=1; j<=i; j++) {
					dp1[i][k] = (dp1[i][k] + dp1[j][k-1]) % MOD;
				}
				for (int j=i; j<=n; j++) {
					dp2[i][k] = (dp2[i][k] + dp2[j][k-1]) % MOD;
				}
			}
		}

		long ans = 0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (i > j) continue;
				ans = (ans + dp1[i][m-1] * dp2[j][m-1]) % MOD;
			}
		}
		System.out.println(ans);
	}

	static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;

		// standard input
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(new FileWriter(problemName + ".out"));
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}

		// returns null if no more input
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}

		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
}