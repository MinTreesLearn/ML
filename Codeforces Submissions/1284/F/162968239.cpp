#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2.5e5 + 9, L = 20;
int n, pos[N], dfn[N], tot;
vector<int> es[2][N];
int fa[N][L], dph[N], f[N];
int findf(int x) { return f[x] == x ? x : f[x] = findf(f[x]); }
void add(int u, int v, int id) {
  es[id][u].push_back(v), es[id][v].push_back(u);
}
void dfs(int u) {
  for (int i = 0; i + 1 < L; ++i) fa[u][i + 1] = fa[fa[u][i]][i];
  for (int v : es[0][u])
    if (v != fa[u][0]) dph[v] = dph[fa[v][0] = u] + 1, dfs(v);
}
int lca(int u, int v) {
  if (dph[u] < dph[v]) swap(u, v);
  for (int i = L - 1; ~i; --i)
    if (dph[u] - (1 << i) >= dph[v]) u = fa[u][i];
  if (u == v) return u;
  for (int i = L - 1; ~i; --i)
    if (int fu = fa[u][i], fv = fa[v][i]; fu != fv) u = fu, v = fv;
  return fa[u][0];
}
bool dif(int x, int y, int z) {
  return (findf(x) == findf(z)) ^ (findf(y) == findf(z));
}
int solve(int u, int p) {
  int b = u, l = lca(u, p);
  if (dif(p, l, b)) u = p;
  for (int i = L - 1; ~i; --i)
    if (int fu = fa[u][i]; dph[fu] > dph[l] && !dif(u, fu, b)) u = fu;
  return u;
}
void calc(int u, int p) {
  for (int v : es[1][u])
    if (v != p) calc(v, u);
  if (u == 1) return;
  int d = solve(u, p);
  cout << d << ' ' << (f[d] = fa[d][0]) << ' ' << u << ' ' << p << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) cin >> u >> v, add(u, v, 0);
  for (int i = 1, u, v; i < n; ++i) cin >> u >> v, add(u, v, 1);
  dfs(1), iota(f + 1, f + n + 1, 1);
  cout << n - 1 << '\n', calc(1, -1);
  return cout << flush, 0;
}