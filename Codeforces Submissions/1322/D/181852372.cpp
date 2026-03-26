#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 5010;
const int inf = 1e9 + 10;
int n, m, a[N], s[N], c[N], f[N][N], g[N];

void cmax(int &x, int y) {x = x > y ? x : y;}

int main() {
	n = read(), m = read() + (g[0] = n);
	rep(i, 1, n) a[i] = read(), g[i] = g[i - 1] >> 1;
	rep(i, 1, n) s[i] = read();
	rep(i, 1, m) {c[i] = read(); rep(j, 1, n) f[i][j] = -inf;}
	per(i, n, 1) {
		int v = a[i];
		per(j, n, 1) cmax(f[v][j], f[v][j - 1] + c[v] - s[i]);
		rep(j, v, m) rep(k, 0, g[j - v])
			cmax(f[j + 1][k >> 1], f[j][k] + c[j + 1] * (k >> 1));
	}
	printf("%d\n", f[m + 1][0]);
	return 0;
}
