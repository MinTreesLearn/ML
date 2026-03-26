// Problem: E. Array Shrinking
// Contest: Codeforces - Educational Codeforces Round 83 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1312/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

import java.io.*;
import java.util.*;

public class Main {
    static IntReader in;
    static FastWriter out;
    static String INPUT = "";
	
	static final int N = 505, INF = 0x3f3f3f3f;
	static int[][] dp = new int[N][N], f = new int[N][N];
	static int n;
    static void solve() {
        n = ni();
        for (int i = 1; i <= n; i++) {
        	dp[i][i] = 1;
        	f[i][i] = ni();
        }
        
        for (int len = 2; len <= n; len++) {
        	for (int i = 1; i + len - 1 <= n; i++) {
        		int j = i + len - 1;
        		dp[i][j] = INF;
        		for (int k = i; k < j; k++) {
        			if (dp[i][k] + dp[k + 1][j] < dp[i][j]) {
        				dp[i][j] = dp[i][k] + dp[k + 1][j];
        				if (dp[i][k] == 1 && dp[k + 1][j] == 1 && f[i][k] == f[k + 1][j]) {
        					dp[i][j] = 1;
        					f[i][j] = f[i][k] + 1;
        				}
        			}
        		}
        	}
        }
        out.println(dp[1][n]);
    }

    public static void main(String[] args) throws Exception {
        in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
        out = new FastWriter(System.out);
        solve();
        out.flush();
    }

    public static class IntReader {
        private InputStream is;
        private byte[] inbuf = new byte[1024];
        public int lenbuf = 0, ptrbuf = 0;

        public IntReader(InputStream is) {
            this.is = is;
        }
        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }
        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }
        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }
        private double nd() {
            return Double.parseDouble(ns());
        }
        private char nc() {
            return (char) skip();
        }
        private String ns() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        private char[] ns(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(isSpaceChar(b))) {
                buf[p++] = (char) b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }
        private int ni() {
            return (int) nl();
        }
        private long nl() {
            long num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
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
    }

    public static class FastWriter {
        private static final int BUF_SIZE = 1 << 13;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastWriter() {
            out = null;
        }
        public FastWriter(OutputStream os) {
            this.out = os;
        }
        public FastWriter(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }
        public FastWriter write(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }
        public FastWriter write(char c) {
            return write((byte) c);
        }
        public FastWriter write(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }
        public FastWriter write(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }
        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }
        public FastWriter write(int x) {
            if (x == Integer.MIN_VALUE) {
                return write((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }
        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }
        public FastWriter write(long x) {
            if (x == Long.MIN_VALUE) {
                return write("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }
        public FastWriter write(double x, int precision) {
            if (x < 0) {
                write('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            //		if(x < 0){ x = 0; }
            write((long) x).write(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                write((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }
        public FastWriter writeln(char c) {
            return write(c).writeln();
        }
        public FastWriter writeln(int x) {
            return write(x).writeln();
        }
        public FastWriter writeln(long x) {
            return write(x).writeln();
        }
        public FastWriter writeln(double x, int precision) {
            return write(x, precision).writeln();
        }
        public FastWriter write(int... xs) {
            boolean first = true;
            for (int x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }
        public FastWriter write(long... xs) {
            boolean first = true;
            for (long x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }
        public FastWriter writeln() {
            return write((byte) '\n');
        }
        public FastWriter writeln(int... xs) {
            return write(xs).writeln();
        }
        public FastWriter writeln(long... xs) {
            return write(xs).writeln();
        }
        public FastWriter writeln(char[] line) {
            return write(line).writeln();
        }
        public FastWriter writeln(char[]... map) {
            for (char[] line : map) write(line).writeln();
            return this;
        }
        public FastWriter writeln(String s) {
            return write(s).writeln();
        }
        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }
        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
        public FastWriter print(byte b) {
            return write(b);
        }
        public FastWriter print(char c) {
            return write(c);
        }
        public FastWriter print(char[] s) {
            return write(s);
        }
        public FastWriter print(String s) {
            return write(s);
        }
        public FastWriter print(int x) {
            return write(x);
        }
        public FastWriter print(long x) {
            return write(x);
        }
        public FastWriter print(double x, int precision) {
            return write(x, precision);
        }
        public FastWriter println(char c) {
            return writeln(c);
        }
        public FastWriter println(int x) {
            return writeln(x);
        }
        public FastWriter println(long x) {
            return writeln(x);
        }
        public FastWriter println(double x, int precision) {
            return writeln(x, precision);
        }
        public FastWriter print(int... xs) {
            return write(xs);
        }
        public FastWriter print(long... xs) {
            return write(xs);
        }
        public FastWriter println(int... xs) {
            return writeln(xs);
        }
        public FastWriter println(long... xs) {
            return writeln(xs);
        }
        public FastWriter println(char[] line) {
            return writeln(line);
        }
        public FastWriter println(char[]... map) {
            return writeln(map);
        }
        public FastWriter println(String s) {
            return writeln(s);
        }
        public FastWriter println() {
            return writeln();
        }
    }
    static int ni() {
        return in.ni();
    }
    static long nl() {
        return in.nl();
    }
    static String ns() {
        return in.ns();
    }
    static double nd() {
        return Double.parseDouble(in.ns());
    }
}
