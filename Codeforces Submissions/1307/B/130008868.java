import java.util.*;
import java.io.*;
public class Main {
		static long mod = 1000000007;
		static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		public static void main(String[] args) throws IOException  {
			FastReader sc = new FastReader();
				int t = sc.nextInt();
				while( t-- > 0) {
					int n =sc.nextInt();
					boolean check = false;
					double x= sc.nextDouble();
					boolean equal = false;
					double max = Double.MIN_VALUE;
					for( int i = 0 ;i < n; i++) {
						double temp =sc.nextDouble();
						if( temp >= x/2 ) {
							check = true;
						}
						if( temp == x) {
							equal = true;
						}
						max = Math.max(max, temp);
					}
					if( equal) {
						out.println(1);
					}
					else if( check) {
						out.println(2);
					}
					else {
						double temp = (x-2*max)/max;
						//out.println(temp);
						long ans = find( temp);
						out.println(ans+2);
					}
				}
				out.flush();
		}
		
		private static long find(double temp) {
			if( (long) temp == temp) {
				return (long)temp;
			}
			else {
				return (long)temp + 1;
			}
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
		
		static int gcd(int a, int b)
		{
			if (a == 0)
				return b;
			return gcd(b % a, a);
		}
		
			   
		 static int lcm(int a, int b)
		 {
			 return (a / gcd(a, b)) * b;
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