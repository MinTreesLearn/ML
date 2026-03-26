#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
vector<int> G[N];
long long dp[N][N];
int par[N][N], sz[N][N], fpar[N][N];

void dfs(int rt, int v, int p) {
  par[rt][v] = p;
  fpar[rt][v] = (p == rt ? v : fpar[rt][p]);
  sz[rt][v] = 1;
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(rt, u, v);
    sz[rt][v] += sz[rt][u];
  }
}

long long calc(int u, int v) {
  long long &x = dp[u][v];
  if (x != -1) return x;
  if (u == v) return x = 0;
  bool flag = (u == 4 && v == 5);
  x = calc(u, par[u][v]);
  if (fpar[u][v] != v) x = max(x, calc(v, fpar[u][v]));
  x += sz[u][v]*(sz[u][u]-sz[u][fpar[u][v]]);
  dp[v][u] = x;
  return x;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int v = 1; v <= n; v++) {
    dfs(v, v, v);
  }
  long long ans = 0;
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      ans = max(ans, calc(u, v));
    }
  }
  cout << ans << '\n';
}
