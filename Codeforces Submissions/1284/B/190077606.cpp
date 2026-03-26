#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, i, j, x, ans, t[8000321];
vector<int> g[123123], v;

void update(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		t[v]++;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm) update(v + v, tl, tm, pos);
	else update(v + v + 1, tm + 1, tr, pos);
	t[v] = t[v + v] + t[v + v + 1];
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l == tl && tr == r) return t[v];
	int tm = (tl + tr) / 2;
	return get(v + v, tl, tm, l, min(r, tm)) + get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> j;
		while (j--) {
			cin >> x;
			x++;
			g[i].push_back(x);
		}
		reverse(g[i].begin(), g[i].end());
		if (is_sorted(g[i].begin(), g[i].end())) {
			update(1, 1, 1e6 + 1, g[i].back());
		}
		reverse(g[i].begin(), g[i].end());
	}
	ans = n * n;
	for (i = 1; i <= n; i++) {
		reverse(g[i].begin(), g[i].end());
		if (is_sorted(g[i].begin(), g[i].end())) {
			ans -= get(1, 1, 1e6 + 1, 1, g[i][0]);
		}
		reverse(g[i].begin(), g[i].end());
	}
	cout << ans;
}