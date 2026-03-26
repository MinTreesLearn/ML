//package USACO;
import java.util.*;
import java.io.*;
public class kuroniAndImpossibleCalculation {
	public static void main(String[]args){
		Kattio io = new Kattio();
		int n = io.nextInt();
		int m = io.nextInt();
		int[]arr = new int[m]; 
		for(int i = 0; i < m; i++) {
			arr[i] = -1;
		}
		boolean zero = false;
		for(int i = 0; i < n; i++) {
			int s = io.nextInt();
			if(arr[s %  m ] != -1) {
				zero = true;
			}
			arr[s % m] = s;
			//io.println(s);
		}
		if(zero == true) {
			io.println("0");
		}
		else {
			ArrayList<Integer>arr2 = new ArrayList<Integer>();
			for(int i = 0; i < m; i++) {
				if(arr[i] != -1) {
					arr2.add(arr[i]);
				}
			}
			long ans = 1L;
			for(int i = 0; i < arr2.size(); i++) {
				for(int j = i+1; j < arr2.size(); j++) {
					//io.println(arr2.get(i) + " " + arr2.get(j));
					ans = (ans * Math.abs(arr2.get(i)- arr2.get(j))) % m;
				}
			}
			io.println(ans);
		}
		io.close();
	}
	static class Kattio extends PrintWriter {
		private BufferedReader r;
		private StringTokenizer st;
		// standard input
		public Kattio() { this(System.in, System.out); }
		public Kattio(InputStream i, OutputStream o) {
			super(o);
			r = new BufferedReader(new InputStreamReader(i));
		}
		// USACO-style file input
		public Kattio(String problemName) throws IOException {
			super(problemName + ".out");
			r = new BufferedReader(new FileReader(problemName + ".in"));
		}
		// returns null if no more input
		public String next() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(r.readLine());
				return st.nextToken();
			} catch (Exception e) { }
			return null;
		}
		public int nextInt() { return Integer.parseInt(next()); }
		public double nextDouble() { return Double.parseDouble(next()); }
		public long nextLong() { return Long.parseLong(next()); }
	}
		
}
