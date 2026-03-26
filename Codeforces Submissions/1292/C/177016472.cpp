#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

#define eb emplace_back

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 3010;
int n, dis[N][N], siz[N][N], par[N][N];
vector<int> g[N];
int t; pii arc[N * N]; ll f[N][N];

void dfs(int u, int fa, int tp) {
	par[tp][u] = fa, siz[tp][u] = 1, dis[tp][u] = dis[tp][fa] + 1;
	for(int v : g[u]) if(v != fa) dfs(v, u, tp), siz[tp][u] += siz[tp][v];
}

void push(int x, int y, ll v) {if(x > y) swap(x, y); f[x][y] = f[x][y] > v ? f[x][y] : v;}

int main() {
	n = read();
	rep(i, 2, n) {int u = read(), v = read(); g[u].eb(v), g[v].eb(u);}
	rep(i, 1, n) dfs(i, 0, i);
	rep(i, 1, n) rep(j, i + 1, n) arc[++ t] = mp(i, j), f[i][j] = 1;
	
	sort(arc + 1, arc + t + 1, [](pii x, pii y) {return dis[x.fi][x.se] > dis[y.fi][y.se];});
	
	ll ans = 0;
	
	rep(i, 1, t) {
		int x = arc[i].fi;
		int y = arc[i].se;
		ans = max(ans, f[x][y]);
		if(dis[x][y] == 1) continue;
		
		int nx = par[y][x];
		push(nx, y, f[x][y] + siz[nx][y] * siz[y][nx]);
		int ny = par[x][y];
		push(x, ny, f[x][y] + siz[x][ny] * siz[ny][x]);
	}
	
	printf("%lld\n", ans);
	return 0;
}
