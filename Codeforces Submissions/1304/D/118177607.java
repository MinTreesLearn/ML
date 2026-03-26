import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<ttt;tt++) {
			int n=f.nextInt();
			char[] l=f.next().toCharArray();
			int num = n, last = 0;
			int[] ans=new int[n];
			for (int i = 0; i < n; i++)
			{
				if (i == n - 1 || l[i] == '>')
				{
					for (int j = i; j >= last; j--)
						ans[j] = num--;
					last = i + 1;
				}
			}
			for (int i:ans) System.out.print(i+" ");
			System.out.println();
			ans=new int[n];
			num = 1;
			last = 0;
			for (int i = 0; i < n; i++)
			{
				if (i == n - 1 || l[i] == '<')
				{
					for (int j = i; j >= last; j--)
						ans[j] = num++;
					last = i + 1;
				}
			}
			for (int i:ans) System.out.print(i+" ");
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