#include <bits/stdc++.h>
using namespace std;

const int D = 5;
const int S = 374;

int transition[S][1<<D];
int combination[S][S];

struct linear_space {
  uint32_t x;
  linear_space(): x(1) {};
  linear_space(uint32_t _x): x(_x) {};
  bool has(int k) {
    return (x>>k)&1;
  }
  bool operator == (const linear_space& other) {
    return x == other.x;
  }
  bool operator < (const linear_space& other) {
    return x < other.x;
  }
  linear_space operator + (int k) {
    uint32_t res = x;
    for (int i = 0; i < (1<<D); i++) {
      if ((x>>i)&1) res |= 1<<(k^i);
    }
    return linear_space(res);
  }
  linear_space operator + (const linear_space& other) {
    uint32_t res = 0;
    for (int i = 0; i < (1<<D); i++) {
      for (int j = 0; j < (1<<D); j++) {
        if ((x>>i)&1 && (other.x>>j)&1) res |= 1<<(i^j);
      }
    }
    return linear_space(res);
  }
  friend ostream& operator << (ostream& os, const linear_space& l) {
    return os << bitset<32>(l.x);
  }
};

vector<linear_space> spaces(1);

int get_index(linear_space x) {
  return lower_bound(spaces.begin(), spaces.end(), x)-spaces.begin();
}

void precompute() {
  for (int i = 0; i < (int)spaces.size(); i++) {
    for (int j = 0; j < (1<<D); j++) {
      if (spaces[i].has(j)) continue;
      linear_space y = spaces[i]+j;
      if (find(spaces.begin(), spaces.end(), y) == spaces.end()) {
        spaces.push_back(y);
      }
    }
  }
  sort(spaces.begin(), spaces.end());
  assert(spaces.size() == S);

  for (int i = 0; i < S; i++) {
    for (int j = 0; j < (1<<D); j++) {
      transition[i][j] = (spaces[i].has(j) ? -1 : get_index(spaces[i]+j));
    }
  }
  
  for (int i = 0; i < S; i++) {
    for (int j = 0; j < S; j++) {
      combination[i][j] =
        ((spaces[i].x&spaces[j].x) == 1 ? get_index(spaces[i]+spaces[j]) : -1);
    }
  }
}

const int MOD = 1e9+7;
void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

const int N = 1e5+5;
vector<pair<int, int>> G[N];
int wt[N], tree_space[N], dep[N];
bool inner[N], vis[N];

vector<tuple<int, int, int>> special_edges;

void dfs(int v) {
  for (auto& [u, w]: G[v]) {
    if (inner[u] && inner[v]) {
      if (u < v) special_edges.emplace_back(u, v, w);
      continue;
    }
    if (dep[u] < dep[v] && (dep[u] > 0 || u == 1)) continue;
    if (dep[u] > dep[v]+1) {
      if (tree_space[v] != -1) {
        tree_space[v] = transition[tree_space[v]][wt[u]^wt[v]^w];
      }
      continue;
    }
    dep[u] = dep[v]+1;
    wt[u] = wt[v]^w;
    dfs(u);
    if (v != 1 && tree_space[v] != -1) {
      if (tree_space[u] == -1) tree_space[v] = -1;
      else tree_space[v] = combination[tree_space[v]][tree_space[u]];
    }
  }
}

void increment(array<int, S>& a, array<int, S>& b, int c) {
  for (int i = 0; i < S; i++) {
    int j = combination[i][c];
    if (j != -1) add(b[j], a[i]);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  precompute();

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  for (auto& [v, _]: G[1]) inner[v] = 1;
  dfs(1);

  fill(vis, vis+N, 0);
  array<int, S> dp({});
  dp[0] = 1;
  for (auto& [u, v, w]: special_edges) {
    vis[u] = vis[v] = 1;
    array<int, S> _dp = dp;
    if (tree_space[u] != -1 && tree_space[v] != -1) {
      int k = combination[tree_space[u]][tree_space[v]];
      if (k != -1) {
        increment(dp, _dp, k);
        increment(dp, _dp, k);
        int l = transition[k][wt[u]^wt[v]^w];
        if (l != -1) increment(dp, _dp, l);
      }
    }
    swap(dp, _dp);
  }

  for (auto& [v, _]: G[1]) {
    if (vis[v]) continue;
    if (tree_space[v] != -1) {
      array<int, S> _dp = dp;
      increment(dp, _dp, tree_space[v]);
      swap(dp, _dp);
    }
  }

  int ans = 0;
  for (int x: dp) add(ans, x);
  cout << ans << '\n';
}
