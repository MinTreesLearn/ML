import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
//		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		outer:for(int tt=0;tt<ttt;tt++) {
			int n=f.nextInt();
			int[] x=new int[n];
			int[] y=new int[n];
			for(int i=0;i<n;i++) {
				x[i]=f.nextInt();
				y[i]=f.nextInt();
			}
			if(n%2==1) {
				System.out.println("NO");
				continue ;
			}
			for(int i=0; i+1<n/2; ++i) {
				if(x[i]+x[i+n/2]!=x[i+1]+x[i+1+n/2]||y[i]+y[i+n/2]!=y[i+1]+y[i+1+n/2]) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
			
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