import java.util.*;
import java.io.*;
 
public class A {
	static class Pair {
		long x;
		long y;
 
		public Pair(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}
 
	static long gcd(long n, long m) {
		if (m == 0)
			return n;
		else
			return gcd(m, n % m);
	}
 
	static long lcm(long n, long m) {
		return (n * m) / gcd(n, m);
	}
 
	static void dfs(ArrayList<ArrayList<Integer>> adj, int s, int[] vis, int[] cnt) {
		for (int i : adj.get(s)) {
			if (vis[i] == 1) {
				continue;
			}
			cnt[0]++;
			vis[i] = 1;
			dfs(adj, i, vis, cnt);
		}
	}
 
	public static long solve(long a, long b, long x, long y, long n) {
		if (a - n >= x) {
			return ((a - n) * b);
		} else {
			n -= a - x;
			a = x;
			if (b - n >= y) {
				return (a * (b - n));
			} else {
				b = y;
				return (a * b);
			}
		}
	}
 
	static int high(int n) {
		int p = (int) (Math.log(n) / Math.log(2));
		return (int) Math.pow(2, p);
	}
 
	static void reverseandflip(char[] s1, int pos) {
		int i = 0;
		int j = pos;
		while (i <= j) {
			if (s1[i] == s1[j]) {
				if (s1[i] == '1') {
					s1[i] = '0';
					s1[j] = '0';
				} else {
					s1[i] = '1';
					s1[j] = '1';
				}
			}
			i++;
			j--;
		}
	}
 
	static int bs(ArrayList<Long> pow, long target) {
		int low = 0;
		int idx = -1;
		int high = pow.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (pow.get(mid) <= target) {
				low = mid + 1;
				idx = mid;
			} else {
				high = mid - 1;
			}
		}
		return idx;
	}
 
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		StringBuilder str = new StringBuilder();
		int t = sc.nextInt();
		for (int xx = 0; xx < t; xx++) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			long[] arr = new long[n];
			long max = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextLong();
				max = Math.max(max, arr[i]);
			}
			ArrayList<Long> pow = new ArrayList<>();
			pow.add(1L);
			pow.add((long) k);
			while (true) {
				pow.add(pow.get(pow.size() - 1) * k);
				if (pow.get(pow.size() - 1) >= max)
					break;
			}
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				if (arr[i] == 0)
					continue;
				while (arr[i] != 0) {
					if (pow.size() == 0)
						break;
					int id = bs(pow, arr[i]);
					if (id == -1)
						break;
					arr[i] -= pow.get(id);
					pow.remove(id);
				}
				if (arr[i] != 0) {
					ok = false;
					break;
				}
			}
			if (ok)
				str.append("YES" + "\n");
			else
				str.append("NO" + "\n");
		}
		System.out.println(str);
		sc.close();
	}
}