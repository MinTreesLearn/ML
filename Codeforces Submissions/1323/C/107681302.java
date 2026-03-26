import java.io.*;
import java.math.*;
import java.util.*;

// author : Multi-Thread

public class A {

	static int mod = (int) 1e9 + 7;
	static int MAX = Integer.MAX_VALUE;
	static int MIN = Integer.MIN_VALUE;

	public static void main(String[] args) {

//		int test = fs.nextInt();
		int test = 1;
		for (int cases = 0; cases < test; cases++) {

//			solve();
			System.out.println(solve());

		}
	}

	static int solve() {
		int n = fs.nextInt();
		char ar[] = fs.next().toCharArray();
		Stack<Character> st = new Stack<Character>();
		int closing = 0;
		int ans = 0;
		for (char c : ar) {
			if (c == ')') {
				++closing;
				if (st.size() == closing) {
//					ans += st.size() + closing;
					st.clear();
					closing = 0;
				}
			} else {
				st.add(c);
//				System.out.println("HERE " + st.size() + " " + c);
				if (st.size() == closing) {
					ans += st.size() + closing;
					st.clear();
					closing = 0;
				}

			}
//			System.out.println(st + " " + closing + " " + ans);
		}
//		System.out.println(st + " " + ans);
		if (closing != 0 || !st.isEmpty())
			return -1;
		return ans;
	}

	static void intSort(int[] a, boolean reverse) {
		ArrayList<Integer> al = new ArrayList<Integer>();
		for (int i : a)
			al.add(i);
		Collections.sort(al);
		if (reverse) {
			for (int i = 0; i < a.length; i++)
				a[i] = al.get(a.length - i - 1);
		} else {
			for (int i = 0; i < a.length; i++)
				a[i] = al.get(i);
		}
	}

	static void longSort(long[] a, boolean reverse) {
		ArrayList<Long> al = new ArrayList<>();
		for (long i : al)
			al.add(i);
		Collections.sort(al);
		if (reverse) {
			for (int i = 0; i < a.length; i++)
				a[i] = al.get(a.length - i - 1);
		} else {
			for (int i = 0; i < a.length; i++)
				a[i] = al.get(i);
		}
	}

	public static int[] radixSort(int[] f) {
		return radixSort(f, f.length);
	}

	public static int[] radixSort(int[] f, int n) {
		int[] to = new int[n];
		{
			int[] b = new int[65537];
			for (int i = 0; i < n; i++)
				b[1 + (f[i] & 0xffff)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < n; i++)
				to[b[f[i] & 0xffff]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		{
			int[] b = new int[65537];
			for (int i = 0; i < n; i++)
				b[1 + (f[i] >>> 16)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < n; i++)
				to[b[f[i] >>> 16]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		return f;
	}

	static class Pair {
		int first, second;

		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}

		public String toString() {
			return "[" + first + "," + second + "]";
		}
	}

	static class LongPair {
		long first;
		long second;

		LongPair(long a, long b) {
			this.first = a;
			this.second = b;
		}

		public String toString() {
			return "[" + first + "," + second + "]";
		}
	}

	static boolean isPrime(long n) {
		// Corner cases
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;

		long sq = (long) Math.sqrt(n);
		for (int i = 5; i <= sq; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void println() {
			writer.print("\n");
		}

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void flush() {
			writer.flush();
		}

	}

	private static final FastReader fs = new FastReader();
	private static final OutputWriter out = new OutputWriter(System.out);
}