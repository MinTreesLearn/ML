#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;
const ll inf = 1LL<<60;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n), revG(n);
  for (int i=0; i<m; i++) {
    int a, b; cin >> a >> b; a--; b--;
    G[a].emplace_back(b);
    revG[b].emplace_back(a);
  }
  int k; cin >> k;
  vector<int> p(k);
  for (int i=0; i<k; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector<int> d(n, -1);
  d[p.back()] = 0;
  queue<int> q;
  q.push(p.back());
  while (q.size()) {
    auto now = q.front(); q.pop();
    for (auto e : revG[now]) if (d[e] == -1) {
      d[e] = d[now] + 1;
      q.push(e);
    }
  }
  int mi = 0, ma = 0;
  for (int i=k-2; i>=0; i--) {
    if (d[p[i]] != d[p[i+1]] + 1) {
      mi++;
      ma++;
    } else {
      int cnt = 0;
      for (auto e : G[p[i]]) if (d[e] == d[p[i+1]]) cnt++;
      ma += (cnt > 1);
    }
  }
  cout << mi << " " << ma << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // int t; cin >> t;
  /*while (t--)*/ solve();
}
