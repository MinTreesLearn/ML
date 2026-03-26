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
			double[] a=new double[n];
			for(int i=0;i<n;i++) a[i]=f.nextDouble();
			Stack<double[]> stack = new Stack();
			for (int i = n - 1; i >= 0; i--) {
				double sum = a[i];
				int len = 1;
				while (!stack.isEmpty()) {
					double[] top = stack.peek();
	 
					if (sum / len > top[0]) {
						sum += top[0] * top[1];
						len += top[1];
						stack.pop();
					} else
						break;
	 
				}
				double curr = sum / len;
				stack.push(new double[] { curr, len });
			}
			while (!stack.isEmpty()) {
				double[] curr = stack.pop();
				while (curr[1]-- > 0)
					out.println(curr[0]);
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