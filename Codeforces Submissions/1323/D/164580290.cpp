#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;
const ll inf = 1LL<<60;

void solve() {
  ll n; cin >> n;
  vector<ll> a(n);
  for (int i=0; i<n; i++) cin >> a[i];
  ll ans = 0;
  for (int k=0; k<26; k++) {
    int t = 1<<(k+1), s = 1<<k;
    ll res = 0;
    vector<int> mod(n);
    for (int i=0; i<n; i++) {
      int p = a[i]%t;
      mod[i] = p;
    }
    sort(mod.begin(), mod.end());
    for (int i=0; i<n; i++) {
      int p = a[i]%t;
      if (p <= s) {
        res += lower_bound(mod.begin(), mod.end(), t-p) - lower_bound(mod.begin(), mod.end(), s-p);
      } else {
        res += lower_bound(mod.begin(), mod.end(), t-p) - mod.begin();
        res += lower_bound(mod.begin(), mod.end(), t) - lower_bound(mod.begin(), mod.end(), s + t - p);
      }
      // cout << res << endl;
      if (s <= (p+p)%t && (p+p)%t < t) res--;
    }
    res /= 2;
    if (res & 1) ans += s;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // int t; cin >> t;
  /*while (t--)*/ solve();
}
