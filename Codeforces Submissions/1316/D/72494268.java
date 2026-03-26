import java.io.*;
import java.util.*;

public class E {

	static int n;
	static int[] di = { -1, 1, 0, 0 };
	static int[] dj = { 0, 0, -1, 1 };

	static boolean valid(int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < n;
	}

	static char empty = '#';

	static boolean eq(int[] a, int[] b) {
		return a[0] == b[0] && a[1] == b[1];
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		int[][][] a = new int[n][n][2];
		char[][] ans = new char[n][n];
		Queue<int[]> q = new LinkedList();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				ans[i][j] = empty;
				for (int k = 0; k < 2; k++)
					a[i][j][k] = sc.nextInt() - 1;
				if (a[i][j][0] == i && a[i][j][1] == j) {
					q.add(new int[] { i, j });
					ans[i][j] = 'X';
				}
			}
		char[] dir = "UDLR".toCharArray();

		while (!q.isEmpty()) {
			int[] curr = q.poll();
			int i = curr[0], j = curr[1];
			for (int k = 0; k < 4; k++) {
				int i2 = i + di[k], j2 = j + dj[k];
				if (!valid(i2, j2) || ans[i2][j2] != empty)
					continue;
				if (eq(a[i2][j2], a[i][j])) {
					ans[i2][j2] = dir[k ^ 1];
					q.add(new int[] { i2, j2 });
				}
			}

		}
		boolean ok = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (ans[i][j] != empty)
					continue;
				if (a[i][j][0] != -2) {
					ok = false;
					break;
				}
				int deg = 0;
				for (int k = 0; k < 4; k++) {
					int i2 = i + di[k], j2 = j + dj[k];
					if (!valid(i2, j2) || !eq(a[i2][j2], a[i][j]))
						continue;
					deg++;
					ans[i][j] = dir[k];
					if (ans[i2][j2] == empty) {
						ans[i2][j2] = dir[k ^ 1];

					}
					break;
				}
				ok&=deg>0;

			}

		if (!ok) {
			System.out.println("INVALID");
			return;
		}
		out.println("VALID");
		for (char[] x : ans)
			out.println(x);
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

		int[] nxtArr(int n) throws IOException {
			int[] ans = new int[n];
			for (int i = 0; i < n; i++)
				ans[i] = nextInt();
			return ans;
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