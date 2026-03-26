import java.io.*;
import java.util.*;
import java.math.*;

 
 public class Main	{
	 static class tuple{
		 int a, b;
		 long c;
		 public tuple(int a, int b, long c) {this.a = a;this.b = b;this.c = c;}
	 }
   static class Pair implements Comparable<Pair>{

	   int a;
	   int b;
//	   int ind;
//	   public Pair(int x, long y) {a = x;b=y;}
	   public Pair(int x, int y) {a = x;b=y;}
//	   public Pair(int x,int y, int z){a=x;b=y;ind = z;}
	   public int compareTo(Pair p){
		   return p.a - a;
	   }
//		@Override
//		public int hashCode() {
//			final int prime = 31;
//			int result = 1;
//			result = prime * result + a;
//			result = prime * result + b;
//		   
//			return result;
//		}
//		@Override
//		public boolean equals(Object obj) {
//			Pair cur = (Pair)obj;
//			if((a==cur.a && b==cur.b))return true;
//			return false;
//		}
 }
  static class cell{
	  int a, b;
	  public cell(int x, int y) {
		  a = x;
		  b = y;
	  }
  }
static class TrieNode{
	TrieNode left, right;
	int cnt;
	public TrieNode() {
		cnt = 0;
	}
}
  public static int gcd(int a,int b)
  {
    if(a<b)
      return gcd(b,a);
    if(b==0)
      return a;
    return gcd(b,a%b);
    
  }
  static int lcm(int a,int b) {
	  return  a*b / (int)gcd(a,b);
  }
  
   
    public static void main(String[] args) throws Exception {
       new Thread(null, null, "Anshum Gupta", 99999999) {
            public void run() {
                try {
                    solve();
                } catch(Exception e) {
                    e.printStackTrace();
                    System.exit(1);
                }
            }
        }.start();
    }

static long pow(long x,long y){
    if(y == 0)return 1;
    if(y==1)return x;
    long a = pow(x,y/2);
    a = (a*a)%mod;
    if(y%2==0){
        return a;
    }
    return (a*x)%mod;
}

static final long mxx = (long)(1e18+5);
static final int mxN = (int)(1e5 + 5);
static final int mxV = (int)(2e5);
static final long mod = (long)(1e9+7); //998244353;//
static long[]fact,inv_fact;
static long my_inv(long a) {
	return pow(a,mod-2);
}
static long bin(int a,int b) {
	if(a < b || a<0 || b<0)return 0;
    return ((fact[a]*inv_fact[a-b])%mod * inv_fact[b])%mod;
}
	
static void make_facts() {
  fact=new long[mxN];
  inv_fact = new long[mxN];
  fact[0]=inv_fact[0]=1L;
  for(int i=1;i<mxN;i++) {
	   fact[i] = (i*fact[i-1])%mod;
	   inv_fact[i] = my_inv(fact[i]);
  }
}
static void lazy(int st, int e, int tn) {
	if(lazy[tn] != INF) {
		tree[tn] = Math.min(tree[tn], lazy[tn]);
		if(st != e) {
			lazy[2*tn] = Math.min(lazy[2*tn], lazy[tn]);
			lazy[2*tn+1] = Math.min(lazy[2*tn+1], lazy[tn]);
		}
		lazy[tn] = INF;
	}
}
static void update(int ind, int val, int st, int e, int tn) {
	if(st == e) {
		tree[tn] = val;
		return;
	}
	int mid = (st + e) >> 1;	
  	if(ind <= mid)
		update(ind, val, st, mid, 2*tn);
  	else
		update(ind, val, mid+1, e, 2*tn+1);
	tree[tn] = Math.min(tree[2*tn], tree[2*tn+1]);
}
static int query(int l, int r, int st, int e, int tn) {
	if(st > r || e < l)return INF;
	
	if(st >= l && e <= r) {
		return tree[tn];
	}

	int mid = (st + e) >> 1;
	int x = query(l, r, st, mid, 2 * tn);
	int y = query(l, r, mid+1, e, 2 * tn + 1);
	return Math.min(x, y);
}
static int[]tree, lazy;
static final int INF = (int)1e9+5;
static ArrayList<ArrayList<Pair>> adj;
static boolean[]vis;
static int n;
static char[][]res;
static Pair[][]arr;
static final int[]dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
static final char[]d = {'U', 'D', 'L', 'R'};
static void dfs(int x, int y) {
	for(int i=0; i<4; i++) {
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= n)continue;
		if(arr[x1][y1].a != arr[x][y].a || arr[x1][y1].b != arr[x][y].b)continue;
		if(res[x1][y1] != '\0')continue;
		res[x1][y1] = d[i ^ 1];
		dfs(x1, y1);
	}
}
 public static void solve() throws Exception {
   // solve the problem here
   MyScanner s = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out), true);
        int tc = 1;//s.nextInt();
        
//	        make_facts(); 
        
        while(tc-->0){
        	n = s.nextInt();
        	res = new char[n][n];
        	arr = new Pair[n][n];
        	for(int i=0; i<n; i++) {
        		for(int j=0; j<n; j++) {
        			int x = s.nextInt();
        			int y = s.nextInt();
        			x--;y--;
        			arr[i][j] = new Pair(x, y);
        		}
        	}
        	
        	for(int i=0;i<n;i++) {
        		for(int j=0;j<n;j++) {
        			if(arr[i][j].a == i && arr[i][j].b == j) {
//        				out.println("i = " + i + " j = " + j);
        				res[i][j] = 'X';
        				dfs(i, j);
        			}
        		}
        	}
        	for(int i=0;i<n;i++) {
        		for(int j=0;j<n;j++) {
        			if(arr[i][j].a != -2)continue;
        			for(int k=0; k<4; k++) {
        				int x1 = i + dx[k];
        				int y1 = j + dy[k];
        				if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= n)continue;
        				if(arr[x1][y1].a == -2 && arr[x1][y1].b == -2) {
        					res[i][j] = d[k];
        				}
        			}
        		}
        	}
        	for(int i=0;i<n;i++) {
        		for(int j=0;j<n;j++) {
        			if(res[i][j] == '\0') {
        				out.println("INVALID");
        				return;
        			}
        		}
        	}
        	out.println("VALID");
        	for(int i=0;i<n;i++) {
        		for(int j=0;j<n;j++) {
        			out.print(res[i][j]);
        		}out.println();
        	}
        }
        	
           
        out.flush();
}
 
     
 
 
 
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
 
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
 
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
         
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    //--------------------------------------------------------
}
