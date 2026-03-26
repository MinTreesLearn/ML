// Problem: B. Двойное выбывание
// Contest: Codeforces - Codeforces Round #623 (Div. 1, по задачам VK Cup 2019-2020 - Отборочный раунд, Engine)
// URL: https://codeforces.com/contest/1314/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> interesting(1<<n);
	for(int t, i = 0; i < m; i++) {
		cin >> t;
		interesting[t - 1] = 1;
	}
	const int W_BIT = 2;
	const int L_BIT = 1;
	auto solve = [&](auto self, int l, int r) -> array<int, 4> {
		array<int, 4> dp;
		dp.fill(-(1<<20));
		if(l + 2 == r) {
			int score = interesting[l] || interesting[r - 1];
			dp[W_BIT * interesting[l] + L_BIT * interesting[r - 1]] = score;
			dp[W_BIT * interesting[r - 1] + L_BIT * interesting[l]] = score;
			return dp;
		}
		int m = (l + r) / 2;
		auto ldp = self(self, l, m);
		auto rdp = self(self, m, r);
		//L wins
		for(int T = 0; T < 2; T++, swap(ldp, rdp)) {
			for(int l = 0; l < 4; l++) {
				for(int r = 0; r < 4; r++) {
					int score = 0, nmsk = 0;
					score += (l & W_BIT) || (r & W_BIT);//winners play
					score += (l & L_BIT) || (r & L_BIT);//losers play
					int losers_2 = (r & W_BIT) || (l & L_BIT) || (r & L_BIT);
					score += losers_2;//losers play again
					nmsk += l & W_BIT;
					nmsk += losers_2 * L_BIT;
					dp[nmsk] = max(dp[nmsk], ldp[l] + rdp[r] + score);
				}
			}
		}
		return dp;
	};
	auto dp = solve(solve, 0, 1<<n);
	int ans = 0;
	for(int i = 0; i < 4; i++)
		ans = max(ans, dp[i] + !!i);
	cout << ans << '\n';
}
