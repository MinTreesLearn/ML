import java.util.*;
import java.io.*;

public class A {
	static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
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

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		StringBuilder str = new StringBuilder();
		int t = sc.nextInt();

		for (int xx = 1; xx <= t; xx++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = sc.nextInt();
			Arrays.sort(arr);
			for(int i=n-1;i>=0;i--)
				str.append(arr[i]+" ");
			str.append("\n");
		}
		System.out.println(str);
		sc.close();
	}
}