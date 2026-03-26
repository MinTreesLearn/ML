import java.io.*;
import java.util.*;
 
public class  Main{
	static LinkedList<Integer>[]adj;
	static int[][] sub ,par;
	static void dfs(int i,int root,int parent) {
		sub[root][i]=1;
		for(int j:adj[i]) {
			if(j!=parent) {
				dfs(j,root,i);
				sub[root][i]+=sub[root][j];
				par[root][j]=i;
			}
		}
	}
	static long[][]memo;
	static long dp(int i,int j) {
		if(i==j)return 0;
		if(memo[i][j]!=-1)return memo[i][j];
		int nxti=par[j][i],nxtj=par[i][j];
		return memo[i][j]=sub[i][j]*1l*sub[j][i]+Math.max(dp(nxti,j), dp(i,nxtj));
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		adj=new LinkedList[n];
		sub=new int[n][n];
		par=new int[n][n];
		for(int i=0;i<n;i++)adj[i]=new LinkedList<Integer>();
		for(int i=0;i<n-1;i++) {
			int x=sc.nextInt()-1,y=sc.nextInt()-1;
			adj[x].add(y);adj[y].add(x);
		}
		for(int i=0;i<n;i++) {
			dfs(i,i,-1);
		}
		memo=new long[n][n];
		for(long[]i:memo)Arrays.fill(i, -1);
		long ans=0;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				ans=Math.max(ans, dp(i, j));
			}
		}
		pw.println(ans);
		pw.flush();
	}	
	static class MScanner {
		StringTokenizer st;
		BufferedReader br;
		public MScanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}
 
		public MScanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public int[] takearr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] takearrl(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public Integer[] takearrobj(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] takearrlobj(int n) throws IOException {
	        Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
 
		public char nextChar() throws IOException {
			return next().charAt(0);
		}
 
		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
		public void waitForInput() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}