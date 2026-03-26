
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
      void solve() {
	    int n = sc.nextInt();
	    long a = sc.nextLong();
	    long b = sc.nextLong();
	    long k = sc.nextLong();
	    long ar[] = sc.readLongArray(n);
	    long ans = 0;
	    long req = b / a;
	    if (b % a != 0) req++;
	    TreeMap<Long, Integer> map = new TreeMap<>();
	    for (long i : ar) {
		  long last = i % (a + b);
		  if (last > 0) {
			if (last <= a) {
			      map.put(0l, map.getOrDefault(0l, 0) + 1);
			} else {
			      long x = last - a;
			      long r = x / a + (x % a != 0 ? 1 : 0);
			      if (k >= r) { map.put(r, map.getOrDefault(r, 0) + 1); }
			}
		  } else {
			if (k >= req) { map.put(req, map.getOrDefault(req, 0) + 1); }
		  }
	    }
	    for (long key : map.keySet()) {
		  for (int i = 0; i < map.get(key) && k >= key; i++) {
			k -= key;
			ans++;
		  }
	    }
	    System.out.println(ans);
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