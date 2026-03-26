import java.io.*;
import java.util.*;

public class C {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	public static void main(String[] args) throws IOException {
		readInput();
		out.close();
	}
	static int n,m,k;
	static long[] a;
	
	
	static long calc(int start, int end) {
		long max = Long.MAX_VALUE;
		// Mobile dictates I do a similar thing here w/ prefix sums and shit.
		int head = start;
		int tail = end-mobile;
		if (head > tail) return max;
		max = Long.min(Long.max(a[head], a[tail]), max);
		//System.out.println("Calculating for " + start + " -> " + end);
		for (int delta = 1; delta <= mobile; delta++) {
			head++;
			tail++;
			if (head >= n) break;
			long cur = a[head];
			if (tail < n) cur = Long.max(a[head], a[tail]); 
			max = Long.min(max, cur);
		}
		
		return max;
	}
	
	static int mobile;
	
	static long solve() {
		long sol = Long.MAX_VALUE;
		for (int i = 0; i < n; i++) sol = Math.min(sol, a[i]);
		int head = 0;
		int end = n-k-1;
		mobile = m-1-k;
		if (head > end) return sol;
		sol = Math.max(sol, calc(head,end));
		for (int delta = 1; delta <= k; delta++) {
			head++;
			end++;
			if (head >= n) break;
			sol = Math.max(sol, calc(head,Integer.min(end, n-1)));
		}
		return sol;
	}
	
	public static void readInput() throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		int t = Integer.parseInt(br.readLine());
		while (t-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			k = Integer.min(k, m-1);
			a = new long[n];
			 st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				a[i] = Long.parseLong(st.nextToken());
			}
			out.println(solve());
		}
	}
}
