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

		public Pair(int index,int value) {
			this.index = index;
			this.value = value;
		}

		@Override
		public int compareTo(Pair other) {
			// multiplied to -3 as the author need descending sort order
			if(other.index < this.index) return -1;
			if(other.index > this.index) return 1;
			else return 0;
		}
		@Override
		public String toString() {
			return this.index + " " + this.value;
		}
	}
	static boolean isPrime(long d) {
		if (d == 3)
			return false;
		for (int i = 2; i <= (long) Math.sqrt(d); i++) {
			if (d % i == 0)
				return false;
		}
		return true;
	}
	static void decimalTob(int n, int k, Stack<Integer> ss) {
          int x = n % k;
          int y = n / k;
          ss.push(x);
          if(y > 0) {
        	   decimalTob(y, k, ss);
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
	static long power(long x, long y)
	{
	    long res = 1;
	    while (y > 0)
	    {
	        if ((y & 1) != 0)
	            res = res * x;	  
	        y = y >> 1; 
	        x = x * x;  
	    }
	    return res;
	}static void dfsdd(int node, int count, ArrayList<ArrayList<Integer>> ss, boolean visited[], PriorityQueue<Pair> queue) {
		 visited[node] = true;
		 queue.add(new Pair(count, node));
		 for(int e: ss.get(node)) {
			 if(!visited[e]) {
				 dfsdd(e, count + 1, ss, visited, queue);
			 }
		 }
	}
	static void dfs(int node, long count, ArrayList<ArrayList<Integer>> ss , int brr[], long ans[], boolean visited[]) {
		visited[node] = true;
		count += brr[node];
		for(int e: ss.get(node)) {
			if(!visited[e]) {
				dfs(e, count, ss, brr, ans, visited);
			}
		}
		if(brr[node] == 0) ans[0] += count;
	}
	public static void main(String[] args) throws Exception {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = 1;
		outerloop:
			while(t-- > 0) {
         int n = sc.nextInt();
         int m = sc.nextInt();
         String arr[] = new String[n];
         String brr[] = new String[m];
         for(int i = 0; i < n; i++) arr[i] = sc.next();
         for(int i = 0; i < m; i++) brr[i] = sc.next();
         String crr[] = new String[(int)lcm(n, m)];
         int j = 0;
         int i = 0;
         int k = 0;
         int z = (int)lcm(n, m);
         while(k < z) {
        	 crr[k++] = arr[i++] + brr[j++];
        	 if(i >= n) {
        		 i = 0;
        	 }
        	 if(j >= m) j = 0;
         }
         int q = sc.nextInt();
         while(q-- > 0) {
        	 int a = sc.nextInt();
        	 if(a % z == 0) a = z - 1;
        	 else a = a%z - 1;
        	 out.println(crr[a]);
         }
             }
		out.close();
	}
}