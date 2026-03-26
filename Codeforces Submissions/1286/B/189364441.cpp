#include "bits/stdc++.h"

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;

  vector<vector<int>> g(n);
  vector<int> C(n);
  vector<vector<int>> ans(n);

  int rt = -1;
  for (int i = 0; i < n; i++) {

    int p; cin >> p >> C[i];

    if (p == 0) rt = i;
    else g[p - 1].push_back(i);

  }

  function<void(int)> dfs = [&](int c) {

    for (int i : g[c]) {
      dfs(i);
      for (int x : ans[i]) {
        ans[c].push_back(x);
      }
    }

    if (C[c] > ans[c].size()) {
      cout << "NO\n";
      exit(0);
    }

    ans[c].insert(ans[c].begin() + C[c], c);

  };

  dfs(rt);

  vector<int> res(n);
  assert(ans[rt].size() == n);

  for (int i = 0; i < n; i++) {
    res[ans[rt][i]] = i + 1;
  }
  
  cout << "YES\n";
  for (int i : res)
    cout << i << " ";
  cout << "\n";

}

// ~ BucketPotato