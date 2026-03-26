#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, i, ans = 1e18, a[1200001], p[1200001], pr[1200001], pos[1200001], t[1200001], d[1200001];

void push(int v) {
	if (!d[v]) return;
	t[v + v] += d[v];
	t[v + v + 1] += d[v];
	d[v + v] += d[v];
	d[v + v + 1] += d[v];
	d[v] = 0;
}
 
void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = pr[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
	t[v] = min(t[v + v], t[v + v + 1]);
}
 
void update(int v, int tl, int tr, int l, int r, int x) {
	if (l > r) return;
	if (l == tl && tr == r) {
		t[v] += x;
		d[v] += x;
		push(v);
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	update(v + v, tl, tm, l, min(r, tm), x);
	update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, x);
	t[v] = min(t[v + v], t[v + v + 1]);
}
 
int get(int v, int tl, int tr, int l, int r) {
	if (l > r) return 1e18;
	push(v);
	if (l == tl && tr == r) return t[v];
	int tm = (tl + tr) / 2;
	return min(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n;
	for (i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		pr[i] = pr[i - 1] + a[i];
	}
	build(1, 1, n);
	ans = min(ans, get(1, 1, n, 1, n - 1));
	for (i = 1; i <= n; i++) {
		update(1, 1, n, pos[i], n, -a[pos[i]]);
		update(1, 1, n, 1, pos[i] - 1, a[pos[i]]);
		ans = min(ans, get(1, 1, n, 1, n - 1));
		//cout << ans << " ";
	}
	cout << ans;
}