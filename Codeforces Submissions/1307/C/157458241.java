import java.util.*;
import java.io.*;

public class Main extends PrintWriter {
      Main() { super(System.out); }

      static boolean cases = false;

      // Solution
      void solve(int t) {
	    char a[] = sc.next().toCharArray();
	    long f[] = new long[26];
	    long max = 0;
	    for (char ch : a) {
		  f[ch - 'a']++;
		  max = Math.max(max, f[ch - 'a']);
	    }
	    f = new long[26];
	    long dp[][] = new long[26][26];
	    for (char ch : a) {
		  for (int i = 0; i < 26; i++) { dp[ch - 'a'][i] += (f[i]); }
		  f[ch - 'a']++;
	    }
	    for (long x[] : dp) { for (long i : x) max = Math.max(max, i); }
	    System.out.println(max);
      }

      public static void main(String[] args) {
	    Main obj = new Main();
	    int c = 1;
	    for (int t = (cases ? sc.nextInt() : 0); t > 1; t--, c++) obj.solve(c);
	    obj.solve(c);
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

      private static final FastScanner sc = new FastScanner();
      private PrintWriter out = new PrintWriter(System.out);
}
