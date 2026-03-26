import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution{
	
	static LinkedList<Integer>[] adjList;
	static int n,m;
	static int[] dep;
	static int[][] par;
	
	
	public static void main(String[] args) throws Exception{

		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		n = fs.nextInt();
		m = 16;
		
		par = new int[n+1][m+1];
		dep = new int[n+1];
		
		adjList = new LinkedList[n+1];
		for(int i=0;i<=n;i++) adjList[i] = new LinkedList<Integer>();
		
		for(int i=0;i<n-1;i++) {
			int u = fs.nextInt(), v = fs.nextInt();
			adjList[u].add(v);
			adjList[v].add(u);	
		}
		
		build(1,0);
		
		int q = fs.nextInt();
		
		while(q-->0) {
			int x = fs.nextInt(), y = fs.nextInt(), a = fs.nextInt(), b = fs.nextInt(), k = fs.nextInt();
			
			int len1 = lenPath(a,b);
			int len2 = Math.min(lenPath(a,x)+lenPath(b,y), lenPath(a,y)+ lenPath(b,x)) + 1;
			boolean bool = false;
			if(len1%2==k%2 && len1<=k) bool = true;
			if(len2%2==k%2 && len2<=k) bool = true;
			
			out.println(bool?"YES":"NO");
			
			
		}
		
		
		
		
		
		out.close();
	}
	
	static int lenPath(int a, int b) {
		return dep[a] + dep[b] - 2*dep[lca(a,b)];
	}
	
	
	//O(NLOG(N))
	static void build(int cur, int p) { 
		par[cur][0] = p;
		for(int j=1;j<=m;j++) {
			par[cur][j] = par[par[cur][j-1]][j-1];
		}
		
		for(int n: adjList[cur]) {
			if(n!=p) {
				dep[n] = 1 + dep[cur];
				build(n,cur);
			}
		}
	}
	
	//O(LOG(N))
	static int lca(int u, int v) {
		if(u==v) return v;
		if(dep[u]<dep[v]) {
			int temp = u;
			u = v;
			v = temp;
		}
		int dif = dep[u]-dep[v];
		for(int i=m;i>=0;i--) {
			if(((dif>>i)&1)==1) {
				u = par[u][i];
			}
		}
		if(u==v) return u;
		for(int i=m;i>=0;i--) {
			if(par[u][i]!=par[v][i]) {
				u = par[u][i];
				v = par[v][i];
			}
		}
		return par[u][0];	
	}
	
	
	static class FastScanner{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		public String next(){
			while(!st.hasMoreElements()){
				try{
					st = new StringTokenizer(br.readLine());
				} catch(IOException e){
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		public String nextLine() throws IOException {
			return br.readLine();
		}
		
		public int nextInt(){
			return Integer.parseInt(next());
		}

		public int[] readArray(int n){
			int[] a = new int[n];
			for(int i=0;i<n;i++)
				a[i] = nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	
}
