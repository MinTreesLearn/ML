#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector par(n, vector<int>(n, -1)), sz(n, vector<int>(n, 1));
  for (int i = 0; i < n; i++) {
    auto DFS = [&](int u, auto&& DFS) -> void {
      for (int v : g[u])
        if (v != par[i][u]) {
          par[i][v] = u;
          DFS(v, DFS);
          sz[i][u] += sz[i][v];
        }
    };
    DFS(i, DFS);
  }

  vector dp(n, vector<long long>(n, -1));
  auto Calc = [&](int u, int v, auto&& Calc) -> long long {
    if (u == v)
      return 0;
    else if (dp[u][v] != -1)
      return dp[u][v];
    else
      return dp[u][v] = 1ll * sz[u][v] * sz[v][u] + max(Calc(u, par[u][v], Calc), Calc(v, par[v][u], Calc));
  };

  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans = max(ans, Calc(i, j, Calc));
  
  cout << ans << "\n";
}