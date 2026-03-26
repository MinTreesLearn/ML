#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 4e5 + 10;
const int inf = 1e9;
int n, m, r, dis[N], dep[N], con[N], par[N][20];
vector<int> g[N];

int find(int x) {return x == con[x] ? x : con[x] = find(con[x]);}

void dfs(int u, int fa) {
	dep[u] = dep[par[u][0] = fa] + 1;
	for(int i = 1; (1 << i) <= dep[u]; i ++) par[u][i] = par[par[u][i - 1]][i - 1];
	for(int v : g[u]) if(v != fa) dfs(v, u);
}

int getlca(int x, int y) {
	if(dep[x] > dep[y]) swap(x, y);
	per(i, 18, 0) if(dep[par[y][i]] >= dep[x]) y = par[y][i];
	if(x == y) return x;
	per(i, 18, 0) if(par[x][i] != par[y][i]) x = par[x][i], y = par[y][i];
	return par[x][0];
}

int calc(int x, int y) {
	per(i, 18, 0) if(y >> i & 1) x = par[x][i];
	return x;
}

int main() {
	n = read(), m = read(), r = read();
	rep(i, 1, n - 1) {
		int u = read(), v = read();
		g[u].eb(n + i), g[n + i].eb(u);
		g[v].eb(n + i), g[n + i].eb(v);
	}
	n = 2 * n - 1;

	queue<int> q;
	rep(i, 1, n) con[i] = i, dis[i] = inf;
	rep(i, 1, r) {int x = read(); q.push(x), dis[x] = 0;}
	while(! q.empty()) {
		int u = q.front(); q.pop();
		if(dis[u] == m) break;
		for(int v : g[u]) {
			con[find(v)] = find(u);
			if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.push(v);
		}
	}
	
	dfs(1, 0); int t = read();
	while(t --) {
		int x = read(), y = read(), z = getlca(x, y);
		int len = dep[x] + dep[y] - 2 * dep[z];
		if(len <= 2 * m) {puts("YES"); continue;}
		
		int a = (dep[x] - dep[z] >= m) ? calc(x, m) : calc(y, len - m);
		int b = (dep[y] - dep[z] >= m) ? calc(y, m) : calc(x, len - m);
		if(find(a) == find(b)) puts("YES"); else puts("NO");
	}
	return 0;
}
