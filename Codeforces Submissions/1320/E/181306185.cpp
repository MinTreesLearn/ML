#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 2e5 + 10;
const int inf = 1e9 + 10;
int n, q;
vector<int> g[N], h[N];

int par[N], dep[N], siz[N], son[N];
void dfs1(int u, int fa) {
	dep[u] = dep[par[u] = fa] + (siz[u] = 1);
	for(int v : g[u]) if(v != fa) {
		dfs1(v, u);
		siz[u] += siz[v];
		if(!son[u] || siz[v] > siz[son[u]]) son[u] = v;
	}
}

int tim, top[N], dfn[N];
void dfs2(int u, int tp) {
	top[u] = tp, dfn[u] = ++ tim;
	if(son[u]) dfs2(son[u], tp);
	for(int v : g[u]) if(v != par[u] && v != son[u]) dfs2(v, v);
}

int getlca(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = par[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int k, s[N], c[N], m, t[N], stk[N], tot;
vector<int> arc;

void add(int u, int v) {
	// cerr << "addedge " << u << ' ' << v << endl;
	h[u].eb(v), h[v].eb(u);
}

void build() {
	sort(arc.begin(), arc.end(), [](int x, int y) {return dfn[x] < dfn[y];});
	arc.erase(unique(arc.begin(), arc.end()), arc.end());

	vector<int> tmp = arc;
	for(int o : tmp) {
		if(! tot) {stk[++ tot] = o; continue;}
		int cur = getlca(o, stk[tot]);
		if(cur != stk[tot]) {
			while(tot > 1 && dfn[stk[tot - 1]] >= dfn[cur])
				add(stk[tot], stk[tot - 1]), tot --;
			if(cur != stk[tot]) add(stk[tot], cur), stk[tot] = cur, arc.eb(cur);
		}
		stk[++ tot] = o;
	}
	if(tot) while(-- tot) add(stk[tot], stk[tot + 1]);
}

struct node {
	int t, x, d;
	bool operator < (const node &a) const {
		return (t ^ a.t) ? t > a.t : ((x ^ a.x) ? x > a.x : d > a.d);
	}
} dis[N];

bool vis[N];

void solve() {
	for(int o : arc) dis[o] = (node) {inf, inf, inf}, vis[o] = false;
	priority_queue<pair<node, int>> q;
	rep(i, 1, k) {int o = s[i]; dis[o] = (node) {0, i, 0}; q.push(mp(dis[o], o));}
	while(! q.empty()) {
		int u = q.top().se; q.pop();
		if(vis[u]) continue; else vis[u] = true;
		
		// cerr << "dis " << u << ' ' << dis[u].t << ' ' << dis[u].x << ' ' << dis[u].d << endl;
		
		for(int v : h[u]) {
			int w = abs(dep[u] - dep[v]);
			node nxt;
			nxt.t = dis[u].t + (w - dis[u].d + c[dis[u].x] - 1) / c[dis[u].x];
			nxt.x = dis[u].x;
			nxt.d = (w > dis[u].d) ? (nxt.t - dis[u].t) * c[nxt.x] + dis[u].d - w : dis[u].d - w;
			if(dis[v] < nxt) dis[v] = nxt, q.push(mp(dis[v], v));
		}
	}
	rep(i, 1, m) printf("%d%c", dis[t[i]].x, i == m ? '\n' : ' ');
}

int main() {
	n = read();
	rep(i, 2, n) {int u = read(), v = read(); g[u].eb(v), g[v].eb(u);}
	
	dfs1(1, 0), dfs2(1, 1);
	
	q = read();
	while(q --) {
		k = read(), m = read();
		arc.clear();
		rep(i, 1, k) s[i] = read(), c[i] = read(), arc.eb(s[i]);
		rep(i, 1, m) t[i] = read(), arc.eb(t[i]);
		
		// cerr << "current " << k << ' ' << m << endl;
		
		build(), solve();
		for(int o : arc) h[o].clear();
	}
	return 0;
}
