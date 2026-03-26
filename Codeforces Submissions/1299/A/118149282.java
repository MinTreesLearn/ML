import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
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

		int[] a = new int[n + 2];
		int[] pre = new int[n + 2];
		int[] suf = new int[n + 2];

		for (int i = 1; i <= n; i++) {
			a[i] = nextInt();
		}

		// pre and suf
		for (int i = 1, j = n; i <= n; i++, j--) {
			pre[i] = pre[i - 1] | a[i];
			suf[j] = suf[j + 1] | a[j];
		}

		int Max = -INF, inx = 0;
		for (int i = 1; i <= n; i++) {
			int temp = a[i] & ~(pre[i - 1] | suf[i + 1]);
			if (temp > Max) {
				Max = temp;
				inx = i;
			}
		}

		int temp = a[1];
		a[1] = a[inx];
		a[inx] = temp;

		for (int i = 1; i <= n; i++) {
			pw.print(a[i] + " ");
		}
		pw.println();
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


 		 			 			 				 	 			 		   	 	