import java.util.* ;
import java.math.*;
import java.io.*;


public class javaTemplate {
	
	 public static final int M = 1000000007 ;
	static FastReader sc = new FastReader();
	//	static Scanner sc = new Scanner(System.in) ;
	
	public static void main(String[] args) {
		
		
     int t = sc.nextInt() ;
		
		while(t -- != 0) {
			int n = sc.nextInt() ;
			int d = sc.nextInt() ;
			int arr[] = new int[n] ;
			for(int i = 0 ; i< n ; i++) {
				arr[i] = sc.nextInt() ;
			}
			
			while(d -- != 0) {
				for(int i = 1 ; i<n ; i++) {
					if(arr[i] > 0) {
						arr[i]-- ;
						arr[i-1] ++ ;
						break ;
					}
				}
			}
			
			System.out.println(arr[0]);
			
		}
		
		
	}
	

	





			
	
	
	
	 
	
	


	
	
//_________________________//Template//_____________________________________________________________________
	
	
		//		FAST I/O
		static class FastReader {
	        BufferedReader br;
	        StringTokenizer st;
	        
	        public FastReader()
	        {
	            br = new BufferedReader(
	                new InputStreamReader(System.in));
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
	
	
		
		
//		Check Perfect Squre
		public static boolean checkPerfectSquare(double number) {   
			
			double sqrt=Math.sqrt(number);   
		
			return ((sqrt - Math.floor(sqrt)) == 0);   
		}   
		
		
		
		
		
		static boolean isPrime(int n) {
	        
	        if (n <= 1) return false;
	  
	        for (int i = 2; i < n; i++) {
	            if (n % i == 0) return false;
	        	}
	  
	        return true;
	    }
		
		
		
		
		// Modulo
		static int mod(int a)
		{
		    return (a%M + M) % M;
		}
		
		
		
		
		
			
			
		
		
		
		//		Palindrom or Not
		static boolean isPalindrome(StringBuilder str, int low, int high) {
					
					while (low < high) {
						if (str.charAt(low) != str.charAt(high)) return false;
					 	low++;
					 	high--;
					}
					return true;
				}
	
	
		// Euler Tortient fx
	static int Phi(int n) {
		
		int count = 0 ;
		for(int i = 1 ; i< n ; i++) {
			if(GCD(i,n) == 1) count ++ ;
		}
		return count ;
	}
	
	
	
		// Integer Sort
		static void sort(int[] a) 
		   {
				ArrayList<Integer> l=new ArrayList<>();
				for (int i:a) l.add(i);
				Collections.sort(l);
				for (int i=0; i<a.length; i++) a[i]=l.get(i);
			}
	
		
		
		
		// Long Sort
		static void sort(long[] a) 
		   {
				ArrayList<Long> l=new ArrayList<>();
				for (long i:a) l.add(i);
				Collections.sort(l);
				for (int i=0; i<a.length; i++) a[i]=l.get(i);
			}
	
	
		
		// boolean Value
		static void value(boolean val)
	    {
	       System.out.println(val ? "YES" : "NO");
	       System.out.flush();
	    }
	
	
		
	
		// GCD
		public static int GCD(int a , int b) {
				if(b == 0) return a ;
				
				return GCD(b, a%b) ;
			}
	
		
		
		
		
		
		// sieve
		public static boolean [] sieveofEratosthenes(int n) {
			
			boolean isPrime[] = new boolean[n+1] ;
			Arrays.fill(isPrime, true);
			isPrime[0] = false ;
			isPrime[1] = false ;
			
			for(int i = 2 ; i * i <= n ; i++) {
				
				for(int j = 2 * i ; j<= n ; j+= i) {
					isPrime[j] = false ;
				}
			}
			
			return isPrime ;
		}
		
		
		
		
		// fastPower
		public static long fastPowerModulo(long a, long b, long n) {
			
			long res = 1 ;
			
			while(b > 0) {
			if((b&1) != 0) {
				res = (res * a % n) % n ;
			}
			
			a = (a % n * a % n) % n ;
			b = b >> 1 ;
			}
			
			return res ;
		}
		
		
		
		
		// check if sorted or not	
		public static boolean isSorted(int[] a)
	    {
	        for (int i = 0; i < a.length - 1; i++)
	        {
	            if (a[i] > a[i + 1]) {
	                return false;
	            }
	        }
	 
	        return true;
	    }
	
	
		
		
		
    	static int LCM(int a, int b)
	    {
	        return (a / GCD(a, b)) * b;
	    }
	

}











