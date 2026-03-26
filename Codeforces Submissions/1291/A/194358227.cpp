#include <iostream>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef string s;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvld;
typedef vector<vector<vector<ll>>> vvvll;
typedef vector<string> vstr;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define textfile    freopen("input.txt" , "r" , stdin); freopen("output.txt" , "w" , stdout);
#define pb push_back
#define nl "\n"
#define all(c) (c).begin(), (c).end()
#define iotam1 cout << -1 << nl
#define cty cout << "YES" << nl
#define ctn cout << "NO" << nl
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define sz(v) (v).size()
#define prec(n) fixed << setprecision(n)
#define c(x) cout << (x)
#define csp(x) cout << (x) << " ";
#define c1(x) cout << (x) << nl;
#define c2(x, y) cout << (x) << " " << (y) << nl;
#define c3(x, y, z) cout << (x) << " " << (y) << " " << (z) << nl;
#define c4(a, b, c, d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << nl;
#define c5(a, b, c, d, e) cout << (a) << " " << (b) << " " << (c) << " " << (d) << " " << (e) << nl;
#define c6(a, b, c, d, e, f) cout << (a) << " " << (b) << " " << (c) << " " << (d) << " " << (e) << " " << (f) << nl;
#define f(i, a, n) for (ll i = a; i < n; i++)
#define rf(i, n, a) for (ll i = n; i > a; i--)
#define fi first
#define se second
#define print(vec, a, b) for (ll i = a; i < b; i++) cout << vec[i] << " "; cout << nl;
#define input(vec, a, b)  for (ll i = a; i < b; i++) cin >> vec[i];
#define ms(a, val) memset(a, val, sizeof(a))
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
ll pct(ll x) { return __builtin_popcount(x); } // #of set bits
ll modI(ll a, ll m = mod)
{
    ll m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

ll powm(ll a, ll b, ll m = mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll __lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
ll __lcm(vector<ll> &arr) { ll res = arr[0]; for (ll i = 1; i < arr.size(); i++) res = __lcm(res, arr[i]); return res; }
ll __gcd(ll a, ll b) { if (b == 0) return a; return __gcd(b, a % b); }
ll __gcd(vector<ll> &arr) { ll res = arr[0]; for (ll i = 1; i < arr.size(); i++) res = __gcd(res, arr[i]); return res; }
ll __gcd(ll a, ll b, ll c) { return __gcd(__gcd(a, b), c); }
ll __lcm(ll a, ll b, ll c) { return __lcm(__lcm(a, b), c); }
ll pow(ll a, ll b) { ll res = 1; while (b) { if (b & 1) res = (res * a); a = (a * a); b >>= 1; } return res; }
ll pow(ll a, ll b, ll m) { ll res = 1; while (b) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
ll modInv(ll a, ll m = mod) { return pow(a, m - 2, m); }
ll fact(ll n) { ll res = 1; for (ll i = 1; i <= n; i++) res = (res * i) % mod; return res; }
vector<ll> sieve(ll n) { bool prime[n + 1]; memset(prime, true, sizeof(prime)); for (ll p = 2; p * p <= n; p++) { if (prime[p] == true) { for (ll i = p * p; i <= n; i += p) prime[i] = false; } } vector<ll> v; for (ll i = 2; i <= n; i++) { if (prime[i]) v.pb(i); } return v; }
ll dijkstra(vector<vector<pair<ll, ll>>> &adj, ll src, ll dest) { vector<ll> dist(adj.size(), 1e18); dist[src] = 0; priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; pq.push({0, src}); while (!pq.empty()) { ll u = pq.top().se; ll d = pq.top().fi; pq.pop(); if (d > dist[u]) continue; for (auto v : adj[u]) { if (dist[u] + v.se < dist[v.fi]) { dist[v.fi] = dist[u] + v.se; pq.push({dist[v.fi], v.fi}); } } } return dist[dest]; }
ll nCr(ll n, ll r) { if (r > n) return 0; if (r > n - r) r = n - r; ll ans = 1; for (ll i = 0; i < r; i++) { ans *= (n - i); ans /= (i + 1); } return ans; }



void func()
{
   s s1;
   ll res=1,t1,oc=0,ec=0,n;
   cin >> n;
   cin >> s1;
   
   ll a[n];
   f(i,0,n) {
       t1=(int(s1[i])-'0');
       if (t1%2==0) {
           a[i]=0;
           ec++;
       } else {
           a[i]=1;
           oc++;
       }
   }
   
   if (oc==0 || oc==1 || (oc==1 && a[0]==1)) {
       c1(-1);
   } else {
       ll count=0;
       f(i,0,n) {
           if (count==2) {
               break;
           } 
           
           if (a[i]==1) {
               c(s1[i]);
               count++;
           }
       } c(nl);
   }
}
int main(){
fast;

    ll t;
    cin >> t;

    while (t--)
    {
        func();
    }


    return 0;
}