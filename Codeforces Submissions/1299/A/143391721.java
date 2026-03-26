import java.util.*;

import java.io.*;

public class Practice {
	static boolean multipleTC = false;
	FastReader in;
	PrintWriter out;

	static int mod = (int) (1e9 + 7);
	static int mod2 = 998244353;
	int parent[];
	int rank[];
	ArrayList<Integer> primes;
	boolean sieve[];
	int pf[];
	int MAX = 1000005;
	int dirX[] = { 1, -1, 0, 0 };
	int dirY[] = { 0, 0, -1, 1 };

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

	// declare all variables fucking long even array indices.
	// if you are copying some code make sure you done all necessary modifications
	// that's leads WA.
	// Divide by Zero Exception Ruin Your Life.
	// Number Format Exception : Make sure you read constraint carefully.
	// Always use TreeMap instead of HashMap.
	// Always write comparators using wrapper classes;
	// Integer wrapper class are traitor;
	void solve(int TC) throws Exception {
		int n = ni();
		int arr[] = readArr(n);
		if(n==1) {
			pn(arr[0]);
			return;
		}
		int idx = -1;
		for(int i=31;i>=0;i--) {
			int count =0;
			
			for(int k = 0;k<n;k++) {
				if((arr[k]&(1<<i))!=0) {
					idx =k;
					count++;
				}
			}
			if(count==1) {
				break;
			}
		}
		StringBuilder ans = new StringBuilder();
		idx= idx==-1?0:idx;
		ans.append(arr[idx]+" ");
		for(int i=0;i<n;i++ ) {
			if(i==idx)continue;
			ans.append(arr[i]+" ");
		}
		pn(ans);

	}

	ArrayList<Integer> getDivisors(int n) {
		ArrayList<Integer> res = new ArrayList<>();
		for (int i = 2; i * i <= n; i++) {
			res.add(i);
			if (i != n / i) {
				res.add(n / i);
			}
		}
		Collections.sort(res);
		return res;
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

	public StringBuilder printArr(int arr[]) {
		StringBuilder sb = new StringBuilder();
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			sb.append(arr[i] + " ");
		}
		return sb;
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