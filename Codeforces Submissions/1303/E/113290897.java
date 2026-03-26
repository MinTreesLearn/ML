import java.io.*;
import java.util.*;
public class Main {
	static int n, m;
	static int[][] nxt;
	static char[] s, t;
	static int[][] dp;
	static boolean solve(char[] t1, char[] t2) {
		dp[0][0]=-1;
		for(int i=0; i<=t1.length; ++i) {
			for(int j=0; j<=t2.length; ++j) {
				if(i==0 && j==0) continue;
				dp[i][j]=n;
				if(i>0)
					dp[i][j]=Math.min(dp[i][j], nxt[dp[i-1][j]+1][t1[i-1]-'a']);
				if(j>0)
					dp[i][j]=Math.min(dp[i][j], nxt[dp[i][j-1]+1][t2[j-1]-'a']);
			}
		}
		return dp[t1.length][t2.length]<n;
	}
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		outer:for(int tt=0;tt<ttt;tt++) {
			s=f.next().toCharArray();
			t=f.next().toCharArray();
			nxt=new int[402][26];
			dp=new int[401][401];
			n=s.length;
			m=t.length;
			for(int i=0; i<26; ++i)
				nxt[n][i]=nxt[n+1][i]=n;
			for(int i=n-1; i>-1;i--) {
				for(int j=0;j<26;j++) {
					nxt[i][j]=nxt[i+1][j];
				}
				nxt[i][s[i]-'a']=i;
			}
			for(int i=0; i<m; ++i) {
				char[] t1=new char[i];
				char[] t2=new char[m-i];
				for(int j=0;j<m;j++) {
					if(j<t1.length) {
						t1[j]=t[j];
					}
					else {
						t2[j-t1.length]=t[j];
					}
				}
				if(solve(t1, t2)) {
					System.out.println("YES");;
					continue outer;
				}
			}
			System.out.println("NO");
		}
		out.close();
	} 
	static void sort(int[] p) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i: p) q.add( i);
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