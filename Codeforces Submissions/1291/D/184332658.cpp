#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pr 101
#define M 1000000007
#define mod 998244353
#define MAX 20000000000
#define set_zero(a) memset(a,0,sizeof(a))
#define init_dp(a) memset(a,-1,sizeof(a))
#define trace(x) cerr<<#x<<" "<<x<<" "<<endl;
#define N 200005
#define pi 3.14
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll binpow(ll x, ll n){
	if (n == 0) return 1;
	long long u = binpow(x,n/2);
	u = (u*u);
	if (n%2 == 1) u = (u*x);
	return u;
}
ll modpow(ll x, ll n,ll p){
	if (n == 0) return 1;
	long long u = binpow(x,n/2) % p;
	u = (u*u); u %= p;
	if (n%2 == 1) u = (u*x) % p;
	return u % p;
}
string decToBinary(ll n, ll bit){
    string s;
    for (ll i = bit; i >= 0; i--) {
        ll k = n >> i;
        if (k & 1) s.push_back('1');
        else s.push_back('0');
    }
    return s;
}
bool is_prime(ll x){
    for(ll i = 2;i*i<=x;i++){
        if(x % i == 0) return false;
    }
    return true;
}
ll nextPrime(ll n){
    if (n <= 1) return 2;
    ll prime = n;
    bool found = false;
    while(!found){
        prime++;
        if(is_prime(prime)) found = true;
    }
    return prime;
}
vector<ll> Divisors(ll n){ 
    vector<ll> v,f;
    if(n == 1){
        return {1};
    }
    for(ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) f.push_back(i); 
            else { 
                f.push_back(i); 
                v.push_back(n / i); 
            } 
        } 
    } 
    for(ll i = v.size() - 1; i >= 0; i--){
      f.push_back(v[i]);
    }
    return f;
}
bool is_palindrome(string s){
    ll i = 0, j = s.length() - 1;
    while(i <= j){
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
ll power(ll x,ll y, ll p = M){
    ll res = 1; 
    x = x % p; 
    while (y > 0){
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// ll fact[N] , inv[N], pwr[N];
ll modInverse(ll n,ll p){
    return power(n, p - 2, p);
}
// ll nCrModPFermat(ll n,ll r,ll p){
//     if (n < r) return 0;
//     if (r == 0) return 1;
//     return (fact[n] * inv[r] % p * inv[n-r] % p);
// }
// void pre(){
//     fact[0] = 1;
//     inv[0] = modInverse(fact[0], mod);
//     for(ll i = 1;i<N;i++){
//         fact[i] = (fact[i-1] * i) % mod;
//         inv[i] = modInverse(fact[i],mod);
//     }
// }
vector<ll> factors(ll n) {
    vector<ll> f;
    for (ll x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}
ll lcm(ll x, ll y){
    ll r = __gcd(x, y);
    ll u = x * y;
    return u / r;
} 
struct FenwickTree{
    vector<ll> bit;  
    ll n;

    FenwickTree(ll n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll query(ll idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx){
            ret += bit[idx];
        }
        return ret;
    }

    void range_add(ll l, ll r, ll val) {
        add(l, val);
        add(r + 1, -val);
    }

    void add(ll idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }
};
ll p[N];
void manacher(string s){
    string g;
    g.push_back('#');
    for(auto p : s){
        g.push_back(p); g.push_back('#');
    }
    ll l = 0, r = -1;
    ll ind = 0;
    s = g;
    // trace(s);
    ll n = s.length();
    for(ll i = 0;i<n;i++){
        ll k;
        if(i > r) k = 0;
        else{
            ll j = r - i + l;
            k = min(p[j], r - i);
        }
        while(i - k >= 0 && i + k < n && s[i-k] == s[i+k]) ++k;
        if(s[i-k] != s[i+k]) --k;
        p[i] = k;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
    }
}
struct DSU {
    ll n; 
    vector<ll> par, siz;
    DSU(ll n){
        this->n = n + 5;
    }
    void init(){
        par.assign(n + 5 , 0);
        siz.assign(n + 5 , 0);
        for(ll i = 0;i<=n;i++){
            par[i] = i; siz[i] = 1;
        }
    }
    ll find_set(ll x){
        if(par[x] == x) return x;
        return par[x] = find_set(par[x]);
    }
    ll get_size(ll x){
        return siz[find_set(x)];
    }
    void union_set(ll x, ll y){
        x = find_set(x); y = find_set(y);
        if(x == y) return;
        if(siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
    }
};
// ll table[300005][25];
// ll log1[300005];
// void build_log(){
//     log1[1] = 0;
//     for(ll i = 2;i<100005;i++){
//         log1[i] = 1 + log1[i / 2];
//     }
// }
// void build(vector<ll> data){
//     ll n = data.size();
//     for(ll l = n-1;l>=0;l--){
//         for(ll w = 0;w < 25; w++){
//             ll r = l + (1 << w) - 1;
//             if(r >= n) break;
//             if(w == 0) table[l][w] = data[l];
//             else table[l][w] = max(table[l][w-1],table[l + (1 << (w-1))][w-1]);
//         }
//     }
// }
// ll query(ll L , ll R){
//     ll W = R - L + 1;
//     ll power = log1[W];
//     return max(table[L][power] , table[R - (1 << power) + 1][power]);
// }
vector<ll> z_function(string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
// inline void time_taken(){ cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n"; }
void solve(ll tc){
    string s; cin>>s;
    map<char,vector<ll>> mp;
    for(ll i = 0;i<s.length();i++){
        mp[s[i]].push_back(i+1);
    }
    ll q; cin>>q;
    for(ll i = 0;i<q;i++){
        ll l,r; cin>>l>>r;
        map<char,ll> mo;
        for(char j = 'a';j<='z';j++){
            if(mp[j].empty()) continue;
            ll upper = upper_bound(mp[j].begin(),mp[j].end(),r) - mp[j].begin();
            ll lower = lower_bound(mp[j].begin(),mp[j].end(),l) - mp[j].begin();
            ll len = upper - lower;
            if(len > 0) mo[j] = len;
        }
        ll siz = mo.size();
        bool ok = false;
        if(siz > 1) ok = true;
        if(siz == 2){
            if(s[l-1] == s[r-1]) ok = false;
        }
        ll tot = r - l + 1;
        if(ok || tot < 2) cout << "Yes\n";
        else cout << "No\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1, tc = 0; 
    // cin>>t; 
    while(t--){
      tc++; solve(tc);
    }
    // time_taken();   
    return 0;
}