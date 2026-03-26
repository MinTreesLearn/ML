import java.io.*;
import java.util.*;

public class C {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	public static void main(String[] args) throws IOException {
		readInput();
		out.close();
	}
	
	static int[][][][] dp;
	static int[] a;
	static int n;
	
	static int solve(int i, int o, int e, int p) {
		if (o < 0 || e < 0) return n+300;
		if (i>= n) return 0;
		if (dp[i][o][e][p] == -1) {
			dp[i][o][e][p] = n+300;
			if (a[i] == -1) {
				// Pick odd.
				int bias = 0;
				if (p == 0)bias++;
				int v1 = solve(i+1,o-1,e,1)+bias;
				// Pick even.
				bias = 0;
				if (p == 1)bias++;
				int v2 = solve(i+1,o,e-1,0)+bias;
				dp[i][o][e][p] = Integer.min(v1, v2);
			}
			else if (a[i] == 1) {
				int bias = 0;
				if (p == 0)bias++;
				dp[i][o][e][p] = solve(i+1,o,e,1)+bias;
			}
			else if (a[i] == 0){
				int bias = 0;
				if (p == 1)bias++;
				dp[i][o][e][p] = solve(i+1,o,e,0)+bias;
			}
		}
		return dp[i][o][e][p];
	}

	public static void readInput() throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		n = Integer.parseInt(br.readLine());
		int odds = (n+1)/2;
		int evens = n/2;
		a=  new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
			if (a[i] == 0) a[i]--;
			else {
				if((a[i]&=1)==1) odds--;
				else evens--;
			}
		}
		dp = new int[n][odds+1][evens+1][2];
		for (int[][][] k: dp) for (int[][] d: k) for (int[] c: d) Arrays.fill(c, -1);
		if (a[0] != -1) {
			out.println(solve(1,odds,evens,a[0]));
		}
		else {
			out.println(Integer.min(solve(1,odds-1,evens,1), solve(1,odds,evens-1,0)));
		}
		
		
	}
}
