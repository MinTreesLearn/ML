#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << '\n';
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), G(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    G[v].push_back(u);
  }
  
  int k;
  cin >> k;
  vector<int> p(k);
  for (int &x : p) {
    cin >> x;
    --x;
  }

  auto bfs = [&] (int s, const vector<vector<int>> &g) {
    vector<int> dis(n, -1);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (dis[v] != -1) continue;
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
    return dis;
  };

  int s = p.front();
  int t = p.back();
  auto disFrom = bfs(s, g);
  auto disTo = bfs(t, G);

  int mn = 0, mx = 0;
  for (int i = 0; i + 1 < k; ++i) {
    int cnt = 0;
    int u = p[i];
    map<int, int> f;
    int mnn = 1e9;
    for (int v : g[u]) {
      if (disTo[v] == -1) continue;
      ++f[disTo[v]];
      mnn = min(mnn, disTo[v]);
    }
    int ok = (f[mnn] > 1);
    int v = p[i + 1];
    if (disTo[v] > disTo[u] - 1) {
      ++mn;
      ok = 1;
    }
    mx += (ok);
  }

  cout << mn << ' ' << mx << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
}