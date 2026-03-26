import java.io.*;
import java.util.*;
public class Main{
	static int[][][]dest;
	static int []dx= {0,1,0,-1},dy= {1,0,-1,0};
	static char []dir= {'L','U','R','D'};
	static char ans[][];
	static boolean valid(int x,int y) {
		return x>=0 && y>=0 && x<n && y<n;
	}
	static int n;
	static boolean yes=true;
	
	static void dfs(int x,int y,char direction) {
		if(ans[x][y]!='O')return;
		ans[x][y]=direction;
		for(int j=0;j<4;j++) {
			int xx=x+dx[j],yy=y+dy[j];
			if(!valid(xx, yy))continue;
			if(dest[xx][yy][0]==dest[x][y][0] && dest[xx][yy][1]==dest[x][y][1]) {
				dfs(xx, yy, dir[j]);
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		MScanner sc=new MScanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		n=sc.nextInt();
		dest=new int[n][n][2];
		ans=new char[n][n];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				dest[i][j][0]=sc.nextInt()-1;dest[i][j][1]=sc.nextInt()-1;
				ans[i][j]='O';
			}
		}
		for(int x=0;x<n && yes;x++) {
			for(int y=0;y<n && yes;y++) {
				if(dest[x][y][0]==-2) {
					boolean ok=false;
					for(int j=0;j<4;j++) {
						int xx=x+dx[j],yy=y+dy[j];
						if(!valid(xx, yy))continue;
						if(dest[xx][yy][0]==-2 && dest[xx][yy][1]==-2) {
							ans[x][y]=dir[(j+2)%4];
							ok=true;
							break;
						}
					}
					if(!ok) {
						yes=false;
					}
				}
				else {
					if(dest[x][y][0]==x && dest[x][y][1]==y)
						dfs(x, y, 'X');
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(ans[i][j]=='O')yes=false;
			}
		}
		if(!yes) {
			pw.println("INVALID");
		}
		else {
			pw.println("VALID");
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++)pw.print(ans[i][j]);
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
 


 