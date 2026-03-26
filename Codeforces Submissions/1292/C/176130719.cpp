#include <bits/stdc++.h>
#ifdef __LOCAL__
  #include <debug_local.h>
#endif
using namespace std;
const int mxN = 3005;
vector<int> ad[mxN];
int par[mxN][mxN], dist[mxN][mxN], sz[mxN][mxN];
long long dp[mxN][mxN];
void  dfs(int r, int u, int p) {
  par[r][u] = p;
  sz[r][u] = 1;
  for (int v : ad[u]) {
    if (v == p) continue;
    dist[r][v] = dist[r][u] + 1;
    dfs(r, v, u);
    sz[r][u] += sz[r][v];
  }
}
long long solve(int u, int v) {
  if (u == v) return 0LL;
  if (dp[u][v] != -1) return dp[u][v];
  long long &r = dp[u][v];
  int cur = dist[u][v];
  r = max(r, solve(u, par[u][v]) + 1LL * sz[u][v] * sz[v][u]);
  r = max(r, solve(par[v][u], v) + 1LL * sz[u][v] * sz[v][u]);
  return r;
}
void testCase() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, i, i);
  }
  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = max(ans, solve(i, j));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  testCase();
}