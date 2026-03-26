import java.io.*;
import java.util.*;

public class E{
	static int n,m;
	static int[][] g;
	static int[][] t;
	
	static void dbg(int[][] cur) {
		for (int[] x: cur) {
			for (int y: x) out.print(y + " ");
			out.println();
		}
	}
	
	public static void main(String[] args) throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		//new Thread(null, new (), "peepee", 1<<28).start();
		n = readInt();
		m = readInt();
		g = new int[n][m];
		t = new int[n][m];
		int b = 1;
		for (int i =0 ; i < n; i++) {
			for (int j = 0; j < m; j++) {
				t[i][j] = b++;
				g[i][j] = readInt();
			}
		}
		long cost = 0;
		for (int i = 0; i < m; i++) {
			long v = solve(i);
			//System.out.println(v);
			cost += v;
		}
		out.println(cost);
		out.close();
	}
	
	static void dbg(long[] a) {
		for (long x: a) out.print(x + " ");
		out.println();
	}
	
	static long solve(int col) {
		long[] r = new long[n];
		long[] r2 = new long[n];
		HashMap<Long, List<Integer>>hm = new HashMap<Long, List<Integer>>();
		for (int i = 0; i < n; i++) {
			r[i] = g[i][col];
			r2[i] = t[i][col];
			if (!hm.containsKey(r2[i])) {
				hm.put(r2[i], new ArrayList<Integer>());
			}
			hm.get(r2[i]).add(i);
		}
		
		long ans = 2*n;
		long[] cycles = new long[n]; // I cycled i times.
		
		for (int i = 0; i < n; i++) {
			if (!hm.containsKey(r[i])) continue;
			for (int x: hm.get(r[i])) {
				// X IS FROM R2 (the correct)
				// I IS FROM R1. (ours)
				if (i >= x) cycles[i-x]++;
				else {
					int newR2Pos = x-n;
					//System.out.println("We saw it at r2 pos " + x + " but our r pos is " + i );
					cycles[i-newR2Pos]++;
				}
			}
		}
		for (int i= 0 ; i < n; i++) {
			long tans = i+n-cycles[i];
			ans = Long.min(ans, tans);

		}
		//System.out.println(ans);
		return ans;
	}

	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static StringTokenizer st = new StringTokenizer("");
	static String read() throws IOException{return st.hasMoreTokens() ? st.nextToken():(st = new StringTokenizer(br.readLine())).nextToken();}
	static int readInt() throws IOException{return Integer.parseInt(read());}
	static long readLong() throws IOException{return Long.parseLong(read());}
	static double readDouble() throws IOException{return Double.parseDouble(read());}
	
}