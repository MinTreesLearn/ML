#include <bits/stdc++.h>

#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; ++i)
#define rFor(i, b, a) for (int i = b, i##end = a; i >= i##end; --i)
#define eFor(i, u, v) for (int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)

typedef long long ll;

using std::cin;
using std::cout;
using std::endl;

typedef std::pair<int, int> pii;
#define fi first
#define se second

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

template<typename T> T myrand(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rnd);
}

void close_stdio() {
	std::ios::sync_with_stdio(false);
	std::cerr << "DO NOT use scanf/printf!\n";
}

const int kN = 85;
const int kK = 15;

int n, k, e[kN][kN], d[kN][kK], c[kN];

int main() {
	scanf("%d%d", &n, &k);
	For(i, 1, n) For(j, 1, n) scanf("%d", &e[i][j]);
	int T = 5000, ans = 0x3f3f3f3f;
	while (T--) {
		memset(d, 0x3f, sizeof(d));
		For(i, 1, n) c[i] = myrand(0, 1);
		d[1][0] = 0;
		For(i, 0, k - 1) For(u, 1, n) if (d[u][i] < 0x3f3f3f3f) {
			For(v, 1, n) if (c[u] != c[v]) 
				d[v][i + 1] = std::min(d[v][i + 1], d[u][i] + e[u][v]);
		}
		ans = std::min(ans, d[1][k]);
	}
	printf("%d", ans);
	return 0;
}
/* PAY ATTENTION TO: */
/* 1. Memory Limit, Array Size */
/* 2. Integer Overflow */
/* 3. Multi-test */
/* 4. Potential Constant-speedup */
/* Stay organized and write things down. */
