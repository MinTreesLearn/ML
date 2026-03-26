import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;

public class Solution {

	static HashSet<String> set;

	public static void main(String[] args) {

		PrintWriter out = new PrintWriter(System.out);
		FastScanner fs = new FastScanner();
		DecimalFormat formatter = new DecimalFormat("#0.000000");
		int ti = fs.nextInt();

		outer: while (ti-- > 0) {

			int a = fs.nextInt();
			int b = fs.nextInt();
			int p = fs.nextInt();
			char[] c = fs.next().toCharArray();
			int n = c.length;
			int res = n - 1;

			for (int i = n - 2; i >= 0; i--) {
				res = i + 1;
				while (i > 0 && c[i] == c[i - 1])
					i--;

				if (c[i] == 'A')
					p -= a;
				else
					p -= b;
				if (p < 0)
					break;
			}

			if (p >= 0)
				res = 0;
			out.println(res + 1);
		}
		out.close();
	}

	static final int mod = 1_000_000_007;

	static void sort(long[] a) {
		Random random = new Random();
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int oi = random.nextInt(n);
			long temp = a[oi];
			a[oi] = a[i];
			a[i] = temp;
		}
		Arrays.sort(a);
	}

	static void sort(int[] a) {
		Random random = new Random();
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int oi = random.nextInt(n), temp = a[oi];
			a[oi] = a[i];
			a[i] = temp;
		}
		Arrays.sort(a);
	}

	static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
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

		float nextFloat() {
			return Float.parseFloat(next());
		}

		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	static class Pair {
		String a;
		int b;

		public Pair(String a, int b) {
			this.a = a;
			this.b = b;
		}
	}

}
