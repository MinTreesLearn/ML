
/*

    /$$$$$  /$$$$$$  /$$    /$$  /$$$$$$                                                                  
   |__  $$ /$$__  $$ |$$    |$$ /$$__  $$                                                                 
          | $$| $$  \ $$|    $$|$$| $$  \ $$                                                                 
          | $$| $$$$$$$$|  $$ / $$/| $$$$$$$$                                                                 
/ $$  | $$| $$__  $$ \  $$ $$/ | $$__  $$                                                                 
| $$  | $$| $$  | $$  \  $$$/  | $$  | $$                                                                 
|  $$$$$$/| $$  | $$   \  $/   | $$  | $$                                                                 
 \______/ |__/  |__/    \_/    |__/  |__/                                                                 
/$$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$  /$$      /$$ /$$      /$$ /$$$$$$$$ /$$$$$$$ 
| $$__  $$| $$__  $$ /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$| $$$    /$$$| $$$    /$$$| $$_____/| $$__  $$
| $$  \ $$| $$  \ $$| $$  \ $$| $$  \__/| $$  \ $$| $$  \ $$| $$$$  /$$$$| $$$$  /$$$$| $$      | $$  \ $$
| $$$$$$$/| $$$$$$$/| $$  | $$| $$ /$$$$| $$$$$$$/| $$$$$$$$| $$ $$/$$ $$| $$ $$/$$ $$| $$$$$   | $$$$$$$/
| $$____/ | $$__  $$| $$  | $$| $$|_  $$| $$__  $$| $$__  $$| $$  $$$| $$| $$  $$$| $$| $$__/   | $$__  $$
| $$      | $$  \ $$| $$  | $$| $$  \ $$| $$  \ $$| $$  | $$| $$\  $ | $$| $$\  $ | $$| $$      | $$  \ $$
| $$      | $$  | $$|  $$$$$$/|  $$$$$$/| $$  | $$| $$  | $$| $$ \/  | $$| $$ \/  | $$| $$$$$$$$| $$  | $$
|__/      |__/  |__/ \______/  \______/ |__/  |__/|__/  |__/|__/     |__/|__/     |__/|________/|__/  |__/
																																																				
																																																				

*/

import java.io.BufferedReader;
import java.text.DecimalFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class abc {
	static PrintWriter pw;
	/*
	 * static long inv[]=new long[1000001]; static long dp[]=new long[1000001];
	 */
	/// MAIN FUNCTION///
	public static void main(String[] args) throws Exception {

		FastReader sc = new FastReader();
		pw = new PrintWriter(System.out);
		// use arraylist as it use the concept of dynamic table(amortized analysis)
		// Arrays.stream(array).forEach(a -> Arrays.fill(a, 0));
		/* List<Integer> l1 = new ArrayList<Integer>(); */
		int tst =1;
		while (tst-- > 0) {
			int n =sc.nextInt();
			int m =sc.nextInt();
			int p =sc.nextInt();
			int a[]=sc.readArray(n);
			int b[]=sc.readArray(m);
			for(int i=0;i<n;i++)
			{
				if(a[i]%p!=0)
				{
					n=i;
					break;
				}
			}
			for(int i=0;i<m;i++)
			{
				if(b[i]%p!=0)
				{
					m=i;
					break;
				}
			}
			pw.println(n+m);
		}
		pw.flush();
	}
	
	static void recursion(int n)
	{
		if(n==1)
		{
			pw.print(n+" ");
			return;
		}
		//pw.print(n+" "); gives us n to 1
		recursion(n-1);
		//pw.print(n+" "); gives us 1 to n
	}
	//ch.charAt(i)+"" converts into a char sequence
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

		/* CREATED BY ME */
		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
	}
	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public static boolean isPrime(long n) {
		if (n == 2)
			return true;
		long i = 2;
		while (i * i <= n) {
			if (n % i == 0)
				return false;
			i++;
		}
		return true;
	}

	static int ceil(int x, int y) {
		return (x % y == 0 ? x / y : (x / y + 1));
	}

	static long ceil(long x, long y) {
		return (x % y == 0 ? x / y : (x / y + 1));
	}

	static int max(int x, int y) {
		return Math.max(x, y);
	}

	static int min(int x, int y) {
		return Math.min(x, y);
	}

	static int abs(int x) {
		return Math.abs(x);
	}

	static long abs(long x) {
		return Math.abs(x);
	}

	static int log2(int N) {
		int result = (int) (Math.log(N) / Math.log(2));
		return result;
	}

	static long max(long x, long y) {
		return Math.max(x, y);
	}

	static long min(long x, long y) {
		return Math.min(x, y);
	}

	public static class pair {
		int x;
		int y;

		public pair(int a, int b) {
			x = a;
			y = b;
		}
	}

	public static class Comp implements Comparator<pair> {
		public int compare(pair a, pair b) {
			if (a.x != b.x) {
				return a.x - b.x;
			} else {
				return a.y - b.y;
			}
		}
	}

	//modular exponentiation
	public static long fastExpo(long a,int n,int mod){
        if (n == 0)
            return 1;
        else{
            if ((n&1) == 1){
                long x = fastExpo(a,n/2,mod);
                return (((a*x)%mod)*x)%mod;
            }
            else{
                long x = fastExpo(a,n/2,mod);
                return (((x%mod)*(x%mod))%mod)%mod;
            }
        }
    }
 
    public static long modInverse(long n,int p){
        return fastExpo(n,p-2,p);
    }
	
	/*
	 * public static void extract(ArrayList<Integer> ar, int k, int d) { int c = 0;
	 * for (int i = 1; i < k; i++) { int x = 0; boolean dm = false; while (x > 0) {
	 * long dig = x % 10; x = x / 10; if (dig == d) { dm = true; break; } } if (dm)
	 * ar.add(i); } }
	 */

	public static int[] prefixfuntion(String s)
	{
		int n=s.length();
		int z[]=new int[n];
		for(int i=1;i<n;i++)
		{
			int j=z[i-1];
			while(j>0 && s.charAt(i)!=s.charAt(j))
				j=z[j-1];
			if(s.charAt(i)==s.charAt(j))
				j++;
			z[i]=j;
		}
		return z;
	}
	public static void dfs(int index, boolean vis[], int a[], int b[], int n) {
		vis[index] = true;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && (a[i] == a[index] || b[i] == b[index]))
				dfs(i, vis, a, b, n);
		}
	}

