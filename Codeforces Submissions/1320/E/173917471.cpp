/**
 *    Author:  LZVSDY
**/
#include <bits/stdc++.h>
using namespace std;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
/*
freopen("orxor.in", "r", stdin);
*/
typedef long long LL;
typedef unsigned long long int ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int N = 2500010;
const int M = 5e5 + 10;
int h[N], e[M], ne[M], idx;
int dep[N], dfn[N], f[N][19], sz[N], son[N], ti;
int st[N], s[N], tp;
bool vis[N], use[N];
PII dist[N];
int n, k, m;
struct V{
    int v, s, col;
}v[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs1(int u, int fa) {
    sz[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        f[j][0] = u;
        dep[j] = dep[u] + 1;
        dfs1(j, u);
        sz[u] += sz[j];
        if (sz[u] > sz[son[u]]) son[u] = j;
    }
}
void dfs2(int u, int fa) {
    dfn[u] = ++ ti;
    if (son[u]) {
        dfs2(son[u], u);
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa || j == son[u]) continue;
            dfs2(j, u);
        }
    }
}
void init() {
    for (int j = 1; j < 19; j ++ )
        for (int i = 1; i <= n; i ++ )
            f[i][j] = f[f[i][j - 1]][j - 1];
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int k = 18; k >= 0; k -- )
        if (dep[f[a][k]] >= dep[b])
            a = f[a][k];
    if (a == b) return a;
    for (int k = 18; k >= 0; k -- ) 
        if (f[a][k] != f[b][k])
            a = f[a][k], b = f[b][k];
    return f[a][0];
}
bool cmp1(V &a, V &b) {
    return dfn[a.v] < dfn[b.v];
}
bool cmp2(V &a, V &b) {
    return a.col < b.col;
}
void ins(int x) {
    if (!tp) {
        st[++ tp] = x;
        return;
    }
    int anc = lca(st[tp], x);
    while (tp > 1 && dep[st[tp - 1]] > dep[anc]) {
		add(st[tp - 1], st[tp]), add(st[tp], st[tp - 1]);
        tp --;
    }
    if (dep[st[tp]] > dep[anc]) {
        add(anc, st[tp]), add(st[tp], anc);
        tp --;
    }
    if (!tp || st[tp] != anc) st[++ tp] = anc;
    st[++ tp] = x;
}
int query(int v, int u, int op) {
    int anc = lca(u, v);
    int len = dep[u] + dep[v] - 2 * dep[anc];
    return (len + s[op] - 1) / s[op];
}
struct Node{
    int rounds, col, fa, now;
    bool operator> (const Node& w) const {
        if (rounds != w.rounds) return rounds > w.rounds;
        else if (col != w.col) return col > w.col;
        else if (fa != w.fa) return fa > w.fa;
        else return now > w.now;
    }
};
void dij() {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    sort(v + 1, v + k + m + 1, cmp2);
    for (int i = 1; i <= k; i ++ ) {
        dist[v[i].v] = {0, v[i].col};
        q.push({0, v[i].col, v[i].v, v[i].v});
    }
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        if (vis[t.now]) continue;
        vis[t.now] = 1;
        for (int i = h[t.now]; ~i; i = ne[i]) {
            int j = e[i];
            int len = query(j, t.fa, t.col);
            if (dist[j].FI > len) {
                dist[j] = {len, dist[t.now].SE};
                q.push({len, dist[j].SE, t.fa, j});
            } else if (dist[j].FI == len && dist[j].SE > dist[t.now].SE) {
                dist[j].SE = dist[t.now].SE;
                q.push({len, dist[j].SE, t.fa, j});
            }
        }
    }
}
void build(int k, int m) {
    for (int i = 1; i <= k; i ++ ) {
        cin >> v[i].v >> v[i].s;
        s[i] = v[i].s;
        v[i].col = i;
    }
    for (int i = 1; i <= m; i ++ ) {
        cin >> v[i + k].v;
        v[i + k].col = i + k;
    }
    sort(v + 1, v + m + k + 1, cmp1);
    tp = 0;
    if (v[1].v != 1) st[++ tp] = 1;
    for (int i = 1; i <= k + m; i ++ ) {
        if (use[v[i].v]) continue;
        ins(v[i].v);
        use[v[i].v] = 1;
    }
    for (int i = 1; i <= k + m; i ++ )
        use[v[i].v] = 0;
    while (-- tp) 
        add(st[tp], st[tp + 1]), add(st[tp + 1], st[tp]);
    dij();
}
void recover(int u, int fa) {
    dist[u].FI = dist[u].SE = INF;
    vis[u] = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        recover(j, u);
    }
    h[u] = -1;
}
int main() {
//	#ifdef lz
//		freopen("lz.in", "r", stdin);
//    #endif
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i ++ ) dist[i].FI = dist[i].SE = INF;
    for (int i = 1; i <= n; i ++ ) h[i] = -1;
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dep[1] = 1;
    dfs1(1, -1);
    dfs2(1, -1);
    init();
    for (int i = 1; i <= n; i ++ ) h[i] = -1;
    int q;
    cin >> q;
    while (q -- ) {
        cin >> k >> m;
        idx = 0;
        build(k, m);
        for (int i = k + 1; i <= k + m; i ++ )
            cout << dist[v[i].v].SE << ' ';
        cout << endl;
        recover(1, -1);
    }
	return 0;
}