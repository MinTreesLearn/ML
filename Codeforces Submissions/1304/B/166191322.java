
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
	    int m = sc.nextInt();
	    List<String> al = new ArrayList<>();
	    HashMap<String, Integer> map = new HashMap<>();
	    for (int i = 0; i < n; i++) {
		  String s = sc.next();
		  al.add(s);
		  map.put(s, map.getOrDefault(s, 0) + 1);
	    }
	    LinkedList<String> ans = new LinkedList<>();
	    int len = 0;
	    for (String s : al) {
		  String rev = new StringBuilder(s).reverse().toString();
		  if (map.containsKey(rev)) {
			int t = min(map.get(s), map.get(rev));
			if (rev.equals(s)) t = map.get(s) / 2;
			for (int i = 0; i < t; i++) {
			      ans.addFirst(s);
			      len += s.length();
			}
			for (int i = 0; i < t; i++) {
			      ans.addLast(rev);
			      len += s.length();
			}
			map.put(s, map.get(s) - t);
			map.put(rev, map.get(rev) - t);
			if (map.get(s) == 0) map.remove(s);
			if (map.get(rev) == 0) map.remove(rev);
		  }
	    }
	    String max = "";
	    for (String s : map.keySet()) {
		  if (isPal(s)) {
			if (s.length() > max.length()) {
			      //
			      max = s;
			}
		  }
	    }
	    len += max.length();
	    System.out.println(len);
	    for (int i = 0; i < ans.size() / 2; i++) { System.out.print(ans.get(i)); }
	    System.out.print(max);
	    for (int i = ans.size() / 2; i < ans.size(); i++) { System.out.print(ans.get(i)); }
      }

      boolean isPal(String s) {
	    int i = 0, j = s.length() - 1;
	    while (i <= j) { if (s.charAt(i++) != s.charAt(j--)) return false; }
	    return true;
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