// counts the set(1) bit of a number
	public static long countSetBitsUtil(long x) {
		if (x <= 0)
			return 0;
		return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
	}

//tells whether a particular index has which bit of a number	
	public static int getIthBitsUtil(int x, int y) {
		return (x & (1 << y)) != 0 ? 1 : 0;
	}

	public static void swap(long x, long y) {
		x = x ^ y;
		y = y ^ x;
		x = x ^ y;
	}

	/*
	 * static long mod_inverse(long a, long b) { long mod=(long) (1000000007); long
	 * ans=1; while(b>0) { if((b%2)==0) ans=(ans*a) %mod; b/=2; a=(a*a) % mod;
	 * 
	 * } return ans; }
	 */

	public static double decimalPlaces(double sum) {
		DecimalFormat df = new DecimalFormat("#.00");
		String angleFormated = df.format(sum);
		double fin = Double.parseDouble(angleFormated);
		return fin;
	}

//use collections.swap for swapping 
	static boolean isSubSequence(String str1, String str2, int m, int n) {
		int j = 0;

		for (int i = 0; i < n && j < m; i++)
			if (str1.charAt(j) == str2.charAt(i))
				j++;

		return (j == m);
	}

	static long sum(long n) {
		long sum = n%10;
		long s2=0,c=1;
		while (n > 0) {
			s2 += (n % 10);
			n = n / 10;
		}
		return s2;
	}

	static long pow(long base, long power) {
		if (power == 0) {
			return 1;
		}
		long result = pow(base, power / 2);
		if (power % 2 == 1) {
			return result * result * base;
		}
		return result * result;
	}

	// return the hash value of a string
	static long compute_hash(String s) {
		long val = 0;
		long p = 31;
		long mod = (long) (1000000007);
		long pow = 1;
		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			val = (val + (int) (ch - 'a' + 1) * pow) % mod;
			pow = (pow * p) % mod;
		}
		return val;
	}

	// return a prefix sum array of hash values
	/*
	 * static void prefix_array_value(String s) { long p=31; long mod=(long)
	 * (1000000007); long pow=1; inv[0]=1; dp[0]=(long)(s.charAt(0)-'a'+1);
	 * 
	 * for(int i=1;i<s.length();i++) { char ch=s.charAt(i); pow= ( pow*p ) % mod;
	 * inv[i]=mod_inverse(pow, mod-2); dp[i]=(dp[i-1]+ (long)(ch- 'a' +1)*pow)%mod;
	 * } }
	 */

	/*
	 * static long substringHash(int L , int R ) { long result = dp[R]; long
	 * mod=(long) (1000000007); if(L > 0) result = (result - dp[L-1] + mod) % mod;
	 * result= (result * inv[L]) % mod; return result; }
	 */
}
