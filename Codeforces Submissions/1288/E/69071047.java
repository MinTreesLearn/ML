import java.io.*;
import java.util.*;
 
public class  Main{
	static class ftreeReversed{
		int n;
		long[]ft;
		ftreeReversed(int z){
			ft=new long[z+1];
			n=z;
		}
		void updatesum(int idx,int k) {
			while(idx>0) {
				ft[idx]+=k;
				idx-=(idx&(-1*idx));
			}
			
		}
		int querysum(int idx) {
			int sum=0;
			while(idx<=n) {
				sum+=ft[idx];
				idx+=(idx&(-1*idx));
			}
			return sum;
		}
	}
	static class ftree{
		int n;
		long[]ft;
		ftree(int z){
			ft=new long[z+1];
			n=z;
		}
		void updatesum(int idx,int k) {
			while(idx<=n) {
				ft[idx]+=k;
				idx+=(idx&(-1*idx));
			}
			
		}
		int querysum(int idx) {
			int sum=0;
			while(idx>0) {
				sum+=ft[idx];
				idx-=(idx&(-1*idx));
			}
			return sum;
		}
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt(),m=sc.nextInt();
		
		int[]messages=new int[m+1];
		for(int i=1;i<=m;i++)messages[i]=sc.nextInt();
		
		int[]lastOcc=new int[n+1];
		Arrays.fill(lastOcc, -1);
		int[]ansMin=new int[n+1];
		int[]ansMax=new int[n+1];
		for(int i=1;i<=n;i++) {
			ansMin[i]=i;ansMax[i]=i;
		}
		for(int i=1;i<=m;i++)ansMin[messages[i]]=1;
		
		ftreeReversed ftSeen=new ftreeReversed(n+7);
		
		ftree ftCount=new ftree(m+7);
		
		for(int i=1;i<=m;i++) {
			if(lastOcc[messages[i]]==-1) {
				int query=ftSeen.querysum(messages[i]);
				ansMax[messages[i]]+=query;
				
				ftSeen.updatesum(messages[i], 1);
				
				ftCount.updatesum(i, 1);
				
				lastOcc[messages[i]]=i;
			}
			else {
				ftCount.updatesum(lastOcc[messages[i]], -1);
				ftCount.updatesum(i, 1);
				
				int left=lastOcc[messages[i]]+1;
				int right=i-1;
				
				lastOcc[messages[i]]=i;
				
				if(left>right)continue;
				
				int cnt=ftCount.querysum(right)-ftCount.querysum(left-1);
				ansMax[messages[i]]=Math.max(ansMax[messages[i]], cnt+1);
				
			}
		}
		for(int i=1;i<=n;i++) {
			if(lastOcc[i]==-1) {
				int query=ftSeen.querysum(i);
				ansMax[i]+=query;
			}
			else {
				int left=lastOcc[i]+1;
				int right=m;
				if(left>right)continue;
				int cnt=ftCount.querysum(right)-ftCount.querysum(left-1);
				ansMax[i]=Math.max(ansMax[i], cnt+1);
			}
		}
		for(int i=1;i<=n;i++) {
			pw.println(ansMin[i]+" "+ansMax[i]);
		}
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