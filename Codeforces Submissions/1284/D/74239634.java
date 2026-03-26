import java.io.*;
import java.util.*;
public class  Main{
	static int[][]in;
	static int n;
	static boolean check() {
		int[][]events=new int[2*n][4];
		for(int i=0;i<n;i++) {
			events[2*i]=new int[] {in[i][0],0,in[i][2],in[i][3]};
			events[2*i+1]=new int[] {in[i][1],1,in[i][2],in[i][3]};
		}
		Arrays.sort(events,(x,y)->x[0]==y[0]?x[1]-y[1]:x[0]-y[0]);
		
		TreeMap<Integer, Integer>start=new TreeMap<>(),end=new TreeMap<>();
		for(int[] e:events) {
			if(e[1]==0) {//start point
				if(end.size()!=0) {
					int minEnd=end.firstKey();
					if(e[2]>minEnd)return false;
				}
				
				if(start.size()!=0) {
					int maxStart=start.lastKey();
					if(e[3]<maxStart)return false;
				}
				
				start.put(e[2], start.getOrDefault(e[2], 0)+1);
				end.put(e[3], end.getOrDefault(e[3], 0)+1);
			}
			else {//end point
				start.put(e[2], start.get(e[2])-1);
				if(start.get(e[2])==0)start.remove(e[2]);
				end.put(e[3], end.get(e[3])-1);
				if(end.get(e[3])==0)end.remove(e[3]);
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		n=sc.nextInt();
		in=new int[n][4];
		for(int i=0;i<n;i++)in[i]=sc.intArr(4);
		
		boolean ans=check();
		
		for(int i=0;i<n;i++) {
			int[]tmp=new int[] {in[i][0],in[i][1]};
			in[i][0]=in[i][2];
			in[i][1]=in[i][3];
			in[i][2]=tmp[0];
			in[i][3]=tmp[1];
		}
		
		ans&=check();
		
		pw.println(ans?"YES":"NO");
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
 
		public long nextLong() throws IOException {
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