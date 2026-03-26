#include <bits/stdc++.h>

#define SP putchar(' ')
#define EL putchar('\n')
#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

template <typename T>
void read(T &);
template <typename T>
void write(const T &);

const int N = 250005;

namespace DSU {
int find(int x);
void merge(int x, int y);

int mnd[N];
int fa[N];
}  // namespace DSU

int LCA(int u, int v);
int anck(int u, int k);
void dfs(int u);

int fa[N][20], dep[N];
int que[N], qh, qt, fa2[N];
bool inq[N];
std::vector<int> G1[N], G2[N];
int n;

int main() {
  read(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    G1[u].push_back(v), G1[v].push_back(u);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    G2[u].push_back(v), G2[v].push_back(u);
  }
  dfs(1);
  que[qh = qt = 0] = 1;
  while (qh <= qt) {
    int u = que[qh++];
    inq[u] = true;
    for (int v : G2[u]) {
      if (inq[v]) continue;
      fa2[v] = u;
      que[++qt] = v;
    }
  }
  for (int i = 1; i <= n; ++i) DSU::fa[i] = i, DSU::mnd[i] = dep[i];
  std::reverse(que + 1, que + n);
  write(n - 1), EL;
  for (int i = 1; i < n; ++i) {
    int u = que[i], v = fa2[u];
    int L = LCA(u, v);
    int fu = DSU::find(u);
    int x;
    if (DSU::mnd[fu] > dep[L]) {
      x = anck(u, dep[u] - DSU::mnd[fu]);
    } else {
      x = v;
      for (int i = 18; i >= 0; --i) {
        if (dep[x] - (1 << i) >= dep[L] && DSU::find(fa[x][i]) != fu) x = fa[x][i];
      }
    }
    DSU::merge(x, fa[x][0]);
    write(x), SP, write(fa[x][0]), SP, write(u), SP, write(v), EL;
  }
  return 0;
}

int LCA(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  u = anck(u, dep[u] - dep[v]);
  if (u == v) return u;
  for (int i = 18; i >= 0; --i) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i], v = fa[v][i];
    }
  }
  return fa[u][0];
}
int anck(int u, int k) {
  for (int i = 0; i < 19; ++i) {
    if (k >> i & 1) u = fa[u][i];
  }
  return u;
}
void dfs(int u) {
  for (int i = 1; i <= 18; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : G1[u]) {
    if (v == fa[u][0]) continue;
    fa[v][0] = u;
    dep[v] = dep[u] + 1;
    dfs(v);
  }
}

namespace DSU {
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    fa[fx] = fy;
    mnd[fy] = std::min(mnd[fy], mnd[fx]);
  }
}
}  // namespace DSU

template <typename T>
void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) k = k * 10 + ch - '0', ch = getchar();
  Re = flag * k;
}
template <typename T>
void write(const T &Wr) {
  if (Wr < 0)
    putchar('-'), write(-Wr);
  else if (Wr < 10)
    putchar(Wr + '0');
  else
    write(Wr / 10), putchar((Wr % 10) + '0');
}
