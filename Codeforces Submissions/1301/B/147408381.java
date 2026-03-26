import java.util.*;
import java.io.*;

public class Practice {

	static boolean multipleTC = true;
	final static int mod = 1000000007;
	final static int mod2 = 998244353;
	final double E = 2.7182818284590452354;
	final double PI = 3.14159265358979323846;
	int MAX = 10000005;

	void pre() throws Exception {
	}

	// All the best
	void solve(int TC) throws Exception {
		int n = ni();
		long arr[] = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = ni();
		}
		boolean missing[] = new boolean[n];
		for (int i = 0; i < n; i++)
			if (arr[i] < 0)
				missing[i] = true;
		TreeSet<Long> set = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			if (missing[i]) {
				if (i > 0 && arr[i - 1] >= 0) {
					set.add(arr[i - 1]);
				}
				if (i + 1 < n && arr[i + 1] >= 0)
					set.add(arr[i + 1]);
			}
		}
		if (set.size() == 0) {
			pn("0 1");
			return;
		}
		long x = ((set.first() + set.last()) / 2);
		for (int k = 0; k < n; k++) {
			if (missing[k]) {
				arr[k] = x;
			}
		}
		long cur = 0;
		for (int k = 1; k < n; k++) {
			cur = max(cur, abs(arr[k] - arr[k - 1]));
		}

		pn(cur + " " + x);

	}

	void leftRotatebyOne(int arr[], int n) {
		int temp = arr[0], i;
		for (i = 0; i < n - 1; i++)
			arr[i] = arr[i + 1];

		arr[n - 1] = temp;
	}

	boolean isFibo(int arr[]) {
		int n = arr.length;
		for (int i = 0; i + 2 < n; i++) {
			if (arr[i] + arr[i + 1] == arr[i + 2]) {
				return true;
			}
		}
		return false;
	}

	public void permute(int[] arr) {
		permuteHelper(arr, 0);
	}

	ArrayList<int[]> perm = new ArrayList<>();

	private void permuteHelper(int[] arr, int index) {
		if (index >= arr.length - 1) {
			perm.add(arr.clone());
			return;
		}
		if (perm.size() > 3 * arr.length) {
			return;
		}
		for (int i = index; i < arr.length; i++) {
			int t = arr[index];
			arr[index] = arr[i];
			arr[i] = t;
			permuteHelper(arr, index + 1);
			t = arr[index];
			arr[index] = arr[i];
			arr[i] = t;
		}
	}

	int[] readArr(int n) throws Exception {
		int arr[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = ni();
		}
		return arr;
	}

	void sort(int arr[], int left, int right) {
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = left; i <= right; i++)
			list.add(arr[i]);
		Collections.sort(list);
		for (int i = left; i <= right; i++)
			arr[i] = list.get(i - left);
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

	public static void main(String[] args) throws Exception {
		new Practice().run();
	}

	FastReader in;
	PrintWriter out;

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