// <-- Code By: Ashu Mittal -->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T> >;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ff first
#define ss second
#define ll long long
#define all(sss) (sss).begin(),(sss).end()
#define pb push_back
#define pob pop_back
#define endl "\n"
#define input(ass) for(auto &x:(ass)) cin>>x;
#define iendl "\n", cout<<flush

const int mod = 1000000007;
// const int mod = 998244353;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(x)
#endif

// help
ll LCM(ll aaa, ll bbb) {return (aaa / __gcd(aaa, bbb)) * bbb;}
ll power(ll aaa, ll bbb) {ll ans = 1; while (bbb) {if (bbb & 1) ans = (ans * aaa); bbb >>= 1; aaa = (aaa * aaa);} return ans;}
ll mod_inv(ll a) {return power(a, mod - 2);}

/*----------------------------------x x x---------------------------------*/

void solve() {
	ll n;
	cin >> n;

	std::vector<ll> co(n);
	for (auto &x : co) {
		cin >> x;
		if (x == 0) x = -1;
	}

	std::vector<vector<ll>> v(n);
	for (int i = 0; i < n - 1; i++) {
		ll a, b; cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}

	std::vector<ll> dp(n, 0);
	function<void(ll, ll)> dfs = [&](ll i, ll p) {
		dp[i] += co[i];
		for (auto &x : v[i]) {
			if (x == p) continue;
			dfs(x, i);
			dp[i] += max(0ll, dp[x]);
		}
	};
	dfs(0, -1);
	dbg(dp)

	function<void(ll, ll)> dfs1 = [&](ll i, ll p) {
		for (auto &x : v[i]) {
			if (x == p) continue;
			ll val = (dp[x] < 0) ? 0 : dp[x];
			dp[x] += max(0ll, dp[i] - val);
			dfs1(x, i);
		}
	};
	dfs1(0, -1);

	for (auto &x : dp) cout << x << ' ';
	cout << endl;

}

/*

*/

int32_t main() {

	ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif

	ll TT = 1;
	// cin >> TT;
	for (ll TEST = 1; TEST <= TT; TEST++) {
		// cout<<"Case #"<<TEST<<": ";
		solve();
	}
}