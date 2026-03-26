import java.io.*;
import java.util.*;
public class StringColoring {
	public static void main(String[] args) throws Exception {
		FastIO in = new FastIO();
		int n = in.nextInt();
		String s = in.next();
		int prev0 = -1;
		int prev1 = -1;
		int[] ans = new int[n];
		boolean works = true;
		for (int i=0; i<n; i++) {
			int c = s.charAt(i)-'a';
			if (c<prev0 && c<prev1) {
				works = false;
				break;
			}
			else if (c<prev0 && c>=prev1) {
				prev1 = c;
				ans[i] = 1;
			}
			else if (c>=prev0 && c<prev1) {
				prev0 = c;
				ans[i] = 0;
			}
			else {
				if (prev1<prev0) {
					prev0 = c;
					ans[i] = 0;
				}
				else {
					prev1 = c;
					ans[i] = 1;
				}
			}
		}
		if (!works) System.out.println("NO");
		else {
			System.out.println("YES");
			for (int i: ans) System.out.print(i);
			System.out.println();
		}
	}
	static class FastIO {
		BufferedReader br;
	    StringTokenizer st;
	    PrintWriter pr;
	    public FastIO() throws IOException
	    {
	        br = new BufferedReader(new InputStreamReader(System.in));
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
