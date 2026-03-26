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

mt19937 myrand(19260817);

const int N = 85;
const int inf = 1e9 + 10;
int n, k, a[N], v[N][N], f[15][N];

int main() {
	n = read(), k = read();
	rep(i, 1, n) rep(j, 1, n) v[i][j] = read();
	rep(i, 1, n >> 1) a[i] = 1;
	
	int t = 2000, ans = inf;
	while(t --) {
		shuffle(a + 1, a + n + 1, myrand);
		rep(i, 1, n) f[0][i] = inf;
		f[0][1] = 0;
		rep(j, 0, k - 1) {
			rep(i, 1, n) f[j + 1][i] = inf;
			rep(i, 1, n) if(f[j][i] != inf)
			rep(o, 1, n) if(a[i] ^ a[o]) f[j + 1][o] = min(f[j + 1][o], f[j][i] + v[i][o]);
		}
		ans = min(ans, f[k][1]);
	}
	
	printf("%d\n", ans);
	return 0;
}
