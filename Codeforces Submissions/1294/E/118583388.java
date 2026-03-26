import java.io.*;
import java.util.*;
public class Main {
	static int func(int[] g,int num,int m) {
		int n=g.length;
		int[] fill=new int[n];
		int ans=n;
		for(int i=0;i<n;i++) {
			if(g[i%n]%m!=num || g[i%n]>n*m) continue;
			int orig=(g[i%n]-num)/m;
			if(num==0) orig--;
			int shift=-1;
			if(orig<=i) {
				shift=(i-orig);
			}
			else {
				shift=(n+i-orig);
			}
			fill[shift]++;
		}
//		System.out.println(Arrays.toString(fill));
		for(int i=0;i<n;i++) {
			int temp=i+n-fill[i];
			ans=Math.min(ans, temp);
			
		}
		return ans;
	}
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
//		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<ttt;tt++) {
			int n=f.nextInt();
			int m=f.nextInt();
			int[][] g=new int[m][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					g[j][i]=f.nextInt();
				}
			}
			int ans=0;
			for(int i=0;i<m;i++) {
				ans+=func(g[i],(i+1)%m,m);
//				System.out.println(ans);
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