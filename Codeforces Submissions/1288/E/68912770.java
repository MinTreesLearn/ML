import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Indrajit Sinha
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		EMessengerSimulator solver = new EMessengerSimulator();
		solver.solve(1, in, out);
		out.close();
	}

	static class EMessengerSimulator {
		int n;
		PrintWriter out;
		InputReader in;
		final Comparator<Query> com = new Comparator<Query>() {
			public int compare(Query x, Query y) {
				int xx = Integer.compare(x.r, y.r);
				if (xx == 0)
					return Integer.compare(x.l, y.l);
				return xx;
			}
		};

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int t, i, j, tt, k;
			this.out = out;
			this.in = in;
			n = in.nextInt();
			int m = in.nextInt();
			int a[] = new int[m];
			int[] mn, mx;
			mn = new int[n];
			mx = new int[n];
			for (i = 0; i < n; i++) {
				mn[i] = i;
				mx[i] = i;
			}
			for (i = 0; i < m; i++) {
				a[i] = in.nextInt() - 1;
				mn[a[i]] = 0;
			}
			ArrayList<Integer> ar[] = new ArrayList[n];
			for (i = 0; i < n; i++) {
				ar[i] = new ArrayList<>();
			}
			for (i = 0; i < m; i++) {
				ar[a[i]].add(i);
			}
			TreeSet<Integer> ts = new TreeSet<>();
			SegmenTree sg = new SegmenTree();
			sg.build(n);
			for (i = 0; i < m; i++) {
				if (ts.contains(a[i]))
					continue;
				mx[a[i]] = Math.max(mx[a[i]], a[i] + sg.query(a[i] + 1, n));
				ts.add(a[i]);
				sg.updateTreeNode(a[i], 1);
			}
			for (i = 0; i < n; i++) {
				if (ar[i].size() == 0) {
					mx[i] = Math.max(mx[i], i + sg.query(i + 1, n));
				}
			}
			ArrayList<Query> queries = new ArrayList<>();
			for (i = 0; i < n; i++) {
				if (i == 98) {
					int ou = 0;
				}
				for (j = 1; j < ar[i].size(); j++) {
					int l = ar[i].get(j - 1) + 1;
					int r = ar[i].get(j) - 1;
					if (l <= r) {
						queries.add(new Query(l, r, i));
					}
					if (j == ar[i].size() - 1) {
						l = ar[i].get(j) + 1;
						r = m - 1;
						if (l <= r)
							queries.add(new Query(l, r, i));
					}
				}
				if (ar[i].size() == 1) {
					int l = ar[i].get(0) + 1;
					int r = m - 1;
					if (l <= r)
						queries.add(new Query(l, r, i));
				}
			}
			Collections.sort(queries, com);
			int bit[] = new int[m + 1];
			int last_visit[] = new int[n + 5];
			Arrays.fill(last_visit, -1);
			int query_counter = 0, q = queries.size();
			for (i = 0; i < m; i++) {
				if (last_visit[a[i]] != -1)
					update(last_visit[a[i]] + 1, -1, bit, m);
				last_visit[a[i]] = i;
				update(i + 1, 1, bit, m);
				while (query_counter < q && queries.get(query_counter).r == i) {
					int an = query(queries.get(query_counter).r + 1, bit, m) - query(queries.get(query_counter).l, bit, m);
					int idx = queries.get(query_counter).idx;
					mx[idx] = Math.max(mx[idx], an);
					query_counter++;
				}
			}
			for (i = 0; i < n; i++) {
				pn((mn[i] + 1) + " " + (mx[i] + 1));
			}

		}

		void update(int idx, int val, int bit[], int n) {
			for (; idx <= n; idx += idx & -idx)
				bit[idx] += val;
		}

		int query(int idx, int bit[], int n) {
			int sum = 0;
			for (; idx > 0; idx -= idx & -idx)
				sum += bit[idx];
			return sum;
		}

		void pn(String zx) {
			out.println(zx);
		}

		class Query {
			int l;
			int r;
			int idx;

			Query(int a, int b, int c) {
				l = a;
				r = b;
				idx = c;
			}

		}

		class SegmenTree {
			int n;
			int[] tree;

			void build(int x) {
				n = x;
				tree = new int[2 * n + 1];
			}

			void updateTreeNode(int p, int value) {
				tree[p + n] = value;
				p = p + n;
				for (int i = p; i > 1; i >>= 1)
					tree[i >> 1] = tree[i] + tree[i ^ 1];
			}

			int query(int l, int r) {
				int res = 0;
				for (l += n, r += n; l < r;
				     l >>= 1, r >>= 1) {
					if ((l & 1) > 0)
						res += tree[l++];

					if ((r & 1) > 0)
						res += tree[--r];
				}

				return res;
			}

		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1) {
				throw new UnknownError();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new UnknownError();
				}
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public String next() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));

			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}

