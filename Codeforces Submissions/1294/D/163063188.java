import java.util.*;
import java.io.*;

public class Main extends PrintWriter {
      Main() { super(System.out); }

      static boolean cases = false;

      // Solution
      void solve(int t) {
	    int n = sc.nextInt();
	    int x = sc.nextInt();
	    int c[] = new int[n + 1];
	    int val[] = new int[n];
	    for (int i = 0; i < n; i++) { val[i] = i; }
	    int ans = 0;
	    for (int i = 0; i < n; i++) {
		  int e = sc.nextInt();
		  e %= x;
		  while (val[e] < n && c[val[e]] != 0) { val[e] += x; }
		  if (val[e] < n) c[val[e]] = 1;
		  while (c[ans] != 0) { ans++; }
		  println(ans);
	    }
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

      final int ima = Integer.MAX_VALUE;
      final int imi = Integer.MIN_VALUE;
      final long lma = Long.MAX_VALUE;
      final long lmi = Long.MIN_VALUE;
      static final long mod = (long) 1e9 + 7;
      private static final FastScanner sc = new FastScanner();
      private PrintWriter out = new PrintWriter(System.out);
}