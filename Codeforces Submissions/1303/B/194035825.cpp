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
  int n, g, b;
  cin >> n >> g >> b;
  int need = ceil(n / 2.0);
  int c = (need / g) * (g + b);
  debug(c);
  int left = need % g;
  if(left == 0) {
    c = max(c - b, n);
  } else {
    c = max(c + left, n);
  }
  cout << c << endl;
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


 	 		    		  	 	 			     					