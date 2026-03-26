
import java.util.*;
import java.util.Map.Entry;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


public class CF {
	private static FS sc = new FS();
	
	private static class FS {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());				               
	            } catch (IOException e) {}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
	
	private static class extra {
		
		static int[] intArr(int size) {
			int[] a = new int[size];
			for(int i = 0; i < size; i++) a[i] = sc.nextInt();
			return a;
		}
		
		static long[] longArr(int size) {
			long[] a = new long[size];
			for(int i = 0; i < size; i++) a[i] = sc.nextLong();
			return a;
		}
		
		static long intSum(int[] a) {
			long sum = 0; 
			for(int i = 0; i < a.length; i++) {
				sum += a[i];
			}
			return sum;
		}
		
		static long longSum(long[] a) {
			long sum = 0; 
			for(int i = 0; i < a.length; i++) {
				sum += a[i];
			}
			return sum;
		}
		
		static LinkedList[] graphD(int vertices, int edges) {
			LinkedList<Integer>[] temp = new LinkedList[vertices+1];
			for(int i = 0; i <= vertices; i++) temp[i] = new LinkedList<>();
			for(int i = 0; i < edges; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				temp[x].add(y);
			}
			return temp;
		}
		
		static LinkedList[] graphUD(int vertices, int edges) {
			LinkedList<Integer>[] temp = new LinkedList[vertices+1];
			for(int i = 0; i <= vertices; i++) temp[i] = new LinkedList<>();
			for(int i = 0; i < edges; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				temp[x].add(y);
				temp[y].add(x);
			}
			return temp;
		}
		
		static void printG(LinkedList[] temp) {
			for(LinkedList<Integer> aa:temp) System.out.println(aa);
		}
		
		static long cal(long val, long pow) {
			if(pow == 0) return 1;
			long res = cal(val, pow/2);
			
//			long ret = (res*res)%mod;
//			if(pow%2 == 0) return ret;
//			return (val*ret)%mod;
			long ret = res*res;
			if(pow%2 == 0) return ret;
			return val*ret;
		}
		
		static long gcd(long a, long b) { return b == 0 ? a:gcd(b, a%b); }
		
	}
	
	static int mod = (int) 1e9 + 9;
//	static int mod = (int) 998244353;
	static int max = (int) 1e5+5, sq = 316;
	static LinkedList<Integer>[] temp;
//	static int[][] pre;
	static int ans;
	
	static class pair {
		int l, r, idx;
		pair(int x, int y, int z) {
			l = x; r = y; idx = z;
		}
	}
	
	public static void main(String[] args) {	
//		int t = sc.nextInt();
		int t = 1;
		StringBuilder ret = new StringBuilder();
		while(t-- > 0) {
			int n = sc.nextInt(), flag = 0;
			String s = sc.next();
			char cur = 'a', maxO = 'a';
			String ans = "";
			for(int i = 0; i < s.length(); i++) {
				char now = s.charAt(i);
				if(now >= cur) {
					ans += 0;
					cur = now;
				}
				else if(now >= maxO) {
					ans += 1;
					maxO = now;
				}
				else flag = 1;
			}
			ret.append(flag == 1 ? "NO\n":"YES\n"+ans + "\n");
 		}
		System.out.println(ret);
	}
}