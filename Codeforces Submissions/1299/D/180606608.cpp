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

const int P = 1e9 + 7;
inline int plu(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int del(int x, int y) {return x - y <  0 ? x - y + P : x - y;}
inline void add(int &x, int y) {x = plu(x, y);}
inline void sub(int &x, int y) {x = del(x, y);}
inline int qpow(int a, int b) {int s = 1; for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) s = 1ll * s * a % P; return s;}

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e5 + 10;
const int M = 500;
int n, m; vector<pii> g[N];

struct node {
	int a[5];
	node() {memset(a, 0, sizeof(a));}
	void init(int x) {
		a[0] = x & 1;
		a[1] = x >> 1 & 3;
		a[2] = x >> 3 & 7;
		a[3] = x >> 6 & 15;
		a[4] = x >> 10 & 31;
	}
	int hash() {return a[0] | a[1] << 1 | a[2] << 3 | a[3] << 6 | a[4] << 10;}
	
	bool insert(int x) {
		per(i, 4, 0) if(x >> i & 1) {
			if(a[i]) x ^= a[i];
			else {
				a[i] = x;
				per(j, i - 1, 0) if(a[i] >> j & 1) a[i] ^= a[j];
				rep(j, i + 1, 4) if(a[j] >> i & 1) a[j] ^= a[i];
				return true;
			}
		}
		return false;
	}
} mask[N];

int cnt, idx[N], rex[N], trans[M][M];

void find(node p) {
	int x = p.hash();
	if(! idx[x]) rex[idx[x] = ++ cnt] = x; else return;
	rep(i, 1, 31) {node q = p; if(q.insert(i)) find(q);}
}

void prework() {
	node sta; find(sta);
	rep(i, 1, cnt) {
		node u; u.init(rex[i]);
		rep(j, 1, cnt) {
			node v; v.init(rex[j]);
			bool valid = true;
			rep(k, 0, 4) if(u.a[k] && ! v.insert(u.a[k])) {valid = false; break;}
			if(valid) trans[i][j] = idx[v.hash()];
		}
	}
}

int tot, bel[N], root[N], len[N]; bool cir[N], invalid[N];
int tim, val[N], dfn[N];

void dfs(int u, int fa, int tp) {
	
	// cerr << "edge " << u << ' ' << fa << endl;
	
	bel[u] = tp;
	dfn[u] = ++ tim;
	for(auto e : g[u]) {
		int v = e.fi, w = e.se;
		if(v == 1 || v == fa) continue;
		if(! bel[v]) val[v] = val[u] ^ w, dfs(v, u, tp);
		else {
			// cerr << u << ' ' << v << ' ' << (val[u] ^ val[v] ^ w) << endl;
			if(dfn[v] < dfn[u] && ! mask[tp].insert(val[u] ^ val[v] ^ w)) invalid[tp] = true;
		}
	}
}

int f[M], h[M];

int main() {
	prework(), n = read(), m = read();
	rep(i, 1, m) {
		int u = read(), v = read(), w = read();
		g[u].eb(mp(v, w));
		g[v].eb(mp(u, w));
	}
	for(auto e : g[1]) {
		int u = e.fi, w = e.se;
		if(! bel[u]) root[++ tot] = u, len[tot] = w, dfs(u, 1, tot);
		else {
			int p = bel[u], v = root[p];
			len[p] ^= w, cir[p] = true;
			for(auto e : g[u]) if(e.fi == v) {len[p] ^= e.se; break;}
		}
	}
	
	f[1] = 1;
	rep(i, 1, tot) if(! invalid[i]) {
		
		// cerr << i << ' ' << cir[i] << ' ' << len[i] << endl;
		
		rep(j, 1, cnt) h[j] = f[j];
		if(! cir[i]) {
			int k = idx[mask[i].hash()];
			rep(j, 1, cnt) if(trans[j][k]) add(f[trans[j][k]], h[j]);
		}
		else {
			int k = idx[mask[i].hash()];
			node tmp = mask[i]; bool valid = tmp.insert(len[i]);
			int l = idx[tmp.hash()];
			rep(j, 1, cnt) {
				if(trans[j][k]) add(f[trans[j][k]], 2ll * h[j] % P);
				if(valid && trans[j][l]) add(f[trans[j][l]], h[j]);
			}
		}
	}
	int ans = 0;
	rep(i, 1, cnt) add(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
