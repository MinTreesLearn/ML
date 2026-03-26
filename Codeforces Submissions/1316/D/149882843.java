import java.io.*;
import java.util.*;
public class Matrix {
	static boolean works;
	static Pair[][] dest;
	static boolean[][] visited;
	static char[][] ans;
	static int n, size;
	public static void main(String[] args) throws Exception {
		FastIO in = new FastIO();
		n = in.nextInt();
		works = true;
		dest = new Pair[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int x = in.nextInt()-1;
				int y = in.nextInt()-1;
				dest[i][j] = new Pair(x, y);
			}
		}
		visited = new boolean[n][n];
		ans = new char[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (dest[i][j].x==-2 && !visited[i][j]) {
					size = 0;
					floodfill1(i, j);
					if (size==1) {
						works = false;
//						System.out.println("failed "+i+" "+j+" "+dest[i][j].x+" "+dest[i][j].y);
						break;
					}
				}
				if (dest[i][j].x==i && dest[i][j].y==j && !visited[i][j]) {
					ans[i][j] = 'X';
					floodfill2(i, j);
				}
			}
		}
		for (int i=0; i<n; i++) {
			if (!works) break;
			for (int j=0; j<n; j++) {
				if (!visited[i][j]) {
//					System.out.println(i+" "+j+" unvisited");
					works = false;
					break;
				}
			}
		}
		if (!works) in.pr.println("INVALID");
		else {
			in.pr.println("VALID");
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					in.pr.print(ans[i][j]);
				}
				in.pr.println();
			}
		}
		in.pr.close();
	}
	public static void floodfill1(int x, int y) {
		if (visited[x][y]) return;
		visited[x][y] = true;
//		System.out.println(x+" "+y);
		size++;
		if (x<n-1 && dest[x+1][y].x==-2) {
			floodfill1(x+1, y);
			if (ans[x][y]==0) ans[x][y] = 'D';
		}
		if (x>0 && dest[x-1][y].x==-2) {
			floodfill1(x-1, y);
			if (ans[x][y]==0) ans[x][y] = 'U';
		}
		if (y<n-1 && dest[x][y+1].x==-2) {
//			System.out.println("going to "+ x+" "+(y+1));
			floodfill1(x, y+1);
			if (ans[x][y]==0) ans[x][y] = 'R';
		}
		if (y>0 && dest[x][y-1].x==-2) {
			floodfill1(x, y-1);
			if (ans[x][y]==0)  ans[x][y] = 'L';
		}
	}
	public static void floodfill2(int x, int y) {
		if (visited[x][y]) return;
		visited[x][y] = true;
//		System.out.println(x+" "+y);
		if (x<n-1 && dest[x+1][y].equals(dest[x][y])) {
			if (ans[x+1][y]==0) ans[x+1][y] = 'U';
			floodfill2(x+1, y);
			
		}
		if (x>0 && dest[x-1][y].equals(dest[x][y])) {
			if (ans[x-1][y]==0) ans[x-1][y] = 'D';
			floodfill2(x-1, y);
			
		}
		if (y<n-1 && dest[x][y+1].equals(dest[x][y])) {
			if (ans[x][y+1]==0) ans[x][y+1] = 'L';
			floodfill2(x, y+1);
			
		}
		if (y>0 && dest[x][y-1].equals(dest[x][y])) {
			if (ans[x][y-1]==0)  ans[x][y-1] = 'R';
			floodfill2(x, y-1);
			
		}
	}
	static class Pair {
		int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public boolean equals(Object other) {
			Pair p = (Pair)other;
			return x==p.x && y==p.y;
		}
	}
	static class FastIO {
		BufferedReader br;
	    StringTokenizer st;
	    PrintWriter pr;
	    public FastIO() throws IOException
	    {
	        br = new BufferedReader(
	            new InputStreamReader(System.in));
	        pr = new PrintWriter(System.out);
	        }
	    

	    public String next() throws IOException
	    {
	        while (st == null || !st.hasMoreElements()) {
	           
	            st = new StringTokenizer(br.readLine());
	        }
	        return st.nextToken();
	    }

	    public int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	    public long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }

	    public double nextDouble() throws NumberFormatException, IOException
	    {
	        return Double.parseDouble(next());
	    }

	    public String nextLine() throws IOException
	    {
	        String str = br.readLine();
	        return str;
	    }
	}
}
