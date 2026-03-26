import java.io.*;
import java.util.*;
public class Main {
	static void add(int[] count, int x, int y,int[][] dp) {
		int n=dp[1].length;
		if(dp[x^1][y]==1) count[0]++;
		if(x==0) {
			if(y!=0 && dp[x^1][y-1]==1) {
				count[2]++;
			}
			if(y<n-1 && dp[x^1][y+1]==1) {
				count[1]++;
			}
		}
		else {
			if(y!=0 && dp[x^1][y-1]==1) {
				count[1]++;
			}
			if(y<n-1 && dp[x^1][y+1]==1) {
				count[2]++;
			}
		}
	}
	static void remove(int[] count,int x,int y,int[][] dp) {
		int n=dp[1].length;
		if(dp[x^1][y]==1) count[0]--;
		if(x==0) {
			if(y!=0 && dp[x^1][y-1]==1) {
				count[2]--;
			}
			if(y<n-1 && dp[x^1][y+1]==1) {
				count[1]--;
			}
		}
		else {
//			System.out.println((y<n-1) +" "+dp[x^1][y+1]);
			if(y!=0 && dp[x^1][y-1]==1) {
				count[1]--;
			}
			if(y<n-1 && dp[x^1][y+1]==1) {
//				System.out.println("UO)IU");
				count[2]--;
			}
		}
	}
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
//		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<ttt;tt++) {
			int n=f.nextInt();
			int q=f.nextInt();
			int[][] dp=new int[2][n];
			int[] count=new int[3];
			for(int i=0;i<q;i++) {
				int x=f.nextInt()-1;
				int y=f.nextInt()-1;
				if(dp[x][y]==0) {
					dp[x][y]=1;
					add(count,x,y,dp);
				}
				else {
					dp[x][y]=0;
					remove(count,x,y,dp);
				}
//				System.out.println(Arrays.toString(count));
				if(count[0]==0 && count[1]==0 && count[2]==0 && dp[0][0]==0 && dp[1][n-1]==0) System.out.println("YES");
				else System.out.println("NO");
			}
		}
		out.close();
	} 
	static void sort(int[] p) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i: p) q.add( i);
        Collections.sort(q);
        for (int i = 0; i < p.length; i++) p[i] = q.get(i);
    }
    static long gcd(long a,long b) {
    	if(a==0) return b;
    	return gcd(b%a,a);
    }
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}
} 	