
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
import java.util.function.Consumer;
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
			return -1 * Integer.valueOf(this.value).compareTo(other.value);
		}
	}

	static boolean isPrime(long d) {
		if (d == 1)
			return true;
		for (int i = 2; i <= (long) Math.sqrt(d); i++) {
			if (d % i == 0)
				return false;
		}
		return true;
	}

	static String decimalTob(int n, int b, String g) {
		int z = n % b;
		g = String.valueOf(z) + g;
		n /= b;
		if (n > 0) {
			g = decimalTob(n, b, g);
		}
		return g;
	}

	static long powermod(long x, long y, long mod) {
		long ans = 1;
		x = x % mod;
		if (x == 0)
			return 0;
		int i = 1;
		while (y > 0) {
			if ((y & 1) != 0)
				ans = (ans * x) % mod;
			y = y >> 1;
			x = (x * x) % mod;
		}
		return ans;
	}

	public static void main(String[] args) throws Exception {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = 1;
		while(t-- > 0) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int arr[] = new int[n];
        int brr[] = new int[m];
        for(int i = 0; i < n; i++) arr[i] = sc.nextInt();
        for(int i = 0; i < m; i++) brr[i] = sc.nextInt();
        int crr[] = new int[n + 1];
        int drr[] = new int[m + 1];
       int i = 0;
       while(i < n) {
    	   int temp = arr[i];
    	   int count = 0;
    	   while(i < n && temp == arr[i]) {i++; count++; if(temp == 1) crr[count]++;}
       }
       i = 0;
       while(i < m) {
    	   int temp = brr[i];
    	   int count = 0;
    	   while(i < m && temp == brr[i]) {i++; count++; if(temp == 1) drr[count]++;}
       }
       for(int j = n - 1; j >= 0; j--) {
    	   crr[j] += crr[j + 1];
       }
       for(int j = m - 1; j >= 0; j--) {
    	   drr[j] += drr[j + 1];
       }
       long count = 0;
		for(int j = 1; j * j <= k; j++) {
			if(k % j != 0) 
				continue;
			int d = k / j;
			if(j <= n && d <= m) count += (long)crr[j] * drr[d];
			if(j <= m && d <= n && j != d) count += (long)crr[d] * drr[j];
		}
		out.println(count);
		}
           out.close();
	 }
}