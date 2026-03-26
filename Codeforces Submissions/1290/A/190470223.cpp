#include "bits/stdc++.h"
using namespace std;

// #define ORD_SET
// #define ROPE
#ifdef ORD_SET
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    template<typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#endif
#ifdef ROPE
    #include <ext/rope>
    using namespace __gnu_cxx;
#endif        

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

using ll = long long;
using ld = long double;
#define pb push_back
#define ff first
#define ss second
#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define ll int
void freopen(string s) { freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout); }
void NotInteractive() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
void pre(ll a) { cout<<fixed<<setprecision(a); }
ll bit(ll x) { return __builtin_popcountll(x); }
ll binpow(ll x, ll y, ll z) { ll pow = 1; while(y) { if(y&1) pow *= x, pow %= z; x *= x, x %= z; y >>= 1; } return pow; }
template<typename T> T gcd(T a, T b) { if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b) { return a/gcd(a, b)*b; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct sn { ll l, r, x; }; // a.swap(b)
ll B = 316;
const ll mod = (ll)1e9+7;
const ll inf = (ll)1e18+7;
const ll MX = LLONG_MAX;
const ll MN = LLONG_MIN;
const ld P = acos(-1.0);
const ll N = (ll)3e5+5;
ll a[N];

void kigash() {
    ll n, m, k;
    cin>>n>>m>>k;
    for(ll i=1; i<=n; i++) cin>>a[i];
    k = min(k, m-1);
    ll d = m-1-k, ans = MN;
    for(ll j=0; j<=k; j++) {
        ll mn = MX;
        for(ll i=0; i<=d; i++) mn = min(mn, max(a[j+i+1], a[j+i+1+n-m]));
        ans = max(ans, mn);
    }
    cout<<ans<<"\n";
    return;
}

signed main(/**/) {
    // freopen("");
    NotInteractive();
    // precalc();
    
    ll tt = 1;
    cin>>tt;
    for(ll i=1; i<=tt; i++) kigash();
    
    exit(0);
}