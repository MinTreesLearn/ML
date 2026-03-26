import java.util.*;
import java.io.*;
public class Main {
		static long mod = 1000000007;
		static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		public static void main(String[] args) throws IOException  {
			FastReader sc = new FastReader();
					int n = sc.nextInt();
					char arr[] = sc.next().toCharArray();
					int fst = 0;
					int scnd = 0;
					for( int i = 0 ;i < n; i++) {
						if( arr[i] == '(') {
							fst++;
						}
						else {
							scnd++;
						}
					}
					if( fst!= scnd) {
						out.println(-1);
					}
					else {
						fst = 0;
						scnd = 0;
						int cost = 0;
						for( int i =0  ;i< n;i++) {
							if( arr[i] == '(') {
								fst++;
							}
							else {
								scnd++;
							}
							if( scnd > fst) {
								int len = 1;
								int count = 1;
								while( i < n-1 && arr[i+1] == ')') {
									i++;
									len++;
									count++;
								}
								while( count!= 0) {
									i++;
									len++;
									if( arr[i] == ')') {
										count++;
									}
									else {
										count--;
									}
								}
								cost+=len;
								fst = scnd;
							}
						}
						out.println(cost);
					}
				out.flush();
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