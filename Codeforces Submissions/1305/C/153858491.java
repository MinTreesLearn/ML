import java.util.*;
import java.io.*;
public class Main {
	 	static long mod = 1000000007;
		static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		public static void main(String[] args) throws IOException  {
			FastReader sc = new FastReader();
			int t = 1;
			while( t-- > 0) {
				int n = sc.nextInt();
				int m = sc.nextInt();
				int arr[] = new int[n];
				for( int i = 0 ;i < n ;i++) {
					arr[i] = sc.nextInt();
				}
				if( n > 1000) {
					out.println(0);
				}
				else {
					long ans = 1;
					for( int i = 0 ;i < n ;i++) {
						for( int j = i+1 ;j < n ;j++) {
							ans*=Math.abs(arr[j] - arr[i])%m;
							ans%=m;
						}
					}
					out.println(ans);
				}
			}
			out.flush();
		}
		/*
		 * time for a change 
		 */
		public static boolean ifpowof2(long n ) {
			return ((n&(n-1)) == 0);
		}
		
		static boolean isprime(long x ) {
			if( x== 2) {
				return true;
			}
			if( x%2 == 0) {
				return false;
			}
			for( long i = 3 ;i*i <= x ;i+=2) {
				if( x%i == 0) {
					return false;
				}	
			}
			return true;
		}
		
		static boolean[] sieveOfEratosthenes(long n) { 
			boolean prime[] = new boolean[(int)n + 1];
			for (int i = 0; i <= n; i++) {
				prime[i] = true;
			}
			for (long p = 2; p * p <= n; p++) {   
				if (prime[(int)p] == true) {
					for (long i = p * p; i <= n; i += p)
						prime[(int)i] = false;
				}
			}		 
			return prime;
		}
		
		public static int[] nextLargerElement(int[] arr, int n)	{ 
			Stack<Integer> stack = new Stack<>();
			int rtrn[] = new int[n];
			rtrn[n-1] = -1;
	        stack.push( n-1);
	        for( int i = n-2 ;i >= 0 ; i--){
	            int temp = arr[i];
	            int lol = -1;
	            while( !stack.isEmpty() && arr[stack.peek()] <= temp){
	            	if(arr[stack.peek()] == temp ) {
	            		lol = stack.peek();
	            	}
	                stack.pop();
	            }
	            if( stack.isEmpty()){
	            	if( lol != -1) {
	            		rtrn[i] = lol;
	            	}
	            	else {
	            		rtrn[i] = -1;
	            	}
	            }
	            else{
	            	rtrn[i] = stack.peek();
	            }
	            stack.push( i);
	        }
	        return rtrn;
		}
		
		static void mysort(int[] arr) {
			for(int i=0;i<arr.length;i++) {
	            int rand = (int) (Math.random() * arr.length);
	            int loc = arr[rand];
	            arr[rand] = arr[i];
	            arr[i] = loc;
	        }
	        Arrays.sort(arr);
	    }
		
		
		static void mySort(long[] arr) {
	        for(int i=0;i<arr.length;i++) {
	            int rand = (int) (Math.random() * arr.length);
	            long loc = arr[rand];
	            arr[rand] = arr[i];
	            arr[i] = loc;
	        }
	        Arrays.sort(arr);
	    }
		
		static long gcd(long a, long b)
		{
			if (a == 0)
				return b;
			return gcd(b % a, a);
		}
		
			   
		 static long lcm(long a, long b)
		 {
			 return (a / gcd(a, b)) * b;
		 }
		 

		 static long rightmostsetbit(long n) {
			 return n&-n;
		 }
		 
		 static long leftmostsetbit(long n)
		    {
		        long k = (long)(Math.log(n) / Math.log(2));
		        return k;
		    }
	 
		 static HashMap<Long,Long> primefactor( long n){
			 HashMap<Long ,Long> hm = new HashMap<>();
			 long temp = 0;
			 while( n%2 == 0) {
				 temp++;
				 n/=2;
			 }	
			 if( temp!= 0) {
				 hm.put( 2L, temp);
			 }
			 long c = (long)Math.sqrt(n);
			 for( long i = 3 ; i <= c ; i+=2) {
				 temp = 0;
				 while( n% i == 0) {
					 temp++;
					 n/=i;
				 }
				 if( temp!= 0) {
					 hm.put( i, temp);
				 }
	 		 }
	 		 if( n!= 1) {
	 			 hm.put( n , 1L);
	 		 }
	 		 return hm;	
		 }
		 
		 
		 static ArrayList<Long> allfactors(long abs) {
			 HashMap<Long,Integer> hm = new HashMap<>();
			 ArrayList<Long> rtrn = new ArrayList<>();
			 for( long i = 2 ;i*i <= abs; i++) {
				 if( abs% i == 0) {
					 hm.put( i , 0);
					 hm.put(abs/i, 0);
				 }
			 }
			 for( long x : hm.keySet()) {
				 rtrn.add(x);
			 }
			 
			 if( abs != 0) {
				 rtrn.add(abs);
			 }
			 
			 return rtrn;
		 }
			
		 public static int[][] prefixsum( int n , int m , int arr[][] ){
			 int prefixsum[][] = new int[n+1][m+1];
			 for( int i = 1 ;i <= n ;i++) {
				 for( int j = 1 ; j<= m ; j++) {
					 int toadd = 0;
					 if( arr[i-1][j-1] == 1) {
						 toadd = 1;
					 }
					 prefixsum[i][j] = toadd + prefixsum[i][j-1] + prefixsum[i-1][j] - prefixsum[i-1][j-1];
				 }
			 }
			 return prefixsum;
		 }
		 
		 static class FastReader {
			 BufferedReader br;
			 StringTokenizer st;
		 
			 public FastReader()
			 {
				 br = new BufferedReader(new InputStreamReader(System.in));
			 }
		        
			 String next()
			 {
				 while (st == null || !st.hasMoreElements()) {
					 try {
						 st = new StringTokenizer(br.readLine());
					 }
					 catch (IOException e) {
						 e.printStackTrace();
					 }
				 }
				 return st.nextToken();
			 }
		 
			 int nextInt() { return Integer.parseInt(next()); }
			 
			 long nextLong() { return Long.parseLong(next()); }
			 
			 double nextDouble()
			 {
				 return Double.parseDouble(next());
			 }	
		 
			 String nextLine()
			 {
				 String str = "";
				 try {
					 str = br.readLine();
				 }
				 catch (IOException e) {
					 e.printStackTrace();
				 }
				 return str;
			 }
		 }	
}

