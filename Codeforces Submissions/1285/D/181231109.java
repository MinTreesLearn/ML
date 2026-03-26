import java.io.*;
import java.util.*;

public class D1275 {
	static int N = (int)1e5 + 7;
	static int[][] nod = new int[30 * N][2];
	static int res = (1 << 30);	
	static void dfs(int u, int cur, int lvl) {
		if(nod[u][0] == 0 && nod[u][1] == 0) res = Math.min(res, cur);
		else if(nod[u][0] > 0 && nod[u][1] > 0) {
			cur += (1 << lvl);
			dfs(nod[u][0], cur, lvl - 1);
			dfs(nod[u][1], cur, lvl - 1);
		}
		else {
			if(nod[u][0] > 0) dfs(nod[u][0], cur, lvl - 1);
			else dfs(nod[u][1], cur, lvl - 1);
		}
	}
	public static void main(String[] args) {
		//Scanner sc = new Scanner(System.in);
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int T, cs=0;
		int n = fs.nextInt(), tot = 0;
		for (int i = 0; i < n; i++) {
			int x;
			x = fs.nextInt();
			int cur = 0;
			for (int j = 30; j >= 0; j--) {
				int bit = 1 & (x >> j);
				if(nod[cur][bit] == 0) nod[cur][bit] = ++tot;
				cur = nod[cur][bit];
			}
		}
		dfs(0, 0, 30);
		out.println(res);
		out.close();
	}

	public static void dbg(Object... o){
		System.err.print("Line #"+Thread.currentThread().getStackTrace()[2].getLineNumber() + ": ");
		System.err.println(Arrays.deepToString(o));
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(br.readLine());
				} 
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}