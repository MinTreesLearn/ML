import java.util.*;
import java.io.*;
public class LIS {
	public static void main(String[] args) throws Exception {
		FastIO in = new FastIO();
		int t = in.nextInt();
		for (int tc=0; tc<t; tc++) {
			int n = in.nextInt();
			String s = in.next();
			int[] min = new int[n];
			int[] max = new int[n];
			for (int i=0; i<n; i++) {
				max[i] = i+1;
				min[n-i-1] = i+1;
			}
			int start = -1;
			boolean prev = false;
			for (int i=0; i<n-1; i++) {
				if (s.charAt(i)=='>') {
					if (start<0) start = i;
				}
				else {
					if (start>=0) {
						reverse(max, start, i);
						start = -1;
					}
				}
			}
			if (start>=0) reverse(max, start, n-1);
			start = -1;
//			boolean prev = false;
			for (int i=0; i<n-1; i++) {
				if (s.charAt(i)=='<') {
					if (start<0) start = i;
				}
				else {
//					in.pr.println(start+" "+i);
					if (start>=0) {
						reverse(min, start, i);
						start = -1;
					}
				}
			}
			if (start>=0) reverse(min, start, n-1);
//			reverse(min, 2, 3);
			for (int i: min) {
				in.pr.print(i+" ");
			}
			in.pr.println();
			for (int i: max) {
				in.pr.print(i+" ");
			}
			in.pr.println();
		}
		in.pr.close();
	}
	public static void reverse(int[] arr, int l, int r) {
		for (int i=l; i<=(l+r)/2; i++) {
			int temp = arr[i];
			arr[i] = arr[r-(i-l)];
			arr[r-(i-l)] = temp;
		}
	}
	static class FastIO {
		BufferedReader br;
	    StringTokenizer st;
	    PrintWriter pr;
	    public FastIO() throws IOException
	    {
	        br = new BufferedReader(
	           new InputStreamReader(System.in));
	        pr = new PrintWriter(System.out);
	    }
	    

	    public String next() throws IOException
	    {
	        while (st == null || !st.hasMoreElements()) {
	           
	            st = new StringTokenizer(br.readLine());
	        }
	        return st.nextToken();
	    }

	    public int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	    public long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }

	    public double nextDouble() throws NumberFormatException, IOException
	    {
	        return Double.parseDouble(next());
	    }

	    public String nextLine() throws IOException
	    {
	        String str = br.readLine();
	        return str;
	    }
	}
}
