import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
      static InputStream is;
      static PrintWriter out;
      static String INPUT = "";
      static final int ima = Integer.MAX_VALUE, imi = Integer.MIN_VALUE;
      static final long lma = Long.MAX_VALUE, lmi = Long.MIN_VALUE;
      static final long mod = (long) 1e9 + 7;

      static void solve() {
	    int caseNo = 1;
	    // for (int T = sc.nextInt(); T > 1; T--, caseNo++) { solveIt(caseNo); }
	    solveIt(caseNo);
      }

      // Solution
      static void solveIt(int testCaseNo) {
	    int n = sc.nextInt();
	    int a[] = sc.readIntArray(n);
	    int max = 0;
	    for (int s = 0, e = 0; e < n; e++) {
		  if (a[e] == 0) {
			s = e + 1;
			continue;
		  }
		  max = max(max, e - s + 1);
	    }
	    int s = 0;
	    while (s < n && a[s] == 1) s++;
	    int e = n - 1;
	    while (e >= 0 && a[e] == 1) e--;
	    max = max(max, s + (n - e - 1));
	    System.out.println(max);
      }

      public static void main(String[] args) throws Exception {
	    long S = System.currentTimeMillis();
	    is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
	    out = new PrintWriter(System.out);

	    solve();
	    out.flush();
	    long G = System.currentTimeMillis();
	    sc.tr(G - S + "ms");
      }

      static class sc {
	    private static boolean endOfFile() {
		  if (bufferLength == -1) return true;
		  int lptr = ptrbuf;
		  while (lptr < bufferLength) {

			if (!isThisTheSpaceCharacter(inputBufffferBigBoi[lptr++])) return false;

		  }
		  try {
			is.mark(1000);
			while (true) {
			      int b = is.read();
			      if (b == -1) {
				    is.reset();
				    return true;
			      } else if (!isThisTheSpaceCharacter(b)) {
				    is.reset();
				    return false;
			      }
			}
		  } catch (IOException e) {
			return true;
		  }
	    }

	    private static byte[] inputBufffferBigBoi = new byte[1024];
	    static int bufferLength = 0, ptrbuf = 0;

	    private static int justReadTheByte() {
		  if (bufferLength == -1) throw new InputMismatchException();
		  if (ptrbuf >= bufferLength) {
			ptrbuf = 0;
			try {
			      bufferLength = is.read(inputBufffferBigBoi);
			} catch (IOException e) {
			      throw new InputMismatchException();
			}
			if (bufferLength <= 0) return -1;
		  }
		  return inputBufffferBigBoi[ptrbuf++];
	    }

	    private static boolean isThisTheSpaceCharacter(int c) { return !(c >= 33 && c <= 126); }

	    private static int skipItBishhhhhhh() {
		  int b;
		  while ((b = justReadTheByte()) != -1 && isThisTheSpaceCharacter(b));
		  return b;
	    }

	    private static double nextDouble() { return Double.parseDouble(next()); }

	    private static char nextChar() { return (char) skipItBishhhhhhh(); }

	    private static String next() {
		  int b = skipItBishhhhhhh();
		  StringBuilder sb = new StringBuilder();
		  while (!(isThisTheSpaceCharacter(b))) {
			sb.appendCodePoint(b);
			b = justReadTheByte();
		  }
		  return sb.toString();
	    }

	    private static char[] readCharArray(int n) {
		  char[] buf = new char[n];
		  int b = skipItBishhhhhhh(), p = 0;
		  while (p < n && !(isThisTheSpaceCharacter(b))) {
			buf[p++] = (char) b;
			b = justReadTheByte();
		  }
		  return n == p ? buf : Arrays.copyOf(buf, p);
	    }

	    private static char[][] readCharMatrix(int n, int m) {
		  char[][] map = new char[n][];
		  for (int i = 0; i < n; i++) map[i] = readCharArray(m);
		  return map;
	    }

	    private static int[] readIntArray(int n) {
		  int[] a = new int[n];
		  for (int i = 0; i < n; i++) a[i] = nextInt();
		  return a;
	    }

	    private static long[] readLongArray(int n) {
		  long[] a = new long[n];
		  for (int i = 0; i < n; i++) a[i] = nextLong();
		  return a;
	    }

	    private static int nextInt() {
		  int num = 0, b;
		  boolean minus = false;
		  while ((b = justReadTheByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		  if (b == '-') {
			minus = true;
			b = justReadTheByte();
		  }

		  while (true) {
			if (b >= '0' && b <= '9') {
			      num = num * 10 + (b - '0');
			} else {
			      return minus ? -num : num;
			}
			b = justReadTheByte();
		  }
	    }

	    private static long nextLong() {
		  long num = 0;
		  int b;
		  boolean minus = false;
		  while ((b = justReadTheByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		  if (b == '-') {
			minus = true;
			b = justReadTheByte();
		  }

		  while (true) {
			if (b >= '0' && b <= '9') {
			      num = num * 10 + (b - '0');
			} else {
			      return minus ? -num : num;
			}
			b = justReadTheByte();
		  }
	    }

	    private static void tr(Object... o) {

		  if (INPUT.length() != 0) System.out.println(Arrays.deepToString(o));

	    }
      }
}
// And I wish you could sing along, But this song is a joke, and the melody I
// wrote, wrong