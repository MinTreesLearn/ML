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

const int N = 2e5 + 10;
const int inf = 1e9 + 10;
int n, m, a[N], par[N];
struct node {int v1, p1, v2, p2;} f[1 << 18], g[N];
struct edge {int u, v, w;};

int find(int x) {return x == par[x] ? x : par[x] = find(par[x]);}
void push(node &f, int v, int p) {
	if(f.v1 == -inf) {f.v1 = v, f.p1 = p; return;}
	if(f.p1 == p) {if(v > f.v1) f.v1 = v, f.p1 = p; return;}
	if(v >= f.v1) {f.v2 = f.v1, f.p2 = f.p1, f.v1 = v, f.p1 = p; return;}
	if(v > f.v2) f.v2 = v, f.p2 = p;
}

int main() {
	n = read();
	rep(i, 1, n) a[i] = read();
	a[++ n] = 0;
	rep(i, 1, n) m = max(m, a[i]), par[i] = i;
	
	int t = 1; while((1 << t) <= m) t ++;
	ll ans = 0;
	
	while(true) {
		rep(i, 0, (1 << t) - 1) f[i] = (node) {-inf, 0, -inf, 0};
		rep(i, 1, n) push(f[a[i]], a[i], find(i)), g[i] = (node) {-inf, 0, -inf, 0};
		rep(i, 1, (1 << t) - 1) rep(o, 0, t - 1) if(i >> o & 1) {
			int j = i ^ (1 << o);
			push(f[i], f[j].v1, f[j].p1);
			push(f[i], f[j].v2, f[j].p2);
		}
		rep(i, 1, n) {
			int j = ((1 << t) - 1) ^ a[i];
			int p = find(i);
			if(p == f[j].p1) push(g[p], a[i] + f[j].v2, f[j].p2);
			else push(g[p], a[i] + f[j].v1, f[j].p1);
		}
		vector<edge> arc;
		rep(i, 1, n) if(i == find(i)) {
			if(g[i].v1 > -inf) arc.eb((edge) {i, g[i].p1, g[i].v1});
		}
		for(edge e : arc) {
			int u = find(e.u);
			int v = find(e.v); if(u == v) continue;
			par[u] = v, ans += e.w;
		}
		int cnt = 0;
		rep(i, 1, n) cnt += (i == find(i));
		if(cnt == 1) break;
	}
	
	rep(i, 1, n) ans -= a[i];
	printf("%lld\n", ans);
	return 0;
}
