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
	static long lcm(long a, long b) {
		return a / gcd(a,b) * b;
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
			return false;
		for (int i = 2; i <= (long) Math.sqrt(d); i++) {
			if (d % i == 0)
				return false;
		}
		return true;
	}

	static void decimalTob(long n, int b, int arr[], int i) {
		long z = n % b;
		arr[i] += (int) z;
		n /= b;
		if (n > 0) {
			i++;
			decimalTob(n, b, arr, i);
		}
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
	static boolean isEqual(ArrayList<Integer> ss , ArrayList<Integer> ssf) {
		for(int i = 0; i < ss.size(); i++) if((int)ss.get(i) != (int)ssf.get(i)) return false;
		return true;
	}
	public static void main(String[] args) throws Exception {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = 1;
		outerloop: 
			while (t-- > 0) {
              int n = sc.nextInt();
              long count = 0, count1 = 0;
              int arr[] = new int[1000000 + 2];
              ArrayList<Pair> ss  =new ArrayList<>();
              for(int i = 0; i < n; i++) {
            	  int m = sc.nextInt();
            	  ArrayList<Integer> ssf = new ArrayList<>();
            	  ArrayList<Integer> ssd = new ArrayList<>();
            	  for(int j = 0; j < m; j++) {
            		  int a = sc.nextInt();
            		  ssf.add(a);
            		  ssd.add(a);
            		  }
            	  Collections.sort(ssf, Collections.reverseOrder());
            	  if(isEqual(ssf, ssd)) {
            		  ss.add(new Pair(ssf.get(0), ssf.get(m - 1)));
            		  arr[ssf.get(0)]++;
            	  }
            	  else {
            		  count += n;
            		  count1++;}
              }
              for(int i = arr.length - 2; i >= 0; i--) arr[i] += arr[i + 1];
              count += count1 * ss.size();
              for(int i = 0; i < ss.size(); i++) {
            	  int z = ss.get(i).value;
            	  count += arr[z + 1];
              }
              out.println(count);
              }
		out.close();
	}
}