import java.util.*;
import java.io.*;
public class Main {
		static long mod = 1000000007;
		static long max ;
		static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		public static void main(String[] args) throws IOException  {
			FastReader sc = new FastReader();
			int t = sc.nextInt();
			while( t-- > 0) {
				/*
				 * i will form a arrray or 2n integers assign all integers strating form 1 with diff 2 the value give in b
				 * 
				 */
				HashSet<Integer> hs = new HashSet<>();
				int n = sc.nextInt();
				int b[] = new int[n];
				for( int i = 0 ;i< n ;i++) {
					b[i] = sc.nextInt();
				}
				boolean check = true;
				int arr[] = new int[2*n];
				int j = 0;
				for( int i = 0 ;i < 2*n ;i+=2) {
					arr[i] = b[j];
					hs.add(b[j]);
					j++;
				}
				for( int i = 1 ;i< 2*n ;i+=2) {
					boolean find = false;
					for( j = arr[i-1]+ 1 ; j<=2*n ;j++) {
						if(!hs.contains(j)) {
							find = true;
							arr[i] = j;
							hs.add(j);
							break;
						}
					}
					if( !find) {
						check = false;
					}
				}
				if( check) {
					for( int x : arr) {
						out.print(x+" ");
					}
					out.println();
				}
				else {
					out.println(-1);
				}
			}
			out.flush();
		}
		/*
		 * WARNING -> DONT EVER USE ARRAYS.SORT() IN ANY WAY.
		 * FIRST AND VERY IMP -> READ AND UNDERSTAND THE QUESTION VERY CAREFULLY.
		 * WARNING -> DONT CODE BULLSHIT , ALWAYS CHECK THE LOGIC ON MULTIPLE TESTCASES AND EDGECASES BEFORE. 
		 * SECOND -> TRY TO FIND RELEVENT PATTERN SMARTLY.
		 * WARNING -> IF YOU THINK YOUR SOLUION IS JUST DUMB DONT SUBMIT IT BEFORE RECHECKING ON YOUR END.
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
		        return 1 << k;
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
		 
		 
		 static ArrayList<Integer> allfactors(int abs) {
			 HashMap<Integer,Integer> hm = new HashMap<>();
			 ArrayList<Integer> rtrn = new ArrayList<>();
			 for( int i = 2 ;i*i <= abs; i++) {
				 if( abs% i == 0) {
					 hm.put( i , 0);
					 hm.put(abs/i, 0);
				 }
			 }
			 for( int x : hm.keySet()) {
				 rtrn.add(x);
			 }
			 
			 if( abs != 0) {
				 rtrn.add(abs);
			 }
			 
			 return rtrn;
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


