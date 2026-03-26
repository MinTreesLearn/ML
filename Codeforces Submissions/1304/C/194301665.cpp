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
  vector<int> t(n + 1, 0), l(n + 1, 0), h(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    cin >> t[i] >> l[i] >> h[i];
  }
  int x = it, y = it;
  l[0] = it, h[0] = it;
  for(int i = 1; i <= n; i++) {
    int time = t[i] - t[i - 1];
    x = max(l[i - 1], x) - time;
    y = min(h[i - 1], y) + time;
    debug(x, y);
    if(l[i] > y || h[i] < x) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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