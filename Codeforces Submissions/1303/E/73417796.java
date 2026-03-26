import java.io.*;
import java.util.*;


public class  Main{
	static char[]in1,in2;
	static int[][]memo;
	static int startSub1=0,endSub1,startSub2,endSub2,inf=10000;
	static int[][]nxt;
	static int dp(int i,int j) {
		if(i<startSub1 && j<startSub2)return 0;
		if(i<startSub1) {
			int o2=dp(i,j-1);
			int option2=o2>=in1.length?inf:nxt[o2][in2[j]-'a'];
			return option2+1;
		}
		if(j<startSub2) {
			int o1=dp(i-1,j);
			int option1=o1>=in1.length?inf:nxt[o1][in2[i]-'a'];
			return option1+1;
		}
		if(memo[i][j]!=-1)return memo[i][j];
		int o1=dp(i-1,j),o2=dp(i,j-1);
		int option1=o1>=in1.length?inf:nxt[o1][in2[i]-'a'];
		int option2=o2>=in1.length?inf:nxt[o2][in2[j]-'a'];
		
		return memo[i][j]=Math.min(option1, option2)+1;
	}
	
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int tc=sc.nextInt();
		while(tc-->0) {
			in1=sc.nextLine().toCharArray();
			in2=sc.nextLine().toCharArray();
			nxt=new int[in1.length][26];
			for(int i[]:nxt) {
				Arrays.fill(i, inf);
			}
			for(int i=in1.length-1;i>=0;i--) {
				if(i<in1.length-1)
					nxt[i]=nxt[i+1].clone();
				for(char c='a';c<='z';c++) {
					if(in1[i]==c) {
						nxt[i][c-'a']=i;
					}
				}
			}
			boolean yes=false;
			endSub2=in2.length-1;
			for(int cut=0;cut<in1.length;cut++) {
				endSub1=cut;startSub2=cut+1;
				memo=new int[in2.length][in2.length];
				for(int i[]:memo)Arrays.fill(i, -1);
				
				int len=dp(endSub1,endSub2);
				if(len<=in1.length) {
					yes=true;break;
				}
			}
			
			pw.println(yes?"YES":"NO");
			
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
		public int[] intArr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public long[] longArr(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        return in;
		}
		public int[] intSortedArr(int n) throws IOException {
	        int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        shuffle(in);
	        Arrays.sort(in);
	        return in;
		}
		public long[] longSortedArr(int n) throws IOException {
	        long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
	        shuffle(in);
	        Arrays.sort(in);
	        return in;
		}
		static void shuffle(int[]in) {
			for(int i=0;i<in.length;i++) {
				int idx=(int)(Math.random()*in.length);
				int tmp=in[i];
				in[i]=in[idx];
				in[idx]=tmp;
			}
		}
		static void shuffle(long[]in) {
			for(int i=0;i<in.length;i++) {
				int idx=(int)(Math.random()*in.length);
				long tmp=in[i];
				in[i]=in[idx];
				in[idx]=tmp;
			}
		}
		public Integer[] IntegerArr(int n) throws IOException {
	        Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
	        return in;
		}
		public Long[] LongArr(int n) throws IOException {
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
	static void addX(int[]in,int x) {
		for(int i=0;i<in.length;i++)in[i]+=x;
	}
	static void addX(long[]in,int x) {
		for(int i=0;i<in.length;i++)in[i]+=x;
	}
}