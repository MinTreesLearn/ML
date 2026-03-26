/*
    JAI MATA DI
 */

import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.sql.Array;

 public class Codechef {
	  static class FR{
			BufferedReader br;
			StringTokenizer st;
			public FR() {
				br = new BufferedReader(new InputStreamReader(System.in));
			}
			String next() 
		    { 
		        while (st == null || !st.hasMoreElements()) 
		        { 
		            try
		            { 
		                st = new StringTokenizer(br.readLine()); 
		            } 
		            catch (IOException  e) 
		            { 
		                e.printStackTrace(); 
		            } 
		        } 
		        return st.nextToken(); 
		    } 

		    int nextInt() 
		    { 
		        return Integer.parseInt(next()); 
		    } 

		    long nextLong() 
		    { 
		        return Long.parseLong(next()); 
		    } 

		    double nextDouble() 
		    { 
		        return Double.parseDouble(next()); 
		    } 

		    String nextLine() 
		    { 
		        String str = ""; 
		        try
		        { 
		            str = br.readLine(); 
		        } 
		        catch (IOException e) 
		        { 
		            e.printStackTrace(); 
		        } 
		        return str; 
		    } 
		}
	 static long mod  = 1000000007;
	 static int gcd(int a, int b)
	  {      
	     if (b == 0)
	        return a;
	     return gcd(b, a % b); 
	  }
		static void sort(long[] arr ) {
			 ArrayList<Long> al = new ArrayList<>();
			 for(long e:arr) al.add(e);
			 Collections.sort(al);
			 for(int i = 0 ; i<al.size(); i++) arr[i] = al.get(i);
		 }
		static void sort(int[] arr ) {
			 ArrayList<Integer> al = new ArrayList<>();
			 for(int e:arr) al.add(e);
			 Collections.sort(al);
			 for(int i = 0 ; i<al.size(); i++) arr[i] = al.get(i);
		 }
		static int UB(long[] arr , long find , int l , int r) {
			while(l<=r) {
				int m = (l+r)/2;
				if(arr[m]<find) l = m+1;
				else r = m-1;
			}
			return l;
		}
		static int LB(long[] arr , long find,int l ,int r ) {
			while(l<=r) {
				int m = (l+r)/2;
				if(arr[m] > find) r = m-1;
				else l = m+1;
			}
			return r;
		}
		static int UB(int[] arr , long find , int l , int r) {
			while(l<=r) {
				int m = (l+r)/2;
				if(arr[m]<find) l = m+1;
				else r = m-1;
			}
			return l;
		}
		static int LB(int[] arr , long find,int l ,int r ) {
			while(l<=r) {
				int m = (l+r)/2;
				if(arr[m] > find) r = m-1;
				else l = m+1;
			}
			return r;
		}
	 static long gcd(long a, long b)
	  {      
	     if (b == 0)
	        return a;
	     return gcd(b, a % b); 
	  }
	 static boolean[] prime(int num) {
			boolean[] bool = new boolean[num];
		     
		      for (int i = 0; i< bool.length; i++) {
		         bool[i] = true;
		      }
		      for (int i = 2; i< Math.sqrt(num); i++) {
		         if(bool[i] == true) {
		            for(int j = (i*i); j<num; j = j+i) {
		               bool[j] = false;
		            }
		         }
		      }
		      if(num >= 0) {
		    	  bool[0] = false;
		    	  bool[1] = false;
		      }
		      
		      return bool;
		}


/* ***************************************************************************************************************************************************/	 
	 static FR sc = new FR();
	 static StringBuilder sb = new StringBuilder();
	 public static void main(String args[]) {
		
//		 int tc = sc.nextInt();
		 int tc = 1;

		while(tc-- > 0) {
		
			test_case();
		}
		 
		System.out.println(sb);
	 	
	 }
	 
	static void test_case() {
		long n = sc.nextLong() ,mod = sc.nextLong();
		long[] fac = new long[(int)n+1];
		fac[0] = 1;
		for(int i = 1;i<=n ; i++)
			fac[i] = (fac[i-1]*i)%mod;
		
		long ans = (fac[(int)n]*n)%mod;
		for(int i = 2 ; i<=n ; i++) {
			long out = n - (i);
			long terms = n-i+1;
			
			long a = fac[(int)out+1];
			long b = (fac[(int)i])%mod;
			a = (a*b)%mod;
			a  = (terms*a)%mod;
			
//			System.out.println(a+" "+i);
			ans = (ans + (a)%mod)%mod;
		}
		sb.append(ans);
	}

}

































