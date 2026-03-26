

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
	  
	  
	   public static void main(String args[]) throws Exception { 
		
		   Scanner sc = new Scanner();
		   StringBuilder res = new StringBuilder();
		  
		   int tc = 1;
		  
		   while(tc-->0) { 
			
			int n = sc.nextInt();
			
			int a[] = new int[n-1];
			
			for(int i=0;i<n-1;i++) {
				a[i] = sc.nextInt();
			}
			
			int start = 1;
			
			int sum = 0;
			
			for(int i=0;i<n-1;i++) {
				
				sum += a[i];
				
				if(sum<0) {
					
					start = Math.max(start, Math.abs(sum)+1);
				}
			}
			
			int ans[] = new int[n];
			
			Set<Integer> set = new HashSet<>();
			
			ans[0] = start;
			set.add(start);
			
			for(int i=1;i<n;i++) {
				ans[i] = ans[i-1] + a[i-1];
				set.add(ans[i]);
			}
			
			boolean flag = true;
			
			for(int i=1;i<=n;i++) {
				if(!set.contains(i)) {
					flag = false;
					break;
				}
			}
			
			if(flag) {
				
				for(int i : ans) {
					res.append(i+" ");
				}
			}
			else {
				res.append(-1);
			}
			
		   }
		  
		   System.out.println(res);
	   }
}  




