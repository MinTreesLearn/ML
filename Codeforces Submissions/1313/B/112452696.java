import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int t=1;
		t=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<t;tt++) {
			int n=f.nextInt();
			int x=f.nextInt();
			int y=f.nextInt();
			int temp=x+y;
			int k=Math.min(n,temp);
			System.out.println(Math.min(n,temp-k+1)+" "+Math.min(temp-1,n));
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