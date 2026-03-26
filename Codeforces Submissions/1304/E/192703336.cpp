#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define debug(x) cout << #x << ": " << x << "\n";
const int mxN = 1e5 + 5, lg = 20;
int lift[lg][mxN], tin[mxN], tout[mxN], dep[mxN], timer = 0;
vector<int> adj[mxN];
void dfs(int u, int p) {
    lift[0][u] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i < lg; i++) lift[i][u] = lift[i - 1][lift[i - 1][u]];
    tin[u] = ++timer;
    for (auto i : adj[u]) {
        if (i != p) dfs(i, u);
    }
    tout[u] = timer;
}
int lca(int u, int v) {
    if (tin[u] <= tin[v] && tout[u] >= tout[v]) return u;
    if (tin[v] <= tin[u] && tout[v] >= tout[u]) return v;
    for (int i = lg - 1; i >= 0; i--) {
        if (tin[lift[i][u]] > tin[v] || tout[lift[i][u]] < tout[v]) u = lift[i][u];
    }
    return lift[0][u];
}
int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tin[0] = timer;
    dfs(1, 0);
    tout[0] = timer;
    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int wow = dist(a, b), bruh = min(dist(a, x) + dist(b, y), dist(a, y) + dist(b, x)) + 1;
        if ((wow <= k && wow % 2 == k % 2) || (bruh <= k && bruh % 2 == k % 2)) cout << "YES\n";
        else cout << "NO\n";
    }
}
int32_t main() {
    clock_t t1 = clock();
	#ifndef ONLINE_JUDGE
       freopen("wake.in", "r", stdin);
       freopen("sleep.out", "w", stdout);
    #endif
	int t = 1;
    // cin >> t;
    while (t--) solve();
    // cout << "Time used: " << clock() - t1 << " ms\n";
	return 0;
}
