
/*
  It's always like another kick for me to make sure I get what I want to get done,
  because honestly you never know. 
*/
import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main extends PrintWriter {
      Main() { super(System.out); }

      static boolean cases = false;

      // Solution
      int l, h, r, a[];
      int dp[][];

      void solve() {
	    int n = sc.nextInt();
	    h = sc.nextInt();
	    l = sc.nextInt();
	    r = sc.nextInt();
	    a = sc.readIntArray(n);
	    this.dp = new int[n + 1][h + 1];

	    for (int i = n - 1; i >= 0; i--) {
		  for (int j = h; j >= 0; j--) {
			int d1 = (j + a[i]) % h;
			int d2 = (j + (a[i] - 1)) % h;
			if (d1 >= l && d1 <= r) {
			      dp[i][j] = max(dp[i][j], 1 + dp[i + 1][d1]);
			} else dp[i][j] = max(dp[i][j], dp[i + 1][d1]);
			if (d2 >= l && d2 <= r) {
			      dp[i][j] = max(dp[i][j], 1 + dp[i + 1][d2]);
			} else dp[i][j] = max(dp[i][j], dp[i + 1][d2]);
		  }
	    }

	    System.out.println(dp[0][0]);

      }

      void sort(int[] a) {
	    ArrayList<Integer> l = new ArrayList<>();
	    for (int i : a) l.add(i);
	    Collections.sort(l);
	    for (int i = 0; i < a.length; i++) a[i] = l.get(i);
      }

      public static void main(String[] args) {
	    Main obj = new Main();
	    int c = 1;
	    for (int t = (cases ? sc.nextInt() : 0); t > 1; t--, c++) obj.solve();
	    obj.solve();
	    obj.flush();
      }

      static class FastScanner {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st = new StringTokenizer("");

	    String next() {
		  while (!st.hasMoreTokens()) try {
			st = new StringTokenizer(br.readLine());
		  } catch (IOException e) {
			e.printStackTrace();
		  }
		  return st.nextToken();
	    }

	    int nextInt() { return Integer.parseInt(next()); }

	    int[] readIntArray(int n) {
		  int[] a = new int[n];
		  for (int i = 0; i < n; i++) a[i] = nextInt();
		  return a;
	    }

	    char[] readCharArray(int n) {
		  char a[] = new char[n];
		  String s = sc.next();
		  for (int i = 0; i < n; i++) { a[i] = s.charAt(i); }
		  return a;
	    }

	    long[] readLongArray(int n) {
		  long[] a = new long[n];
		  for (int i = 0; i < n; i++) a[i] = nextLong();
		  return a;
	    }

	    long nextLong() { return Long.parseLong(next()); }
      }

      final int ima = Integer.MAX_VALUE;
      final int imi = Integer.MIN_VALUE;
      final long lma = Long.MAX_VALUE;
      final long lmi = Long.MIN_VALUE;
      static final long mod = (long) 1e9 + 7;
      private static final FastScanner sc = new FastScanner();
      private PrintWriter out = new PrintWriter(System.out);
}