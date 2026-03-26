#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1005, M = 1000005;

int n, m, cnt, lcp[N][N];
ll k, f[N][N], g[N][N];
char s[N];
struct str {int l, r;} a[M];
bool operator< (const str &x, const str &y) {
	int l1 = x.l, r1 = x.r, l2 = y.l, r2 = y.r;
	int lp = lcp[l1][l2], len = min(r1 - l1, r2 - l2) + 1;
	if (lp >= len) return r1 - l1 < r2 - l2;
	return s[l1 + lp] < s[l2 + lp];
}
bool check(int mid) {
	memset(f, 0, sizeof f);
	memset(g, 0, sizeof g);
	for (int i = 0; i <= n + 1; i++) g[i][0] = 1;
	int len = a[mid].r - a[mid].l + 1;
	for (int j = 1; j <= m; j++) {
		for (int i = n; i >= 1; i--) {
			int lp = lcp[i][a[mid].l];
			// 要比 mid 大 
			if (str{a[mid].l, a[mid].r} < str{i, n})
				f[i][j] = g[i + min(len, lp) + 1][j - 1];
			// i + min() + 1 是为了大于 
		}
		for (int i = n; i >= 1; i--) 
			g[i][j] = min(k, g[i + 1][j] + f[i][j]);
			// 防止爆 long long 
	}
	return f[1][m] >= k;
}
int main() {
	scanf("%d%d%lld%s", &n, &m, &k, s + 1);
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
			if (j >= i) a[++cnt] = {i, j};
		}
	}
	sort(a + 1, a + 1 + cnt);
	int l = 1, r = cnt, ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	// 因为算的是大于, 所以要加 1
	for (int i = a[ans + 1].l; i <= a[ans + 1].r; i++) printf("%c", s[i]);
	return 0;
}
	 		     	 	     			 	 		     	