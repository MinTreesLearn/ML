#include <bits/stdc++.h>

using namespace std;
using llong = int64_t;

#define len(c) int((c).size())
#define file_name "test"

#ifdef DAT
#include "debug.hpp"
#else
#define debug(x...) 12
#endif

namespace Task {

const int MAX_N = 150001;
const int MAX_LOG = 18;
const llong INF = 1e18;
vector<vector<int>> adj;

typedef class CentroidTree {
public:
  int size_tree;
  int root;
  vector<vector<int>> tree;
  vector<vector<int>> lev;
  vector<vector<int>> child;
  vector<bool> removed;
  vector<int> cnt_child;

  CentroidTree(){};
  CentroidTree(int init_size_tree) : size_tree(init_size_tree) {
    tree.resize(size_tree + 1, vector<int>());
    child.resize(size_tree + 1, vector<int>());
    lev.resize(MAX_LOG + 1, vector<int>());
    removed.resize(size_tree + 1, false);
    cnt_child.resize(size_tree + 1, 0);
  }

  void compute_size(int u, int par) {
    cnt_child[u] = 1;
    for (int v : adj[u]) {
      if (v != par and !removed[v]) {
        compute_size(v, u);
        cnt_child[u] += cnt_child[v];
      }
    }
  }

  int find_centroid(int u, int par, int cur_size) {
    while (true) {
      pair<int, int> best(-1, -1);
      for (int v : adj[u]) {
        if (v != par and !removed[v]) {
          if (cnt_child[v] > best.first) {
            best = {cnt_child[v], v};
          }
        }
      }
      if ((best.first << 1) <= cur_size) {
        return u;
      }
      par = u;
      u = best.second;
    }
  }

  void decompose(int u, int par, int cur_lev) {
    compute_size(u, -1);
    int cen_ver = find_centroid(u, -1, cnt_child[u]);
    removed[cen_ver] = true;
    if (par == -1) {
      root = cen_ver;
    }
    lev[cur_lev].emplace_back(cen_ver);
    child[cen_ver].emplace_back(cen_ver);
    if (par != -1) {
      tree[par].emplace_back(cen_ver);
    }
    for (int v : adj[cen_ver]) {
      if (!removed[v]) {
        decompose(v, cen_ver, cur_lev + 1);
      }
    }
    if (par != -1) {
      for (const int &v : child[cen_ver]) {
        child[par].emplace_back(v);
      }
    }
  }

  void decompose() { decompose(1, -1, 0); }
} td_centroid_tree;

typedef class Tree {
public:
  int size_tree;
  vector<vector<int>> jump;
  vector<int> euler_tour;
  vector<int> st;
  vector<llong> sum[2];
  vector<llong> sum_mult;
  vector<int> dep;
  vector<int> values;
  vector<int> dad;
  function<int(int, int)> comp = [&](const int &u, const int &v) {
    return (dep[u] <= dep[v] ? u : v);
  };

  Tree(){};
  Tree(int init_size_tree) : size_tree(init_size_tree) {
    jump.resize(MAX_LOG + 1, vector<int>(2 * size_tree + 1, 0));
    sum[0].resize(size_tree + 1, 0);
    sum[1].resize(size_tree + 1, 0);
    sum_mult.resize(size_tree + 1, 0);
    st.resize(size_tree + 1, 0);
    dep.resize(size_tree + 1, 1);
    dad.resize(size_tree + 1, 0);
    dep[0] = 0;
  }

  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  void dfs(int u, int par) {
    dad[u] = par;
    sum[0][u] = sum[0][par] + llong(values[u]);
    sum[1][u] = sum[1][par] + sum[0][u];
    sum_mult[u] = sum_mult[par] + llong(dep[u]) * llong(values[u]);
    st[u] = len(euler_tour);
    euler_tour.emplace_back(u);
    for (int v : adj[u]) {
      if (v != par) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
        euler_tour.emplace_back(u);
      }
    }
  }

  void build_lca() {
    for (int u = 0; u < len(euler_tour); ++u) {
      jump[0][u] = euler_tour[u];
    }
    for (int j = 1; j <= MAX_LOG; ++j) {
      for (int u = 0; u + (1 << j) - 1 < len(euler_tour); ++u) {
        jump[j][u] = comp(jump[j - 1][u], jump[j - 1][u + (1 << (j - 1))]);
      }
    }
  }

  int get_lca(int u, int v) const {
    int l, r;
    tie(l, r) = pair<int, int>{st[u], st[v]};
    if (l > r) {
      swap(l, r);
    }
    int x = int(log2(r - l + 1));
    return comp(jump[x][l], jump[x][r - (1 << x) + 1]);
  }

  int get_dist(int u, int v) const {
    return dep[u] + dep[v] - 2 * dep[get_lca(u, v)] + 1;
  }

  llong get_sum(int u, int v) const {
    int R = get_lca(u, v);
    return sum[0][u] + sum[0][v] - 2 * sum[0][R] + llong(values[R]);
  }

  llong sum_to_root(int u, int R) const {
    int p = (R == 1 ? 0 : dad[R]);
    return sum_mult[u] - sum_mult[p] - llong(dep[p]) * (sum[0][u] - sum[0][p]);
  }

  llong sum_from_root(int u, int R) const {
    int p = (R == 1 ? 0 : dad[R]);
    return sum[1][u] - sum[1][p] - llong(dep[u] - dep[p]) * sum[0][p];
  }

