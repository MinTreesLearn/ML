// LUOGU_RID: 93522213
/*
* @Author: ftt2333
* @Email: ftt2333@126.com
* @Last Modified time: 2022-11-10 21:50:51
*/

#include <bits/stdc++.h>
using namespace std;
#define int ll
#define off ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fin(s) freopen(s, "r", stdin)
#define fout(s) freopen(s, "w", stdout)
#define fio(s) fin(s".in"), fout(s".out")
using ll = long long; using ull = uint64_t;
using lll = __int128; using ulll = __uint128_t;
using db = double; using ldb = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using vi = vector<int>; using vl = vector<ll>;
using uchar = unsigned char; using uint = unsigned int;
template<class T> using uid = uniform_int_distribution<T>;
template<class T> using urd = uniform_real_distribution<T>;
#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define per(i, a, b) for(auto i = (a); i >= (b); i--)
#define go(i, h, e, x) for(int i = h[x]; i; i = e[i].nxt)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define szof(a) ((int)(a).size())
#define mem(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))

mt19937 rnd(random_device{}());
const int mod = 998244353;
const int inf = 1e18;
const int N = 2e6 + 10;
const int M = 2e6 + 10;

struct mcmf {
  struct edge { int y, c, w, nxt; }ed[M];
  int head[N], cur[N], dis[N], tot = 1, s, t, mc, mf;
  int deg[N];
  bool vis[N];
  void init(){ tot = 1; mem(head, 0); }
  void add(int x, int y, int c, int w) { ed[++tot] = edge{ y, c, w, head[x] }; head[x] = tot; }
  void link(int x, int y, int l, int r, int w) {
    // cout << "LINK " << x << ' ' << y << ' ' << l << ' ' << r << ' ' << w << '\n';
    deg[x] -= l, deg[y] += l;
    add(x, y, r - l, w), add(y, x, 0, -w);
  }
  bool lable(){
    fill(dis, dis + N, inf); mem(vis, 0); mcpy(cur, head);
    deque<int> q; dis[s] = 0, vis[s] = 1; q.push_front(s);
    for(; !q.empty(); ) {
      int x = q.front(); vis[x] = 0; q.pop_front();
      go(i, head, ed, x) {
        int y = ed[i].y, c = ed[i].c, w = ed[i].w;
        if(!c || dis[y] <= dis[x] + w) continue; dis[y] = dis[x] + w;
        if(vis[y]) continue; vis[y] = 1;
        if(!q.empty() && dis[y] <= dis[q.front()]) q.push_front(y);
        else q.push_back(y);
      }
    }
    return dis[t] != inf;
  }
  int dfs(int x, int f){
    if(x == t)return f;
    vis[x] = 1; int r = f;
    go(i, head, ed, x) {
      cur[x] = i; if(!r) break;
      int y = ed[i].y, c = ed[i].c, w = ed[i].w;
      if(!c || dis[y] != dis[x] + w || vis[y]) continue;
      int k = dfs(y, min(r, c));
      if(k) r -= k, ed[i].c -= k, ed[i ^ 1].c += k, mc += w * k;
      else dis[y] = inf;
    } vis[x] = 0;
    return f - r;
  }
  void calc(int S, int T){ s=S, t=T; mc = mf = 0; for(; lable(); ) mf += dfs(s, inf); }
} g;
int n1, n2, m, r, b;
char s1[N], s2[N];

signed main() {
  cin >> n1 >> n2 >> m >> r >> b;
  int s = n1 + n2 + 1, t = s + 1, S = t + 1, T = S + 1;
  scanf("%s%s", s1 + 1, s2 + 1);
  rep(i, 1, m) {
    int x, y; cin >> x >> y;
    g.link(x, y + n1, 0, 1, r);
    g.link(y + n1, x, 0, 1, b);
  }
  // cout << "------------------\n";
  rep(i, 1, n1) {
    if(s1[i] == 'R') g.link(s, i, 1, inf, 0);
    if(s1[i] == 'B') g.link(i, t, 1, inf, 0);
    if(s1[i] == 'U') g.link(s, i, 0, inf, 0), g.link(i, t, 0, inf, 0);
  }
  // cout << "------------------\n";
  rep(i, 1, n2) {
    if(s2[i] == 'B') g.link(s, n1 + i, 1, inf, 0);
    if(s2[i] == 'R') g.link(n1 + i, t, 1, inf, 0);
    if(s2[i] == 'U') g.link(s, n1 + i, 0, inf, 0), g.link(n1 + i, t, 0, inf, 0);
  }
  // cout << "------------------\n";
  g.link(t, s, 0, inf, 0);
  int sum = 0;
  rep(i, 1, t) {
    if(g.deg[i] > 0) sum += g.deg[i], g.link(S, i, 0, g.deg[i], 0);
    if(g.deg[i] < 0) g.link(i, T, 0, -g.deg[i], 0);
  }
  g.calc(S, T);
  if(g.mf != sum) {
    cout << -1 << '\n';
    return 0;
  }
  cout << g.mc << '\n';
  rep(i, 1, m) {
    if(!g.ed[i * 4 - 2].c) cout << 'R';
    else if(!g.ed[i * 4].c) cout << 'B';
    else cout << 'U';
  } 
}