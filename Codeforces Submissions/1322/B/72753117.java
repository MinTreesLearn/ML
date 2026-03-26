import java.io.*;
import java.util.*;


public class  Main{
	static int solveLower(int i,int[]in,int left,int right) {
		int lo=0,hi=i-1;
		int ans=-1;
		while(lo<=hi) {
			int mid=(lo+hi)>>1;
			int sum=in[i]+in[mid];
			if(sum<left) {
					lo=mid+1;
			}
			else {
				if(sum>right)
				    hi=mid-1;
				else{
				    ans=mid;
			        hi=mid-1;    
				}    
			}
		}
		return ans;
	}
	static int solveUpper(int i,int[]in,int left,int right) {
		int lo=0,hi=i-1;
		int ans=-1;
		while(lo<=hi) {
			int mid=(lo+hi)>>1;
			int sum=in[i]+in[mid];
			if(sum<left) {
					lo=mid+1;
			}
			else {
				if(sum>right)
				    hi=mid-1;
				else{
				    ans=mid;
			        lo=mid+1;    
				}    
			}
		}
		return ans;
	}
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt();
		int[]in=sc.takearr(n);
		int ans=0;
		for(int b=0;b<27;b++) {
		    int tmp[]=new int[n];
			for(int i=0;i<n;i++) {
				tmp[i]=in[i]%(1<<(b+1));
			}
			Arrays.sort(tmp);
			
			int left=1<<b,right=(1<<(b+1))-1;
			
			long cnt=0;
			for(int i=1;i<n;i++) {
				int lower=solveLower(i, tmp, left, right);
				if(lower==-1)continue;
				int upper=solveUpper(i, tmp, left, right);
				cnt+=upper-lower+1;
			}
			
			left=(1<<b)+(1<<(b+1));right=(1<<(b+2))-2;
			
			for(int i=1;i<n;i++) {
				int lower=solveLower(i, tmp, left, right);
				if(lower==-1)continue;
				int upper=solveUpper(i, tmp, left, right);
				cnt+=upper-lower+1;
			}
			if(cnt%2==1) {
				ans+=1<<b;
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