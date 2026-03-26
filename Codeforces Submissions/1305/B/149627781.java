
/*
Created on = 14-Mar-2022 / 8:07:56 PM
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
			e.printStackTrace();
		}
	}

	// SOLUTION STARTS HERE
	// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	static void solve() {
		String s = sc.next();
		/*
		 * (()()) 122333 333221
		 */
		List<List<Integer>> ans = new ArrayList<>();
		while (true) {
			char a[] = s.toCharArray();
			List<Integer> o = new ArrayList<>();
			List<Integer> c = new ArrayList<>();
			for (int i = 0; i < a.length; i++) {
				if (a[i] == '(')
					o.add(i + 1);
				else
					c.add(i + 1);
			}
			int pref[] = new int[a.length];
			int suff[] = new int[a.length];
			if (a[0] == '(')
				pref[0]++;
			if (a[a.length - 1] == ')')
				suff[a.length - 1]++;
			for (int i = 1; i < a.length; i++) {
				pref[i] += pref[i - 1] + (a[i] == '(' ? 1 : 0);
			}
			for (int i = a.length - 2; i >= 0; i--) {
				suff[i] += suff[i + 1] + (a[i] == ')' ? 1 : 0);
			}
//			System.out.println(Arrays.toString(pref));
//			System.out.println(Arrays.toString(suff));
//			System.out.println("xxxxxxxxxxxxx");
			int max = 0;
			int ind = -1;
			for (int i = 0; i < a.length - 1; i++) {
				if (a[i] == '(') {
					if (max < Math.min(pref[i], suff[i + 1])) {
						max = Math.min(pref[i], suff[i + 1]);
						ind = i + 1;
					}
				}
			}
			if (max == 0) {
				break;
			}
			int temp = max;
			boolean t[] = new boolean[a.length + 1];
			StringBuilder sb = new StringBuilder();
			for (int i : o) {
				if (i <= ind && temp > 0) {
					t[i] = true;
					temp--;
				}
			}
			temp = max;
			for (int i = c.size() - 1; i >= 0; i--) {
				if (c.get(i) > ind && temp > 0) {
					t[c.get(i)] = true;
					temp--;
				}
			}
			for (int i = 0; i < a.length; i++) {
				if (!t[i + 1])
					sb.append(a[i]);
			}
			List<Integer> al = new ArrayList<>();
			for (int i = 1; i <= a.length; i++) {
				if (t[i])
					al.add(i);
			}
			ans.add(al);
			s = sb.toString();
			if (s.length() == 0)
				break;
		}
		System.out.println(ans.size());
		for (List<Integer> x : ans) {
			System.out.println(x.size());
			for (int i : x) {
				System.out.print(i + " ");
			}
			System.out.println();
		}
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
				a[i] = nextLong();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	private static final FastScanner sc = new FastScanner();
	private static PrintWriter out = new PrintWriter(System.out);
}
