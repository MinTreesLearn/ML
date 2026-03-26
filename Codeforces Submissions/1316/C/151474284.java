import java.io.*;
import java.util.*;

public class C {
	public static void main (String[] args) throws IOException {
		Kattio io = new Kattio();
		int n = io.nextInt();
		int m = io.nextInt();
		long p = io.nextLong();
		long[] a = new long[n];
		long[] b = new long[m];
		int inda = -1;
		int indb = -1;
		for (int i=0; i<n; i++) {
			a[i] = io.nextLong();
			if (a[i]%p != 0 && inda == -1) {
				inda = i;
			}
		}

		for (int i=0; i<m; i++) {
			b[i] = io.nextLong();
			if (b[i]%p != 0 && indb == -1) {
				indb = i;
			}
		}

		System.out.println(inda + indb);
		
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