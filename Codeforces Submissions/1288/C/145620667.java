/*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
 
*/

import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.Math.*;

public class KickStart2020 {
	 static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);

	}
	static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	public static class Pair implements Comparable<Pair> {
		public int index;
		public int value;

		public Pair(int index, int value) {
			this.index = index;
			this.value = value;
		}

		@Override
		public int compareTo(Pair other) {
			// multiplied to -1 as the author need descending sort order
			if(other.index < this.index) return -1;
			if(other.index > this.index) return 1;
			if(other.value < this.value) return -1;
			if(other.value > this.value) return 1;
			return 0;
		}
		@Override
		public String toString() {
			return this.index + " " + this.value;
		}
	}
	static boolean isPrime(long d) {
		if(d == 0) return true;
		if (d == 1)
			return false;
		for (int i = 2; i <= (long) Math.sqrt(d); i++) {
			if (d % i == 0)
				return false;
		}
		return true;
	}
	static String decimalTob(int n, int k , String count) {
          int x = n % k;
          int y = n / k;
          count += x;
          if(y > 0) {
             count = decimalTob(y, k, count);
          }
          return count;
	}
	static long powermod(long x, long y, long mod) {
		if(y == 0) return 1;
		long value = powermod(x, y / 2, mod);
		if(y % 2 == 0) return (value * value) % mod;
		return (value * (value * x) % mod) % mod;
	}
	static long power(long x, long y) {
		if(y == 0) return 1;
		long value = power(x, y / 2);
		if(y % 2 == 0) return (value * value);
		return value * value * x;
	    }
     static int bS(int l, int r, int find, int arr[]) {
             if(r < l) return l;
                int mid = (l + r) / 2;
             if(arr[mid] >= find) return bS(l, mid - 1, find, arr);
             return bS(mid + 1, r, find, arr);
        }
     static int dp(int l, int r, int dp[][]) {
    	if(r == 0 || r == l) return 1;
    	if(dp[l][r] != 0) return dp[l][r];
    	int ans = dp(l - 1, r - 1, dp) + dp(l - 1, r, dp);
    	return dp[l][r] = ans % 1000000007;
     }
   	public static void main(String[] args) throws Exception {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = 1;
		outerloop:
			while(t-- > 0) {
           int n = sc.nextInt();
           int m = sc.nextInt();
           int dp[][] = new int[2*m + n][n];
           int ans = dp(2 * m  + n - 1, n - 1, dp);
           out.println(ans);
             }
		out.close();
	}
}