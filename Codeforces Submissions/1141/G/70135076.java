import java.io.*;
import java.util.*;
 
public class A{
 
	static ArrayList<edge>[]adj;
	static int []col;
	static class edge
	{
		int v,idx;
		edge(int v,int idx){
			this.v=v;
			this.idx=idx;
		}
	}
	static void dfs(int u,int max,int p,int colP) {
		int curr=1;
		for(edge a:adj[u]) {
			int v=a.v,idx=a.idx;
			if(v==p)
				continue;
			if(curr==colP)
				curr++;
			if(curr>max)
				curr=1;
			col[idx]=curr;
			dfs(v,max,u,curr);
			if(++curr>max)
				curr=1;
			
		}
	}
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=sc.nextInt(),k=sc.nextInt();
		adj=new ArrayList[n];
		for(int i=0;i<n;i++)
			adj[i]=new ArrayList();
		for(int i=1;i<n;i++) {
			int u=sc.nextInt()-1,v=sc.nextInt()-1;
			adj[u].add(new edge(v, i));
			adj[v].add(new edge(u, i));
		}
		int ans=-1,lo=1,hi=n-1;
		while(lo<=hi) {
			int greater=0;
			int mid=lo+hi>>1;
			for(int i=0;i<n;i++)
				if(adj[i].size()>mid)
					greater++;
			if(greater<=k) {
				ans=mid;
				hi=mid-1;
			}
			else
				lo=mid+1;
		}
		col=new int [n];
		out.println(ans);
		dfs(0, ans, -1, -1);
		for(int i=1;i<n;i++)
			out.println(col[i]);
		out.close();
 
	}
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		Scanner(String fileName) throws FileNotFoundException{
			br=new BufferedReader(new FileReader(fileName));
		}
		String next() throws IOException {
			while(st==null || !st.hasMoreTokens())
				st=new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		String nextLine() throws IOException {
			return br.readLine();
		}
		int nextInt() throws IOException{
			return Integer.parseInt(next());
		}
		long nextLong()  throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}
		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}
	}
}
