import java.io.*;
import java.util.*;
public class ThreeIntegers {
	public static void main(String[] args) throws Exception {
		FastIO in = new FastIO();
		int t = in.nextInt();
		for (int tc=0; tc<t; tc++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();
			int min = Integer.MAX_VALUE;
			int[] ans = new int[3];
			for (int checkA = 1; checkA<2*a; checkA++) {
				for (int checkB = checkA; checkB<2*b; checkB+=checkA) {
					int checkC1 = c/checkB * checkB;
					int checkC2 = c/checkB * checkB + checkB;
					if (checkB<=checkC1) {
						int operations = (Math.abs(checkA-a)+Math.abs(checkB-b)+Math.abs(checkC1-c));
						if (operations<min) {
							min = operations;
							ans[0] = checkA;
							ans[1] = checkB;
							ans[2] = checkC1;
						}
					}
					if (checkB<=checkC2) {
						int operations = (Math.abs(checkA-a)+Math.abs(checkB-b)+Math.abs(checkC2-c));
						if (operations<min) {
							min = operations;
							ans[0] = checkA;
							ans[1] = checkB;
							ans[2] = checkC2;
						}
					}
				}
			}
			System.out.println(min);
			for (int i: ans) System.out.print(i+" ");
			System.out.println();
		}
	}
	static class FastIO {
		BufferedReader br;
	    StringTokenizer st;
	    public FastIO() throws IOException
	    {
	        br = new BufferedReader(
	            new InputStreamReader(System.in));

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
