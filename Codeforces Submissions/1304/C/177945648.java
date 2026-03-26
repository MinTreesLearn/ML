import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main { public static void main(String[] args) { new MainClass().execute(); } }

class MainClass extends PrintWriter {
	MainClass() { super(System.out, true); }

	boolean cases = true;

	// Solution

	void solveIt(int testCaseNo) {
      int n = sc.nextInt();
      long m = sc.nextLong();
      List<long[]> al = new ArrayList<>();
      for(int i=0;i<n;i++){ 
          long time = sc.nextLong();
          long lb = sc.nextLong();
          long rb = sc.nextLong();
          al.add(new long[]{time,lb,rb});
      }
      long max = m, min = m, prev = 0;
      for(long x[] : al){
          max += (x[0]-prev);
          min -= (x[0]-prev);
          if(max < x[1] || min > x[2]) {
              println("NO");
              return;
          }
          max = min(max,x[2]);
          min = max(min,x[1]);
          prev = x[0];
      }
      println("YES");
	}

	void solve() {
		int caseNo = 1;
		if (cases) for (int T = sc.nextInt(); T > 1; T--, caseNo++) { solveIt(caseNo); }
		solveIt(caseNo);
	}

	void execute() {
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		this.sc = new FastIO();
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		sc.tr(G - S + "ms");
	}

	class FastIO {
		private boolean endOfFile() {
			if (bufferLength == -1) return true;
			int lptr = ptrbuf;
			while (lptr < bufferLength) {
				// __
				if (!spaceChar(inputBuffer[lptr++])) return false;
			}
			try {
				is.mark(1000);
				while (true) {
					int b = is.read();
					if (b == -1) {
						is.reset();
						return true;
					} else if (!spaceChar(b)) {
						is.reset();
						return false;
					}
				}
			} catch (IOException e) {
				return true;
			}
		}

		private byte[] inputBuffer = new byte[1024];
		int bufferLength = 0, ptrbuf = 0;

		private int readByte() {
			if (bufferLength == -1) throw new InputMismatchException();
			if (ptrbuf >= bufferLength) {
				ptrbuf = 0;
				try {
					bufferLength = is.read(inputBuffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (bufferLength <= 0) return -1;
			}
			return inputBuffer[ptrbuf++];
		}

		private boolean spaceChar(int c) { return !(c >= 33 && c <= 126); }

		private int skipIt() {
			int b;
			while ((b = readByte()) != -1 && spaceChar(b));
			return b;
		}

		private double nextDouble() { return Double.parseDouble(next()); }

		private char nextChar() { return (char) skipIt(); }

		private String next() {
			int b = skipIt();
			StringBuilder sb = new StringBuilder();
			while (!(spaceChar(b))) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		private char[] readCharArray(int n) {
			char[] buf = new char[n];
			int b = skipIt(), p = 0;
			while (p < n && !(spaceChar(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}

		private char[][] readCharMatrix(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++) map[i] = readCharArray(m);
			return map;
		}

		private int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}

		private long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) a[i] = nextLong();
			return a;
		}

		private int nextInt() {
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
			if (b == '-') {
				minus = true;
				b = readByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}

		private long nextLong() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
			if (b == '-') {
				minus = true;
				b = readByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}

		private void tr(Object... o) {

			if (INPUT.length() != 0) System.out.println(Arrays.deepToString(o));

		}
	}

	InputStream is;
	PrintWriter out;
	String INPUT = "";
	final int ima = Integer.MAX_VALUE, imi = Integer.MIN_VALUE;
	final long lma = Long.MAX_VALUE, lmi = Long.MIN_VALUE;
	final long mod = (long) 1e9 + 7;
	FastIO sc;

}