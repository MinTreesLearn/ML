#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ll long long
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define ff first
#define ss second
#define nl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
// find_by_order, order_of_key

#ifndef youknowwhoiam1
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//-----------------------------------------------------------------------------------------------------------------------------//

const ll MOD = LLONG_MAX;
const ll inf = LLONG_MAX;

ll add(ll x, ll y) {x += y; while (x >= MOD) x -= MOD; while (x < 0) x += MOD; return x;}
ll sub(ll x, ll y) {return add(x, -y);}
ll mul(ll x, ll y) {return (x * 1ll * y) % MOD;}
ll binpow(ll x, ll y) {ll z = 1; while (y) {if (y & 1) z = mul(z, x); x = mul(x, x); y >>= 1;} return z;}
ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

//-----------------------------------------------------------------------------------------------------------------------------//

/*
*/

void solve() {

	ll i, j;

	string s;
	cin >> s;

	ll n = s.length();

	vector<vector<ll>> dp(n + 1, vector<ll>(26));

	for (i = 0; i < n; i++) {
		for (j = 0; j < 26; j++) {
			dp[i + 1][j] = dp[i][j] + (s[i] == char(j + 97));
		}
	}

	ll q;
	cin >> q;

	for (i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;

		if (r - l == 0) {cout << "Yes" << nl; continue;}

		ll id = s[r - 1] - 'a';

		if (s[l - 1] == s[r - 1]) {
			ll ctr = 0;
			for (j = 0; j < 26; j++) {
				if (dp[r][j] - dp[l - 1][j] > 0) {
					ctr++;
				}
			}
			if (ctr > 2) {cout << "Yes" << nl;}
			else {
				cout << "No" << nl;
			}
		} else {
			cout << "Yes" << nl;
		}
	}

}

int main() {

	NFS;
#ifndef youknowwhoiam1
	freopen("error.txt", "w", stderr);
#endif
	using namespace std::chrono;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	ll tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	std::cerr << setprecision(10) << fixed;
	std::cerr << "Time: " << time_span.count() << " seconds.";
	std::cerr << std::endl;

	return 0;
}