  llong prefix_sums(int u, int v) const {
    int R = get_lca(u, v);
    int p = (R == 1 ? 0 : dad[R]);
    if (u == R) {
      return sum_from_root(v, R);
    } else if (v == R) {
      return sum_to_root(u, R);
    } else {
      llong lhs = sum_to_root(u, R) +
                  llong(dep[v] - dep[p] - 1) * (sum[0][u] - sum[0][p]);
      llong rhs =
          sum_from_root(v, R) - llong(dep[v] - dep[p]) * llong(values[R]);
      return lhs + rhs;
    }
  }
} td_tree;

class Line {
public:
  llong m, b;
  Line() : m(0), b(-INF){};
  Line(llong init_m, llong init_b) : m(init_m), b(init_b){};
  llong operator()(const int &x) { return m * llong(x) + b; }
};

vector<Line> lichao_tree;
vector<bool> clean;

void insert_line(Line upd_line, int l, int r, int node = 1) {
  if (l == r) {
    clean[node] = false;
    if (lichao_tree[node](l) < upd_line(l)) {
      lichao_tree[node] = upd_line;
    }
    return;
  }
  int mid = (l + r) >> 1;
  if (lichao_tree[node].m > upd_line.m) {
    swap(lichao_tree[node], upd_line);
  }
  if (lichao_tree[node](mid) > upd_line(mid)) {
    insert_line(upd_line, mid + 1, r, node << 1 | 1);
  } else {
    swap(lichao_tree[node], upd_line);
    insert_line(upd_line, l, mid, node << 1);
  }
  clean[node] = clean[node << 1] & clean[node << 1 | 1];
}

llong get_max(int pos, int l, int r, int node = 1) {
  if (l > r or r < pos or l > pos) {
    return -INF;
  }
  if (l == r) {
    return lichao_tree[node](l);
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    return max(lichao_tree[node](pos), get_max(pos, l, mid, node << 1));
  } else {
    return max(lichao_tree[node](pos), get_max(pos, mid + 1, r, node << 1 | 1));
  }
}

void delete_lichao_tree(int l, int r, int node = 1) {
  if (l > r or clean[node]) {
    return;
  }
  clean[node] = true;
  lichao_tree[node] = Line();
  if (l < r) {
    int mid = (l + r) >> 1;
    delete_lichao_tree(l, mid, node << 1);
    delete_lichao_tree(mid + 1, r, node << 1 | 1);
  }
}

void solve() {
  int n;
  cin >> n;

  adj.resize(n + 1, vector<int>());

  lichao_tree.resize((MAX_N << 2) + 10, Line());
  clean.resize((MAX_N << 2) + 10, true);

  td_tree tree_gr(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    tree_gr.add_edge(u, v);
  }

  {
    vector<int> values(n + 1);
    for (int u = 1; u <= n; ++u) {
      cin >> values[u];
    }
    tree_gr.values = values;
  }

  tree_gr.dfs(1, 1);
  tree_gr.build_lca();

  td_centroid_tree cen_tree(n);
  cen_tree.decompose();

  llong ans = -INF;

  function<void(int, int)> dfs = [&](int u, int cen_root) -> void {
    vector<Line> lines;
    for (const int &v : cen_tree.child[u]) {
      int x = tree_gr.get_dist(v, cen_root);
      ans = max({ans,
                 get_max(x - 1, 0, MAX_N) + tree_gr.prefix_sums(cen_root, v) -
                     llong(x) * tree_gr.values[cen_root],
                 tree_gr.prefix_sums(cen_root, v),
                 tree_gr.prefix_sums(v, cen_root)});
      llong m = tree_gr.get_sum(v, cen_root);
      llong b = tree_gr.prefix_sums(v, cen_root);
      lines.emplace_back(Line(m, b));
    }
    for (const Line &line : lines) {
      insert_line(line, 0, n);
    }
  };

  auto go = [&](int u, auto it_st, auto it_en) {
    for (; it_st != it_en; ++it_st) {
      dfs(*it_st, u);
    }
  };

  for (int cur_lev = 0; cur_lev <= MAX_LOG; ++cur_lev) {
    for (const int &u : cen_tree.lev[cur_lev]) {
      go(u, ranges::rbegin(cen_tree.tree[u]), ranges::rend(cen_tree.tree[u]));
      delete_lichao_tree(0, MAX_N);
      go(u, ranges::begin(cen_tree.tree[u]), ranges::end(cen_tree.tree[u]));
      delete_lichao_tree(0, MAX_N);
    }
  }

  cout << ans << '\n';

  //// CLEAR
  auto clearData = [&]() -> void { adj.clear(); };
  clearData();
}
} // namespace Task

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int nTest = 1;

#ifdef DAT
  freopen(file_name ".inp", "r", stdin);
  // freopen(file_name".out","w",stdout);
  freopen(".log", "w", stderr);
  nTest = (argc > 1 ? stoi(argv[1]) : 1);

  auto rand_range = [&](int l, int r) -> int { return l + rand(r - l + 1); };

  auto generate_tree = [&](int size_tree) {
    ofstream cout("test.inp");
    cout << size_tree << '\n';
    for (int i = 2; i <= size_tree; ++i) {
      int p = rand_range(1, i - 1);
      cout << i << ' ' << p << '\n';
    }
    for (int i = 1; i <= size_tree; ++i) {
      cout << rand_range(1, 1000000) << ' ';
    }
    cout.close();
  };

#endif

  // cin >> nTest;
  for (int _ = 1; _ <= nTest; ++_) {
#ifdef DAT
    cout << "Test #" << _ << ":\n";
    // generate_tree(150000);
#endif
    Task::solve();
  }
}
