
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
	    for (int d[] : dp) Arrays.fill(d, -1);
	    int ans = solve(0, 0);
	    System.out.println(ans);
      }

      int solve(int i, int x) {
	    if (i >= a.length) return 0;
	    if (dp[i][x] != -1) return dp[i][x];
	    int d1 = (x + a[i]) % h;
	    int d2 = (x + (a[i] - 1)) % h;
	    int ans = 0;
	    ans = max((d1 >= l && d1 <= r ? 1 : 0) + solve(i + 1, d1), ans);
	    ans = max((d2 >= l && d2 <= r ? 1 : 0) + solve(i + 1, d2), ans);
	    return dp[i][x] = ans;
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