import java.io.*;
import java.util.*;


public class  Main{
	public static void main(String[] args) throws Exception{
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int tc=sc.nextInt();
		while(tc-->0) {
			int n=sc.nextInt(),d=sc.nextInt();
			long max=((n-1)*n)/2;
			long min=0;
			int nodes=n-1;
			int lvl=1;long cnt=2;
			while(true) {
				if(cnt>nodes) {
					long inc=lvl*1l*nodes;
					min+=inc;
					break;
				}
				long inc=lvl*1l*cnt;
				min+=inc;
				nodes-=cnt;
				lvl++;
				cnt*=2;
			}
			if(d<min || d>max) {
				pw.println("NO");
			}
			else {
				pw.println("YES");
				LinkedList<Integer>[]levels=new LinkedList[n];
				long[]cap=new long[n];
				
				for(int i=0;i<n;i++) {
					levels[i]=new LinkedList<Integer>();
					levels[i].add(i);
					cap[i]=i==0?1:(cap[i-1]*2l);
				}
				int cmax=n-1,cmin=1;
				while(true) {
					long dif=cmax-cmin;
					if(max-dif<=d) {
						dif=max-d;
						levels[(int)(cmax-dif)].add(levels[cmax].poll());
						break;
					}
					else {
						levels[cmin].add(levels[cmax].poll());
						if(levels[cmin].size()==cap[cmin]) {
							cmin++;
						}
					}
					cmax--;
					max-=dif;
				}
				int[]par=new int[n];
				int[]children=new int[n];
				for(int i=n-1;i>=1;i--) {
					if(levels[i].size()==0)continue;
					int[]parents=new int[levels[i-1].size()];
					int o=0;
					
					for(int j:levels[i-1]) {
						parents[o++]=j;
					}
					o=0;
					for(int j:levels[i]) {
						int curP=parents[o];
						par[j]=curP;
						children[curP]++;
						if(children[curP]==2)o++;
					}
				}
				for(int i=1;i<n;i++)pw.print((par[i]+1)+" ");
				pw.println();
			}
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