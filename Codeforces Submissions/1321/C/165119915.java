import java.util.*;
import java.io.*;

public class codeforce {

	static boolean multipleTC = false;
	final static int Mod = 1000000007;
	final static int Mod2 = 998244353;
	final double PI = 3.14159265358979323846;
	int MAX = 1000000007;

	void pre() throws Exception {
	}

	long combination(int n, int r, long fact[], long ifact[]) {
	
		long val1 = fact[n];
		long val2 = ifact[(n-r)];
		long val3 = ifact[r];
		
		return (((val1*val2)%Mod)*val3)%Mod;
	}
	
	long expo(long a, long b, long mod) {
		long res = 1; 
		while (b != 0) {
			if ((b & 1) == 1)
				res = (res * a) % mod; 
			
			a = (a * a) % mod; 
			b >>= 1;
		} 
		
		return res;
    }
	
	long gcd(long a, long b) {
		if(b == 0)
			return a;
		
		return gcd(b, a%b);
	}
	
	long mminvprime(long a, long b) {
		return expo(a, b - 2, b);
	}
	
	void solve(int t) throws Exception {

		int n = ni();
		String str = n();
		
		if(str.length() == 1) {
			pn(0);
			return;
		}
		
		long ans = 0;
		for(char c='z';c>'a';c--) {
			for(int i=0;i<str.length();i++) {
				
				if(str.length() == 1)
					break;
				
				if(str.charAt(i) != c)
					continue;
				
				if(i == 0) {
					if(str.charAt(i+1) == c-1) {
						ans++;
						str = str.substring(0, i) + str.substring(i+1);
						i--;
					}
				}
				else if(i == str.length()-1) {
					if(str.charAt(i-1) == c-1) {
						ans++;
						str = str.substring(0, i) + str.substring(i+1);
						i -= 2;
					}
				}
				else {
					if(str.charAt(i-1) == c-1 || str.charAt(i+1) == c-1) {
						ans++;
						str = str.substring(0, i) + str.substring(i+1);
						i -= 2;
					}
				}
			}
		}
		
		pn(ans);
	}

	double dist(int x1, int y1, int x2, int y2) {
		double a = x1 - x2, b = y1 - y2;
		return Math.sqrt((a * a) + (b * b));
	}

	long xor_sum_upton(long n) {
        if (n % 4 == 0)
            return n;
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        return 0;		
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

	void pn(int[] arr) {
		int n = arr.length;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(arr[i] + " ");
		}
		pn(sb);
	}

	void pn(long[] arr) {
		int n = arr.length;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(arr[i] + " ");
		}
		pn(sb);
	}

	String n() throws Exception {
		return in.next();
	}

	String nln() throws Exception {
		return in.nextLine();
	}

	char c() throws Exception {
		return in.next().charAt(0);
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
		new codeforce().run();
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