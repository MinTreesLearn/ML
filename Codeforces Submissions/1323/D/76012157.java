import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

	//static int p = 1000000007;
	static int p = 998244353;
	
	

	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		//Mod mod = new Mod();
		//mod.precalc();

		int t = 1;
		//t = sc.nextInt();

		
		while (t-- > 0) {
			
			int n = sc.nextInt(), arr[]=new int[n];
			for(int i=0; i<n; i++)
				arr[i]=sc.nextInt();
			
			int ans=0;
			
			for(int i=0; i<25; i++) {
				
				int arr1[] = new int[n];
				for(int j=0; j<n; j++)
					arr1[j] = arr[j]%(1<<i+1);
				Arrays.parallelSort(arr1);
				long cnt =0;
				int l1=-1, l2=-1, l3=-1;
				for(int j=0; j<n; j++) {
					
					if(l1==-1 && arr1[j]+arr1[n-1]>=(1<<i))
						l1=n-1;
					if(l2==-1 && arr1[j]+arr1[n-1]>=(1<<i+1))
						l2=n-1;
					if(l3==-1 && arr1[j]+arr1[n-1]>=(1<<i)+(1<<i+1))
						l3=n-1;
					
					while(l1!=-1 && l1>j && arr1[j]+arr1[l1-1]>=(1<<i))
						l1--;
					while(l2!=-1 && l2>j && arr1[j]+arr1[l2-1]>=(1<<i+1))
						l2--;
					while(l3!=-1 && l3>j && arr1[j]+arr1[l3-1]>=(1<<i)+(1<<i+1))
						l3--;
					
					if(l1!=-1) {
						if(l2==-1)
							cnt+=n-max(j+1,l1);
						else {
							if(l2>j)
								cnt+=l2-max(j+1,l1);
							if(l3!=-1)
								cnt+=n-max(j+1,l3);
						}
					}
					
					//if(i<3)
						//out.println(j+" "+cnt+" "+l1+" "+l2+" "+l3);
					
				}
				ans += (cnt%2)<<i;
			}
			
			out.print(ans);
		}
		out.flush();
	}
	
	
	
    
	static int count(int x, int[] arr) {
		int count = 0;

		for (int i = 0; i < arr.length; i++)
			if (arr[i] == x)
				count++;
		return count;
	}

	public static String reverseString(String str) {
		StringBuilder sb = new StringBuilder(str);
		sb.reverse();
		return sb.toString();
	}

	static boolean isPalindrome(String str) {
		int i = 0, j = str.length() - 1;

		while (i < j) {

			if (str.charAt(i) != str.charAt(j))
				return false;

			i++;
			j--;
		}
		return true;
	}

	static void print(int[] arr) {
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	public static int abs(int x) {
		return ((x > 0) ? x : -x);
	}

	public static long abs(long x) {
		return ((x > 0) ? x : -x);
	}

	public static int max(int a, int b) {
		return Math.max(a, b);
	}

	public static long max(long a, long b) {
		return Math.max(a, b);
	}

	public static int min(int a, int b) {
		return Math.min(a, b);
	}

	public static long min(long a, long b) {
		return Math.min(a, b);
	}

	static int gcd(int a, int b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	static int modInverse(int a, int m) {
		int g = gcd(a, m);
		if (g != 1)
			return -1;
		else
			return power(a, m - 2, m);

	}

	// To compute x^y under modulo m
	static int power(int x, int y, int m) {
		if (y == 0)
			return 1;

		int p = power(x, y / 2, m) % m;
		p = (p * p) % m;

		if (y % 2 == 0)
			return p;
		else
			return (x * p) % m;
	}

	static int[] primeGenerator(int num) {
		int length = 0, arr[] = new int[num], a = num, factor = 1;
		if (num % 2 == 0) {
			while (num % 2 == 0) {
				num /= 2;
				factor *= 2;
			}
			arr[length++] = factor;
		}
		for (int i = 3; i * i <= a; i++) {
			factor = 1;
			if (num % i == 0) {
				while (num % i == 0) {
					num /= i;
					factor *= i;
				}
				arr[length++] = factor;
			}
		}
		if (num > 1)
			arr[length++] = num;
		return Arrays.copyOfRange(arr, 0, length);
	}

	static boolean isPrime(int n) {
		// Corner cases
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		// This is checked so that we can skip
		// middle five numbers in below loop
		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	
	  static class Scanner { BufferedReader br; StringTokenizer st;
	  
	 Scanner() { br = new BufferedReader(new InputStreamReader(System.in)); }
	  
	  Scanner(String fileName) throws FileNotFoundException { br = new
	  BufferedReader(new FileReader(fileName)); }
	  
	  String next() throws IOException { while (st == null || !st.hasMoreTokens())
	  st = new StringTokenizer(br.readLine()); return st.nextToken(); }
	  
	  String nextLine() throws IOException { return br.readLine(); }
	  
	  int nextInt() throws IOException { return Integer.parseInt(next()); }
	  
	  long nextLong() throws NumberFormatException, IOException { return
	  Long.parseLong(next()); }
	  
	  double nextDouble() throws NumberFormatException, IOException { return
	  Double.parseDouble(next()); }
	  
	  boolean ready() throws IOException { return br.ready(); }
	  
	  }
	 

	static void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	static void shuffle(int[] a) {
		int n = a.length;
		Random rand = new Random();
		for (int i = 0; i < n; i++) {
			int tmpIdx = rand.nextInt(n);
			int tmp = a[i];
			a[i] = a[tmpIdx];
			a[tmpIdx] = tmp;
		}
	}
}

class Pair {
	int x;
	int y;

	Pair(int a, int b) {
		x = a;
		y = b;
	}

	void print() {
		System.out.println(this.x + " " + this.y);
	}
}

class Mod{
	static final int MOD = 998244353;
	
	int add(int x, int y){
		x += y;
	    while(x >= MOD) x -= MOD;
	    while(x < 0) x += MOD;
	    return x;
	}
	
	int subtract(int x, int y) {
		x -= y;
	    while(x >= MOD) x -= MOD;
	    while(x < 0) x += MOD;
	    return x;
	}

	int mul(int x, int y)
	{
		int result = (int)((long)x*y % MOD);
	    return result>=0?result:result+MOD;
	}

	int binpow(int x, int y)
	{
	    int z = 1;
	    while(y!=0)
	    {
	        if((y & 1)!=0) 
	        	z = mul(z, x);
	        x = mul(x, x);
	        y >>= 1;
	    }
	    return z;
	}

	int inv(int x)
	{
	    return binpow(x, MOD - 2);
	}

	int divide(int x, int y)
	{
	    return mul(x, inv(y));
	}
	
	static final int N =200043;
	int[] fact;
	
	Mod() {
		fact = new int[N];
	}
	
	void precalc()
	{
	    fact[0] = 1;
	    for(int i = 1; i < N; i++)
	        fact[i] = mul(fact[i - 1], i);
	}

	int C(int n, int k)
	{
	    return divide(fact[n], mul(fact[k], fact[n - k]));
	}
}
