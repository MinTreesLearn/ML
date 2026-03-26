#include "bits/stdc++.h"

using namespace std;

#define ll long long
const int MAXN = 100100;
const int LOG = 20;

int n;
vector<int> g[MAXN];
int dep[MAXN];
int jp[LOG][MAXN];

void dfs(int c, int l, int d) {
  dep[c] = d;
  jp[0][c] = l;
  for (int i : g[c]) {
    if (i == l) continue;
    dfs(i, c, d + 1);
  }
}

int lca(int x, int y) {

  if (dep[x] < dep[y]) swap(x, y);
  int k = dep[x] - dep[y];
  for (int i = 0; i < LOG; i++) {
    if (k & (1 << i)) {
      x = jp[i][x];
    }
  }

  if (x == y) return x;

  for (int i = LOG - 1; i >= 0; i--) {
    if (jp[i][x] == jp[i][y]) continue;
    x = jp[i][x];
    y = jp[i][y];
  }

  return jp[0][x];

}

int dist(int x, int y) {
  int L = lca(x, y);
  return (dep[x] - dep[L]) + (dep[y] - dep[L]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1, 1, 0);

  for (int i = 1; i < LOG; i++) {
    for (int j = 1; j <= n; j++) {
      jp[i][j] = jp[i - 1][jp[i - 1][j]];
    }
  }

  auto check = [](int x, int y) {
    return ((x & 1) == (y & 1)) && x <= y;
  };

  int q; cin >> q;
  while (q--) {

    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;

    int ans = check(dist(a, b), k) ||
              check(dist(a, x) + 1 + dist(y, b), k) ||
              check(dist(a, y) + 1 + dist(x, b), k);

    cout << (ans ? "YES\n" : "NO\n");

  }
  
}