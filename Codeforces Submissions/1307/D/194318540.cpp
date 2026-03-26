#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int dis1[N], disn[N];
bitset<N> special;
vector<int> g[N];


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    special[x] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<int> q;
  memset(dis1, -1, sizeof dis1);
  q.push(1);
  dis1[1] = 0;
  vector<int> sorted;
  while (!q.empty()) {
    int src = q.front();
    if (special[src]) {
      sorted.push_back(src);
    }
    q.pop();
    for (int u : g[src]) {
      if (dis1[u] == -1) {
        dis1[u] = dis1[src] + 1;
        q.push(u);
      }
    }
  }
  memset(disn, -1, sizeof disn);
  disn[n] = 0;
  q.push(n);
  while (!q.empty()) {
    int src = q.front();
    q.pop();
    for (int u : g[src]) {
      if (disn[u] == -1) {
        disn[u] = disn[src] + 1;
        q.push(u);
      }
    }
  }
  int ans = 0;
  int mx = disn[sorted.back()];
  // for (int i : sorted) { 
  //   cout << i << ' ';
  // }
  // cout << '\n';
  // for (int i : sorted) {
  //   cout << disn[i] << ' ';
  // }
  // cout << '\n';
  for (int i = k - 2; i >= 0; --i) {
    ans = max(ans, dis1[sorted[i]] + mx);
    // cout << sorted[i] << ' ' << mx << ' ' << ans << '\n';
    mx = max(mx, disn[sorted[i]]);
  }
  cout << min(disn[1], ans + 1) << '\n';
  return 0;
}