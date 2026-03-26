


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
	 static int max[] = new int[200005];
	 static int ans[] = new int[200005];
	   static void dfs(int src,int par,ArrayList<Integer> adj[],int a[]) {
		   
		   max[src] = a[src];
		   for(int i : adj[src]) {
			      
			   if(i == par) {
				   continue;
			   }
				   dfs(i,src,adj,a);
				   max[src] += Math.max(0, max[i]);
			   
		   }
		   
	   }
	   
	   static void dfs(int src,int par,ArrayList<Integer> adj[]) {
		   
		   ans[src] = max[src];
		   
		   for(int i : adj[src]) {
			   if(i == par) {
				   continue;
			   }
			   
			   max[src] -= Math.max(0, max[i]);
			   max[i] += Math.max(0, max[src]);
			   
			   dfs(i,src,adj);
			   
			   max[i] -= Math.max(0, max[src]);
			   max[src] += Math.max(0, max[i]);
		   }
	   }
	   public static void main(String args[]) throws Exception { 
		
		   Scanner sc = new Scanner();
		   StringBuilder res = new StringBuilder();
		   
		   int tc = 1;
		  
		   while(tc-->0) {
			   
			   int n = sc.nextInt();
			   
			   int a[] = new int[n];
			   
			   for(int i=0;i<n;i++) {
				   a[i] = sc.nextInt();
				   if(a[i] == 0) {
					   a[i] = -1;
				   }
			   }
			   
			   ArrayList<Integer> adj[] = new ArrayList[n];
			   
			   for(int i=0;i<n;i++) {
				   adj[i] = new ArrayList<>();
			   }
			   
			   for(int i=0;i<n-1;i++) {
				   int src = sc.nextInt()-1;
				   int dest = sc.nextInt()-1;
				   
				   adj[src].add(dest);
				   adj[dest].add(src);
			   }
			   
			   dfs(0,-1,adj,a);
			   dfs(0,-1,adj);
			   
			   for(int i=0;i<n;i++) {
				   res.append(ans[i]+" ");
			   }
			   
		   }
		   System.out.println(res);
	   }
}  




