// Created on: 10:12:32 PM | 14-Mar-2022

import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	static void solve() {
		int caseNo = 1;
		for (int T = sc.nextInt(); T > 0; T--, caseNo++) {
			solveIt(caseNo);
		}
	}

	// Solution
	static void solveIt(int t) {
		int n = sc.nextInt();
		int a[] = sc.readIntArray(n);
		int b[] = sc.readIntArray(n);
		sort(a);
		sort(b);
		for (int i = 0; i < n; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
		for (int i = 0; i < n; i++) {
			System.out.print(b[i] + " ");
		}
		System.out.println();
	}

	static void revArray(int a[], int i, int j) {
		while (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	static boolean isSorted(int a[], int s, int e, boolean strict) {
		for (int i = s + 1; i <= e; i++) {
			if (strict && a[i - 1] >= a[i])
				return false;
			if (!strict && a[i - 1] > a[i])
				return false;
		}
		return true;
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

	public static int[] seiveOnlyPrimes(int n) {
		if (n <= 32) {
			int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
			for (int i = 0; i < primes.length; i++) {
				if (n < primes[i]) {
					return Arrays.copyOf(primes, i);
				}
			}
			return primes;
		}

		int u = n + 32;
		double lu = Math.log(u);
		int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
		ret[0] = 2;
		int pos = 1;

		int[] isp = new int[(n + 1) / 32 / 2 + 1];
		int sup = (n + 1) / 32 / 2 + 1;

		int[] tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		for (int tp : tprimes) {
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for (int i = (tp - 3) / 2; i < tp << 5; i += tp)
				ptn[i >> 5] |= 1 << (i & 31);
			for (int i = 0; i < tp; i++) {
				for (int j = i; j < sup; j += tp)
					isp[j] |= ptn[i];
			}
		}
		int[] magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17,
				9, 6, 16, 5, 15, 14 };
		int h = n / 2;
		for (int i = 0; i < sup; i++) {
			for (int j = ~isp[i]; j != 0; j &= j - 1) {
				int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
				int p = 2 * pp + 3;
				if (p > n)
					break;
				ret[pos++] = p;
				for (int q = pp; q <= h; q += p)
					isp[q >> 5] |= 1 << (q & 31);
			}
		}
		return Arrays.copyOf(ret, pos);
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

	public static void main(String[] args) throws Exception {
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		solve();
		out.flush();
		long G = System.currentTimeMillis();
		sc.tr(G - S + "ms");
	}

	static class sc {

		private static boolean endOfFile() {
			if (bufferLength == -1)
				return true;
			int lptr = ptrbuf;
			while (lptr < bufferLength)
				if (!isThisTheSpaceCharacter(inputBufffferBigBoi[lptr++]))
					return false;

			try {
				is.mark(1000);
				while (true) {
					int b = is.read();
					if (b == -1) {
						is.reset();
						return true;
					} else if (!isThisTheSpaceCharacter(b)) {
						is.reset();
						return false;
					}
				}
			} catch (IOException e) {
				return true;
			}
		}

		private static byte[] inputBufffferBigBoi = new byte[1024];
		static int bufferLength = 0, ptrbuf = 0;

		private static int justReadTheByte() {
			if (bufferLength == -1)
				throw new InputMismatchException();
			if (ptrbuf >= bufferLength) {
				ptrbuf = 0;
				try {
					bufferLength = is.read(inputBufffferBigBoi);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (bufferLength <= 0)
					return -1;
			}
			return inputBufffferBigBoi[ptrbuf++];
		}

		private static boolean isThisTheSpaceCharacter(int c) {
			return !(c >= 33 && c <= 126);
		}

		private static int skipItBishhhhhhh() {
			int b;
			while ((b = justReadTheByte()) != -1 && isThisTheSpaceCharacter(b))
				;
			return b;
		}

		private static double nextDouble() {
			return Double.parseDouble(next());
		}

		private static char nextChar() {
			return (char) skipItBishhhhhhh();
		}

		private static String next() {
			int b = skipItBishhhhhhh();
			StringBuilder sb = new StringBuilder();
			while (!(isThisTheSpaceCharacter(b))) {
				sb.appendCodePoint(b);
				b = justReadTheByte();
			}
			return sb.toString();
		}

		private static char[] readCharArray(int n) {
			char[] buf = new char[n];
			int b = skipItBishhhhhhh(), p = 0;
			while (p < n && !(isThisTheSpaceCharacter(b))) {
				buf[p++] = (char) b;
				b = justReadTheByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}

		private static char[][] readCharMatrix(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = readCharArray(m);
			return map;
		}

		private static int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		private static long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		private static int nextInt() {
			int num = 0, b;
			boolean minus = false;
			while ((b = justReadTheByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = justReadTheByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = justReadTheByte();
			}
		}

		private static long nextLong() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = justReadTheByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = justReadTheByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = justReadTheByte();
			}
		}

		private static void tr(Object... o) {
			if (INPUT.length() != 0)
				System.out.println(Arrays.deepToString(o));
		}
	}
}
