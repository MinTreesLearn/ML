#include <bits/stdc++.h>

using namespace std;

#define int long long

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define db(x) cout << "[" << #x << "]: " << x << '\n';

const int INF = 2e18;

struct SegmentTree {
  int merge(const int& left_child, const int& right_child) {
    int parent;
    parent = max(left_child, right_child);
    return parent;
  }
  
  int n;
  vector<int> tree;
  vector<int> a;
  
  void initialize(const vector<int>& x) {
    n = sz(x);
    tree.resize(4 * n + 1);
    a.resize(n + 1);
    for (int i = 0; i < n; ++i) {
      a[i] = x[i];
    }
  }

  void build(int id, int id_left, int id_right) {
    if (id_left == id_right) {
      tree[id] = a[id_left];
      return;
    }
    int id_middle = (id_left + id_right) / 2;
    build(2 * id, id_left, id_middle);
    build(2 * id + 1, id_middle + 1, id_right);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
  }

  void element_update(int id, int id_left, int id_right, int idx, int value) {
    if (idx < id_left || idx > id_right) {
      return;
    }
    if (id_left == id_right) {
      tree[id] = value;
      return;
    }
    int id_middle = (id_left + id_right) / 2;
    element_update(2 * id, id_left, id_middle, idx, value);
    element_update(2 * id + 1, id_middle + 1, id_right, idx, value);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
  }
  
  int query(int id, int id_left, int id_right, int query_left, int query_right) {
    if (id_right < query_left || id_left > query_right) {
      return -INF;
    }
    if (query_left <= id_left && id_right <= query_right) {
      return tree[id];
    }
    int id_middle = (id_left + id_right) / 2;
    return merge(query(2 * id, id_left, id_middle, query_left, query_right), query(2 * id + 1, id_middle + 1, id_right, query_left, query_right));
  }
  
  void build() {
    build(1, 0, n - 1);
  }
  
  void element_update(int idx, int value) {
    element_update(1, 0, n - 1, idx, value);
  }
  
  int query(int query_left, int query_right) {
    return query(1, 0, n - 1, query_left, query_right);
  }
};

const int N = 2e5 + 2;

int a[N], x[N], pfx[N], mx[N];
vector<int> nw;
SegmentTree st;
int t, n, m, h;

void solve() {
  cin >> h >> n;
  nw.resize(2 * n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = -a[i];
    pfx[i] = (i == 0 ? a[i] : a[i] + pfx[i - 1]);
    nw[i] = pfx[i];
    mx[i] = (i == 0 ? pfx[i] : max(mx[i - 1], pfx[i]));
    sum += a[i];
  }
  for (int i = n; i < 2 * n; ++i) {
    nw[i] = nw[i - 1] + a[i % n];
  }
  st.initialize(nw);
  st.build();
  int cur = pfx[0], pos = 0;
  for (int i = 1; i < n; ++i) {
    if (pfx[i] > cur) {
      cur = pfx[i];
      pos = i;
    }
  }
  if (h <= mx[n - 1]) {
    int l = 0, r = n - 1;
    while (l < r) {
      int md = (l + r) / 2;
      if (mx[md] >= h) {
        r = md;
      } else {
        l = md + 1;
      }
    }
    cout << l + 1;
    exit(0);
  }
  int ans = pos, val = cur, diff = h - cur;
  if (val < h && sum <= 0) {
    cout << -1;
    exit(0);
  }
  ans += (diff / sum * n);
  val += ((diff / sum) * sum);
  diff %= sum;
  if (diff == 0) {
    cout << ans + 1;
    exit(0);
  }
  int left = pos + 1, right = pos + n;
  int offset = nw[pos];
  while (left < right) {
    int middle = (left + right) / 2;
    if (st.query(left, middle) - offset >= diff) {
      right = middle;
    } else {
      left = middle + 1;
    }
  }
  cout << ans + (left - pos) + 1;
  cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}