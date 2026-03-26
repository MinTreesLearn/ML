#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1<<30;
const ll inf = 1LL<<60;

void solve() {
  int n; cin >> n;
  vector<vector<int>> G(n);
  for (int i=0; i<n-1; i++) {
    int u, v; cin >> u >> v;
     u--; v--;
     G[u].emplace_back(v);
     G[v].emplace_back(u);
  }
  vector<vector<int>> par(n, vector<int>(n, -1));
  auto sub = par;
  int root = -1;
  auto dfs = [&](auto&& dfs, int v, int p) -> void {
    sub[root][v] = 1;
    for (auto e : G[v]) if (e != p) {
      par[root][e] = v;
      dfs(dfs, e, v);
      sub[root][v] += sub[root][e];
    }
  };
  for (int i=0; i<n; i++) {
    root = i;
    dfs(dfs, i, -1);
  }
  vector<vector<ll>> dp(n, vector<ll>(n, -1LL));
  ll ans = 0;
  auto calc = [&](auto&& calc, int u, int v) -> ll {
    if (u == v) return 0;
    if (dp[u][v] != -1) return dp[u][v];
    dp[u][v] = sub[u][v]*sub[v][u] + max(calc(calc, par[v][u], v), calc(calc, u, par[u][v]));
    return dp[u][v];
  };
  for (int u=0; u<n; u++) for (int v=0; v<n; v++) ans = max(ans, calc(calc, u, v));
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // int t; cin >> t;
  /*while (t--)*/ solve();
}
