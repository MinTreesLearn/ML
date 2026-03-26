import java.io.*;
import java.util.*;
public class Main{
	static public class SegmentTree {		// 1-based DS, OOP
		
		int N; 			//the number of elements in the array as a power of 2 (i.e. after padding)
		long[] array, sTree, lazy;
		
		SegmentTree(long[] in)		
		{
			array = in; N = in.length - 1;
			sTree = new long[N<<1];		//no. of nodes = 2*N - 1, we add one to cross out index zero
			lazy = new long[N<<1];
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
				sTree[node] = Math.max(sTree[node<<1],sTree[node<<1|1]);
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
				sTree[node] = Math.max(sTree[node<<1],sTree[node<<1|1]);
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
				return -inf;		
			if(b>= i && e <= j)
				return sTree[node];
			int mid = b + e >> 1;
			propagate(node, b, mid, e);
			long q1 = query(node<<1,b,mid,i,j);
			long q2 = query(node<<1|1,mid+1,e,i,j);
			return Math.max(q1, q2);	
					
		}
	}
	static long inf=(long)3e9;
	public static void main(String[] args) throws IOException {
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt(),m=sc.nextInt(),p=sc.nextInt();
		int[][]weapons=new int[n][2],armors=new int[m][2],monsters=new int[p][3];
		for(int i=0;i<n;i++) {
			weapons[i]=sc.takearr(2);
		}
		for(int i=0;i<m;i++) {
			armors[i]=sc.takearr(2);
		}
		for(int i=0;i<p;i++) {
			monsters[i]=sc.takearr(3);
		}
		Arrays.sort(weapons,(x,y) -> x[0]-y[0]);
		Arrays.sort(armors,(x,y) -> x[0]-y[0]);
		Arrays.sort(monsters,(x,y) -> x[0]-y[0]);
		
		int N = 1; while(N < m) N <<= 1; //padding
		long[]armorCosts=new long[N+1];
		for(int i=1;i<=m;i++) {
			armorCosts[i]=-armors[i-1][1];
		}
		SegmentTree st=new SegmentTree(armorCosts);
		
		int lastMonster=0;
		long ans=-inf;
		for(int i=0;i<n;i++) {
			while(lastMonster<p && monsters[lastMonster][0]<weapons[i][0]) {
				int firstArmor=-1;
				int lo=0,hi=m-1;
				while(lo<=hi) {
					int mid=(lo+hi)>>1;
					if(armors[mid][0]>monsters[lastMonster][1]) {
						firstArmor=mid;
						hi=mid-1;
					}
					else {
						lo=mid+1;
					}
				}
				lastMonster++;
				if(firstArmor==-1)continue;
				st.update_range(firstArmor+1, m, monsters[lastMonster-1][2]);
			}
			ans=Math.max(ans, st.query(1, m)-weapons[i][1]);
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
 


 