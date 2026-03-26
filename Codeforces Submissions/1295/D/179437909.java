


import java.io.*;
import java.math.*;
import java.util.*;




// @author : Dinosparton 

public class test {
	 
	   static class Pair{ 
		   long x;
		   long y;
		   
		   Pair(long x,long y){ 
			   this.x = x;
			   this.y = y;
			  
		   }
	   }
	   
	 
	   static class Compare { 
		   
		     void compare(Pair arr[], int n) 
		    { 
		        // Comparator to sort the pair according to second element 
		        Arrays.sort(arr, new Comparator<Pair>() { 
		            @Override public int compare(Pair p1, Pair p2) 
		            { 
		            	if(p1.x!=p2.x) {
		                return (int)(p1.x - p2.x); 
		            	}
		            	else { 
		            		return (int)(p1.y - p2.y);
		            	}
		            } 
		        }); 
		  
//		        for (int i = 0; i < n; i++) { 
//		            System.out.print(arr[i].x + " " + arr[i].y + " "); 
//		        } 
//		        System.out.println(); 
		    } 
		} 
	 
	   static class Scanner {
	        BufferedReader br;
	        StringTokenizer st;
	 
	        public Scanner()
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
	 
	   static long function(long n)
	   {
	       long ans=n;
	       for(long i=2;i*i<=n;i++)
	       {
	           if(n%i==0)
	           {
	               while(n%i==0)n/=i;
	               
	               ans=ans-ans/i;
	           }
	       }
	       if(n>1)
	           ans=ans-ans/n;
	       return ans;
	   }
	   static long gcd(long a, long b)
	    {
	        if (a == 0)
	            return b;
	        return gcd(b % a, a);
	    }
	   public static void main(String args[]) throws Exception { 
		
		   Scanner sc = new Scanner();
		   StringBuilder res = new StringBuilder();
		   
		   int tc = sc.nextInt();
		  
		   while(tc-->0) {
			   
			   long a = sc.nextLong();
			   long m = sc.nextLong();
			   
			   res.append(function(m/gcd(a,m))+"\n");
		   }
		   System.out.println(res);
	   }
}  




