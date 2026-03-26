import java.io.*;
import java.util.*;

public class B {

	static ArrayList<Integer>[] adj;

	static ArrayList<Integer> subtree;

	static int[] ans, c;

	static boolean solve(int u) {
		boolean ret = true;
		for (int v : adj[u]) {
			ret &= solve(v);
		}
		subtree.clear();
		dfs2(u, true);
		Collections.sort(subtree, (x, y) -> ans[x] - ans[y]);
		if (c[u] > subtree.size()) {
			return false;
		}
		if (c[u] == 0)
			ans[u] = 1;
		else {
			ans[u] = ans[subtree.get(c[u] - 1)] + 1;

		}
		for (int x = 0; x < adj.length; x++)
			if (ans[x] >= ans[u] && x != u)
				ans[x]++;
		return ret;

	}

	static void dfs2(int u, boolean start) {
		if (!start)
			subtree.add(u);
		for (int v : adj[u])

			dfs2(v, false);
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt(), root = -1;
		subtree = new ArrayList();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList();
		c = new int[n];
		ans = new int[n];
		for (int i = 0; i < n; i++) {
			int p = sc.nextInt() - 1;
			c[i] = sc.nextInt();
			if (p != -1) {
				adj[p].add(i);
			} else
				root = i;

		}
		if (solve(root)) {
			out.println("YES");
			for (int x : ans)
				out.print(x + " ");

		} else
			out.println("NO");

		out.close();

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