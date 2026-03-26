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

	static boolean isSorted(int arr[]) {
		for (int i = 1; i <= arr.length; i++)
			if (arr[i - 1] != i)
				return false;
		return true;
	}
   static char help(char a, char b) {
	   return a!= 'S' && b!= 'S'? 'S': a!= 'E' && b!= 'E'? 'E': 'T';
   }
	public static void main(String[] args) throws Exception {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = 1;
		outerloop: 
			while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String arr[] = new String[n];
            HashMap<String, Integer> ss = new HashMap<>();
            for(int i = 0; i < n; i++) {
            	 arr[i] = sc.next();
            	ss.put(arr[i], ss.getOrDefault(arr[i], 0) + 1);
            }
            long count = 0;
            for(int i = 0; i < n; i++) {
            	for(int j = i + 1; j < n; j++) {
            		char a[] = new char[k];
            		for(int l = 0; l < k; l++) {
            			if(arr[i].charAt(l) == arr[j].charAt(l)) a[l] = arr[i].charAt(l);
            			else a[l] = help(arr[i].charAt(l), arr[j].charAt(l));
            		}
            		ss.put(arr[i], ss.get(arr[i]) - 1);
            		ss.put(arr[j], ss.get(arr[j]) - 1);
            		count += ss.getOrDefault(new String(a), 0);
            		ss.put(arr[i], ss.get(arr[i]) + 1);
            		ss.put(arr[j], ss.get(arr[j]) + 1);
            	}
            }
            out.println(count / 3);
            }
		out.close();
	}
}