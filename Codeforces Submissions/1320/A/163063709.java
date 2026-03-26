import java.util.*;
import java.io.*;

public class Main extends PrintWriter {
      Main() { super(System.out); }

      static boolean cases = false;

      // Solution
      void solve(int t) {
	    int n = sc.nextInt();
	    int a[] = sc.readIntArray(n);
	    HashMap<Integer, Long> map = new HashMap<>();
	    long max = 0;
	    for (int i = 0; i < n; i++) {
		  int e = a[i] - (i + 1);
		  map.put(e, map.getOrDefault(e, 0l) + (long) a[i]);
		  max = Math.max(max, map.get(e));
	    }
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

      final int ima = Integer.MAX_VALUE;
      final int imi = Integer.MIN_VALUE;
      final long lma = Long.MAX_VALUE;
      final long lmi = Long.MIN_VALUE;
      static final long mod = (long) 1e9 + 7;
      private static final FastScanner sc = new FastScanner();
      private PrintWriter out = new PrintWriter(System.out);
}