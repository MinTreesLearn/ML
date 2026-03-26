


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
	   
	
	   public static void main(String args[]) throws Exception { 
		
		   Scanner sc = new Scanner();
		   StringBuilder res = new StringBuilder();
		  
		   int tc = sc.nextInt();
		  
		   while(tc-->0) {
			   
			   int n = sc.nextInt();
			   long x = sc.nextLong();
			   
			   String s = sc.next();
			   
			   int cnt = 0;
			   
			   for(int i=0;i<n;i++) {
				   if(s.charAt(i)=='0') {
					   cnt++;
				   }
				   else {
					   cnt--;
				   }
			   }
			  
			   int ans = 0;
			  
			   int bal = 0;
			   for(int i=0;i<n;i++) {
				  
				   if(cnt == 0) {
					   if(bal == x) {
						   ans = -1;
						   break;
					   }
				   }
				   else if(Math.abs(x - bal)%Math.abs(cnt) == 0 && (x-bal)/cnt>=0) {
					   ans++;
				   }
				   
				   if(s.charAt(i)=='0') {
					   bal++;
				   }
				   else {
					   bal--;
				   }
			   }
			   
			   res.append(ans+"\n");
		   }
		   System.out.println(res);
	   }
}  




