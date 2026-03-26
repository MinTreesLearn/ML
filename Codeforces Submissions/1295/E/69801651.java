import java.io.*;
import java.util.*;
public class Main {
	static long inf=(long)1e16;
	static public class SegmentTree {		// 1-based DS, OOP
		
		int N; 			//the number of elements in the array as a power of 2 (i.e. after padding)
		long[] array, sTree, lazy;
		
		SegmentTree(long[] in)		
		{
			array = in; N = in.length - 1;
			sTree = new long[N<<1];		//no. of nodes = 2*N - 1, we add one to cross out index zero
			lazy = new long[N<<1];
			Arrays.fill(sTree, inf);
			build(1,1,N);
		}
		
		void build(int node, int b, int e)	// O(n)
		{
			if(b == e)					
				sTree[node] = array[b];
			else						
			{
				int mid = b + e >> 1;
				build(node<<1,b,mid);
				build(node<<1|1,mid+1,e);
				sTree[node] = Math.min(sTree[node<<1],sTree[node<<1|1]);
			}
		}
		
		void update_range(int i, int j, int val)		// O(log n) 
		{
			update_range(1,1,N,i,j,val);
		}
		
		void update_range(int node, int b, int e, int i, int j, int val)
		{
			if(i > e || j < b)		
				return;
			if(b >= i && e <= j)		
			{
				sTree[node] += val;			
				lazy[node] += val;				
			}							
			else		
			{
				int mid = b + e >> 1;
				propagate(node, b, mid, e);
				update_range(node<<1,b,mid,i,j,val);
				update_range(node<<1|1,mid+1,e,i,j,val);
				sTree[node] = Math.min(sTree[node<<1],sTree[node<<1|1]);	
			}
			
		}
		void propagate(int node, int b, int mid, int e)		
		{
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
			sTree[node<<1] += lazy[node];		
			sTree[node<<1|1] += lazy[node];		
			lazy[node] = 0;
		}
		
		long query(int i, int j)
		{
			return query(1,1,N,i,j);
		}
		
		long query(int node, int b, int e, int i, int j)	// O(log n)
		{
			if(i>e || j <b)
				return inf;		
			if(b>= i && e <= j)
				return sTree[node];
			int mid = b + e >> 1;
			propagate(node, b, mid, e);
			long q1 = query(node<<1,b,mid,i,j);
			long q2 = query(node<<1|1,mid+1,e,i,j);
			return Math.min(q1, q2);	
					
		}
	}
	public static void main(String[] args) throws Exception {
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		int[]idx=new int[n];
		for(int i=0;i<n;i++) {
			idx[sc.nextInt()-1]=i;
		}
		int[]costs=sc.takearr(n);
		int N = 1; while(N < n) N <<= 1; //padding
		long[]splits=new long[N+1];
		long ans=inf;
		for(int i=1;i<n;i++) {
			splits[i]=costs[i-1]+splits[i-1];
			ans=Math.min(ans, splits[i]);
		}
		SegmentTree split=new SegmentTree(splits);
		for(int i=0;i<n;i++) {
			int index=idx[i]+1;
			split.update_range(index, n-1, -costs[idx[i]]);
			if(index>1)
				split.update_range(1, index-1, costs[idx[i]]);
			ans=Math.min(ans, split.query(1, n-1));
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
