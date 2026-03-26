#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) 0
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<set<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].insert(v);
    g[v].insert(u);
  }
  set<int> leafs;
  for (int i = 0; i < n; i++) {
    if (g[i].size() == 1) {
      leafs.insert(i);
    }
  }
  auto ask = [](int u, int v) {
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int x;
    cin >> x;
    --x;
    return x;
  };
  function<void(int, int, int)> dfsdelete = [&](int u, int p, int x) {
    if (leafs.find(u) != leafs.end()) {
      leafs.erase(u);
    }
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      if (v == x) {
        g[x].erase(u);
      } else {
        dfsdelete(v, u, x);
      }
    }
  };
  int r = -1;
  while (leafs.size() > 1) {
    dout(vector<int>(leafs.begin(), leafs.end()));
    auto it = leafs.begin();
    int u = *it;
    leafs.erase(it);
    it = leafs.begin();
    int v = *it;
    leafs.erase(it);
    int x = ask(u, v);
    if (x == u || x == v) {
      r = x;
      break;
    }
    dfsdelete(u, -1, x);
    dfsdelete(v, -1, x);
    if (g[x].size() <= 1) {
      leafs.insert(x);
    }
  }
  if (r == -1) {
    r = *leafs.begin();
  }
  cout << "! " << r + 1 << endl;
  return 0;
}
