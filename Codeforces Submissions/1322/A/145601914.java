
/*
Created on = 08-Feb-2022 / 9:10:39 AM
*/
import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		try {
			solve();
			out.close();
		} catch (Exception e) {
			return;
		}
	}

	// SOLUTION STARTS HERE
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	static void solve() {
		int n = sc.nextInt();
		char a[] = sc.next().toCharArray();
		int x[] = new int[n];
		x[0] = a[0] == '(' ? 1 : -1;
		for (int i = 1; i < n; i++) {
			x[i] = x[i - 1] + (a[i] == '(' ? 1 : -1);
		}
		if (x[n - 1] != 0) {
			System.out.println(-1);
			return;
		}
		int last = 0;
		boolean f = false;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!f && x[i] < 0) {
				last = i;
				f = true;
			}
			if (x[i] == 0 && f) {
				ans += i - last + 1;
				f = false;
			}
		}
		System.out.println(ans);
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
