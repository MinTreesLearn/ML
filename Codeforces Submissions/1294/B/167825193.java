import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class C {

	static long dfs(int source, int parent, long x, ArrayList<ArrayList<Integer>> adj, long[] arr) {
		long s = arr[source];
		for (Integer i : adj.get(source)) {
			if (i != parent) {
				s += dfs(i, source, x, adj, arr);
			}
		}
		return Math.max(s, -x);
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	static long gcd(long n, long m) {
		if (m == 0)
			return n;
		return gcd(m, n % m);
	}

	static long lcm(long n, long m) {
		return (n * m) / gcd(n, m);
	}

	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		FastReader sc = new FastReader();
		StringBuilder str = new StringBuilder();
		int t = sc.nextInt();
		for (int xx = 0; xx < t; xx++) {
			int n = sc.nextInt();
			Pair[] arr = new Pair[n];
			for (int i = 0; i < n; i++) {
				arr[i] = new Pair(sc.nextInt(), sc.nextInt());
			}
			Arrays.sort(arr, (p1, p2) -> {
				if (p1.x == p2.x)
					return Integer.compare(p1.y, p2.y);
				return Integer.compare(p1.x, p2.x);
			});
			StringBuilder st = new StringBuilder();
			int currx = 0;
			int curry = 0;
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				if (arr[i].x < currx || arr[i].y < curry) {
					ok = false;
					break;
				}
				for (int j = currx; j < arr[i].x; j++)
					st.append("R");
				for (int j = curry; j < arr[i].y; j++)
					st.append("U");
				currx = arr[i].x;
				curry = arr[i].y;
			}
			if (ok) {
				str.append("YES" + "\n");
				str.append(st + "\n");
			} else
				str.append("NO" + "\n");
		}
		System.out.println(str);
	}
}