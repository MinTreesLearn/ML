#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <atcoder/all>
// using namespace atcoder;
using namespace __gnu_pbds;
using namespace std;
using uns = unsigned;
using ll = long long;
using ld = long double;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using vc = std::vector<char>;
using vvc = std::vector<vc>;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using vld = std::vector<ld>;
using vvld = std::vector<vld>;
using vvvld = std::vector<vvld>;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;
using vu = std::vector<uns>;
using vs = std::vector<std::string>;
using ordered_set = tree<pll, null_type, std::less<pll>, rb_tree_tag, tree_order_statistics_node_update>;

#define siz(x) (ll) x.size()
#define all(v) (v).begin(), (v).end()

#ifdef DEBUG
#include "dbg.hpp"
#else
#define err(...)
#define deb(...)
#endif

const ll mod = 1e9+7;
//using mint = modint998244353;
const ll maxN = 1e5+5;
void run_brute(){
    //cout<<"\n................\n";
}
template<class T> inline T POW(T a,ll n){
    T r=1;
    for (; n>0; n>>=1,a*=a){
         if (n&1)r*=a;
    } 
    return r;
}
inline ll POW(int a,ll n){ return POW((ll)a,n); }

template<class T> vector<T> powers(T m,ll n){
	vector<T> ret(n+1,1);
	for (ll i=1;i<=n;++i) ret[i]=ret[i-1]*m;
	return ret;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= (int)mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += (int)mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}
 
ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint ncr(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint npr(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
void solve()
{   
   ll n,m;
   cin>>n>>m;
   
   // cnt1+cnt2+..cntn = 2*m
   // 2*m stars, n-1bars
   // ncr(n+2*m-1,n-1) or ncr(n+2*m-1,2m)

  cout<<ncr(n+2*m-1,2*m)<<"\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;

    //cout << fixed << setprecision(20);
    //cin >> t;
    init_f();
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
       // run_brute();
    }
    return 0;
}