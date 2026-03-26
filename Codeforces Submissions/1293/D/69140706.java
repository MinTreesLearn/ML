import java.io.*;
import java.util.*;
 
public class  Main{
	static long dist(long x1,long y1,long x2,long y2) {
		return Math.abs(x1-x2)+Math.abs(y1-y2);
	}
	static long[][]in;
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		long x0=sc.nextLong(),y0=sc.nextLong(),ax=sc.nextLong(),ay=sc.nextLong(),bx=sc.nextLong(),by=sc.nextLong();
		long xs=sc.nextLong(),ys=sc.nextLong(),t=sc.nextLong();
		int c=0;
		in=new long[1000][2];
		while(true) {
			
			in[c][0]=x0;in[c][1]=y0;
			x0=x0*ax+bx;y0=y0*ay+by;
			c++;
			if(x0>4e16 || y0>4e16)break;
		}
		int finalAns=0;
		for(int start=0;start<c;start++) {
			//increasing first
			long dist=dist(xs, ys, in[start][0], in[start][1]);
			int ans=0;
			
			if(dist<=t) {
				ans=1;
				long stx=in[start][0],sty=in[start][1];
				for(int j=start+1;j<c;j++) {
					dist+=dist(stx, sty, in[j][0], in[j][1]);
					//if(start==2) {
						//for(int i=0;i<c;i++)System.out.println(in[i][0]+" "+in[i][1]);
						//System.out.println(dist+" "+j+" "+in[j][0]+" "+in[j][1]);
					//}
					if(dist<=t) {
						ans++;
					}
					else {
						break;
					}
					stx=in[j][0];sty=in[j][1];
				}
				for(int j=start-1;j>=0;j--) {
					dist+=dist(stx, sty, in[j][0], in[j][1]);
					if(dist<=t) {
						ans++;
					}
					else {
						break;
					}
					stx=in[j][0];sty=in[j][1];
				}
			}
			//decreasing
			long dist2=dist(xs, ys, in[start][0], in[start][1]);
			int ans2=0;
			if(dist2<=t) {
				ans2=1;
				long stx=in[start][0],sty=in[start][1];
				for(int j=start-1;j>=0;j--) {
					dist2+=dist(stx, sty, in[j][0], in[j][1]);
					if(dist2<=t) {
						ans2++;
					}
					else {
						break;
					}
					stx=in[j][0];sty=in[j][1];
				}
				for(int j=start+1;j<c;j++) {
					dist2+=dist(stx, sty, in[j][0], in[j][1]);
					if(dist2<=t) {
						ans2++;
					}
					else {
						break;
					}
					stx=in[j][0];sty=in[j][1];
				}
			}
			finalAns=Math.max(finalAns, ans);
			finalAns=Math.max(finalAns, ans2);
		}
		pw.println(finalAns);
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