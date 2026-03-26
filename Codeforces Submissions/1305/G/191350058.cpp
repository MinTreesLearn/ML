#include <bits/stdc++.h>
#define sz(v) (int) (v).size()
#define all(v) begin(v), end(v)
#define view(v, l, r) begin(v) + l, begin(v) + r + 1
#define dbg(fmt...) fprintf(stderr, fmt)
#define fi first
#define se second
using namespace std;
using i64 = long long;
using i128 = __int128_t;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = __uint128_t;
using f64 = double;
using f128 = long double;
template<typename T> bool chmin(T &a, const T &b) { return (b < a) ? a = b, 1 : 0; }
template<typename T> bool chmax(T &a, const T &b) { return (b > a) ? a = b, 1 : 0; }
constexpr int M = 18;
int buc[1 << M], par[1 << M];
int get(int x) {
  return par[x] == x ? x : par[x] = get(par[x]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = __lg(*max_element(all(a)) - 1) + 1;
  iota(par, par + (1 << m), 0);
  int full = (1 << m) - 1;
  i64 ans = 0;
  for (auto &x : a) {
    ++buc[x];
    ans -= x;
  }
  ++buc[0];
  for (int s = full; s; --s) {
    for (int u = s; ; u = (u - 1) & s) {
      int v = s ^ u;
      if (buc[u] && buc[v] && get(u) != get(v)) {
        ans += (buc[u] + buc[v] - 1ll) * s;
        buc[u] = buc[v] = 1;
        par[get(v)] = get(u);
      }
      if (!u) {
        break;
      }
    }
  }
  cout << ans;
}