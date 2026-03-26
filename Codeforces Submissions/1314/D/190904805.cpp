// Problem: D. Путешествие
// Contest: Codeforces - Codeforces Round #623 (Div. 1, по задачам VK Cup 2019-2020 - Отборочный раунд, Engine)
// URL: https://codeforces.com/contest/1314/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int N = 82, inf = 1e9;
int n, k, a[N][N], path[N], mark[N], ans = inf, timer = 0;
vector<array<int, 2>> best[N][N];
void rec(int p) {
	if(p == 0) {
		path[p] = 0;
		rec(p + 1);
		return;
	}
	if(2*p == k) {
		path[p] = 0;
		int cost = 0;
		++timer;
		for(int i = 1; i <= p; i++)
			mark[path[i]] = timer;
		for(int i = 1; i <= p; i++) {
			int j = 0, u = path[i - 1], v = path[i];
			while(mark[best[u][v][j][1]] == timer)
				j++;
			cost += best[u][v][j][0];
		}
		ans = min(ans, cost);
		return;
	}
	for(int i = 0; i < n; i++) {
		path[p] = i;
		rec(p + 1);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				best[i][j].push_back({a[i][k] + a[k][j], k});
			}
			while(best[i][j].size() < 6)
				best[i][j].push_back({inf, -1});
			sort(all(best[i][j]));
		}
	}
	rec(0);
	cout << ans << '\n';
}
