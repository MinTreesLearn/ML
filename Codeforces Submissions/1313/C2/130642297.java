
import java.util.*;
import java.util.concurrent.CompletableFuture;

import javax.swing.event.TreeExpansionEvent;
import javax.swing.text.Segment;


import java.io.*;
import java.math.*;
import java.sql.Array;



public class Main {
	  static class Reader{
		  
			BufferedReader br;
			StringTokenizer st;
			public Reader() {
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
	 
	  static long mod = (long)(1e9 + 7);
	 
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
	static void sort(char[] arr) {
		ArrayList<Character> al = new ArrayList<Character>();
		for(char cc:arr) al.add(cc);
		Collections.sort(al);
		for(int i = 0 ;i<arr.length ;i++) arr[i] = al.get(i);
	}
	static void rvrs(int[] arr) {
		int i =0 , j = arr.length-1;
		while(i>=j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	static long[] rvrs(long[] arr) {
		int i =0 , j = arr.length-1;
		int n = arr.length;
		long[] ans = new long[n];
		for( i =0 ; i<n ; i++)
			ans[i] = arr[j--];
		return ans;
	}

	static long mod_mul(long a , long b ,long mod) {
		return ((a%mod)*(b%mod))%mod;
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

	 static long modInverse(long a, long m)
	    {
	        long g = gcd(a, m);
	       
	          return   power(a, m - 2, m);
	        
	    }
	   
	 static long power(long x, long y, long m){
	        if (y == 0) return 1; long p = power(x, y / 2, m) % m; p = (int)((p * (long)p) % m);
	        if (y % 2 == 0) return p; else return (int)((x * (long)p) % m); }
	   
     static class Combinations{
	    	 private long[] z;
	    	 private long[] z1;
	    	 private long[] z2;
	    	 long MOD;
	    	  public Combinations(long N , long mod) {
	    		  MOD  = mod;
				z = new long[(int)N+1];
				z1 = new long[(int)N+1];
				z[0] = 1;
				for(int i =1 ; i<=N ; i++) z[i] = (z[i-1]*i)%MOD;
			     z2 = new long[(int)N+1];
				z2[0] = z2[1] = 1;
			    for (int i = 2; i <= N; i++)
			        z2[i] = z2[(int)(MOD % i)] * (MOD - MOD / i) % MOD;
			    
			    
			    z1[0] = z1[1] = 1;
			    
			    for (int i = 2; i <= N; i++)
			        z1[i] = (z2[i] * z1[i - 1]) % MOD;
			}
	    	  long fac(long n) {
	    		  return z[(int)n];
	    	  }
	    	  long invrsNum(long n) {
	    		  return z2[(int)n];
	    	  }
	    	  long invrsFac(long n) {
	    		  return invrsFac((int)n);
	    	  }
	    	  long ncr(long N, long R)
	    	  {		if(R<0 || R>N ) return 0;
	    		    long ans = ((z[(int)N] * z1[(int)R])
	    		              % MOD * z1[(int)(N - R)])
	    		             % MOD;
	    		    return ans;
	    		}
	      }
	      static class DisjointUnionSets {
			    int[] rank, parent;
			    int n;
			  
			    public DisjointUnionSets(int n)
			    {
			        rank = new int[n];
			        parent = new int[n];
			        this.n = n;
			        makeSet();
			    }
			  
			    void makeSet()
			    {
			        for (int i = 0; i < n; i++) {
			          
			            parent[i] = i;
			        }
			    }
			  
			    int find(int x)
			    {
			        if (parent[x] != x) {
			        
			            parent[x] = find(parent[x]);
			  
			        }
			  
			        return parent[x];
			    }
			  
			    void union(int x, int y)
			    {
			        int xRoot = find(x), yRoot = find(y);
			  
			        if (xRoot == yRoot)
			            return;
			  
			        if (rank[xRoot] < rank[yRoot])
			  
			            parent[xRoot] = yRoot;
			  
			        else if (rank[yRoot] < rank[xRoot])
			  
			            parent[yRoot] = xRoot;
			  
			        else
			        {
			            parent[yRoot] = xRoot;
			  
			            rank[xRoot] = rank[xRoot] + 1;
			        }
			    }
			}
	      static int[] KMP(String str) {
	    	  int n = str.length();
	    	  int[] kmp = new int[n];
	    	  for(int i = 1 ; i<n ; i++) {
	    		  int j = kmp[i-1];
	    		  while(j>0 && str.charAt(i) != str.charAt(j)) {
	    			  j = kmp[j-1];
	    		  }
	    		  if(str.charAt(i) == str.charAt(j)) j++;
	    		  kmp[i] = j;
	    	  }
	    	  
	    	  return kmp;
	      }
	      
	      
/************************************************ Query **************************************************************************************/	  
	 
/***************************************** 		Sparse Table	********************************************************/
	      static class SparseTable{
	    		
	    		private long[][] st;
	    		
	    		SparseTable(long[] arr){
	    			int n = arr.length;
	    			st = new long[n][25];
	    			log = new int[n+2];
	    			build_log(n+1);
	    			build(arr);
	    		}
	    		
	    		private void build(long[] arr) {
	    			int n = arr.length;
	    			
	    			for(int i = n-1 ; i>=0 ; i--) {
	    				for(int j = 0 ; j<25 ; j++) {
	    					int r = i + (1<<j)-1;
	    					if(r>=n) break;
	    					if(j == 0 ) st[i][j] = arr[i];
	    					else st[i][j] = Math.min(st[i][j-1] , st[ i + ( 1 << (j-1) ) ][ j-1 ] );
	    				}
	    			}
	    		}
	    		public long gcd(long a  ,long b) {
	    			if(a == 0) return b;
	    			return gcd(b%a , a);
	    		}
	    		public long query(int l ,int r) {
	    			
	    			int w = r-l+1;
	    			int power = log[w];
	    			return Math.min(st[l][power],st[r - (1<<power) + 1][power]);
	    		}
	    		private int[] log;
	    		void build_log(int n) {
	    			log[1] = 0;
	    			for(int i = 2 ; i<=n ; i++) {
	    				log[i] = 1 + log[i/2];
	    			}
	    		}
	    	}
	      
	      
/********************************************************	Segement Tree	*****************************************************/
/**
	 	 static class SegmentTree{
			 long[] tree;
			 long[] arr;
			 int n;
			 SegmentTree(long[] arr){
				 this.n = arr.length;
				 tree = new long[4*n+1];
				 this.arr = arr;
				 buildTree(0, n-1, 1);
			 }
			 
			 
			  void buildTree(int s ,int e  ,int index ) {
					if(s == e) {
						tree[index] = arr[s];
						return;
					}
				
					int mid = (s+e)/2;
					
					buildTree( s,  mid, 2*index);
					buildTree( mid+1, e, 2*index+1);
					
					tree[index] = Math.min(tree[2*index] , tree[2*index+1]);
				}
			  
			 long query(int si ,int ei) {
				 return query(0 ,n-1 , si ,ei , 1   );
			 }
			 private long query( int ss ,int se ,int qs , int qe,int index) {
					
					if(ss>=qs && se<=qe) return tree[index];
					
					if(qe<ss || se<qs) return (long)(1e17);
					
					int mid = (ss + se)/2;
					long left = query( ss , mid , qs ,qe , 2*index);
					long right= query(mid + 1 , se , qs ,qe , 2*index+1);
					return Math.min(left, right);
				}
			 public void update(int index , int val) {
				 arr[index] = val;
				 for(long e:arr) System.out.print(e+" ");
				 update(index , 0 , n-1 , 1);
			 }
			 private void update(int id ,int si , int ei , int index) {
				 if(id < si || id>ei) return;
				 if(si == ei ) { 
					 tree[index] = arr[id];
					 return;
				 }
				 if(si > ei) return;
				 int mid = (ei + si)/2;
					
					update( id,  si, mid , 2*index);
					update( id , mid+1, ei , 2*index+1);
					
					tree[index] = Math.min(tree[2*index] ,tree[2*index+1]);
			 }
			  
		 }
		 */

/* ***************************************************************************************************************************************************/	 
	 
	      static Reader sc = new Reader();
	 static StringBuilder sb = new StringBuilder();
	 public static void main(String args[])  {
	
		 int tc = 1;
//		  tc = sc.nextInt();

		  for(int i = 1 ; i<=tc ; i++) {

//			 sb.append("Case #" + i + ": "  );	// During KickStart && HackerCup
			 TEST_CASE();
			 
		 }
		 System.out.println(sb);

	 }
	 
	static void TEST_CASE() {
		int n = sc.nextInt();
		long[] arr = new long[n];
		for(int i =0 ; i <n ; i++) {
			arr[i] = sc.nextLong();
		}
		if( n <=2) {
			for(long e:arr) sb.append(e+" ");
			return;
		}
		long[] left = arr(arr);
		arr = rvrs(arr);
		long[] right = arr(arr);
		right = rvrs(right);
		arr = rvrs(arr);
		long min = Long.MAX_VALUE;
		int ind = -1;
		for(int i =0 ; i<n ; i++) {
			long v = left[i] + right[i];
			if(v<min) {
				min = v;
				ind = i;
			}
		}
		for(int i = ind-1 ; i>=0 ; i--) {
			arr[i]  =Math.min(arr[i], arr[i+1]);
			
		}
		for(int i = ind+1 ; i<n ; i++) {
		arr[i]  = Math.min(arr[i], arr[i-1]);	
		}
		for(long e:arr) sb.append(e+" ");
		
		
	}
	
	static long[] arr(long[] arr) {
		int n = arr.length;
		Stack<Integer> st = new Stack<>();
		int[] tree = new int[n];
		for(int i = 0 ; i<n ; i++) {
			while(!st.isEmpty() && arr[st.peek()]> arr[i]) {
				st.pop();
			}
			if(st.isEmpty()) tree[i] = -1;
			else tree[i] = st.peek();
			st.push(i);
		}
		long[] pre = new long[n];

		pre[0] = arr[0];
		for(int i = 1 ; i<n ; i++) pre[i] += arr[i] + pre[i-1];

		long[] left = new long[n];
	
		for(int i =0 ; i< n ; i++) {
			if(tree[i]!=-1) {
				int ind = tree[i];
			
				left[i] += left[ind];
				left[i] += pre[i-1] - pre[ind];
				left[i] -= (i-1-ind)*arr[i];
			}else {

				if(i!=0) {
					left[i] += pre[i-1] - (i)*arr[i];
				}
			}
	
		}
		return left;
	}
		
}

/*******************************************************************************************************************************************************/

/**
  7 5 3 4 9 8 2 4 7
   
  9 8 7 6 5 4 2 1
 */






