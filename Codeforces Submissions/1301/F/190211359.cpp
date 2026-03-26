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

const pii di[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	ve<ve<int>> a(n, ve<int> (m));
	for (auto &i : a) for (auto &j : i) cin >> j, --j;

	auto valid = [&n,&m](const int &i, const int &j) {
		return i >= 0 && i < n && j >= 0 && j < m;
	};

	ve<ve<pii>> s(k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			s[a[i][j]].pb({i, j});
		}
	}

	queue<pii> q;
	ve<ve<ve<int>>> d(k, ve<ve<int>> (n, ve<int> (m, -1)));

	for (int z = 0; z < k; ++z) {
		for (auto &[i, j] : s[z]) {
			d[z][i][j] = 1;
			q.push({i, j});
		}

		ve<bool> us(k);

		while (sz(q)) {
			auto [x, y] = q.front();
			q.pop();

			int cl = a[x][y];

			if (!us[cl]) {
				us[cl] = 1;
				for (auto &[i, j] : s[cl]) {
					if (!~d[z][i][j]) {
						d[z][i][j] = d[z][x][y] + 1;
						q.push({i, j});
					}
				}
			}

			for (auto &[dx, dy] : di) {
				int xx = x + dx, yy = y + dy;
				if (!valid(xx, yy) || d[z][xx][yy] != -1) continue;

				d[z][xx][yy] = d[z][x][y] + 1;
				q.push({xx, yy});
			}
		}
	}

/*
	for (int z : {0, 3}) {
		cout << z << ":" << '\n';
		for (auto &vec : d[z]) {
			for (auto &x : vec) cout << x << " ";
			cout << '\n';
		}
		cout << '\n';
	}
*/

	int Q;
	cin >> Q;
	while (Q--) {
		int aa, b, c, dd;
		cin >> aa >> b >> c >> dd;

		--aa, --b, --c, --dd;

		int ans = abs(aa - c) + abs(b - dd);
		if (a[aa][b] == a[c][dd]) chmin(ans, 1);

		for (int z = 0; z < k; ++z) chmin(ans, d[z][aa][b] + d[z][c][dd] - 1);

		cout << ans << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q = 1; // cin >> q;
	while (q--) solve();
	cerr << fixed << setprecision(3) << "Time execution: " << (double)clock() / CLOCKS_PER_SEC << endl;
}
