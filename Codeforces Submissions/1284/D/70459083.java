import java.io.*;
import java.util.*;

public class A {
	static int INF = (int) 1e9;

	static boolean solve(int[][] a) {
		int n = a.length;
		Arrays.sort(a, (x, y) -> x[0] - y[0]);
		int[] buildTree = new int[n];
		for (int i = 0; i < n; i++)
			buildTree[i] = a[i][2];
		SegmentTree max = new SegmentTree(buildTree);
		for (int i = 0; i < n; i++)
			buildTree[i] = -a[i][3];
		SegmentTree min = new SegmentTree(buildTree);
		for (int i = 0; i < n; i++) {
			int lo = i, hi = n - 1;
			int intersect = i;
			while (lo <= hi) {
				int mid = lo + hi >> 1;
				if (a[mid][0] <= a[i][1]) {
					intersect = mid;
					lo = mid + 1;
				} else
					hi = mid - 1;
			}
			if (intersect == i)
				continue;
			int maxL = max.query(i + 1, intersect), minR = -min.query(i + 1, intersect);
			if (maxL > a[i][3] || minR < a[i][2])
				return false;

		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int[][] a = new int[n][4];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
				a[i][j] = sc.nextInt();

		boolean ans = solve(a);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				int tmp = a[i][j];
				a[i][j] = a[i][j + 2];
				a[i][j + 2] = tmp;
			}
		}
		ans &= solve(a);
		out.println(ans ? "YES" : "NO");
		out.close();

	}

	static class SegmentTree {
		int n, a[], max[];

		SegmentTree(int[] x) {
			a = x;
			n = a.length;
			max = new int[4 * n];
			build(1, 0, n - 1);
		}

		void build(int node, int tl, int tr) {
			if (tl == tr)
				max[node] = a[tl];
			else {
				int mid = tl + tr >> 1, left = node << 1, right = left | 1;
				build(left, tl, mid);
				build(right, mid + 1, tr);
				max[node] = Math.max(max[left], max[right]);
			}
		}

		int query(int l, int r) {
			return query(1, 0, n - 1, l, r);
		}

		int query(int node, int tl, int tr, int l, int r) {
			if (tr < l || r < tl)
				return -INF;
			if (tl >= l && tr <= r)
				return max[node];
			int mid = tl + tr >> 1, left = node << 1, right = left | 1;
			return Math.max(query(left, tl, mid, l, r), query(right, mid + 1, tr, l, r));
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