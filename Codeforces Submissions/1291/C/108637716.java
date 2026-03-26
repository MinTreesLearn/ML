import java.util.*;
import java.io.*;

public class B{
	public static void main(String[] args)
	{
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int t = fs.nextInt();
		for(int tt=0;tt<t;tt++)
		{
			int n = fs.nextInt(); int m = fs.nextInt(); int k = fs.nextInt();
			int[] arr = fs.readArray(n);
			int ans = Integer.MIN_VALUE;
			k = Math.min(m-1, k);
//			out.println(m-k-1);
			for(int i=0;i<=k;i++)
			{
				int left = i;
				int right = k-i;
//				out.println(ans+" "+left+" "+right);
				int cur = Integer.MAX_VALUE;
				for(int j=0;j<=m-k-1;j++)
				{
					int nleft =left+j;
					int nright = right+(m-k-1)-j;
//					out.println(nleft+" "+nright);
					cur = Math.min(cur,Math.max(arr[n+i-m+j],arr[nleft]));
//					out.println(ans);
				}
				ans = Math.max(ans,cur);
			}
			out.println(ans);
		}
		out.close();
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
	}
}


