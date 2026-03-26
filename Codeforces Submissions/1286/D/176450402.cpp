#include<bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

const int P = 998244353;
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
int n, m, x[N], v[N], p[N];
bool valid[N][2][2];
struct node {int p, tx, ty; bool a, b;} q[N * 3];

struct Matrix {
	int mat[2][2];
	Matrix() {memset(mat, 0, sizeof(mat));}
} dat[N << 2];

Matrix calc(int p, Matrix a, Matrix b) {
	Matrix c;
	// cerr << valid[p][0][0] << ' ' << valid[p][0][1] << ' ' << valid[p][1][0] << ' ' << valid[p][1][1] << endl;
	rep(x, 0, 1) rep(y, 0, 1) if(valid[p][x][y])
	rep(l, 0, 1) rep(r, 0, 1) add(c.mat[l][r], 1ll * a.mat[l][x] * b.mat[y][r] % P);
	return c;
}

int cal(int x) {
	Matrix cur = dat[x];
	return plu(plu(cur.mat[0][0], cur.mat[0][1]), plu(cur.mat[1][0], cur.mat[1][1]));
}

void bui(int o, int l, int r) {
	if(l == r) return dat[o].mat[1][1] = p[l], dat[o].mat[0][0] = del(1, p[l]), void();
	int mid = (l + r) >> 1;
	bui(o << 1, l, mid), bui(o << 1 | 1, mid + 1, r);
	dat[o] = calc(mid, dat[o << 1], dat[o << 1 | 1]);
	// cerr << "bui " << o << ' ' << dat[o].mat[0][0] << ' ' << dat[o].mat[0][1] << ' ' 
	  	 				// 	   << dat[o].mat[1][0] << ' ' << dat[o].mat[1][1] << endl;
}

void moi(int p, int l, int r, int k) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(k <= mid) moi(p << 1, l, mid, k); else moi(p << 1 | 1, mid + 1, r, k);
	dat[p] = calc(mid, dat[p << 1], dat[p << 1 | 1]);
}

int main() {
	n = read();
	int inv = qpow(100, P - 2);
	rep(i, 1, n)
		x[i] = read(), v[i] = read(), p[i] = 1ll * read() * inv % P;
		// cerr << i << ' ' << p[i] << endl;
	rep(i, 1, n - 1) rep(a, 0, 1) rep(b, 0, 1) valid[i][a][b] = true;
	rep(i, 1, n - 1) {
		q[++ m] = (node) {i, x[i + 1] - x[i], v[i] + v[i + 1], 1, 0};
		if(v[i] > v[i + 1]) q[++ m] = (node) {i, x[i + 1] - x[i], v[i] - v[i + 1], 1, 1};
		if(v[i] < v[i + 1]) q[++ m] = (node) {i, x[i + 1] - x[i], v[i + 1] - v[i], 0, 0};
	}
	sort(q + 1, q + m + 1, [](node u, node v) {return 1ll * u.tx * v.ty < 1ll * v.tx * u.ty;});
	bui(1, 1, n);
	
	int ans = 0;
	rep(i, 1, m) {
		node cur = q[i]; bool pre[2][2];
		rep(a, 0, 1) rep(b, 0, 1) pre[a][b] = valid[cur.p][a][b];
		rep(a, 0, 1) rep(b, 0, 1) if(a != cur.a || b != cur.b) valid[cur.p][a][b] = false;
		valid[cur.p][cur.a][cur.b] = true;
		
		// cerr << cur.p << ' ' << cur.a << ' ' << cur.b << endl;
		
		moi(1, 1, n, cur.p);
		add(ans, 1ll * cur.tx * qpow(cur.ty, P - 2) % P * cal(1) % P);
		
		rep(a, 0, 1) rep(b, 0, 1) if(a != cur.a || b != cur.b) valid[cur.p][a][b] = pre[a][b];
		valid[cur.p][cur.a][cur.b] = false;
		
		moi(1, 1, n, cur.p);
	}
	
	printf("%d\n", ans);
	return 0;
}
