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
  vector<ll> c(n);
  for (int i=0; i<n; i++) cin >> c[i];
  vector<set<int>> G(n);
  for (int i=0; i<m; i++) {
    int u, v; cin >> u >> v; u--; v--;
    G[v].insert(u);
  }
  map<set<int>, ll> ma;
  for (int i=0; i<n; i++) ma[G[i]] += c[i];
  ll res = 0;
  auto gcd = [](auto&& gcd, ll x, ll y) -> ll {
    if (x == 0 || y == 0) return x+y;
    if (x%y) return gcd(gcd, y, x%y);
    return y;
  };
  for (auto p : ma) {
    if (p.first.size() == 0) continue;
    res = gcd(gcd, res, p.second);
  }
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}
