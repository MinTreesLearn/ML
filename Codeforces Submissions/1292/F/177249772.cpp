#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back

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

const int N = 65, M = 1 << 15;
int n, a[N], par[N], deg[N], mask[N], f[M], g[M][N], binom[N][N];
vector<int> con[N];

int find(int x) {return x == par[x] ? x : par[x] = find(par[x]);}

void fwt(int *f, int n) {
	for(int o = 2, k = 1; o <= (1 << n); o <<= 1, k <<= 1)
		for(int i = 0; i < (1 << n); i += o) rep(j, 0, k - 1) add(f[i + j + k], f[i + j]);
}

int main() {
	n = read();
	rep(i, 1, n) a[i] = read(), par[i] = i;
	sort(a + 1, a + n + 1);
	rep(i, 1, n) rep(j, i + 1, n) if(a[j] % a[i] == 0) par[find(j)] = find(i), deg[j] ++;
	rep(i, 1, n) con[find(i)].eb(i);
	
	binom[0][0] = 1;
	rep(i, 1, n) {
		binom[i][0] = binom[i][i] = 1;
		rep(j, 1, i - 1) binom[i][j] = plu(binom[i - 1][j], binom[i - 1][j - 1]);
	}
	
	int ans = 1, sum = 0;
	rep(i, 1, n) if(con[i].size() > 1) {
		vector<int> s, t; int cnt = 0;
		for(int o : con[i]) if(! deg[o]) s.eb(o); else cnt ++, t.eb(o);
		int len = s.size();
		
		rep(x, 0, (1 << len) - 1) {f[x] = 0; rep(y, 0, cnt) g[x][y] = 0;}
		
		for(int o : t) {
			rep(p, 0, len - 1) if(a[o] % a[s[p]] == 0) mask[o] |= (1 << p);
			f[mask[o]] ++;
		}
		
		fwt(f, len);
		
		g[0][0] = 1;
		rep(x, 0, (1 << len) - 1) rep(y, 0, cnt) if(g[x][y]) {
			if(f[x] > y) add(g[x][y + 1], 1ll * g[x][y] * (f[x] - y) % P);
			for(int o : t) if((mask[o] & x) != mask[o] && (x == 0 || (mask[o] & x)))
				add(g[x | mask[o]][y + 1], g[x][y]);
				
			// cerr << x << ' ' << y << ' ' << g[x][y] << endl;
		}
		
		ans = 1ll * ans * g[(1 << len) - 1][cnt] % P * binom[sum + cnt - 1][cnt - 1] % P;
		sum += cnt - 1;
	}
	
	printf("%d\n", ans);
	return 0;
}
