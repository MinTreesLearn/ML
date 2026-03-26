#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for (int i = s; i <= e; ++i)
#define drep(i, s, e) for (int i = s; i >= e; --i)
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)
#define pv(a) cout << #a << " = " << a << endl
#define pa(a, l, r) cout << #a " : "; rep(_, l, r) cout << a[_] << ' '; cout << endl

const int INF = 0x3f3f3f3f;

const int N = 1e5 + 10;

int read() {
  int x = 0, f = 1; char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * f;
}

int s, t, head[N], tot, d[N], pre[N], mc, mf;
bool tag[N];
struct node {
  int nxt, to, f, w;
  node(int _nxt = 0, int _to = 0, int _f = 0, int _w = 0) {
    nxt = _nxt, to = _to, f = _f, w = _w;
  }
} e[N];

void adde(int u, int v, int f, int w) {
  e[++ tot] = node(head[u], v, f, w), head[u] = tot;
  e[++ tot] = node(head[v], u, 0, -w), head[v] = tot;
}

bool spfa() {
  rep(u, s, t) d[u] = INF, pre[u] = 0;
  queue <int> q;
  d[s] = 0, q.push(s), tag[s] = true;
  while (q.size()) {
    int u = q.front(); q.pop(), tag[u] = false;
    for (int i = head[u], v; i; i = e[i].nxt) {
      if (!e[i].f || d[v = e[i].to] <= d[u] + e[i].w) continue;
      pre[v] = i, d[v] = d[u] + e[i].w;
      if (!tag[v]) q.push(v), tag[v] = true;
    }
  }
  return d[t] < INF;
}

int n, m, q;

int main() {
  n = read(), m = read(), s = 1, t = n, tot = 1;
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    adde(u, v, 1, w);
  }
  vector <pair <int, int> > ver;
  while (spfa()) {
    int flow = INF;
    for (int i = pre[t]; i; i = pre[e[i ^ 1].to]) flow = min(flow, e[i].f);
    mf += flow;
    for (int i = pre[t]; i; i = pre[e[i ^ 1].to]) e[i].f -= flow, e[i ^ 1].f += flow, mc += flow * e[i].w;
    ver.emplace_back(make_pair(mf, mc));
  }
  for (int q = read(); q; -- q) {
    int x = read(); double ans = 1e18;
    for (auto it : ver) ans = min(ans, (double) (it.second + x) / it.first);
    printf("%.10lf\n", ans);
  }
  return 0;
}