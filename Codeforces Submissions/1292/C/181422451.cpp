//0 1 1 0 1
//0 1 0 0 1
//1 0 0 1 1
//0 1 1 0 1
//uoy kcuf;
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define F 			first
#define S 			second
#define pb 			push_back
#define sze			size()
#define	all(x)		x.begin() , x.end()
#define wall__		cout << "--------------------------------------\n";
#define node		int mid = (tl + tr) >> 1, cl = v << 1, cr = v << 1 | 1
#define file_io		freopen("input.cpp", "r", stdin) ; freopen("output.cpp", "w", stdout);

typedef long long ll;
typedef long double dl;
typedef pair < int , int > pii;
typedef pair < int , ll > pil;
typedef pair < ll , int > pli;
typedef pair < ll , ll > pll;
typedef pair < int , pii > piii;
typedef pair < ll, pll > plll;


const ll N = 3e3 + 10;
const ll mod = 1e9 + 7;
const ll inf = 2e16;
const ll rinf = -2e16;
const ll INF = 1e9 + 10;
const ll rINF = -1e9 - 10;
const ll lg = 12;

ll n, subtree[N], val[N][N], dp[N][N], st[N], en[N], timer, parent[N], par[lg][N], lca[N][N], dis[N][N], h[N], ppp[N][N];
vector < int > g[N];
vector < pii > len[N];

void dfs (int v, int p) {

	st[v] = ++timer;
	parent[v] = p;
	par[0][v] = p;
	h[v] = h[p] + 1;
	for (int i = 1; i < lg; i++) par[i][v] = par[i - 1][par[i - 1][v]];
	subtree[v] = 1;
	for (auto u : g[v]) {

		if (p == u) continue;
		dfs (u, v);
		subtree[v] += subtree[u];

	}
	en[v] = ++timer;

}

bool be_anc (int v, int u) {

	if (st[v] <= st[u] && en[u] <= en[v]) return 1;
	return 0;

}

int get_par (int v, int u) {

	if (be_anc(u, v)) swap(v, u);
	for (int i = lg - 1; i >= 0; --i) {

		if (!be_anc(par[i][u], v)) u = par[i][u];

	}
	return u;

}

void solve() {

	cin >> n;
	for (int i = 1; i < n; i++) {

		int v, u; cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);

	}
	st[0] = -1;
	en[0] = INF;
	dfs (1, 0);
	for (int i = 1; i <= n; i++) {

		val[i][i] = subtree[i] * (n - subtree[i] + 1);
		lca[i][i] = i;
		for (int j = i + 1; j <= n; j++) {

			int pp = get_par(i, j);
			ppp[i][j] = ppp[j][i] = pp;
			int lc = par[0][pp];
			if (i == lc) val[i][j] = subtree[j] * (n - subtree[pp]);
			else if (j == lc) val[i][j] = subtree[i] * (n - subtree[pp]);
			else {

				val[i][j] = subtree[i] * subtree[j];

			}
			lca[i][j] = lca[j][i] = lc;
			dis[i][j] = h[i] + h[j] - (2 * h[lc]);
			len[dis[i][j]].pb({i, j});
			val[j][i] = val[i][j];

		}
		dp[i][i] = 0;

	}
	// cout << "lca = \n";
	// for (int i = 1; i <= n; i++) {

	// 	cout << i << " : ";
	// 	for (int j = 1; j <= n; j++) cout << j << " = " << lca[i][j] << " , " << val[i][j] << " | ";
	// 	cout << '\n';

	// }
	// wall__
	// cout << "subtree = ";for (int i = 1; i <= n; i++) cout << i << " , " << subtree[i] << " | "; cout << '\n';
	// wall__

	ll ans = 0;
	for (int i = 1; i <= n; i++) {

		if (len[i].sze == 0) continue;
		for (auto e : len[i]) {

			int v = e.F;
			int u = e.S;
			if (lca[v][u] == v) 
				dp[v][u] = max(dp[v][parent[u]] + val[v][u], dp[ppp[v][u]][u] + val[v][u]);
			else if (lca[v][u] == u)
				dp[v][u] = max(dp[parent[v]][u] + val[v][u], dp[v][ppp[u][v]] + val[v][u]);
			else 
				dp[v][u] = max(dp[parent[v]][u] + val[v][u], dp[v][parent[u]] + val[v][u]);
			dp[u][v] = dp[v][u];
			ans = max(ans, dp[v][u]);

		}

	}
	cout << ans;

}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1; 
	// cin >> t;
	while (t--) {solve();}

    return 0;
}
/*
*/