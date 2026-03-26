
/*
  It's always like another kick for me to make sure I get what I want to get done,
  because honestly you never know. 
*/
import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main extends PrintWriter {
      Main() { super(System.out); }

      static boolean cases = true;

      // Solution
      void solve() {
	    int n = sc.nextInt();
	    char a[] = sc.readCharArray(n);
	    HashMap<String, Integer> map = new HashMap<>();
	    int ans[] = { 0, 0 };
	    int c[] = { 0, 0 };
	    map.put(0 + " " + 0, -1);
	    boolean f = false;
	    for (int i = 0; i < n; i++) {
		  char ch = a[i];
		  if (ch == 'L') c[0]--;
		  else if (ch == 'R') c[0]++;
		  else if (ch == 'U') c[1]++;
		  else if (ch == 'D') c[1]--;
		  if (map.containsKey(c[0] + " " + c[1])) {
			int s = map.get(c[0] + " " + c[1]);
			int e = i;
			if (!f || ((ans[1] - ans[0] + 1) > (e - s + 1))) {
			      ans[0] = s + 2;
			      ans[1] = e + 1;
			      f = true;
			}
		  }
		  map.put(c[0] + " " + c[1], i);
	    }
	    System.out.println(!f ? -1 : (ans[0] + " " + ans[1]));
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