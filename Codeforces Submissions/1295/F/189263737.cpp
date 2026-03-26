#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define inf 1e9
#define pii pair <int, int>
const int mod = 998244353;
inline int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') f = ((ch == '-') ? -1 : f), ch = getchar ();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar ();
	return x * f;
}
inline void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
inline int quickmod (int x, int y) {
	int Ans = 1;
	while (y) {
		if (y & 1) Ans = (1ll * Ans * x) % mod;
		x = (1ll * x * x) % mod;
		y >>= 1;
	}
	return Ans;
}
inline void Add(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}
int n, all = 1;
struct st {
	int l, r;
}a[505];
vector <int> G;
int f[505][505], sp[505], invsp[505];
inline int C(int x, int y) {
	if(x < y || y < 0) return 0;
	int ans1 = 1, ans2 = 1;
	for(int i = x - y + 1; i <= x; i++) ans1 = ans1 * i % mod;
	for(int i = 1; i <= y; i++) ans2 = ans2 * i % mod;
	return ans1 * quickmod(ans2, mod - 2) % mod;
}
signed main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i].l = read(), a[i].r = read();
		swap(a[i].l, a[i].r);
		a[i].l = mod - 2 - a[i].l, a[i].r = mod - 2 - a[i].r;
		G.push_back(a[i].l), G.push_back(a[i].r + 1);
		all = all * (a[i].r - a[i].l + 1) % mod;
	}
//	sp[0] = invsp[0] = 1;
//	for(int i = 1; i <= n; i++) sp[i] = sp[i-1] * quickmod(a[i].r - a[i].l + 1, mod - 2) % mod, invsp[i] = invsp[i-1] * (a[i].r - a[i].l + 1) % mod;
	sort(G.begin(), G.end());
	G.erase(unique(G.begin(), G.end()), G.end());
	int N = (int)G.size();
	G.push_back(G.back() + 1);
	for(int i = 1; i <= n; i++) {
		a[i].l = lower_bound(G.begin(), G.end(), a[i].l) - G.begin() + 1;
		a[i].r = lower_bound(G.begin(), G.end(), a[i].r + 1) - G.begin() + 1;
//		printf("{%lld %lld %lld}\n", a[i].l, a[i].r, G[1] - G[0]);
	}
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = a[i].l; j < a[i].r; j++) {
			for(int k = i - 1; k >= 0; k--) {//[k + 1, i]
				if(j < a[k+1].l || j >= a[k+1].r) break;
				int s = 0;
				for(int j2 = 0; j2 < j; j2++) Add(s, f[k][j2]);
//				if(!(j2 == 0 && j == 1 && k == 0)) continue;
				int len = i - k;
				Add(f[i][j], s * C(G[j] - G[j-1] + len - 1, len) % mod);
			}
		}
	}
	int Ans = 0;
	for(int i = 1; i <= N; i++) Add(Ans, f[n][i]);
	write(Ans * quickmod(all, mod - 2) % mod), putchar('\n');
	return 0;
}
/*
*/