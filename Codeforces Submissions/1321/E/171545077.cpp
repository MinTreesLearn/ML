#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << '\n';
}

struct SegmentTree {
  int n;
  ll out;
  vector<ll> data;
  vector<ll> seg, lazy;

  SegmentTree(vector<ll> &data, ll out) : n(data.size()), out(out), data(data), seg(n * 4), lazy(n * 4) {
    build(1, 0, n - 1);
  }
  
  void pull(int p) {
    seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
  }

  void build(int p, int s, int e) {
    if (s == e) {
      seg[p] = data[s];
      return;
    }
    int mid = (s + e) / 2;
    build(p * 2, s, mid);
    build(p * 2 + 1, mid + 1, e);
    pull(p);
  }

  ll query(int p, int s, int e, int l, int r) {
    if (l > e || s > r) return out;

    if (l <= s && e <= r) {
      return seg[p];
    }
    int mid = (s + e) / 2;
    return max(query(p * 2, s, mid, l, r), query(p * 2 + 1, mid + 1, e, l, r));
  }

  void push(int p, int s, int e) {
    if (lazy[p] == 0) return;
    if (s != e) {
      lazy[p * 2] += lazy[p];
      lazy[p * 2 + 1] += lazy[p];
    } 
    seg[p] += lazy[p];
    lazy[p] = 0;
  }

  void update(int p, int s, int e, int l, int r, ll val) {
    push(p, s, e);
  
    if (l > e || s > r) return;
  
    if (l <= s && e <= r) {
      lazy[p] += val;
      push(p, s, e);
      return;
    }

    int mid = (s + e) / 2;
    update(p * 2, s, mid, l, r, val);
    update(p * 2 + 1, mid + 1, e, l, r, val);
    pull(p);
  }

  ll get(int l, int r) {
    assert(l <= r);
    return query(1, 0, n - 1, l, r);
  }

  void upd(int l, int r, ll val) {
    update(1, 0, n - 1, l, r, val);
  }
};

const int N = 1e6 + 1;
const ll inf = 1e18;

void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<ll> bestw(N + 1, -inf), bestr(N + 1, -inf);
  
  for (int i = 0; i < n; ++i) {
    int x, w;
    cin >> x >> w;
    bestw[x] = max(bestw[x], -w * 1ll);
  }

  for (int i = 0; i < m; ++i) {
    int x, w;
    cin >> x >> w;
    bestr[x] = max(bestr[x], -w * 1ll);
  }

  vector<vector<pair<int, int>>> add(N + 1);
  for (int i = 0; i < p; ++i) {
    int w, r, z;
    cin >> w >> r >> z;
    add[w + 1].emplace_back(r, z);
  }

  SegmentTree seg(bestr, -inf);
  ll ans = -inf;
  for (int i = 1; i <= N; ++i) {
    for (auto [r, z] : add[i]) {
      seg.upd(r + 1, N, z);
    }

    ans = max(ans, seg.get(1, N) + bestw[i]);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
}