


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
		   
		   int tc = 1;
		  
		   while(tc-->0) {
			   
			   int n = sc.nextInt();
			   
			   String s = sc.next();
			   char a[] = s.toCharArray();
			   
			   Arrays.sort(a);
			   
//			   System.out.println(a);
			   
			   ArrayList<Integer> adj[] = new ArrayList[26];
			   
			   for(int i=0;i<26;i++) {
				   adj[i] = new ArrayList<>();
			   }
			   
			   for(int i=0;i<n;i++) {
				   adj[a[i]-'a'].add(i);
			   }
			   
			   int dir[] = new int[n];
			   
			   for(int i=0;i<n;i++) {
				   if(i < adj[s.charAt(i)-'a'].get(0)) {
					   dir[i] = 1;
					   adj[s.charAt(i)-'a'].remove(0);
				   }
				   else if(i > adj[s.charAt(i)-'a'].get(0)) {
					   dir[i] = -1;
					   adj[s.charAt(i)-'a'].remove(0);
				   }
			   }
			   
			   boolean ok = true;
			   
			   int min = -1;
			   
			   for(int i=0;i<n;i++) {
				   if(dir[i] == 1) {
					   if(min > s.charAt(i) - 'a') {
//						   System.out.println(i + " " + min);
						   ok = false;
					   }
					   else {
						   min = s.charAt(i) - 'a';
					   }
				   }
			   }
			   
			   min = 26;
			   
			   for(int i=n-1;i>=0;i--) {
				   if(dir[i] == -1) {
					   if(min < s.charAt(i) - 'a') {
//						   System.out.println(i + " " + min+" second");
						   ok = false;
					   }
					   else {
						   min = s.charAt(i) - 'a';
					   }
				   }
			   }
			   
			   for(int i=0;i<n;i++) {
				   if(dir[i] == 0) {
					   
					   for(int j=i-1;j>=0;j--) {
						   if(s.charAt(j) > s.charAt(i)) {
							   ok = false;
							   break;
						   }
					   }
					   for(int j=i+1;j<n;j++) {
						   if(s.charAt(j) < s.charAt(i)) {
							   ok = false;
							   break;
						   }
					   }
				   }
			   }
			   if(ok) {
				   res.append("YES"+"\n");
				   for(int i=0;i<n;i++) {
					   if(dir[i]==1) {
						   res.append(1);
					   }
					   else {
						   res.append(0);
					   }
				   }
				   res.append("\n");
			   }
			   else {
				   res.append("NO"+"\n");
			   }
		   }
		   System.out.println(res);
	   }
}  




