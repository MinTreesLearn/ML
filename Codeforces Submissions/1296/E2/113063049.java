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
			int n=f.nextInt();
			char[] s=f.next().toCharArray();
			int[] dp=new int[26];
			int[] ans=new int[n];
			int a1=0;
			for(int i=n-1;i>-1;i--) {
				int cd=1;
				for(int j=0; j<s[i]-'a'; ++j)
					cd=Math.max(cd, dp[j]+1);
				a1=Math.max(cd, a1);
				ans[i]=cd;
				dp[s[i]-'a']=cd;
			}
			System.out.println(a1);;
			for(int i=0; i<n; ++i)
				System.out.print(ans[i]+" ");
			System.out.println();
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