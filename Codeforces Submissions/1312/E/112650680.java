import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int t=1;
//		t=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<t;tt++) {
			int n= f.nextInt();
			int[] a=f.readArray(n);
			int[][] dp=new int[n][n]; 
			int[] dp2=new int[n+1];	
			for(int i=0; i<n;i++) {
				dp[i][i]=a[i];
			}
			for(int i=n-2;i>-1;i--) {
				for(int j=i+1; j<n;j++) {
					dp[i][j]=-1;
					for(int k=i; k<j;k++) {
						if(dp[i][k]!=-1 && dp[i][k]==dp[k+1][j])
							dp[i][j]=dp[i][k]+1;
					}
				}
			}
			for(int i=1; i<=n; ++i) {
				dp2[i]=Integer.MAX_VALUE;
				for(int j=0; j<i;j++) {
					if(dp[j][i-1]!=-1) {
						dp2[i]=Math.min(dp2[i], dp2[j]+1);
					}
				}
			}
			System.out.println(dp2[n]);
				
		}
		out.close();
	} 
	static void sort(long[] p) {
        ArrayList<Integer> q = new ArrayList<>();
        for (long i: p) q.add((int) i);
        Collections.sort(q);
        for (int i = 0; i < p.length; i++) p[i] = q.get(i);
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
//Some things to notice
//Check for the overflow
//Binary Search
//Bitmask
//runtime error most of the time is due to array index out of range