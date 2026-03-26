//package com.kraken.cf.cf627;

import java.util.*;

public class Codeforces {
	static long[] dp, ans;

	private static ArrayList<ArrayList<Integer>> tree;

	private static int[] a;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		a = new int[n + 1];
		dp = new long[n + 1];
		ans = new long[n + 1];
		tree = new ArrayList<>();
		for (int i = 0; i <= n; i++) tree.add(new ArrayList<>());
		for (int i = 1; i <= n; i++) {
			a[i] = sc.nextInt();
			if (a[i] == 0) a[i] = -1;
		}
		for (int i = 0; i < n - 1; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			tree.get(u).add(v);
			tree.get(v).add(u);
		}
		dfs(1, -1);
		find(1, -1);
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) sb.append(ans[i]).append(" ");
		System.out.println(sb.toString());
	}

	private static void dfs(int v, int lv) {
		dp[v] = a[v];
		for (int x : tree.get(v)) {
			if (x == lv) continue;
			dfs(x, v);
			dp[v] += Math.max(0, dp[x]);
		}
	}

	private static void find(int v, int lv) {
		ans[v] = dp[v];
		for (int x : tree.get(v)) {
			if (x == lv) continue;
			dp[v] -= Math.max(0, dp[x]);
			dp[x] += Math.max(0, dp[v]);
			find(x, v);
			dp[x] -= Math.max(0, dp[v]);
			dp[v] += Math.max(0, dp[x]);
		}
	}
}
