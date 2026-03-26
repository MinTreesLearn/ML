import java.util.*;
import java.io.*;

public class A {
	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
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

	static int bs(long[] pow, long target) {
		int low = 0;
		int idx = -1;
		int high = pow.length - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (pow[mid] <= target) {
				low = mid + 1;
				idx = mid;
			} else {
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

	static StringBuilder str = new StringBuilder();

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int xx = 0; xx < t; xx++) {
			int n = sc.nextInt();
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			long min = (int) 1e9;
			long max = 0;
			for (int i = 0; i < n; i++) {
				if (i > 0 && arr[i] == -1 && arr[i - 1] != -1) {
					min = Math.min(min, arr[i - 1]);
					max = Math.max(max, arr[i - 1]);
				}
				if (i < n - 1 && arr[i] == -1 && arr[i + 1] != -1) {
					max = Math.max(arr[i + 1], max);
					min = Math.min(arr[i + 1], min);
				}
			}
			long c = 2;
			long sum = max + min;
			if (c != 0)
				c = sum / c;
			else
				c = 0;
			if (arr[0] == -1)
				arr[0] = c;
			max = 0;
			for (int i = 1; i < n; i++) {
				if (arr[i] == -1)
					arr[i] = c;
				max = Math.max(max, Math.abs(arr[i] - arr[i - 1]));
			}
			str.append(max + " " + c + "\n");
		}
		System.out.println(str);
		sc.close();
	}
}