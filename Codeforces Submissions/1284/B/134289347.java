import java.util.*;
import java.io.*;
public class Main {
		static long mod = 1000000007;
		static long max ;
		static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		public static void main(String[] args) throws IOException  {
			FastReader sc = new FastReader();
				/*
				 * check for increasing and decreasing 
				 * if increasing add 2*n - 1 and if decreasing add 1 
				 * update n on the way 
				 * make two array one for the minimum and one for the maximum and if decreasing
				 */
			int n = sc.nextInt();
			long ans = 0;
			int temp = n;
			ArrayList<Integer> min = new ArrayList<>();
			ArrayList<Integer> max = new ArrayList<>();
			for( int i = 0 ;i < n ;i++) {
				boolean incr = false;
				boolean dec = false;
				int mi = Integer.MAX_VALUE;
				int ma = Integer.MIN_VALUE;
				int size = sc.nextInt();
				int arr[] = new int[size];
				arr[0] = sc.nextInt();
				mi = Math.min(mi , arr[0]);
				ma = Math.max(ma, arr[0]);
				for( int j = 1 ;j < size ;j++) {
					arr[j] = sc.nextInt();
					mi = Math.min(mi , arr[j]);
					ma = Math.max(ma, arr[j]);
					int t = arr[j];
					if( t > arr[j-1]) {
						incr = true;
					}
					if( t < arr[j-1]) {
						dec = true;
					}
				}
				if( incr) {
					ans+=2*temp - 1;
					temp--;
				}
				else {
//					if( dec) {
//						ans++;
//					}
					min.add(mi);
					max.add(ma);
				}
			}
	
			int size = min.size();
			if( size != 0) {
			Collections.sort(max);
//			out.println(min);
//			out.println(max);
			int ma = max.get(size - 1);
			for( int i = 0 ;i < size ;i++) {
				if( min.get(i) >= ma) {
					continue;
				}
				else {
					ans+=solve( max , min.get(i) , size );
				}
			}
			}
			out.println(ans);
			out.flush();	
		}
	
		private static long solve(ArrayList<Integer> max, int min, int size) {
			int i = 0;
			int j = size - 1;
			int ans = Integer.MAX_VALUE;
			int mid = (i+1)/2;
			while( i <= j) {
				if( max.get(mid) <= min){
					i = mid+1;
				}
				else {
					ans = Math.min(ans, mid);
					j = mid - 1;
				}
				mid = (i+j)/2;
			}
			return size - ans;
		}

		public static boolean ifpowof2(long n ) {
			return ((n&(n-1)) == 0);
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
		
		@SuppressWarnings("unused")
		private static void mysort(int[] arr) {
	        for(int i=0;i<arr.length;i++) {
	            int rand = (int) (Math.random() * arr.length);
	            int loc = arr[rand];
	            arr[rand] = arr[i];
	            arr[i] = loc;
	        }
	        Arrays.sort(arr);
	    }
		
		@SuppressWarnings("unused")
		private static void mySort(long[] arr) {
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
		 
		 @SuppressWarnings("unused")
		private static ArrayList<Integer> allfactors(int abs) {
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
