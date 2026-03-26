import java.io.*;
import java.util.*;
public class Main {
	static class BIT {
		int n;
		int[] tree;
		
		public BIT(int n) {
			this.n = n;
			tree = new int[n + 2];
		}
		
		int read(int i) {
			i++;
			int sum = 0;
			while (i > 0) {
				sum += tree[i];
				i -= i & -i;
			}
			return sum;
		}
		
		void update(int i, int val) {
			i++;
			while (i <= n) {
				tree[i] += val;
				i += i & -i;
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
			int m=f.nextInt();
			BIT bit=new BIT(n+2*m);
			int[] mn=new int[n];
			int[] mx=new int[n];
			int[] pos=new int[n];
			for(int i=0;i<n;i++) {
				mn[i]=mx[i]=i+1;
				pos[i]=m+i+1;
				bit.update(pos[i], 1);
			}
			int top=m;
			for(int i=0;i<m;i++) {
				int u=f.nextInt();
				mn[u-1]=1;
				mx[u-1]=Math.max(mx[u-1], bit.read(pos[u-1]));
				if(bit.read(pos[u-1])==1) {
					continue;
				}
				bit.update(pos[u-1],-1);
		        pos[u-1]=top;
		        bit.update(pos[u-1],1);
		        top--;
			}
			for(int i=0;i<n;i++) {
				mx[i]=Math.max(mx[i],bit.read(pos[i]));
			}
			for(int i=0;i<n;i++) {
				out.println(mn[i]+" "+mx[i]);
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