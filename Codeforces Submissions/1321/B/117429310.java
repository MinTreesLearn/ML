import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	static final int MAX_N = 1000010;
	static final int INF = 0x3f3f3f3f;
	static final int mod = 1000000007;

	public static void main(String[] args) throws IOException {
		initReader(System.in);

//		int T = nextInt();
//		for (int i = 1; i <= T; i++)
		solve();

	pw.flush();
	}

	/*******************************************************************************************************************************/





	public static void solve() throws IOException {
		int n = nextInt();

		long[] arr = new long[n];

		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}

		HashMap<Long, Long> hm = new HashMap<Long, Long>();
		long max = 0;
		for (int i = 0; i < n; i++) {
			hm.put(i - arr[i], hm.getOrDefault(i - arr[i], 0L) + arr[i]);
			max = Math.max(max, hm.get(i - arr[i]));
		}

		pw.println(max);
	}






	/*******************************************************************************************************************************/

	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter pw;

	public static void initReader(InputStream input) throws IOException {
		reader = new BufferedReader(new InputStreamReader(input));
		tokenizer = new StringTokenizer("");
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

//		reader = new BufferedReader(new FileReader("ate.in"));
//		tokenizer = new StringTokenizer("");
//		printWriter = new PrintWriter(new BufferedWriter(new FileWriter("ate.out")));
	}

	public static boolean hasNext() {
		try {
			while (!tokenizer.hasMoreTokens()) {
				tokenizer = new StringTokenizer(reader.readLine());
			}
		} catch (Exception e) {
			return false;
		}
		return true;
	}

	public static String next() throws IOException {
		while (!tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static String nextLine() {
		try {
			return reader.readLine();
		} catch (Exception e) {
			return null;
		}
	}

	public static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	public static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	public static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static char nextChar() throws IOException {
		return next().charAt(0);
	}
}


