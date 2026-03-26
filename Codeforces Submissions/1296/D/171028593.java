import java.util.*;

public class A {
	static class Pair {
		long x;
		long y;

		public Pair(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}

	static long gcd(long n, long m) {
		if (m == 0)
			return n;
		else
			return gcd(m, n % m);
	}

	static long lcm(long n, long m) {
		return (n * m) / gcd(n, m);
	}

	static void dfs(ArrayList<ArrayList<Integer>> adj, int s, int[] vis, int[] cnt) {
		for (int i : adj.get(s)) {
			if (vis[i] == 1) {
				continue;
			}
			cnt[0]++;
			vis[i] = 1;
			dfs(adj, i, vis, cnt);
		}
	}

	public static long solve(long a, long b, long x, long y, long n) {
		if (a - n >= x) {
			return ((a - n) * b);
		} else {
			n -= a - x;
			a = x;
			if (b - n >= y) {
				return (a * (b - n));
			} else {
				b = y;
				return (a * b);
			}
		}
	}

	static int high(int n) {
		int p = (int) (Math.log(n) / Math.log(2));
		return (int) Math.pow(2, p);
	}

	static int lbs(Pair[] pow, Pair target) {
		int low = 0;
		int idx = -1;
		int high = pow.length - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (pow[mid].x >= target.x || pow[mid].y >= target.y) {
				high = mid - 1;
			} else {
				low = mid + 1;
				idx = mid;
			}
		}
		return idx;

	}

	static int ubs(Pair[] pow, Pair target) {
		int low = 0;
		int idx = -1;
		int high = pow.length - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (pow[mid].x <= target.x || pow[mid].y <= target.y) {
				low = mid + 1;
			} else {
				idx = mid;
				high = mid - 1;
			}
		}
		return idx;
	}

	static boolean prime(int n) {
		int m = (int) Math.sqrt(n);
		for (int i = 2; i <= m; i++)
			if (n % i == 0)
				return false;
		return true;
	}

	static long recurr(int[] weight, int[] item, int n, int w, long[][] dp)// recursive solution
	{
		if (n == 0)
			return 0;
		if (dp[n][w] != -1)
			return dp[n][w];
		long k = 0;
		if (weight[n - 1] <= w)
			k = item[n - 1] + recurr(weight, item, n - 1, w - weight[n - 1], dp);
		long k1 = recurr(weight, item, n - 1, w, dp);
		dp[n][w] = Math.max(k, k1);
		return dp[n][w];
	}

	public static void main(String[] args) {
		StringBuilder str = new StringBuilder();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] arr = new long[n];
		long a = sc.nextInt();
		long b = sc.nextInt();
		long k = sc.nextInt();
		for (int i = 0; i < n; i++) {
			long c = sc.nextInt();
			long r = 0;
			if (c % (a + b) != 0)
				r = c % (a + b);
			else
				r = a + b;
			arr[i] = ((r + a - 1) / a) - 1;
		}
		Arrays.sort(arr);
		long c = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			c += arr[i];
			if (c <= k) {
				cnt = i + 1;
			}
		}
		str.append(cnt + "\n");
		System.out.println(str);
		sc.close();
	}
}