/*
*     |\_/|
*    / | | \
*    \ _*_ /
*    /     \    /\
*   / meow  \__/ /
*   \  za O(1)    \
*    \_ _  __  _  /
*     \| \|  \| \|
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a % b);
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> g(n);
	vector<ll> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		u--; v--;
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
	map<vector<ll>, ll> d;
	for (int i = 0; i < n; i++) {
		if (g[i].empty())continue;
		d[g[i]] += c[i];
	}
	ll ans = 0;
	for (auto w : d) {
		ans = gcd(w.second, ans);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}