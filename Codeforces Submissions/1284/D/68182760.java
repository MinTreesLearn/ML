import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class d {
	
	static class Solver {
		
		int N;
		Lecture lecA[], lecB[];
		TreeSet<Lecture> byStart, byEnd;
		
		void solve(FastScanner s, PrintWriter out) {
			N = s.nextInt(); lecA = new Lecture[N]; lecB = new Lecture[N];
			
			for(int i = 0; i < N; i++) {
				int sa = s.nextInt(), ea = s.nextInt(), sb = s.nextInt(), eb = s.nextInt();
				lecA[i] = new Lecture(sa, ea, i);
				lecB[i] = new Lecture(sb, eb, i);
			}
			
			// event queue [time, index, 1 if remove else -1]
			PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> {
				if (a[0] == b[0]) {
					if(a[2] == b[2])
						return a[1] - b[1]; // by ID
					return a[2] - b[2]; // remove first smh
				}
				return a[0] - b[0]; // by time
			});
			
			// sweep A, check B
			byStart = new TreeSet<>((a, b) -> {
				if(a.start == b.start) return a.id - b.id;
				return a.start - b.start;
			});
			byEnd = new TreeSet<>((a, b) -> {
				if(a.end == b.end) return a.id - b.id;
				return a.end - b.end;
			});
			for(int i = 0; i < N; i++) {
				q.add(new int[] { lecA[i].start, i, 1 });
				q.add(new int[] { lecA[i].end + 1, i, -1 });
			}
			
			int cur[];
			Lecture blec, qq;
			while(!q.isEmpty()) {
				cur = q.poll();
				blec = lecB[cur[1]];
				if(cur[2] == -1) {
					byStart.remove(blec);
					byEnd.remove(blec);
					continue;
				} else {
					// any overlapping?
					if(byStart.size() > 0) {
						qq = byStart.last();
						if(qq != null && qq.start > blec.end) { out.println("NO"); return; }
						qq = byEnd.first();
						if(qq != null && blec.start > qq.end) { out.println("NO"); return; }
					}
					byStart.add(blec);
					byEnd.add(blec);
				}
			}
			
			// reset (should be moot)
			byStart.clear(); byEnd.clear(); q.clear();
			
			for(int i = 0; i < N; i++) {
				q.add(new int[] { lecB[i].start, i, 1 });
				q.add(new int[] { lecB[i].end + 1, i, -1 });
			}
			
			Lecture alec;
			while(!q.isEmpty()) {
				cur = q.poll();
				alec = lecA[cur[1]];
				if(cur[2] == -1) {
					byStart.remove(alec);
					byEnd.remove(alec);
					continue;
				} else {
					// any overlapping?
					if(byStart.size() > 0) {
						qq = byStart.last();
						if(qq != null && qq.start > alec.end) { out.println("NO"); return; }
						qq = byEnd.first();
						if(qq != null && alec.start > qq.end) { out.println("NO"); return; }
					}
					byStart.add(alec);
					byEnd.add(alec);
				}
			}
			
			out.println("YES");
		}
		
		static class Lecture {
			int start, end, id;
			Lecture(int ss, int ee, int ii) { start = ss; end = ee; id = ii; }
		}
		
	}
	
	public static void main(String[] args) {
		FastScanner s = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		new Solver().solve(s, out);
		out.close(); s.close();
	}
	
	static class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1 << 22];
		private int curChar;
		private int numChars;
		
		public FastScanner(InputStream stream) {
			this.stream = stream;
		}
		
		public FastScanner(File f) throws FileNotFoundException {
			this(new FileInputStream(f));
		}
		
		public FastScanner(String s) {
			this.stream = new ByteArrayInputStream(s.getBytes(StandardCharsets.UTF_8));
		}
		
		void close() {
			try {
				stream.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
		
		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
		
		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
		public String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}
		
		public String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
		
		public int[] nextIntArray(int N) {
			int[] ret = new int[N];
			for (int i = 0; i < N; i++)
				ret[i] = this.nextInt();
			return ret;
		}
		
		public int[][] next2DIntArray(int N, int M) {
			int[][] ret = new int[N][];
			for (int i = 0; i < N; i++)
				ret[i] = this.nextIntArray(M);
			return ret;
		}
		
		public long[] nextLongArray(int N) {
			long[] ret = new long[N];
			for (int i = 0; i < N; i++)
				ret[i] = this.nextLong();
			return ret;
		}
		
		public long[][] next2DLongArray(int N, int M) {
			long[][] ret = new long[N][];
			for (int i = 0; i < N; i++)
				ret[i] = nextLongArray(M);
			return ret;
		}
		
		public double[] nextDoubleArray(int N) {
			double[] ret = new double[N];
			for (int i = 0; i < N; i++)
				ret[i] = this.nextDouble();
			return ret;
		}
		
		public double[][] next2DDoubleArray(int N, int M) {
			double[][] ret = new double[N][];
			for (int i = 0; i < N; i++)
				ret[i] = this.nextDoubleArray(M);
			return ret;
		}
		
	}
	
}
