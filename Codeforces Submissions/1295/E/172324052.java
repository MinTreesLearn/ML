import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

import javax.transaction.xa.Xid;



public class Main {
	static final long MOD1=1000000007;
	//static final long MOD=998244353;
	static final long MOD = 1000003;
	static final int NTT_MOD1 = 998244353;
	static final int NTT_MOD2 = 1053818881;
	static final int NTT_MOD3 = 1004535809;
	static long MAX = 1000000000000000000l;
	public static void main(String[] args){
		PrintWriter out = new PrintWriter(System.out);
		InputReader sc=new InputReader(System.in);
		int n = sc.nextInt();
		int[] p = sc.nextIntArray(n);
		long[] a = sc.nextLongArray(n);
		int[] inv = new int[n];
		for (int i = 0; i < inv.length; i++) {
			inv[p[i] - 1] = i;
		}
		LazysegTreemin lg = new LazysegTreemin(n);
		for (int i = 0; i < n; i++) {
			lg.apply(i, n, a[i]);
		}
		long min = a[0];
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[inv[i]];
			lg.apply(inv[i], n, -2 * a[inv[i]]);
			min = Math.min(min, sum + lg.prod(0, n - 1));
		}
		System.out.println(min);
   	}
	static class LazysegTreemin{
		int size;
		long[] dat;
		long[] lazy;
		long INF=Long.MAX_VALUE/2;
		public LazysegTreemin(int n) {
			int n_=1;
			while (n_<n) {
				n_*=2;
			}
			size=n_;
			dat=new long[2*n_-1];
			lazy=new long[2*n_-1];
		}
		void propagate(int k,int l,int r) {
			if (lazy[k]!=0) {
				dat[k] += lazy[k];
				if(r - l > 1) {
		            lazy[2*k+1] += lazy[k];
		            lazy[2*k+2] += lazy[k];
		        }
		        lazy[k] = 0;
			}
		}
		void add(int a,int b,long x,int k,int l,int r) {//a<=x<b加算　add(...,0,0,seg.size)で呼ぶ
			this.propagate(k,l,r);
			if (a<=l&&r<=b) {
				lazy[k]+=x;
				this.propagate(k,l,r);
			}
			else if (l<b&&a<r) {//交わっている場合
				this.add(a, b, x, k*2+1,l,(l+r)/2);
				this.add(a, b, x, k*2+2, (l+r)/2, r);
				dat[k] = Math.min(dat[2*k+1],dat[2*k+2]);
			}
		}
		void apply(int a,int b,long x) {
			this.add(a, b, x, 0, 0, size);
		}
		long getmin(int a,int b,int k,int l,int r) {//kが節点番号,l rがその節点番号の範囲
			if (r<=a||b<=l) {
				return INF;
			}
			this.propagate(k, l, r);
			if (a<=l&&r<=b) {
				return dat[k];
			}
			else {
				long vl=this.getmin(a, b, k*2+1,l,(l+r)/2);
				long vr=this.getmin(a, b, k*2+2, (l+r)/2, r);
				return (Math.min(vl, vr));
			}
		}
		long prod(int a,int b) {
			return getmin(a, b, 0, 0, size);
		}
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
