


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
	 
	  static int dfs(int src,int par,ArrayList<Integer> adj[],int child[]) {
		  
		  int node = 1;
		  
		  for(int i : adj[src]) {
			  if( i == par) {
				  continue;
			  }
			  node += dfs(i,src,adj,child);
		  }
		  
		  child[src] = node - 1;
		  
		  return node;
	  }
	  
	  static int get(int pos,ArrayList<Integer> list) {
		  
		  int ans = list.get(pos);
		  
		  for(int i=pos;i<list.size()-1;i++) {
			  list.set(i, list.get(i+1));
		  }
		  list.remove(list.size()-1);
		  
		  return ans;
	  }
	  
	  static void dfs(int src,int par,ArrayList<Integer> adj[],int ans[],int c[],ArrayList<Integer> list) {
		  
		  ans[src] = get(c[src],list);
		  
		  for(int i : adj[src]) {
			  if(i == par) {
				  continue;
			  }
			  dfs(i,src,adj,ans,c,list);
		  }
	  }
	   public static void main(String args[]) throws Exception { 
		
		   Scanner sc = new Scanner();
		   StringBuilder res = new StringBuilder();
		   
		   int tc = 1;
		  
		   while(tc-->0) {
			   
			   int n = sc.nextInt();
			   
			   ArrayList<Integer> adj[] = new ArrayList[n];
			   
			   for(int i=0;i<n;i++) {
				   adj[i] = new ArrayList<>();
			   }
			   int root = -1;
			   int c[] = new int[n];
			   
			   for(int i=0;i<n;i++) {
				   
				   int par = sc.nextInt();
				   int val = sc.nextInt();
				   
				   if(par != 0) {
					   par--;
					   adj[par].add(i);
					   adj[i].add(par);
				   }
				   else {
					   root = i;
				   }
				   
				   c[i] = val;
			   }
			   
			   int child[] = new int[n];
			   
			   dfs(root,-1,adj,child);
			   
//			   for(int i=0;i<n;i++) {
//				   System.out.print(child[i]+" ");
//			   }
//			   System.out.println();
			   boolean ok = true;
			   
			   for(int i=0;i<n;i++) {
				   if(child[i] < c[i]) {
					   ok = false;
					   break;
				   }
			   }
			   
			   if(!ok) {
				   res.append("NO"+"\n");
				   continue;
			   }
			   
			   int ans[] = new int[n];
			   
			   ArrayList<Integer> list = new ArrayList<>();
			   
			   for(int i = 1;i<=n;i++) {
				   list.add(i);
			   }
			   dfs(root,-1,adj,ans,c,list);
			   
			   res.append("YES"+"\n");
			   for(int i=0;i<n;i++) {
				   res.append(ans[i]+" ");
			   }
		   }
		   System.out.println(res);
	   }
}  




