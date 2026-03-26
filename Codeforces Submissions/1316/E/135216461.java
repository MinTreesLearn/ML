import java.util.*;

import java.io.*;

public class dsu {

	static int n;
	static long memo[][];
	static int p;
	static int pl[][];
	static pair[] a;
	static int k;

	public static long dp(int msk, int idx) {
		if (idx == n)
			return 0;
		if (memo[msk][idx] != -1)
			return memo[msk][idx];
		long max = k - (idx - Integer.bitCount(msk)) > 0 ? dp(msk, idx + 1) + a[idx].x : dp(msk, idx + 1);

		for (int i = 0; i < p; i++) {
			if (((msk >> i) & 1) == 0) {
				max = Math.max(max, pl[a[idx].y][i] + dp(msk | 1 << i, idx + 1));
			}
		}
		return memo[msk][idx] = max;

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		p = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		a = new pair[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < a.length; i++) {
			a[i] = new pair(Integer.parseInt(st.nextToken()), i);
		}
		Arrays.sort(a, (x, y) ->  y.x-x.x);
		pl = new int[n][p];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < pl[i].length; j++) {
				pl[i][j] = Integer.parseInt(st.nextToken());

			}
		}
		memo=new long[1<<p][n];
		for (int i = 0; i < memo.length; i++) {
			Arrays.fill(memo[i],-1);
		}
		System.out.println(dp(0,0));
	}

	static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static class pair {
		int x;
		int y;

		pair(int r, int t) {
			x = r;
			y = t;
		}
		@Override
		public String toString() {
			return "("+ x+","+y+")" ;
		}

	}
}