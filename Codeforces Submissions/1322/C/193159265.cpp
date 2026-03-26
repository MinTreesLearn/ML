#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("O2")
using namespace std;
// debug template
#ifdef POTATO
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
// convenient functions
inline void yes() { cout << "YES" << endl; return; }
inline void no() { cout << "NO" << endl; return; }
template <class T>
inline void out(T temp) { cout << temp << endl; return; }
// globals
#define int long long
mt19937_64 rng((int)chrono::duration_cast<chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
long long rnd(long long l, long long r) { // returns a random number in the range [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}
const int mxN = 5e5 + 1;
int hashval[mxN];
void init() {
	// initialize
	for (int i = 1; i < mxN; i++) {
		hashval[i] = rnd(1e18, 4e18);
	}
}
int gcd(int a, int b) {
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}
void solve(int &case_no) {
	// solve
	int n, m;
	cin >> n >> m;
	int c[n + 1];
	for (int i = 1; i <= n; i++) cin >> c[i];
	int val[n + 1];
	for (int i = 1; i <= n; i++) val[i] = 0;
	while (m--) {
		int u, v;
		cin >> u >> v;
		val[v] ^= hashval[u];
	}
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		if (!val[i]) continue;
		v.pb({val[i], c[i]});
	}
	sort(v.begin(), v.end());
	int ans = -1;
	int sum = 0;
	int prev = v[0].ff;
	for (pii &cur : v) {
		if (prev != cur.ff) {
			if (ans == -1) ans = sum;
			else ans = gcd(ans, sum);
			sum = 0;
			prev = cur.ff;
		}
		sum += cur.ss;
	}
	if (ans == -1) ans = sum;
	else ans = gcd(ans, sum);
	cout << ans << endl;
}
signed main() {
#ifdef POTATO
assert(freopen("input.txt", "r", stdin));
// assert(freopen("output.txt", "w", stdout));
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(NULL));
	init();
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) solve(i);
}
/*

*/