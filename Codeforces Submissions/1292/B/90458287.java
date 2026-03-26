import java.io.*;
import java.util.*;

public class Solution {
static class node{
	long x, y;
	public node(long x, long y) {
		this.x = x;
		this.y = y;
	}
}
public static void main(String[] args){

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
static final long mxx = (long)(1e18+5);
static final int mxN = (int)(1e6);
static final int mxV = (int)(5e5+1), log = 18;
static long mod = (long)(1e9+7); //998244353;//̇
static final int INF = (int)1e9;
static boolean[][]vis;
static ArrayList<ArrayList<Integer>> adj;
static int n, m, k, q, x, y;
static long x0, y0, xs, ys, t, bx, by, ax, ay;
static ArrayDeque<node> reachable;
static ArrayList<node> poss;
static final long limit = (long)(1e16+5);
static void computeReachableNodes() {
	reachable = new ArrayDeque<Solution.node>();
	poss = new ArrayList<node>();
	reachable.add(new node(x0, y0));
	poss.add(reachable.getLast());
	while(reachable.getLast().x <= limit && reachable.getLast().y <= limit) {
		reachable.add(new node(reachable.getLast().x * ax + bx, reachable.getLast().y * ay + by));
		poss.add(reachable.getLast());	
	}
}
public static void solve() throws Exception {
	   // solve the problem here
		s = new MyScanner();
   		out = new PrintWriter(new BufferedOutputStream(System.out), true);
//	   		out = new PrintWriter("output.txt");
        int tc = 1;//s.nextInt();
        while(tc-->0){
        	x0 = s.nextLong(); y0 = s.nextLong();
        	ax = s.nextLong(); ay = s.nextLong();
        	bx = s.nextLong(); by = s.nextLong();
        	xs = s.nextLong(); ys = s.nextLong(); t = s.nextLong();
        	computeReachableNodes();
        	assert(reachable.size() == poss.size());
        	long ans = 0;
        	n = reachable.size();
        	for(int i=0; i<n; i++) {
        		for(int j=i; j<n; j++) {
        			long length = poss.get(j).x - poss.get(i).x + poss.get(j).y - poss.get(i).y;
        			long leftDistance = Math.abs(xs - poss.get(i).x) + Math.abs(ys - poss.get(i).y);
        			long rightDistance = Math.abs(xs - poss.get(j).x) + Math.abs(ys - poss.get(j).y);
        			if(leftDistance + length <= t || rightDistance + length <= t) {
        				ans = Math.max(ans, j - i + 1);
        			}
        		}
        	}
        	out.println(ans);
        } 
           
        out.flush();
        out.close();
}

public static PrintWriter out;
public static MyScanner s;
static class MyScanner {

    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    public MyScanner(String fileName) {
    	try {
			br = new BufferedReader(new FileReader(fileName));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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
    int[] nextIntArray(int n){
    	int[]a = new int[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextInt();
    	}
    	return a;
    }
    long[] nextlongArray(int n) {
    	long[]a = new long[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextLong();
    	}
    	return a;
    }
    Integer[] nextIntegerArray(int n){
    	Integer[]a = new Integer[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextInt();
    	}
    	return a;
    }
    Long[] nextLongArray(int n) {
    	Long[]a = new Long[n];
    	for(int i=0; i<n; i++) {
    		a[i] = this.nextLong();
    	}
    	return a;
    }
    char[][] next2DCharArray(int n, int m){
    	char[][]arr = new char[n][m];
    	for(int i=0; i<n; i++) {
    		arr[i] = this.next().toCharArray();
    	}
    	return arr;
    }
    ArrayList<ArrayList<Integer>> readUndirectedUnweightedGraph(int n, int m) {
    	ArrayList<ArrayList<Integer>>adj = new ArrayList<ArrayList<Integer>>();
    	for(int i=0; i<=n; i++)adj.add(new ArrayList<Integer>());
    	for(int i=0; i<m; i++) {
    		int u = s.nextInt();
    		int v = s.nextInt();
    		adj.get(u).add(v);
    		adj.get(v).add(u);
    	}
    	return adj;
    }
    ArrayList<ArrayList<Integer>> readDirectedUnweightedGraph(int n, int m) {
    	ArrayList<ArrayList<Integer>>adj = new ArrayList<ArrayList<Integer>>();
    	for(int i=0; i<=n; i++)adj.add(new ArrayList<Integer>());
    	for(int i=0; i<m; i++) {
    		int u = s.nextInt();
    		int v = s.nextInt();
    		adj.get(u).add(v);
    	}
    	return adj;
    }
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

 
}
