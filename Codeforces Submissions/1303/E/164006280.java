import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.*;



public class Main {
	static final long MOD1=1000000007;
	static final long MOD=998244353;
	static final int NTT_MOD1 = 998244353;
	static final int NTT_MOD2 = 1053818881;
	static final int NTT_MOD3 = 1004535809;
	static long MAX = 1000000000000000000l;
	public static void main(String[] args){
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			char[] S = sc.next().toCharArray();
			char[] T = sc.next().toCharArray();
			out.println(solve(S, T));
		}
		out.flush();
   	}
	static String solve(char[] S, char[] T) {
		int s_len = S.length;
		int t_len = T.length;
		for (int i = 0; i < T.length; i++) {
			int len1 = i + 1;
			int[][] dp = new int[s_len + 1][len1 + 1];
			for (int j = 0; j < dp.length; j++) {
				Arrays.fill(dp[j], -1);
			}
			dp[0][0] = 0;
			for (int j = 0; j < s_len; j++) {
				for (int j2 = 0; j2 <= len1; j2++) {
					if(dp[j][j2] == -1) continue;
					dp[j + 1][j2] = Math.max(dp[j + 1][j2], dp[j][j2]);
					if(j2 + 1 <= len1 && S[j] == T[j2]) dp[j + 1][j2 + 1] = Math.max(dp[j + 1][j2 + 1], dp[j][j2]);
					if(dp[j][j2] + 1 + len1 <= t_len && S[j] == T[dp[j][j2] + len1]) dp[j + 1][j2] = Math.max(dp[j + 1][j2], dp[j][j2] + 1);
				}
			}
			if (dp[s_len][len1] + len1 == t_len) {
				return "YES";
			}
		}
		return "NO";
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