
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
	    char a[] = sc.next().toCharArray();
	    char b[] = sc.next().toCharArray();
	    int ans = 0, j = 0;
	    HashMap<Character, TreeSet<Integer>> map = new HashMap<>();
	    for (int i = 0; i < a.length; i++) {
		  map.putIfAbsent(a[i], new TreeSet<>());
		  map.get(a[i]).add(i);
	    }
	    while (j < b.length) {
		  int pos = j;
		  int i = -1;
		  while (i < a.length && j < b.length) {
			if (!map.containsKey(b[j])) { break; }
			Integer x = map.get(b[j]).higher(i);
			if (x == null) break;
			j++;
			i = x;
		  }
		  if (pos == j) {
			System.out.println(-1);
			return;
		  }
		  ans++;
	    }
	    System.out.println(ans);
      }

      int solve(String str[]) {
	    int mask = 0;
	    for (String s : str) { for (char ch : s.toCharArray()) mask |= (1 << ch - 'a'); }
	    return mask != (1 << 25) ? 0 : 1;
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