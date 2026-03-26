
/*
Created on = 08-Feb-2022 / 8:55:29 AM
*/
import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		try {
			int t = sc.nextInt();
			while (t-- > 0)
				solve();
			out.close();
		} catch (Exception e) {
			return;
		}
	}

	// SOLUTION STARTS HERE
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	static void solve() {
		long a = sc.nextLong(), b = sc.nextLong(), p = sc.nextLong();
		char s[] = sc.next().toCharArray();
		int n = s.length;
		int l = 0, r = n - 1, ans = n;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (ok(mid, s, a, b, p)) {
				ans = Math.min(ans, mid);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		System.out.println(ans + 1);
	}

	static boolean ok(int mid, char[] s, long a, long b, long p) {
		long sum = 0;
		for (int i = mid; i < s.length - 1; i++) {
			char curr = s[i];
			while (i < s.length && s[i] == curr)
				i++;
			i--;
			sum += curr == 'A' ? a : b;
		}
		return sum <= p;
	}

	// SOLUTION ENDS HERE
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	static long binPow(long a, long b, long mod) {
		long ans = 1;
		while (b != 0) {
			if ((b & 1) == 1)
				ans = (ans * a) % mod;
			a = (a * a) % mod;
			b >>= 1;
		}
		return ans;
	}

	static class DSU {
		int rank[];
		int parent[];

		DSU(int n) {
			rank = new int[n + 1];
			parent = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				parent[i] = i;
			}
		}

		int findParent(int node) {
			if (parent[node] == node)
				return node;
			return parent[node] = findParent(parent[node]);
		}

		boolean union(int x, int y) {
			int px = findParent(x);
			int py = findParent(y);
			if (px == py)
				return false;
			if (rank[px] < rank[py]) {
				parent[px] = py;
			} else if (rank[px] > rank[py]) {
				parent[py] = px;
			} else {
				parent[px] = py;
				rank[py]++;
			}
			return true;
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l = new ArrayList<>();
		for (int i : a)
			l.add(i);
		Collections.sort(l);
		for (int i = 0; i < a.length; i++)
			a[i] = l.get(i);
	}

	static boolean[] seiveOfEratosthenes(int n) {
		boolean[] isPrime = new boolean[n + 1];
		Arrays.fill(isPrime, true);
		for (int i = 2; i * i <= n; i++) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
		return isPrime;
	}

	static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static boolean isPrime(long n) {
		if (n < 2)
			return false;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	private static final FastScanner sc = new FastScanner();
	private static PrintWriter out = new PrintWriter(System.out);
}
