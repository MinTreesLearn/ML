// LUOGU_RID: 99128720
#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0; bool f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
const int MAXN = 2.5e5 + 5;
int n, son[MAXN], dep[MAXN], U[MAXN], fa[MAXN], f[MAXN][21];
vector <int> g1[MAXN], g2[MAXN]; queue <int> Q;
int find(int x) { return x == U[x] ? x : U[x] = find(U[x]); }
inline void join(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu != fv) U[fu] = fv;
}
void misaka(int u, int p) {
	dep[u] = dep[p] + 1; f[u][0] = p;
	for (auto v : g1[u])
		if (v != p) misaka(v, u);
}
void init_ST() {
	for (int j = 1; j <= 20; ++j)
		for (int i = 1; i <= n; ++i)
			f[i][j] = f[f[i][j - 1]][j - 1];
}
void misaki(int u, int p) {
	fa[u] = p;
	for (auto v : g2[u])
		if (v != p) misaki(v, u), ++son[u];
	if (!son[u]) Q.emplace(u);
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; ~i; --i)
		if (dep[f[x][i]] >= dep[y])
			x = f[x][i];
	if (x == y) return x;
	for (int i = 20; ~i; --i)
		if (f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}
int main() {
	n = read(); write(n - 1), putchar('\n');
	for (int i = 1; i <= n; ++i) U[i] = i;
	for (int i = 1; i < n; ++i) {
		int u = read(), v = read();
		g1[u].emplace_back(v);
		g1[v].emplace_back(u);
	}
	for (int i = 1; i < n; ++i) {
		int u = read(), v = read();
		g2[u].emplace_back(v);
		g2[v].emplace_back(u);
	}
	misaka(1, 0); init_ST();
	misaki(1, 0);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		if (u == 1) return 0;
		int g = lca(u, fa[u]), x;
		if (dep[find(u)] > dep[g]) x = find(u);
		else {
			x = fa[u];
			for (int i = 20; ~i; --i)
				if (dep[f[x][i]] >= dep[g] && find(f[x][i]) != find(g))
					x = f[x][i];
		}
		join(x, f[x][0]);
		write(x), putchar(' ');
		write(f[x][0]), putchar(' ');
		write(u), putchar(' ');
		write(fa[u]), putchar(' ');
		putchar('\n');
		if (!--son[fa[u]]) Q.emplace(fa[u]);
	}
	return 0;
}