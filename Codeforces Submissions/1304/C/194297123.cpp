/***********

  MK-1311

***********/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define nl '\n'

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif


/*


*/

#define int long long


void solve() {
  int n, it;
  cin >> n >> it;
  vector<tuple<int, int, int>> a(n);
  for(int i = 0; i < n; i++) {
    auto &[t, l, h] = a[i];
    cin >> t >> l >> h;
  }
  vector<vector<int>> b(n, vector<int>(2, false));
  b[0][0] = max(it, get<1>(a[0])) - get<0>(a[0]);
  b[0][1] = min(it, get<2>(a[0])) + get<0>(a[0]);
  for(int i = 1; i < n; i++) {
    auto [t1, l1, h1] = a[i - 1];
    auto [t2, l2, h2] = a[i];
    int timeBetween = t2 - t1;  
    b[i][0] = max(b[i - 1][0], l1) - timeBetween;
    b[i][1] = min(b[i - 1][1], h1) + timeBetween;
  }
  bool ok = true;
  for(int i = 0; i < n; i++) {
    debug(b[i]);
    auto [t, l, h] = a[i];
    if(l > b[i][1] || h < b[i][0]) {
      ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}












int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tt = 1; 
  cin >> tt;
  for(int i = 0; i < tt; i++) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}