import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Main {
	static final long MOD=1000000007;
	static final long MOD1=998244353;
	static long ans=0;
	//static ArrayList<Integer> ans=new ArrayList<>();
	public static void main(String[] args){
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] A = new int[N][M];
		for (int i = 0; i < A.length; i++) {
			A[i] = sc.nextIntArray(M);
		}
		int from= 0;
		int to= 1000000009;
		while ((to-from)>=1) {
			int mid=(to-from)/2+from;
			if (f(mid, N, M, A)) {
				to=mid;
			}
			else {
				from=mid+1;
			}
		}
		int ans = to-1;
		int[] anss = f1(ans, N, M, A);
		System.out.println(anss[0]+" "+anss[1]);
	}
	static boolean f(int mid,int N,int M,int[][] A) {
		HashSet<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < N; i++) {
			int fl = 0;
			for (int j = 0; j < M; j++) {
				if (mid<=A[i][j]) fl |= 1<<j;
			}
			set.add(fl);
		}
		int[] a = new int[set.size()];
		int c = 0;
		for (int i : set) {
			a[c++] = i;
		}
		for (int i = 0; i < a.length; i++) {
			for (int j = i; j < a.length; j++) {
				int v = a[i]|a[j];
				if (Integer.bitCount(v)==M) return false;
			}
		}
		return true;
	}
	static int[] f1(int mid,int N,int M,int[][] A) {
		HashSet<Integer> set = new HashSet<Integer>();
		int[] s = new int[N];
		for (int i = 0; i < N; i++) {
			int fl = 0;
			for (int j = 0; j < M; j++) {
				if (mid<=A[i][j]) fl |= 1<<j;
			}
			s[i] = fl;
			set.add(fl);
		}
		int[] a = new int[set.size()];
		int c = 0;
		for (int i : set) {
			a[c++] = i;
		}
		int[] ans = new int[2];
		for (int i = 0; i < a.length; i++) {
			for (int j = i; j < a.length; j++) {
				int v = a[i]|a[j];
				if (Integer.bitCount(v)==M) {
					for (int k = 0; k < N; k++) {
						if (s[k]==a[i]) {
							ans[0] = k + 1;
							break;
						}
					}
					for (int k = 0; k < N; k++) {
						if (s[k]==a[j]) {
							ans[1] = k + 1;
							break;
						}
					}
					return ans;
				}
			}
		}
		return null;
	}
	static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
		public double[] nextDoubleArray(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; i++)
				a[i] = nextDouble();
			return a;
		}
		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}
