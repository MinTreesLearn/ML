
import java.io.*;
import java.util.*;

public class Main {
	public static void solve(IO io) {
		String s = io.getWord();
		
		ArrayList<Integer> left = new ArrayList<>();
		ArrayList<Integer> right = new ArrayList<>();
		
		
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				left.add(i);
			}
		}
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.charAt(i) == ')') {
				right.add(i);
			}
		}
		int i = 0;
		ArrayList<Integer> ans = new ArrayList<>();
		while (i < left.size() && i < right.size() && left.get(i) <= right.get(i)) {
			ans.add(left.get(i));
			ans.add(right.get(i));
			i++;
		}
		if (i == 0) {
			System.out.println(0);
			return;
		}
		Collections.sort(ans);
		System.out.println(1);
		System.out.println(ans.size());
		for (int j:ans) {
			System.out.print((j + 1) + " ");
		}
		System.out.println();
		
	}

	public static void main(String[] args) {
		IO io = new IO();
		solve(io);
		io.close();
	}

	static class IO extends PrintWriter {

		public IO() {
			super(new BufferedOutputStream(System.out));
			r = new BufferedReader(new InputStreamReader(System.in));
		}

		public IO(InputStream i) {
			super(new BufferedOutputStream(System.out));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public IO(InputStream i, OutputStream o) {
			super(new BufferedOutputStream(o));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}

		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
			if (token == null)
				try {
					while (st == null || !st.hasMoreTokens()) {
						line = r.readLine();
						if (line == null)
							return null;
						st = new StringTokenizer(line);
					}
					token = st.nextToken();
				} catch (IOException e) {
				}
			return token;
		}

		private String nextToken() {
			String ans = peekToken();
			token = null;
			return ans;
		}
	}
}

  	  	  	  			 	 	 		     		