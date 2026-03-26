import java.util.*;

import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

	long mod1 = (long) 1e9 + 7;
	int mod2 = 998244353;

	public void solve() throws Exception {
		int n=sc.nextInt();
		int odd=0;
		int even=0;
		int arr[]=sc.readArray(n);
		int dp[][][]=new int[n+1][n+1][2];
		int e=0,o=0;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=n;j++) {
				Arrays.fill(dp[i][j], Integer.MAX_VALUE/2);
			}
		}
		if(arr[0]!=0) {
			dp[1][arr[0]%2][arr[0]%2]=0;
			if(arr[0]%2==1) o++;
			else e++;
		}
		else {
			dp[1][0][0]=0;
			dp[1][1][1]=0;
			
		}
		for(int i=2;i<=n;i++) {
			if(arr[i-1]!=0) {
				if(arr[i-1]%2==1) {
					o++;
				}
				else e++;
			}
				for(int j=Math.max(o, i-n/2-(n%2));j<=n/2+(n%2);j++) {
					if(arr[i-1]==0) {
						dp[i][j][0]=Math.min(dp[i-1][j][1]+1, dp[i-1][j][0]);
						if(j-1>=0)
						dp[i][j][1]=Math.min(dp[i-1][j-1][1], dp[i-1][j-1][0]+1);
					}
					else {
						if(arr[i-1]%2==0) {
							dp[i][j][0]=Math.min(dp[i-1][j][0],dp[i-1][j][1]+1);
						}
						else {
							dp[i][j][1]=Math.min(dp[i-1][j-1][1],dp[i-1][j-1][0]+1);
						}
					}
				}
			}
		int min=Integer.MAX_VALUE;
			int i=n;
			//for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(dp[i][j][0]<Integer.MAX_VALUE/2) {
						min=Math.min(min, dp[i][j][0]);
					}
					if(dp[i][j][1]<Integer.MAX_VALUE/2) {
						min=Math.min(min, dp[i][j][1]);
					}
					
					//out.println(i+" "+j+" "+dp[i][j][0]+" "+dp[i][j][1]+" ");
				}
			//}
			
			out.println(min);
			
		}

	

	static void sort(int[] a) {
		ArrayList<Integer> l = new ArrayList<>();
		for (int i : a)
			l.add(i);
		Collections.sort(l);
		for (int i = 0; i < a.length; i++)
			a[i] = l.get(i);
	}

	static long gcd(long a, long b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	static long ncr(int n, int r, long p) {
		if (r > n)
			return 0l;
		if (r > n - r)
			r = n - r;

		long C[] = new long[r + 1];

		C[0] = 1;

		for (int i = 1; i <= n; i++) {

			for (int j = Math.min(i, r); j > 0; j--)
				C[j] = (C[j] + C[j - 1]) % p;
		}
		return C[r] % p;
	}

	public long power(long x, long y, long p) {
		long res = 1;
		// out.println(x+" "+y);
		x = x % p;
		if (x == 0)
			return 0;

		while (y > 0) {
			if ((y & 1) == 1)
				res = (res * x) % p;
			y = y >> 1;
			x = (x * x) % p;
		}
		return res;
	}

	static Throwable uncaught;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", (1 << 26));
		thread.start();
		thread.join();
		if (Solution.uncaught != null) {
			throw Solution.uncaught;
		}
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public int[] readArray(int n) throws Exception {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}