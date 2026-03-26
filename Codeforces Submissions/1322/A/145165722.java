import java.util.*;

import java.io.*;

public class Practice {
	static boolean multipleTC = false;
	FastReader in;
	PrintWriter out;

	final static int mod = 1000000007;
	final static int mod2 = 998244353;
	final double E = 2.7182818284590452354;
	final double PI = 3.14159265358979323846;
	int MAX = 100005;

	public static void main(String[] args) throws Exception {
		new Practice().run();
	}

	void run() throws Exception {
		in = new FastReader();
		out = new PrintWriter(System.out);
		int T = (multipleTC) ? ni() : 1;
		pre();
		for (int t = 1; t <= T; t++)
			solve(t);
		out.flush();
		out.close();
	}

	void pre() throws Exception {
	}

	// All the best
	void solve(int TC) throws Exception {
		int n = ni();
		char s[] = nln().toCharArray();
		int open = 0, close = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				open++;
			} else {
				close++;
			}
		}
		if (open != close) {
			pn("-1");
		} else {
			open = 0;
			close = 0;
			int res = 0;
			Stack<pair> st = new Stack<>();
			for (int i = 0; i < n; i++) {
				if (s[i] == ')' && !st.isEmpty() && st.peek().x == '(') {
					st.pop();
					if (s[i] == '(') {
						open++;
					} else {
						close++;
					}
					if (st.isEmpty()) {
						open = close = 0;
					}
				} else {
					st.push(new pair(s[i], i));
					if (s[i] == '(') {
						open++;
					} else {
						close++;
					}
					if (open == close) {

						res += (open + close);
						open = close = 0;
						st.clear();
					}
				}
			}
			pn(res);
		}
	}

	class pair {
		char x;
		int y;

		pair(char x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "(" + x + "," + y + ")";
		}

	}

	int[] readArr(int n) throws Exception {
		int arr[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = ni();
		}
		return arr;
	}

	void sort(int arr[]) {
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < arr.length; i++)
			list.add(arr[i]);
		Collections.sort(list);
		for (int i = 0; i < arr.length; i++)
			arr[i] = list.get(i);
	}

	public long max(long... arr) {
		long max = arr[0];
		for (long itr : arr)
			max = Math.max(max, itr);
		return max;
	}

	public int max(int... arr) {
		int max = arr[0];
		for (int itr : arr)
			max = Math.max(max, itr);
		return max;
	}

	public long min(long... arr) {
		long min = arr[0];
		for (long itr : arr)
			min = Math.min(min, itr);
		return min;
	}

	public int min(int... arr) {
		int min = arr[0];
		for (int itr : arr)
			min = Math.min(min, itr);
		return min;
	}

	public long sum(long... arr) {
		long sum = 0;
		for (long itr : arr)
			sum += itr;
		return sum;
	}

	public long sum(int... arr) {
		long sum = 0;
		for (int itr : arr)
			sum += itr;
		return sum;
	}

	String bin(long n) {
		return Long.toBinaryString(n);
	}

	String bin(int n) {
		return Integer.toBinaryString(n);
	}

	static int bitCount(int x) {
		return x == 0 ? 0 : (1 + bitCount(x & (x - 1)));
	}

	static void dbg(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	int bit(long n) {
		return (n == 0) ? 0 : (1 + bit(n & (n - 1)));
	}

	int abs(int a) {
		return (a < 0) ? -a : a;
	}

	long abs(long a) {
		return (a < 0) ? -a : a;
	}

	void p(Object o) {
		out.print(o);
	}

	void pn(Object o) {
		out.println(o);
	}

	void pni(Object o) {
		out.println(o);
		out.flush();
	}

	String n() throws Exception {
		return in.next();
	}

	String nln() throws Exception {
		return in.nextLine();
	}

	int ni() throws Exception {
		return Integer.parseInt(in.next());
	}

	long nl() throws Exception {
		return Long.parseLong(in.next());
	}

	double nd() throws Exception {
		return Double.parseDouble(in.next());
	}

	class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastReader(String s) throws Exception {
			br = new BufferedReader(new FileReader(s));
		}

		String next() throws Exception {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new Exception(e.toString());
				}
			}
			return st.nextToken();
		}

		String nextLine() throws Exception {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				throw new Exception(e.toString());
			}
			return str;
		}
	}
}