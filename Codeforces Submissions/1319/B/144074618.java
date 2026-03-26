import java.util.*;
import java.io.*;

public class B {
	FastScanner sc;
	PrintWriter out;

	private void solve() {
		sc = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		int n = sc.nextInt();
		var b = new int[n];
		var d = new int[n];

		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
			d[i] = i - b[i];
		}

		var mp = new HashMap<Integer, Long>();
		long ans = Long.MIN_VALUE;

		for (int i = 0; i < n; i++) {
			int x = d[i];
			long s = mp.getOrDefault(x, 0L);
			s += b[i];
			mp.put(x, s);

			ans = Math.max(ans, s);
		}

		out.println(ans);

		sc.close();
		out.close();
	}

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(InputStream inputStream) {
			br = new BufferedReader(new InputStreamReader(inputStream));
		}

		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				e.printStackTrace();
			}

			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public void close() {
			try {
				br.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		try {
			new B().solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}