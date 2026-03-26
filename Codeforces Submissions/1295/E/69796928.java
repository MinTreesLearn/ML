import java.io.*;
import java.util.*;

public class A {

	static int n;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		int p[] = new int[n], c[] = new int[n + 1];
		for (int i = 0; i < n; i++)
			p[i] = sc.nextInt();
		for (int i = 0; i < n; i++)
			c[p[i]] = sc.nextInt();
		SegmentTree st = new SegmentTree();
		for (int i = 1; i <= n; i++)
			st.update(i, n, c[i]);
		long ans = Long.MAX_VALUE;
		for (int k = 0; k + 1 < n; k++) {
			st.update(0, p[k] - 1, c[p[k]]);
			st.update(p[k], n, -c[p[k]]);

			ans = Math.min(ans, st.query(0, n));

		}
		System.out.println(ans);

		out.close();

	}

	static class SegmentTree {
		long[] min, lazy;

		SegmentTree() {
			min = new long[4 * n];
			lazy = new long[4 * n];
		}

		void update(int l, int r, int v) {
			update(1, 0, n, l, r, v);
		}

		void update(int node, int tl, int tr, int l, int r, int v) {
			if (tr < l || r < tl)
				return;
			if (tl >= l && tr <= r) {
				lazy[node] += v;
				min[node] += v;
				return;
			}
			int mid = tl + tr >> 1, left = node << 1, right = left | 1;
			propagate(node);
			update(left, tl, mid, l, r, v);
			update(right, mid + 1, tr, l, r, v);
			min[node] = Math.min(min[left], min[right]);
		}

		long query(int l, int r) {
			return query(1, 0, n, l, r);

		}

		long query(int node, int tl, int tr, int l, int r) {
			if (r < tl || tr < l)
				return Long.MAX_VALUE;
			if (tl >= l && tr <= r)
				return min[node];
			int mid = tl + tr >> 1, left = node << 1, right = left | 1;

			propagate(node);
			return Math.min(query(left, tl, mid, l, r), query(right, mid + 1, tr, l, r));
		}

		private void propagate(int node) {
			// TODO Auto-generated method stub
			int child = node << 1;
			lazy[child] += lazy[node];
			min[child] += lazy[node];
			child++;
			lazy[child] += lazy[node];
			min[child] += lazy[node];
			lazy[node] = 0;
		}
	}

	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		Scanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		Scanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		String nextLine() throws IOException {
			return br.readLine();
		}

		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		boolean ready() throws IOException {
			return br.ready();
		}

	}

	static void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	static void shuffle(int[] a) {
		int n = a.length;
		Random rand = new Random();
		for (int i = 0; i < n; i++) {
			int tmpIdx = rand.nextInt(n);
			int tmp = a[i];
			a[i] = a[tmpIdx];
			a[tmpIdx] = tmp;
		}
	}

}