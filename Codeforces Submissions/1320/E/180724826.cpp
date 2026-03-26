// LUOGU_RID: 93909098
#include <bits/stdc++.h>

#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; ++i)
#define rFor(i, b, a) for (int i = b, i##end = a; i >= i##end; --i)
#define eFor(i, u, v) for (int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)

typedef long long ll;

typedef std::pair<int, int> pii;
#define fi first
#define se second

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T> 
T myrand(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rnd);
}

template<typename T, typename ...Args> 
void LOG(T str, Args ...args) {
#ifdef DEBUG
	fprintf(stderr, str, args...);
#endif
}

#define fre(s) freopen(#s ".in", "r", stdin), freopen(#s ".out", "w", stdout)

const int kN = 2e5 + 5;

int n, q, s[kN], f[kN], dep[kN], dfn[kN], son[kN], top[kN], clk;
std::vector<int> G[kN];

void dfs1(int u) {
	s[u] = 1;
	for (int v : G[u]) if (v ^ f[u]) {
		f[v] = u;
		dep[v] = dep[u] + 1;
		dfs1(v);
		s[u] += s[v];
		if (s[v] > s[son[u]]) son[u] = v;
	}
}

void dfs2(int u) {
	dfn[u] = ++clk;
	if (!top[u]) top[u] = u;
	if (son[u]) top[son[u]] = top[u], dfs2(son[u]);
	for (int v : G[u]) if (v != f[u] && v != son[u]) dfs2(v);
}

int lca(int u, int v) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] > dep[top[v]]) u = f[top[u]];
		else v = f[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

// virtual tree
int head[kN], ecnt = 1;

struct Arc {
	int next, to, w;
} e[kN << 1];

void addEdge(int from, int to, int w) {
	e[ecnt] = (Arc) {
		head[from], to, w
	};
	head[from] = ecnt++;
}

int k, m, vert[kN * 2], sp[kN], upd[kN], qry[kN], st[kN];
int c[kN], rem[kN], t[kN];
bool vis[kN];
std::priority_queue<std::pair<pii, int> > hp;

void solve() {
	scanf("%d%d", &k, &m);
	For(i, 1, k) scanf("%d%d", upd + i, sp + i), vert[i] = upd[i];
	For(i, 1, m) scanf("%d", qry + i), vert[i + k] = qry[i];
	vert[0] = 1;
	std::sort(vert, vert + k + m + 1, [](int u, int v) {
		return dfn[u] < dfn[v];
	});
	For(i, 0, k + m) head[vert[i]] = 0;
	ecnt = 1;
	int top = 1;
	st[top] = 1;
	For(i, 1, k + m) {
		if (vert[i] == vert[i - 1]) continue;
		int p = lca(vert[i], st[top]);
		while (top > 1 && dep[p] <= dep[st[top - 1]]) {
			addEdge(st[top - 1], st[top], dep[st[top]] - dep[st[top - 1]]);
			addEdge(st[top], st[top - 1], dep[st[top]] - dep[st[top - 1]]);
			--top;
		}
		if (p != st[top]) {
			head[p] = 0;
			vis[p] = false, t[p] = 1e9, c[p] = 0; // ERR
			addEdge(st[top], p, dep[st[top]] - dep[p]);
			addEdge(p, st[top], dep[st[top]] - dep[p]);
			st[top] = p;
		}
		st[++top] = vert[i];
	}
	while (top > 1) {
		addEdge(st[top], st[top - 1], dep[st[top]] - dep[st[top - 1]]);
		addEdge(st[top - 1], st[top], dep[st[top]] - dep[st[top - 1]]);
		--top;
	}
	For(i, 0, k + m) vis[vert[i]] = false, t[vert[i]] = 1e9, c[vert[i]] = 0; // ERR
	For(i, 1, k) {
		t[upd[i]] = 0;
		c[upd[i]] = i;
		rem[upd[i]] = 0;
		hp.push({pii(0, -i), upd[i]});
	}
	while (!hp.empty()) {
		int u = hp.top().se;
		hp.pop();
		if (vis[u]) continue;
		vis[u] = true;
		eFor(i, u, v) {
			int nt = rem[u] < e[i].w ? t[u] + (e[i].w - rem[u] + sp[c[u]] - 1) / sp[c[u]] : t[u];
			int nr = (nt - t[u]) * sp[c[u]] + rem[u] - e[i].w; // ERR
			if (t[v] && pii(nt, c[u]) < pii(t[v], c[v])) { // ERR
				t[v] = nt;
				c[v] = c[u];
				rem[v] = nr;
				hp.push({pii(-t[v], -c[v]), v});
			}
		}
	}
	For(i, 1, m) printf("%d ", c[qry[i]]);
	printf("\n");
}

int main() {
	scanf("%d", &n);
	For(i, 1, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs1(1), dfs2(1);
	scanf("%d", &q);
	For(kase, 1, q) solve();
	return 0;
}
/* PAY ATTENTION TO: */
/* 1. Memory Limit, Array Size */
/* 2. Integer Overflow */
/* 3. Multi-test */
/* 4. Potential Constant-speedup */
/* Stay organized and write things down. */
