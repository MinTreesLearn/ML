// 失ったものなんて数えなくていいよ
// ボクは理由無しに生まれたノンタイトル

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Pragmas
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// Namespaces
#define It		using
#define has		namespace
#define to		std;
#define be		using
#define this	namespace
#define way		__gnu_pbds

It has to be this way;

// Data types
using i8	= __int128;
using ll	= long long;
using si	= short int;
using ld	= long double;

// Pairs
using pi8	= pair<i8, i8>;
using pll	= pair<ll, ll>;
using pii	= pair<int, int>;
using psi	= pair<si, si>;
using pld	= pair<ld, ld>;
#define fi	first
#define se	second

// PBDS
template<typename T>
using ordered_set	= tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Quick macro functions
#define sqr(x)			((x)*(x))
#define pow2(x)			(1ll << (x))
#define debug(x)		cout << #x << " = " << (x) << '\n'
#define debugV(x, a)	cout << #x << "[" << (a) << "] = " << (x[a]) << '\n'

#define MultipleTestcases	int _tc; cin >> _tc; for (int _cur_tc = 1; _cur_tc <= _tc; _cur_tc++)

// Check min and max
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
 
// Modular arithmetic
template<typename T> void maddto(T &a, T b, T mod) {a += b; a %= mod;}
template<typename T> void msubto(T &a, T b, T mod) {a -= b; while (a < 0) a += mod; a %= mod;}
template<typename T> void mmulto(T &a, T b, T mod) {a *= b; a %= mod;}
 
template<typename T> T madd(T a, T b, T mod) {a += b; a %= mod; return a;}
template<typename T> T msub(T a, T b, T mod) {a -= b; while (a < 0) a += mod; return a;}
template<typename T> T mmul(T a, T b, T mod) {a *= b; a %= mod; return a;}

template<typename T> T modexp(T x, T y, T mod) {
	if (!x) return 0; if (!y) return 1;
	T t = modexp<T>(x, y >> 1, mod);
	return mmul<T>(t, mmul<T>(t, (y & 1) ? x : 1, mod), mod);
}

// Constants
const ll ModA	= 998244353;
const ll ModC	= 1e9 + 7;
const ll INF	= 1e18;
const ll iINF	= 1e9;
const ld EPS	= 1e-9;
const ld iEPS	= 1e-6;

const int maxN	= 5005;

ll n, m, s[maxN];
ll fav[maxN], hunger[maxN];

ll cow[maxN][maxN]; // prefix per favorite grass

ll cnt[2][maxN]; // count of left and right grass
ll sleepingCows[maxN], ways[maxN]; // per separator

ll getCow(ll type, ll l, ll r) {
	if (l > r) return 0;
	return cow[type][r] - cow[type][l-1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> s[i];
		cnt[1][s[i]]++;
	}
	for (ll i = 1; i <= m; i++) {
		cin >> fav[i] >> hunger[i];
		cow[fav[i]][hunger[i]]++;
	}

	// compute prefix cow
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			cow[i][j] += cow[i][j-1];
			// cout << cow[i][j] << ' ';
		}
		// cout << '\n';
	}

	// brute force all possible separators
	// [1..sep-1] left, [sep..n] right
	for (ll sep = 1; sep <= n; sep++) {
		// for (ll grass = 1; grass <= n; grass++) {cout << cnt[0][grass] << ' ';} cout << '\n';
		// for (ll grass = 1; grass <= n; grass++) {cout << cnt[1][grass] << ' ';} cout << '\n';
		// cout << '\n';

		// to not double count, only count if there is going to be a sleeping cow from the right here
		ll curGrass = s[sep];
		if (getCow(curGrass, cnt[1][curGrass], cnt[1][curGrass]) != 1) {
			sleepingCows[sep] = -1;
			cnt[0][s[sep]]++;
			cnt[1][s[sep]]--;
			continue;
		}

		ll leftSepGrass = getCow(curGrass, 1, cnt[0][curGrass]);
		if (cnt[0][curGrass] >= cnt[1][curGrass]) leftSepGrass--;
		if (leftSepGrass > 0) {
			ways[sep] = leftSepGrass;
			sleepingCows[sep] = 2;
		} else {
			ways[sep] = 1;
			sleepingCows[sep] = 1;
		}

		// debug(sep);
		// debugV(ways, sep);
		// debugV(sleepingCows, sep);

		for (ll grass = 1; grass <= n; grass++) {
			if (grass == curGrass) continue;

			ll L = getCow(grass, 1, cnt[0][grass]);
			ll R = getCow(grass, 1, cnt[1][grass]);

			ll twoCowPairs = L * R - min(L, R);
			ll oneCow = L + R;

			if (twoCowPairs > 0) {
				sleepingCows[sep] += 2;
				mmulto(ways[sep], twoCowPairs, ModC);
			} else if (oneCow > 0) {
				sleepingCows[sep] += 1;
				mmulto(ways[sep], oneCow, ModC);
			}
		}

		cnt[0][s[sep]]++;
		cnt[1][s[sep]]--;
	}

	// extra case: all cows come from the left
	ways[n+1] = 1;
	for (ll grass = 1; grass <= n; grass++) {
		ll L = getCow(grass, 1, cnt[0][grass]);

		if (L > 0) {
			sleepingCows[n+1]++;
			mmulto(ways[n+1], L, ModC);
		}
	}

	ll maxSleep = -1, maxWays = 0;
	for (ll i = 1; i <= n+1; i++) {
		if (sleepingCows[i] > maxSleep) {
			maxSleep = sleepingCows[i];
			maxWays = 0;
		}
		if (sleepingCows[i] == maxSleep) {
			maddto(maxWays, ways[i], ModC);
		}
	}
	cout << maxSleep << ' ' << maxWays << '\n';
}
 	 	    	 	 	 	 	 				 	 	 	 		