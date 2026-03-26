#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (ll)(3e5+5)
#define fi first
#define se second
ll n, k, p[N], mn[N], col[N], ans, o[N];
bool s[N];
vector<ll> v[N], g[2][N];
inline void merge(ll x, ll y, bool st) {
	if (p[x] == p[y]) return;
	if (g[0][p[x]].size() + g[1][p[x]].size() > g[0][p[y]].size() + g[1][p[y]].size())
		swap(x, y);
	if (!st && col[x] == col[y] || st && col[x] != col[y]) { swap(g[0][p[x]], g[1][p[x]]), o[p[x]] ^= 1; for (auto z : g[0][p[x]]) col[z] ^= 1; for (auto z : g[1][p[x]]) col[z] ^= 1;
	}
	ll px = p[x], py = p[y]; o[py] = min(o[px], o[py]);
	ans -= mn[px], ans -= mn[py]; for (auto z : g[0][px]) g[0][py].push_back(z), p[z] = py; for (auto z : g[1][px]) g[1][py].push_back(z), p[z] = py;
	if (o[py] < 2) mn[py] = g[o[py]][py].size();
	else mn[py] = min(g[0][py].size(), g[1][py].size());
	ans += mn[py];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k; {char a; for (int i = 1; i <= n; i++) cin >> a, s[i] = (a == '1'); }
	ll a, b; for (int i = 1; i <= k; i++) {
		p[i] = i, mn[i] = 0, col[i] = 1, o[i] = 2, g[1][i].push_back(i);
		cin >> a; while (a--) cin >> b, v[b].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 1) {
			a = p[v[i][0]]; b = v[i][0];
			ans -= mn[a]; o[a] = col[b] ^ (s[i] ? 1 : 0); mn[a] = g[o[a]][a].size(); ans += mn[a];
		}
		else if (v[i].size() == 2) merge(v[i][0], v[i][1], s[i]);
		cout << ans << '\n';
	}
}