import java.util.*;
import java.io.*;
public class D{
	static FastScanner fs = null;
	public static void main(String[] args) {
		fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int t = 1;
		while(t-->0){
			int n = fs.nextInt();
			long a = fs.nextLong();
			long b = fs.nextLong();
			long k = fs.nextLong();
			long hei[] = new long[n];
			for(int i=0;i<n;i++){
				hei[i] = fs.nextLong();
			}
			long sum = a+b;
			for(int i=0;i<n;i++){
				long d = hei[i]%sum;
				if(d==(long)0)
					d = sum;
				long z = d/a;
				if(d%a!=(long)0)
					z+=1;
				z-=(long)1;
				hei[i] = z;
			}
			int c = 0;
			long ans = 0;
			Arrays.sort(hei);
			for(int i=0;i<n;i++){
				k-=hei[i];
				c++;
				// out.println(i+" "+k+" "+c);
				if(k<0){
					c-=1;
					break;
				}
			}
			ans = c;
			out.println(ans);
		}
		out.close();
	}
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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
	}
}