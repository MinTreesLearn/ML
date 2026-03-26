import java.io.*;
import java.util.*;

public class D {

	static int dis(int l, int r, int[] a) {
		HashSet<Integer> set = new HashSet();
		for (int i = l; i < r; i++)
			set.add(a[i]);
		return set.size();
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt(), m = sc.nextInt();
		int[] min = new int[n + 1], max = new int[n + 1];
		ArrayList<Integer>[] occ = new ArrayList[n + 1], queries = new ArrayList[m];
		for (int i = 1; i <= n; i++) {
			min[i] = max[i] = i;
			occ[i] = new ArrayList();
		}

		FenwickTree tree = new FenwickTree(n+m+2);
		int[] a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
			min[a[i]] = 1;
			if (occ[a[i]].size() == 0) {
				max[a[i]] += tree.query(a[i] + 1, n);
				tree.update(a[i], 1);
			}
			occ[a[i]].add(i);
			queries[i] = new ArrayList();
		}

		for (int i = 1; i <= n; i++) {
			if (occ[i].size() == 0) {
				max[i] += tree.query(i + 1, n);
				continue;
			}
			occ[i].add(m);
			for (int j = 0; j + 1 < occ[i].size(); j++) {
				int l = occ[i].get(j), r = occ[i].get(j + 1) - 1;
//				max[i] = Math.max(max[i], dis(l, r, a));
				queries[r].add(l);
			}
		}
		Arrays.fill(tree.bit, 0);
		int[] last = new int[n + 1];
		Arrays.fill(last, -1);
		for (int r = 0; r < m; r++) {
			if (last[a[r]] != -1) {
				tree.update(last[a[r]] + 1, -1);
			}
			last[a[r]] = r;
			tree.update(r + 1, 1);
			for (int l : queries[r]) {
				max[a[l]] = Math.max(max[a[l]], tree.query(l + 1, r + 1));
			}

		}
		for (int i = 1; i <= n; i++) {
			out.println(min[i] + " " + max[i]);
		}
		out.close();

	}

	static class FenwickTree {
		int[] bit;

		FenwickTree(int n) {
			bit = new int[n + 1];
		}

		int query(int l, int r) {
			return query(r) - query(l - 1);
		}

		int query(int idx) {
			int ans = 0;
			while (idx > 0) {
				ans += bit[idx];
				idx -= idx & -idx;
			}
			return ans;
		}

		void update(int idx, int v) {
			while (idx < bit.length) {
				bit[idx] += v;
				idx += idx & -idx;
			}
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