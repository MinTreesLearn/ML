import java.util.*;
import java.io.*;

public class A {
	FastScanner sc;
	PrintWriter out;

	private void solve() {
		sc = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		int n = sc.nextInt();
		
		var a = new int[n];
		var b = new int[n];

		int as = 0;
		int bs = 0;

		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			as += a[i];
		}

		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
			bs += b[i];
		}

		int unq = 0;
		int cod = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] == 1 && b[i] == 0)
				unq++;

			if (b[i] == 1 && a[i] == 0) {
				cod++;
			}
		}

		if (unq == 0) {
			out.println(-1);
			out.flush();
			return;
		}

		int ans = cod / unq;
		ans++;

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
			new A().solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}