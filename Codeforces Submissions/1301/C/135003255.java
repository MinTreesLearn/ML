

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
	 
	   static class Sort implements Comparator<Pair>
	   {

	       @Override
	       public int compare(Pair a, Pair b)
	       {
	           if(a.x!=b.x)
	           {
	               return (int)(a.x - b.x);
	           }
	           else
	           {
	               return (int)(a.y-b.y);
	           }
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
	  
	   
	  static int recursion(String s,int k,int n) {
		  
		  if(s.length() == n) {
			  
			  int ans = 0;
			  
			  for(int i=0;i<s.length();i++) {
				  if(s.charAt(i)=='1') {
					  ans += s.length()-i;
				  }
				  else {
					  
					  for(int j=i+1;j<s.length();j++) {
						  if(s.charAt(j)=='1') {
							  ans += s.length()-j;
							  break;
						  }
					  }
				  }
			  }
			  
			 System.out.println(s+" "+ans);
			  return ans;
		  }
		  
		  int pos1 = Integer.MIN_VALUE;
		  if(k>0) {
			  pos1 = recursion(s+'1',k-1,n);
		  }
		  
		  int pos2 = recursion(s+'0',k,n);
		  
		  return Math.max(pos1, pos2);
	  }
	   public static void main(String args[]) throws Exception { 
		
		   
		   Scanner sc = new Scanner();
		   StringBuilder res = new StringBuilder();
		
		   int tc = sc.nextInt();
		  
		   while(tc-->0) { 
			
			long n = sc.nextLong();
			long m = sc.nextLong();
			
			long total = (n*(n+1))/2;
			
			long gap = (n-m)/(m+1);
			
			total -= ((gap*(gap+1))/2)*(m+1);
			total -= (gap+1)*((n-m)%(m+1));
			
			res.append(total+"\n");
		   }
		   System.out.println(res);
	   }
}  




