import java.io.*;
import java.util.*;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);
	static int n, grid[][], dx[], dy[];
	static Pair adj[][];

	static boolean valid(int r, int c) {
		return r >= 0 && r < n && c >= 0 && c < n;
	}

	static boolean dfs(int r, int c) {
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			if (valid(nr, nc) && adj[nr][nc].r == -2) {
				grid[r][c] = i;
				return true;
			}
		}
		return false;
	}

	static void dfs2(int r, int c) {
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			if (valid(nr, nc) && grid[nr][nc] == -1) {
				if (adj[nr][nc].r == adj[r][c].r && adj[nr][nc].c == adj[r][c].c) {
					grid[nr][nc] = (i + 2) % 4;
					dfs2(nr, nc);
				}
			}
		}
	}

	static void bfs(Pair p) {
		Queue<Pair> q = new LinkedList<>();
		q.add(p);
		while (!q.isEmpty()) {
			Pair u = q.poll();
			for (int i = 0; i < 4; i++) {
				int nr = u.r + dx[i], nc = u.c + dy[i];
				if (valid(nr, nc) && grid[nr][nc] == -1) {
					if (adj[nr][nc].r == adj[u.r][u.c].r && adj[nr][nc].c == adj[u.r][u.c].c) {
						grid[nr][nc] = (i + 2) % 4;
						q.add(new Pair(nr,nc));
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		n = sc.nextInt();
		grid = new int[n][n];
		adj = new Pair[n][n];
		dx = new int[] { 0, 1, 0, -1 };
		dy = new int[] { 1, 0, -1, 0 };

		for (int[] arr : grid)
			Arrays.fill(arr, -1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = new Pair(sc.nextInt() - 1, sc.nextInt() - 1);
			}
		}

		boolean flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == -1) {
					if (adj[i][j].r == -2) {
						flag &= dfs(i, j);
					} else {
						if (adj[i][j].r == i && adj[i][j].c == j) {
							grid[i][j] = 4;
							bfs(new Pair(i,j));
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == -1)
					flag = false;
			}
		}

		out.println(flag ? "VALID" : "INVALID");
		if (flag) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int x = grid[i][j];
					if (x == 0)
						out.print("R");
					else if (x == 1)
						out.print("D");
					else if (x == 2)
						out.print("L");
					else if (x == 3)
						out.print("U");
					else
						out.print("X");
				}
				out.println();
			}
		}

		out.close();
	}

	static class Pair {
		int r, c;

		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

}

class Scanner {
	StringTokenizer st;
	BufferedReader br;

	public Scanner(InputStream system) {
		br = new BufferedReader(new InputStreamReader(system));
	}

	public Scanner(String file) throws Exception {
		br = new BufferedReader(new FileReader(file));
	}

	public String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public String nextLine() throws IOException {
		return br.readLine();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public Long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}
