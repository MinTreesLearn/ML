#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb emplace_back
#define rep(i, s, e) for (int i = s; i <= e; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)
#define pv(a) cout << #a << " = " << a << endl
#define pa(a, l, r) cout << #a " : "; rep(_, l, r) cout << a[_] << ' '; cout << endl

using pii = pair <int, int>;

const int P = 1e9 + 7;

const int N = 1e5 + 10;
const int W = 32;
const int K = 400;

int read() {
  int x = 0, f = 1; char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * f;
}

int inc(int a, int b) { return (a += b) >= P ? a - P : a; }
int dec(int a, int b) { return (a -= b) < 0 ? a + P : a; }
int mul(int a, int b) { return 1ll * a * b % P; }
int qpow(int a, int b) { int res = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a); return res; }

struct node {
  int dat[5];
  node() { rep(i, 0, 4) dat[i] = 0; }
  void clear() { rep(i, 0, 4) dat[i] = 0; }
  bool insert(int x) {
    drep(i, 4, 0) if (x >> i & 1) {
      if (!dat[i]) {
        dat[i] = x;
        rep(j, 0, i - 1) if (dat[j] && dat[i] >> j & 1) dat[i] ^= dat[j];
        rep(j, i + 1, 4) if (dat[j] && dat[j] >> i & 1) dat[j] ^= dat[i];
        return true;
      }
      else x ^= dat[i];
    }
    return false;
  }
  int val() {
    int res = 0;
    rep(i, 0, 4) res |= dat[i] << i * (i + 1) / 2;
    return res;
  }
} base[K], con;

int cnt, id[N], h[N], add[K][K];

void dfs(int i, node cur) {
  if (i == W) {
    if (!id[cur.val()]) id[cur.val()] = ++ cnt, base[cnt] = cur, h[cnt] = cur.val();
    return;
  }
  dfs(i + 1, cur);
  if (cur.insert(i)) dfs(i + 1, cur);
}

int join(int u, int v) {
  if (~add[u][v]) return add[u][v];
  node s = base[u], t = base[v];
  rep(i, 0, 4) if (t.dat[i]) {
    if (!s.insert(t.dat[i])) return add[u][v] = add[v][u] = 0;
  }
  return id[s.val()];
}

int n, m, d[N], f[K], g[K], ans, v1[N], v2[N];
vector <pii> e[N];
map <int, int> E[N];
bool tag[N];

int fa[N];
int get(int u) { return u == fa[u] ? u : fa[u] = get(fa[u]); }
void merge(int u, int v) { fa[get(v)] = get(u); }

bool dfs0(int u, int fa) {
  tag[u] = true;
  bool flag = true;
  for (auto [v, w] : e[u]) if (v != 1 && v != fa) {
    if (!tag[v]) d[v] = d[u] ^ w, flag &= dfs0(v, u);
    else if (u < v) flag &= con.insert(d[u] ^ d[v] ^ w);
  }
  return flag;
}

int main() {
  dfs(0, node());
  rep(i, 1, cnt) rep(j, 1, cnt) add[i][j] = -1;
  n = read(), m = read();
  rep(i, 1, n) fa[i] = i;
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    e[u].pb(mp(v, w)), e[v].pb(mp(u, w));
    E[u][v] = E[v][u] = w;
    if (u > 1 && v > 1) merge(u, v);
  }
  tag[1] = true, f[1] = 1;
  for (auto [r, w] : e[1]) {
    if (!v1[get(r)]) v1[get(r)] = r;
    else v2[get(r)] = r;
  }
  rep(r, 1, n) if (v1[r]) {
    if (!v2[r]) {
      int u = v1[r];
      if (dfs0(u, 1)) {
        int p = id[con.val()];
        fill(g, g + K, 0);
        rep(i, 1, cnt) {
          g[i] = inc(g[i], f[i]);
          if (join(i, p)) g[join(i, p)] = inc(g[join(i, p)], f[i]);
        }
        swap(f, g);
      }
      con.clear();
    }
    else {
      int u = v1[r], v = v2[r];
      fill(g, g + K, 0);
      rep(i, 1, cnt) g[i] = inc(g[i], f[i]);
      if (dfs0(u, 1)) {
        int p = id[con.val()];
        rep(i, 1, cnt) {
          if (join(i, p)) g[join(i, p)] = inc(g[join(i, p)], inc(f[i], f[i]));
        }
        if (con.insert(E[1][u] ^ E[1][v] ^ E[u][v])) {
          int p = id[con.val()];
          rep(i, 1, cnt) {
            if (join(i, p)) g[join(i, p)] = inc(g[join(i, p)], f[i]);
          }
        }
      }
      con.clear(), swap(f, g);
    }
  }
  rep(i, 1, cnt) ans = inc(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}