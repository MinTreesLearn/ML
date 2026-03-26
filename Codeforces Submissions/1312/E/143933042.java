import java.io.*;
import java.util.*;

public class Main {
	static Reader in;
	static PrintWriter out;

	int n;
	Integer[] a;

	Main() {
		n = in.nextInt();
		a = new Integer[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		ArrayList<Integer>[] dp = new ArrayList[n + 1];
		for (int i = 0; i <= n; i++)
			dp[i] = new ArrayList<>();
		for (int i = 0; i < n; i++)
			dp[i].add(i + 1);
		for (int i = n - 1; i >= 0; i--)
			for (int x = a[i]; x - a[i] < dp[i].size(); x++) {
				int j = dp[i].get(x - a[i]);
				if (j < n && 0 <= x - a[j] && x - a[j] < dp[j].size())
					dp[i].add(dp[j].get(x - a[j]));
			}
		Integer[] dp2 = new Integer[n + 1];
		dp2[0] = 0;
		for (int i = 0; i < n; i++)
			for (int j : dp[i])
				if (dp2[j] == null)
					dp2[j] = 1 + dp2[i];
				else
					dp2[j] = Math.min(dp2[j], 1 + dp2[i]);
		out.println(dp2[n]);
	}

	public static void main(String[] args) throws Exception {
//		FileIO();
		in = new Reader();
		out = new PrintWriter(System.out);
		new Main();
		out.flush();
	}

	static void FileIO() throws Exception {
		System.setIn(new FileInputStream("In.txt"));
		System.setOut(new PrintStream(new FileOutputStream("Out.txt")));
		System.setErr(new PrintStream(new FileOutputStream("Error.txt")));
	}
}

class Reader {
	BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st;

	String next() {
		try {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(r.readLine());
			return st.nextToken();
		} catch (Exception e) {
		}
		return null;
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}
}