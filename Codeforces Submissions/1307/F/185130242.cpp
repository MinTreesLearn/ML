#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+5;
const int K = 19;
const int INF = 1e9;
vector<int> G[N];
int par[N][K], dep[N], dist_from_rest[N], nearest_rest[N];

int fa[N];

int root(int x) {
  return (fa[x] == x ? x : fa[x] = root(fa[x]));
}

void join(int x, int y) {
  int a = root(x);
  int b = root(y);
  if (a == b) return;
  fa[a] = b;
}

void dfs(int v, int p) {
  par[v][0] = p;
  dep[v] = dep[p]+1;
  for (int i = 1; i < K; i++) {
    par[v][i] = par[par[v][i-1]][i-1];
  }
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = K-1; i >= 0; i--) {
    if (((dep[v]-dep[u])>>i)&1) {
      v = par[v][i];
    }
  }
  if (u == v) return u;
  for (int i = K-1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int kth_ancestor(int v, int k) {
  for (int i = K-1; i >= 0; i--) {
    if ((k>>i)&1) {
      v = par[v][i];
    }
  }
  return v;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k, r;
  cin >> n >> k >> r;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(n+1+i);
    G[v].push_back(n+1+i);
    G[n+1+i].push_back(u);
    G[n+1+i].push_back(v);
  }
  dfs(1, 0);
  fill(dist_from_rest, dist_from_rest+N, INF);
  vector<int> que;
  for (int i = 0; i < r; i++) {
    int v;
    cin >> v;
    que.push_back(v);
    dist_from_rest[v] = 0;
    nearest_rest[v] = v;
  }

  iota(fa, fa+N, 0);
  for (int i = 0; i < (int)que.size(); i++) {
    int v = que[i];
    if (dist_from_rest[v] == k) break;
    for (int u: G[v]) {
      if (nearest_rest[u]) {
        join(nearest_rest[u], nearest_rest[v]);
        continue;
      }
      nearest_rest[u] = nearest_rest[v];
      dist_from_rest[u] = dist_from_rest[v]+1;
      que.push_back(u);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    int w = lca(u, v);
    int d = dep[u]+dep[v]-2*dep[w];
    if (d <= 2*k) {
      cout << "YES\n";
      continue;
    }
    int u0 = (dep[u]-dep[w] >= k ? kth_ancestor(u, k) : kth_ancestor(v, d-k));
    int v0 = (dep[v]-dep[w] >= k ? kth_ancestor(v, k) : kth_ancestor(u, d-k));
    cout << (nearest_rest[u0] && root(nearest_rest[u0]) == root(nearest_rest[v0]) ? "YES" : "NO") << '\n';
  }
}
