import java.util.*;
import java.io.*;

public class C {
	FastScanner sc;
	PrintWriter out;

	StringBuilder sb;

	private void solve() {
		sc = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		int n = sc.nextInt();
		sb = new StringBuilder(sc.next());

		int ans = 0;
		int pos = 0;
		while ((pos = delPos()) != -1) {
			sb.deleteCharAt(pos);
			ans++;
		}

		out.println(ans);

		sc.close();
		out.close();
	}

	boolean canDelete(int pos) {
		int c = sb.charAt(pos);
		return (pos > 0 && sb.charAt(pos-1) == c-1 || pos < sb.length()-1 && sb.charAt(pos+1) == c-1);
	}

	int delPos() {
		int pos = -1;
		int max = 0;

		for (int i = 0; i < sb.length(); i++) {
			if (sb.charAt(i) > max && canDelete(i)) {
				max = sb.charAt(i);
				pos = i;
			}
		}

		return pos;
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
			new C().solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}