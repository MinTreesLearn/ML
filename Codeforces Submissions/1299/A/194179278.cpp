#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//#pragma GCC optimization("g", on)
//#pragma GCC optimization("03")
////#pragma comment(linker, "/stack:200000000")
////#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse,-fgcse-lm")
//#pragma GCC optimize("-ftree-pre,-ftree-vrp")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("Ofast,no-stack-protector")
////#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")

//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define aboba ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define br break;
#define sp " "
#define en "\n"
#define pb push_back
#define sz size()
#define bg begin()
#define ed end()
#define in insert
#define ss second
#define ff first
#define rbg rbegin()
#define setp(a) cout << fixed; cout << setprecision(a);
#define all(v) v.begin(), v.end()
#define emp empty()
 
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pll;
typedef double db;
typedef tree<
    long long,
    null_type,
    less_equal<long long>,
    rb_tree_tag,
    tree_order_statistics_node_update> orset;

void freopen(string s) { freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout); }
ll bp(ll x, ll y, ll z) { ll res = 1; while (y) { if (y & 1) { res = (res * x) % z; y--; } x = (x * x) % z; y >>= 1; } return res; }
// C(n, k) = ((fact[n] * bp(fact[k], mod - 2)) % mod * bp(fact[n - k], mod - 2)) % mod;
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
	
const ll N = 5e5 + 11;
const ll inf = 1e18 + 7;
ll tt = 1;
ll a[N], b[N];
ll cnt[40];

void solve() {
	ll n; cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	ll ans = -1, h = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < 30;j++) {
			if (a[i] & (1 << j)) cnt[j]++;
		}
	}
	for (int i = 1;i <= n;i++) {
		ll tm = 0;
		for (int j = 29;j >= 0;j--) {
			if (a[i] & (1 << j)) {
				if (cnt[j] == 1) {
					tm += (1 << j);
				}
			}
		}
		if (tm > ans) {
			ans = tm;
			h = i;
		}
	}
	cout << a[h] << sp;
	for (int i = 1;i <= n;i++) {
		if (h == i) continue;
		cout << a[i] << sp;
	}
}

int main() {    
    aboba  
//    freopen("B");
//    cin >> tt;
//    precalc();
    for (int i = 1;i <= tt;i++) {
        solve();
    }
}