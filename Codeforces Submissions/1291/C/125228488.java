
import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

public class A {

	static FastReader		sc	= new FastReader();
	static PrintWriter	out	= new PrintWriter(System.out);
	
	public static void main(String[] args) throws Exception {


		int t =sc.ni();
		while (t-- > 0) {
			A.go();
		}
		out.flush();
		
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Code Starts <<<<<<<<<<<<<<<<<<<<<<<<<<<<< //

	static void go() {
		int n=sc.ni(),m=sc.ni(),k=sc.ni();
		int a[]=sc.intArray(n);
		dp=new int[n+1][n+1];
		for(int i=0;i<dp.length;i++) {
			Arrays.fill(dp[i],-1);
		}
		out.println(solve(a,0,n-1,k,1,m));
		
	}
	static int dp[][];
static int solve(int a[],int pos1,int pos2,int k,int c,int m) {
	int res1,res2;
	res1=0;res2=0;;

	if(c==m) {
		return Math.max(a[pos1],a[pos2]);
	}	
	if(dp[pos1][pos2]!=-1) {
		return dp[pos1][pos2];
	}
	if(dp[pos1][pos2]!=-1) {
		return dp[pos1][pos2];
	}

	if(k>0) {
		res1=solve(a,pos1+1,pos2,k-1,c+1,m);
		res2=solve(a,pos1,pos2-1,k-1,c+1,m);
		return dp[pos1][pos2]=Math.max(res1,res2);
	}else {
		return dp[pos1][pos2]=Math.min(solve(a,pos1+1,pos2,k,c+1,m),solve(a,pos1,pos2-1,k,c+1,m));
	}
}
	
	static class helper implements Comparable<helper>{
		int x,y;
		helper(int x,int y){
			this.x=x;
			this.y=y;
		}

		@Override
		public int compareTo(helper o) {
			// TODO Auto-generated method stub
			return Integer.compare(this.x,o.x);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			helper other = (helper) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
	
	}

	static void   prints(char  a[][]) {

	for(int i=0;i<a.length;i++) {
		for(int j=0;j<a[i].length;j++) {
			out.print(a[i][j]);
		}
		out.println();
	}
}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Code Ends <<<<<<<<<<<<<<<<<<<<<<<<<<<<< //
	static long fact[];
	static long invfact[];
	static long ncr(int n,int k) {
		if(k<0||k>n) {
			return 0;
		}
		long x=fact[n]%mod;
		long y=invfact[k]%mod;
		long yy=invfact[n-k]%mod;
		long ans=(x*y)%mod;
		ans=(ans*yy)%mod;
		return ans;
	}
	static long gcd(long a, long b) {
		if (b==0) {
			return a;
		}return gcd(b, a%b);
	}
	
	static int	prime[]	= new int[200005];
	static int	N				= 200005;
	
	static void sieve() {
	
		for(int i=0;i<N;i++) {
			prime[i]=i;
	}
		for (int i = 2; i * i <= N; i++) {
			if (prime[i] == i) {
				prime[i]=i;
				for (int j = i; j < N; j += i) {
					prime[j] =i;
				}}}
	}
	
	
	static int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}return gcd(b, a % b);
	}
	 static void sort(int[] a) {
		ArrayList<Integer> aa = new ArrayList<>();
		for (Integer i : a) {
			aa.add(i);	}
		Collections.sort(aa);
		for (int i = 0; i < a.length; i++)
			a[i] = aa.get(i);}
	
	 static void sort(long[] a) {
		ArrayList<Long> aa = new ArrayList<>();
		for (Long i : a) {
			aa.add(i);}
		Collections.sort(aa);
		for (int i = 0; i < a.length; i++)
			a[i] = aa.get(i);
	}
	
	static int mod = (int) 998244353;
	
	static long pow(long x, long y) {
		long res = 1l;
		while (y != 0) {
			if (y % 2 == 1) {
				res = (x%mod * res%mod)%mod;
				}	y /= 2;
				x = (x%mod * x%mod)%mod;
		}
		return res%mod;
	}
	
	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Fast IO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< //
	
	static class FastReader {
		BufferedReader	br;
		StringTokenizer	st;
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}	
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}		}	return st.nextToken();
		}	
		int ni() {
			return Integer.parseInt(next());
		}	long nl() {
			return Long.parseLong(next());
		}	double nextDouble() {
			return Double.parseDouble(next());
		}



		int[] intArray(int n) {
			int a[]=new int[n];
			for(int i=0;i<n;i++)a[i]=sc.ni();
			return a;
		}
		long[] longArray(int n) {
			long a[]=new long[n];
			for(int i=0;i<n;i++)a[i]=sc.nl();
			return a;
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}	}}
