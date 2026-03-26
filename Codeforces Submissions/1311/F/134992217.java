
import java.util.*;

import javax.swing.text.Segment;

import java.io.*;
import java.math.*;
import java.sql.Array;
import java.sql.ResultSet;
import java.sql.SQLException;



public class Main {
	  static class Scanner{
		  
			BufferedReader br;
			StringTokenizer st;
			public Scanner() {
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
	static void rvrs(long[] arr) {
		int i =0 , j = arr.length-1;
		while(i>=j) {
			long temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	static long mod_mul(  long mod , long... a) {
		long ans = a[0]%mod;
		for(int i = 1 ; i<a.length ; i++) {
			ans = (ans * (a[i]%mod))%mod;
		}
		
		return ans;
	}
	static long mod_sum(long mod , long... a) {
		long ans = 0;
		for(long e:a) {
			ans = (ans + e)%mod;
		}
		return ans;
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
	   static long lcm(long a , long b) {
		   return (a*b)/gcd(a, b);
	   }
	   static int lcm(int a , int b) {
		   return (int)((a*b)/gcd(a, b));
	   }
	 static long power(long x, long y, long m){
	        if (y == 0) return 1; long p = power(x, y / 2, m) % m; p = (int)((p * (long)p) % m);
	        if (y % 2 == 0) return p; else return (int)((x * (long)p) % m); }
	   
     static class Combinations{
	    	 private long[] z;
	    	 private long[] z1;
	    	 private long[] z2;
	    	  public Combinations(long N , long mod) {
				z = new long[(int)N+1];
				z1 = new long[(int)N+1];
				z[0] = 1;
				for(int i =1 ; i<=N ; i++) z[i] = (z[i-1]*i)%mod;
			     z2 = new long[(int)N+1];
				z2[0] = z2[1] = 1;
			    for (int i = 2; i <= N; i++)
			        z2[i] = z2[(int)(mod % i)] * (mod - mod / i) % mod;
			    
			    
			    z1[0] = z1[1] = 1;
			    
			    for (int i = 2; i <= N; i++)
			        z1[i] = (z2[i] * z1[i - 1]) % mod;
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
	    	  long ncr(long N, long R, long mod)
	    	  {		if(R<0 || R>N ) return 0;
	    		    long ans = ((z[(int)N] * z1[(int)R])
	    		              % mod * z1[(int)(N - R)])
	    		             % mod;
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
	      static int max(int... a ) {
	    	  int max = a[0];
	    	  for(int e:a) max = Math.max(max, e);
	    	  return max;
	      }
	      static long max(long... a ) {
	    	  long max = a[0];
	    	  for(long e:a) max = Math.max(max, e);
	    	  return max;
	      }
	      static int min(int... a ) {
	    	  int min = a[0];
	    	  for(int e:a) min = Math.min(e, min);
	    	  return min;
	      }
	      static long min(long... a ) {
	    	  long min = a[0];
	    	  for(long e:a) min = Math.min(e, min);
	    	  return min;
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
	    					else st[i][j] = Math.max(st[i][j-1] , st[ i + ( 1 << (j-1) ) ][ j-1 ] );
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
	    			return Math.max(st[l][power],st[r - (1<<power) + 1][power]);
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
	 
	      static Scanner sc = new Scanner();
	 static StringBuilder sb = new StringBuilder();
	 public static void main(String args[]) throws IOException {

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
		 int[] x = new int[n];
		 int[] v = new int[n];
		 
		 for(int i = 0 ; i<n ; i++)
			 x[i] = sc.nextInt();
		 
		 for(int i = 0 ; i<n ; i++)
			 v[i] = sc.nextInt();
		
		 ArrayList<Pair> al = new ArrayList<>();
		 for(int i = 0 ; i< n ; i++) {
			 al.add(new Pair(x[i]  , v[i]));
		 }
		 Collections.sort(al);
		 long[] arr = new long[n];
		for(int i = 0 ; i < n ; i++) {
			arr[i] = al.get(i).x;
		}
		AVLTreePBDS pbds1 = new AVLTreePBDS(false);
//		pbds1.add(1);
//		pbds1.add(2);
//		System.out.println(pbds1.orderOfKey(3));
		long tot = 0 ;
//		for(long e:arr) System.out.print(e+" ");
//		System.out.println();
		for(long e:arr) {
			tot += pbds1.orderOfKey((int)e)*e;
			pbds1.add((int)e);
		}
//		System.out.println(tot);
		AVLTreePBDS pbds2 = new AVLTreePBDS(false);
		for(int i = n-1 ; i>=0 ; i--) {
//			System.out.println(pbds2.orderOfKey( (int)arr[i]) );
			tot -=  ((n-i-1) - pbds2.orderOfKey((int)arr[i]))*arr[i];
			pbds2.add((int)(arr[i]));
		}
		System.out.println(tot);
	 }
	 static class Pair implements Comparable<Pair>{
		 int x;
		 int v;
		 Pair(int x , int v){
			 this.x = x;
			 this.v = v;
		 }
		  public int compareTo(Pair o) {
			  if(this.v != o.v) return Integer.compare(this.v, o.v);
			  else {
				  return Integer.compare(this.x, o.x);
			  }
		  }
		  
		  public String toString() {
			  return "{" +this.x+","+this.v+"}";
		  }
	 }
	//PBDS JAVA CODE
	static public class AVLTreePBDS {
	  private Node root;
	  private boolean multi;

	  AVLTreePBDS(boolean multi) {
	      this.root = null;
	      this.multi = multi;
	  }

	  int size() {
	      return size(root);
	  }

	  boolean isEmpty() {
	      return size(root) == 0;
	  }

	  boolean contains(int key) {
	      return contains(root, key);
	  }

	  void add(int key) {
	      root = add(root, key);
	  }

	  void remove(int key) {
	      root = remove(root, key);
	  }

	  Integer first() {
	      Node min = findMin(root);
	      return min != null ? min.key : null;
	  }

	  Integer last() {
	      Node max = findMax(root);
	      return max != null ? max.key : null;
	  }

	  Integer poolFirst() {
	      Node min = findMin(root);
	      if (min != null) {
	          remove(min.key);
	          return min.key;
	      }
	      return null;
	  }

	  Integer poolLast() {
	      Node max = findMax(root);
	      if (max != null) {
	          remove(max.key);
	          return max.key;
	      }
	      return null;
	  }

	  // min >= key
	  Integer ceiling(int key) {
	      return contains(key) ? key : higher(key);
	  }

	  // max <= key
	  Integer floor(int key) {
	      return contains(key) ? key : lower(key);
	  }

	  // min > key
	  Integer higher(int key) {
	      Node min = higher(root, key);
	      return min == null ? null : min.key;
	  }

	  private Node higher(Node cur, int key) {
	      if (cur == null)
	          return null;

	      if (cur.key <= key)
	          return higher(cur.right, key);

	      // cur.key > key
	      Node left = higher(cur.left, key);
	      return left == null ? cur : left;
	  }

	  // max < key
	  Integer lower(int key) {
	      Node max = lower(root, key);
	      return max == null ? null : max.key;
	  }

	  private Node lower(Node cur, int key) {
	      if (cur == null)
	          return null;

	      if (cur.key >= key)
	          return lower(cur.left, key);

	      // cur.key < key
	      Node right = lower(cur.right, key);
	      return right == null ? cur : right;
	  }

	  private class Node {
	      int key, height, size;
	      Node left, right;

	      Node(int key) {
	          this.key = key;
	          height = size = 1;
	          left = right = null;
	      }
	      private void preOrder(Node root , StringBuilder ans) {
	     	 if(root == null) return;
	     	 if(root.left != null) preOrder(root.left,ans );
	     	 ans.append(root.key+",");
	     	 if(root.right!=null) preOrder(root.right, ans);
	      }
	      public String toString() {
	     	 StringBuilder res = new StringBuilder();
	     	 preOrder(root, res);
	     	 return "[" + String.valueOf(res.substring(0 , res.length()-1)) +"]" ;
	      }
	  }

	  private int height(Node cur) {
	      return cur == null ? 0 : cur.height;
	  }

	  private int balanceFactor(Node cur) {
	      return height(cur.right) - height(cur.left);
	  }

	  private int size(Node cur) {
	      return cur == null ? 0 : cur.size;
	  }

	  // fixVertex
	  private void fixHeightAndSize(Node cur) {
	      cur.height = Math.max(height(cur.left), height(cur.right)) + 1;
	      cur.size = size(cur.left) + size(cur.right) + 1;
	  }

	  private Node rotateRight(Node cur) {
	      Node prevLeft = cur.left;
	      cur.left = prevLeft.right;
	      prevLeft.right = cur;
	      fixHeightAndSize(cur);
	      fixHeightAndSize(prevLeft);
	      return prevLeft;
	  }

	  private Node rotateLeft(Node cur) {
	      Node prevRight = cur.right;
	      cur.right = prevRight.left;
	      prevRight.left = cur;
	      fixHeightAndSize(cur);
	      fixHeightAndSize(prevRight);
	      return prevRight;
	  }

	  private Node balance(Node cur) {
	      fixHeightAndSize(cur);
	      if (balanceFactor(cur) == 2) {
	          if (balanceFactor(cur.right) < 0)
	              cur.right = rotateRight(cur.right);
	          return rotateLeft(cur);
	      }
	      if (balanceFactor(cur) == -2) {
	          if (balanceFactor(cur.left) > 0)
	              cur.left = rotateLeft(cur.left);
	          return rotateRight(cur);
	      }
	      return cur;
	  }

	  private boolean contains(Node cur, int key) {
	      if (cur == null)
	          return false;
	      else if (key < cur.key)
	          return contains(cur.left, key);
	      else if (key > cur.key)
	          return contains(cur.right, key);
	      else
	          return true;
	  }

	  private Node add(Node cur, int key) {
	      if (cur == null)
	          return new Node(key);

	      if (key < cur.key)
	          cur.left = add(cur.left, key);
	      else if (key > cur.key || multi)
	          cur.right = add(cur.right, key);

	      return balance(cur);
	  }

	  private Node findMin(Node cur) {
	      return cur.left != null ? findMin(cur.left) : cur;
	  }

	  private Node findMax(Node cur) {
	      return cur.right != null ? findMax(cur.right) : cur;
	  }

	  private Node removeMin(Node cur) {
	      if (cur.left == null)
	          return cur.right;

	      cur.left = removeMin(cur.left);
	      return balance(cur);
	  }

	  private Node removeMax(Node cur) {
	      if (cur.right == null)
	          return cur.left;

	      cur.right = removeMax(cur.right);
	      return balance(cur);
	  }

	  private Node remove(Node cur, int key) {
	      if (cur == null)
	          return null;

	      if (key < cur.key)
	          cur.left = remove(cur.left, key);
	      else if (key > cur.key)
	          cur.right = remove(cur.right, key);
	      else { //  k == cur.key
	          Node prevLeft = cur.left;
	          Node prevRight = cur.right;

	          if (prevRight == null)
	              return prevLeft;

	          Node min = findMin(prevRight);
	          min.right = removeMin(prevRight);
	          min.left = prevLeft;

	          return balance(min);
	      }

	      return balance(cur);
	  }

	  int orderOfKey(int key) {
	      return orderOfKey(root, key);
	  }

	  // count < key
	  private int orderOfKey(Node cur, int key) {
	      if (cur == null)
	          return 0;

	      if (cur.key < key)
	          return size(cur.left) + 1 + orderOfKey(cur.right, key);
	      
	      if(cur.key > key || (multi && cur.left!=null && cur.left.key == key))
	      return orderOfKey(cur.left, key);

//	       cur.key == key
	          return size(cur.left);

	     
	  }

	  Integer findByOrder(int pos) {
	      return size(root) > pos ? findByOrder(root, pos) : null;
	  }

	  // get i-th
	  private int findByOrder(Node cur, int pos) {
	      if (size(cur.left) > pos)
	          return findByOrder(cur.left, pos);

	      if (size(cur.left) == pos)
	          return cur.key;

	      // size(cur.left) < pos
	      return findByOrder(cur.right, pos - 1 - size(cur.left));
	  }
	  public String toString() {
	 	 return String.valueOf(this.root) ;
	  }
	 }
	}
	 

/*******************************************************************************************************************************************************/

/**
	
		
 */

 

