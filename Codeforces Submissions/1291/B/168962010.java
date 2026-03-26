import java.util.*;
import java.io.*;

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

	static void reverseandflip(char[] s1, int pos) {
		int i = 0;
		int j = pos;
		while (i <= j) {
			if (s1[i] == s1[j]) {
				if (s1[i] == '1') {
					s1[i] = '0';
					s1[j] = '0';
				} else {
					s1[i] = '1';
					s1[j] = '1';
				}
			}
			i++;
			j--;
		}
	}

	static int bs(ArrayList<Integer> pow, long target) {
		int low = 0;
		int idx = -1;
		int high = pow.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (pow.get(mid) <= target) {
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

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		StringBuilder str = new StringBuilder();
		int t = sc.nextInt();
		for (int xx = 0; xx < t; xx++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			boolean ok = true;
			boolean ok1 = true;
			for (int i = 0; i < n; i++) {
				if (arr[i] < n - i - 1)
					ok1 = false;
			}
			int a = 0;
			arr[0] = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i] >= i && a == 0) {
					continue;
				}
				a++;
				if(a==1)
					i--;
				if (arr[i] < n - i - 1)
					ok = false;
			}
			if (ok || ok1)
				str.append("Yes" + "\n");
			else
				str.append("No" + "\n");
		}
		System.out.println(str);
		sc.close();
	}
}