#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
#define ll long long
#define ld long double
#define sz(x) ((int)(x).size())
#define all(x) 	(x).begin(), (x).end()
#define pb push_back
#define mpp make_pair
#define ve vector
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll inf = 1e18; const int iinf = 1e9;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T> inline bool chmin(T& a, T b) { return (a > b ? a = b, 1 : 0); }
template <typename T> inline bool chmax(T& a, T b) { return (a < b ? a = b, 1 : 0); }

const int N = 2e4 + 100;

int a[N];

int t[4 * N], p[4 * N];
inline void build(int v, int vl, int vr) {
	p[v] = 0;
	if (vl == vr) return void(t[v] = a[vl]);
	int m = vl + vr >> 1;
	build(2 * v + 1, vl, m);
	build(2 * v + 2, m + 1, vr);
	t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}
inline void push(int v) {
	if (!p[v]) return;
	p[2 * v + 1] += p[v], p[2 * v + 2] += p[v];
	t[2 * v + 1] += p[v], t[2 * v + 2] += p[v];
	p[v] = 0;
}
inline void upd(int v, int vl, int vr, int l, int r, int x) {
	if (l > r) return;
	else if (vl == l && vr == r) {
		t[v] += x, p[v] += x;
		return;
	}
	push(v);
	int m = vl + vr >> 1;
	upd(2 * v + 1, vl, m, l, min(r, m), x);
	upd(2 * v + 2, m + 1, vr, max(l, m + 1), r, x);
	t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}
inline int gt(int v, int vl, int vr, int l, int r) {
	if (l > r) return -iinf;
	else if (vl == l && vr == r) return t[v];
	push(v);
	int m = vl + vr >> 1;
	return max(gt(2 * v + 1, vl, m, l, min(r, m)),
				gt(2 * v + 2, m + 1, vr, max(l, m + 1), r));
}

inline void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	ve<ve<int>> ar(n, ve<int> (m));
	for (auto &i : ar) for (auto &j : i) cin >> j;

	ve<ve<int>> pf(n, ve<int> (m));
	for (int i = 0; i < n; ++i) {
		pf[i] = ar[i];
		for (int j = 1; j < m; ++j) pf[i][j] += pf[i][j - 1];
	}
	auto get = [&](int i, int l, int r) { return pf[i][r] - (!l ? 0 : pf[i][l - 1]); };
	auto cost = [&](int i, int j) {
		int res = 0;
		res += get(i, j, j + k - 1);
		if (i + 1 < n) res += get(i + 1, j, j + k - 1);
		return res;
	};

	int s = m - k + 1;

	ve<ve<int>> dp(n, ve<int> (m));
	for (int i = 0; i < s; ++i) dp[0][i] = cost(0, i);

	for (int z = 1; z < n; ++z) {
		for (int i = 0; i < s; ++i) {
			int value = 0;
			value += dp[z - 1][i];
			
			int L = max(0, i), R = min(k - 1, i + k - 1);
			if (L <= R) value -= get(z, L, R);

			a[i] = value;
		}
		build(0, 0, s - 1);

		for (int ps = 0; ps < s; ++ps) {
			dp[z][ps] = cost(z, ps) + t[0];
			upd(0, 0, s - 1, max(ps - k + 1, 0), ps, +ar[z][ps]);
			if (ps + k < m) upd(0, 0, s - 1, ps + 1, min(s - 1, ps + k), -ar[z][ps + k]);

/*
			for (int p = 0; p < s; ++p) {
				int L = max(ps, p);
				int R = min(ps + k - 1, p + k - 1);

				int sum = (L > R ? 0 : get(z, L, R));
				chmax(dp[z][ps], cost(z, ps) - sum + dp[z - 1][p]);
			}
*/
		}
	}
	cout << *max_element(all(dp[n - 1]));
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q = 1; // cin >> q;
	while (q--) solve();
	cerr << fixed << setprecision(3) << "Time execution: " << (double)clock() / CLOCKS_PER_SEC << endl;
}
