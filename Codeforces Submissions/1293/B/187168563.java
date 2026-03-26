import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

	static ArrayList<Integer> prime = new ArrayList<>();
	static int mod = (int)(1e9	+ 7 ) ;
	static ArrayList<Integer> arr;
	static ArrayList<Long> prefix;
	static ArrayList<Long> pre = new ArrayList<>();
	static final long LMAX = 9223372036854775807L;
	static ArrayList<Integer> arr1 = new ArrayList<>();
	static ArrayList<ArrayList<Integer>> vis = new ArrayList<>();
	static int dr[] = {1, 0, -1, 0};
	static int dc[] = {0, -1, 0, 1};


	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreTokens()) {
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
				str = br.readLine().trim();
			} catch (Exception e) {
				e.printStackTrace();
			}
			return str;
		}
	}
	static class FastWriter {
		private final BufferedWriter bw;
		public FastWriter() {
			this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
		}
		public void print(Object object) throws IOException {
			bw.append("" + object);
		}
		public void println(Object object) throws IOException {
			print(object);
			bw.append("\n");
		}
		public void close() throws IOException {
			bw.close();
		}
	}
	public static class Pair {
		int first;
		int second;
		Pair(int first , int second ) {
			this.first = first ;
			this.second = second;
		}
	}


	public static void main(String[] args) {
		try {
			FastReader in = new FastReader();
			FastWriter out = new FastWriter();


			// Collections.sort(arr, new Comparator<Pair>() {
			// 		@Override public int compare(Pair o1, Pair o2) {
			// 			if (o1.second < o2.second ) { // change (>) for desending order
			// 				return -1;
			// 			} else if (o1.second == o2.second ) {
			// 				return 0;
			// 			} else {
			// 				return 1;
			// 			}
			// 		}
			// 	});


			// int testcases = in.nextInt();



			int testcases = 1;

			while ( testcases -- > 0 ) {
				long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;


				double n = in.nextDouble();

				double ans = 0.0 ;
				for ( int i = 1; i <= n; ++i ) {
					double x = (double) 1 / i ;
					ans += x ;
					// out.print(x);
				}
				out.println(ans);




			}



			out.close();

		} catch (Exception e) {
			return;
		}
	}


	private static void dfs(int i, int j , int  n , int m , char arr[][] ) {
		if  ( arr[i][j] == '#' ) return ;
		arr[i][j] = '#';
		// ~~~~~
		for ( int k = 0; k < 4; ++k ) {
			int x = dr[k] + i;
			int y = dc[k] + j;
			if ( x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.'  ) {
				dfs(x, y, n , m , arr );
			}
		}
		// ~~~~~
	}

	private static void bfs( Stack<Pair> q, char[][] arr , int[][] vis ) {
		int n = arr.length;
		int m = arr[0].length;
		while (!q.isEmpty()) {
			int i = q.peek().first;
			int j = q.peek().second;
			vis[i][j] = 1;
			q.pop();
			int dr[] = {1, 0, -1, 0};
			int dc[] = {0, -1, 0, 1};
			for ( int k = 0; k < 4; ++k ) {
				int x = dr[k] + i;
				int y = dc[k] + j;
				if ( x >= 0 && x < n && y >= 0 && y < m  && arr[x][y] == '.' && vis[x][y] != 1 ) {
					q.add(new Pair(x, y));
				}
			}
		}
	}

	public static boolean isSatisfy( ArrayList<Integer> arr , int l , int r ) {
		int ans = 0;
		if ( l == 0 || arr.get(l) < arr.get(l - 1) ) ans++;
		if ( r == arr.size() - 1 || arr.get(r) < arr.get(r + 1) ) ans++;
		if ( ans == 2 ) return true;
		return false;
	}

	public static ArrayList<Long> prefixSum() {

		int mod = 100000;
		// ArrayList<Integer> arr ;
		ArrayList<Long> prefix = new ArrayList<>();
		long prev = 0;
		for ( long i = 0; i <= mod; ++i ) {
			prev += i;
			prefix.add(prev);
		}
		return prefix;
	}

	public static long sumRem(int x ) {
		if ( x <= 1 ) return 1;
		return x + sumRem(x - 1);
	}

	public static boolean isSquare( int n ) {
		int sqrt = (int) Math.sqrt(n);
		return (sqrt * sqrt == n );
	}
	public static void swap ( int l , int r , ArrayList<Integer> a ) {
		int t = a.get(l) ;
		a.add(l, a.get(r) );
		a.add(r, t);
	}
	public static void fib( int a , int b , int n) {
		int x = Math.floorMod(a, mod);
		int y = Math.floorMod(b, mod);
		arr = new ArrayList<>();
		arr.add(a);
		arr.add(b);
		for ( int i = 2; i <= n; ++i ) {
			int cur = Math.floorMod((y - x), mod);
			x = y;
			y = cur;
			arr.add(y);
		}
	}
	public static String reverseString( String s1 ) {
		String s = "";
		for ( int i = s1.length() - 1; i >= 0; --i ) {
			s += s1.charAt(i);
		}
		return s;
	}

	public static long countSetBits(long n) {
		long count = 0;
		while (n > 0) {
			count += n & 1;
			n >>= 1;
		}
		return count;
	}
	public static void sortbykey(HashMap<Long, Long> map) {
		TreeMap<Long, Long> sorted = new TreeMap<>();
		sorted.putAll(map);
	}

	public static long sum(int n) {
		if ( n <= 1 ) return n;
		return n + sum(n - 1);
	}

	public static ArrayList<Long> prefix( ArrayList<Long> arr1 ) {
		Collections.sort(arr1);
		ArrayList<Long> arr = new ArrayList<>();
		long prefix = 0;
		for ( int i = 0; i < arr1.size(); ++i ) {
			prefix += arr1.get(i);
			arr.add(prefix);
		}
		return arr;
	}

	public static int solve(int[][] m, int n) {
		int ans = 0;
		int vis[][] = new int[n][n];
		int di[] = {1, 0, 0, -1};
		int dj[] = {0, -1, 1, 0};
		if (m[0][0] == 1) mazerunner(0, 0, m, n, ans, "", vis, di, dj);
		return ans;
	}
	public static void mazerunner(int i, int j, int m[][], int n, int ans, String move, int vis[][], int di[] , int dj[]) {
		if ( i == n - 1 && j == n - 1) {
			ans++;
			return;
		}
		String dir = "DLRU";
		for (int ind = 0; ind < 4; ind++) {
			int nexti = i + di[ind];
			int nextj = j + dj[ind];
			if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && vis[nexti][nextj] == 0 && m[nexti][nextj] == 1) {
				vis[i][j] = 0;
				mazerunner(nexti, nextj, m, n, ans, move + dir.charAt(ind), vis, di, dj);
				vis[i][j] = -1;
			}
		}
	}
	public static long pow( long k , long n ) {
		long ans = 1;
		while ( n > 0 ) {
			if ( n % 2 == 1 ) {
				ans = (ans * k) % mod;
				n--;
			} else {
				k = (k * k) % mod;
				n /= 2;
			}
		}
		return ans % mod;
	}

	public static long fact(long n ) {
		long ans = 0;
		for (int i = 1; i < n; ++i) {
			ans += (long)i;
		}
		return ans;
	}
	public static boolean isValid( long mid, long arr[] , long k ) {

		long req = 0;

		for ( int i = 1; i < arr.length; ++i) {
			req += Math.min( (arr[i] - arr[i - 1] ) , mid );
		}
		req += mid;

		if ( req >= k ) return true;

		return false;
	}

	public static String sortString(String inputString) {
		char tempArray[] = inputString.toCharArray();
		Arrays.sort(tempArray);
		return new String(tempArray);
	}

	private static void reverse( ArrayList<Long> arr , int i, int j ) {
		while ( i <= j ) {
			swap( arr, i, j);
			i++; j--;
		}
	}

	private static void swap( ArrayList<Long> arr , int i, int j ) {
		long temp = arr.get(i);
		arr.set(i, arr.get(j));
		arr.set(j, temp);
	}


	private static boolean isPrime(long n ) {
		if ( n == 1 ) return true;

		for ( int i = 2; i <= Math.sqrt(n); i++) {
			if ( n % i == 0 ) {
				return false ;
			}
		}
		return true;
	}
	private static boolean[] sieve() {
		int n = 100000000;
		boolean sieve[] = new boolean[n + 1];
		Arrays.fill(sieve, true);
		for ( int i = 2; i * i <= n; i++) {
			for ( int j = i * i; j <= n; j += i) {
				sieve[j] = false;
			}
		}
		return sieve;
	}
	private static ArrayList<Integer> generatePrimes(int n ) {
		boolean sieve[] = sieve();
		for ( int i = 2; i <= n; i++) {
			if ( sieve[i] == true ) {
				prime.add(i);
			}
		}
		return prime;
	}
	private static void segmentedSieve( int l  , int r ) {
		int n = (int) Math.sqrt(r);
		ArrayList<Integer> pr = generatePrimes(n);
		int dummy[] = new int[r - l + 1];
		Arrays.fill(dummy, 1);

		for ( int p : pr ) {

			int firstMultiple = (l / p) * p;
			if ( firstMultiple < l ) firstMultiple += p;
			for ( int j = Math.max(firstMultiple, p * p); j <= r; j += p) {
				dummy[j - l] = 0;
			}
		}

		for ( int i = l; i <= r; i++) {
			if ( dummy[i - l] == 1 ) {
				System.out.println(i);
			}
		}
	}
	private static int[] primeFactors() {
		int n = 1000000;
		int prime[] = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			prime[i] = i;
		}
		for (int i = 2; i * i <= n; i++) {
			if ( prime[i] == i ) {
				for (int j = i * i; j <= n; j += i) {
					if ( prime[j] == j ) {
						prime[j] = i;
					}
				}
			}
		}
		return prime;
	}


	private static boolean isPalindrome(String s ) {
		int i = 0, j = s.length() - 1;
		while ( i <= j ) {
			if ( s.charAt(i) != s.charAt(j) ) {
				return false;
			}
			i++; j--;
		}
		return true;
	}

	private static long power( long a , long b ) {
		long ans = 1;
		while ( b > 0 ) {
			if ( (b & 1) != 0 ) {
				ans = binMultiply(ans, a);
			}
			a = binMultiply(a, a );
			b >>= 1;
		}
		return ans;
	}

	private static long binMultiply(long a , long b ) {
		long ans = 0;
		while ( b > 0 ) {
			if ( (b & 1) != 0 ) {
				ans = (ans + a % mod ); // if  m is given in ques than use ans = ans+a % m ;
			}
			a = (a + a) % mod; // if m is given in ques than use a = (a+a)%m;
			b >>= 1;
		}
		return ans;
	}

	private static int GCD ( int a , int b ) {
		if ( b == 0) return a;
		return GCD( b , a % b);
	}


	private static int binarySearch(int l , int r , int[] arr , int find ) {
		int mid = l + (r - l) / 2;
		if ( arr[mid] == find ) {
			return mid;
		} else if ( arr[mid] > find ) {
			return binarySearch(l, mid - 1, arr, find);
		}

		return binarySearch(mid + 1, r, arr, find);
	}
	private static int upper_bound(ArrayList<Integer> arr , int element ) {
		int l = 0 ;
		int h = arr.size() - 1;
		int mid = 0;
		while ( h - l > 1 ) {
			mid = (h + l) / 2;
			if ( arr.get(mid) <=  element ) {
				l = mid + 1;
			} else {
				h = mid ;
			}
		}
		if ( arr.get(l) > element ) return l;
		if ( arr.get(h) > element ) return h;
		return -1;
	}
	private static int lower_bound( long arr[] , long element ) {
		int l = 0 ;
		int h = arr.length - 1;
		int mid = 0;
		while ( h - l > 1 ) {
			mid = (h - l) / 2;
			if ( arr[mid] < element ) {
				l = mid + 1;
			} else {
				h = mid ;
			}
		}
		if ( arr[l] >= element ) return l;
		if ( arr[h] >= element ) return h;
		return -1;
	}
}
class DisjointSet {
	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
	List<Integer> size = new ArrayList<>();

	public DisjointSet(int n ) {
		for ( int i = 0; i <= n; ++i ) {
			rank.add(0);
			parent.add(i);
			size.add(1);
		}
	}
	public int findUPar(int node ) {
		if ( node == parent.get(node) ) return node;
		int ulp = findUPar(parent.get(node));
		parent.set(node, ulp);
		return parent.get(node);
	}
	public void unionBySize(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if ( ulp_u == ulp_v ) return ;
		if ( size.get(ulp_u) < size.get(ulp_v) ) {
			parent.set(ulp_u, ulp_v);
			size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u) );
		} else {
			parent.set(ulp_v, ulp_u);
			size.set(ulp_u, size.get(ulp_v) + size.get(ulp_u) );
		}
	}
	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if ( ulp_u == ulp_v ) return ;
		if ( rank.get(ulp_u) < rank.get(ulp_v) ) {
			parent.set(ulp_u, ulp_v);
		} else if ( rank.get(ulp_v) < rank.get(ulp_u) ) {
			parent.set(ulp_v, ulp_u);
		} else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU + 1);
		}
	}
}
class Pair {
	int first;
	int second;
	Pair(int first , int second ) {
		this.first = first ;
		this.second = second;
	}
}

