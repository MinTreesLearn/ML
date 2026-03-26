import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		outer:for(int tt=0;tt<ttt;tt++) {
			int n=f.nextInt();
			int m=f.nextInt();
			int k=f.nextInt();
			int[] l=f.readArray(n);
			int ans=-1;
			int min=Integer.MAX_VALUE;
			for(int i:l)min=Math.min(min, i);
//			System.out.println(tt+"a;kjf sd");
			if(m<=k) {
				for(int i=0;i<m;i++) {
					ans=Math.max(ans, l[i]);
					ans=Math.max(ans, l[n-i-1]);
				}
			}
			else {
				for(int i=0;i<=k;i++) {
					int curr=Integer.MAX_VALUE;
					for(int j=i;j<i+(m-k);j++) {
//						System.out.println(i+" "+j+" "+(j+n-m));
						int temp=min;
						temp=Math.max(temp, l[j]);
						temp=Math.max(temp, l[j+n-m]);
						curr=Math.min(curr, temp);
//						System.out.println(curr);
					}
					ans=Math.max(ans,curr);
				}
				
			}
			System.out.println(ans);
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