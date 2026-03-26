#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define point pair<int, int>
#define X first
#define Y second
#define pb push_back
#define show(x) cerr << (#x) << " = " << x << '\n'
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

const int N = 3e3 + 64;
const int LOG = 15;
const int INF = 2e9 + 64;

#define int ll

int n, dist[N][N], dp[N][N], sub[N][N];
vector<int> t[N];

void dfs(int v, int p, int s, int d) {
	dist[s][v] = dist[v][s] = d;
	sub[s][v] = 1;

	for (auto to : t[v])
		if (to != p)
			dfs(to, v, s, d + 1), sub[s][v] += sub[s][to];
}

int closest(int from, int to) {
	int res = -1, d = INF;
	for (int v : t[from])
		if (dist[v][to] < d)
			res = v, d = dist[v][to];
	return res;
}

signed main() {
	fast_io;

	cin >> n;
	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v, t[u].pb(v), t[v].pb(u);

	for (int i = 1; i <= n; ++i)
		dfs(i, i, i, 0);

	vector<point> paths;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			paths.pb({i, j});

	sort(all(paths), [&](point a, point b){
		return dist[a.X][a.Y] < dist[b.X][b.Y];
	});

	int ans = 0;

	for (point it : paths) {
		int u = it.X, v = it.Y;
		int cu = closest(u, v), cv = closest(v, u);

		dp[u][v] = dp[v][u] = max(dp[cu][v], dp[u][cv]) + sub[cu][u] * sub[cv][v];
		ans = max(ans, dp[u][v]);
	}

	cout << ans;
}