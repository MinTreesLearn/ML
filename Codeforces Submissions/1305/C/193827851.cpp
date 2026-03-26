#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vpll vector<pair<long long, long long>>
#define mll map<long long, long long>
#define umll unordered_map<long long>
#define mmll multimap<long long, long long>
#define sll set<long long>
#define msll multiset<long long>
#define usll unordered_set<long long> //faster than set
#define vvll vector<vector<ll>>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl cout << "\n"
#define modv 1000000007
#define md 998244353
#define invll(x, n) \
    vll x(n);       \
    rep(i, 0, n) cin >> x[i];
#define makegraph(graph, edges)    \
    for (ll i = 0; i < edges; i++) \
    {                              \
        ll a, b;                   \
        cin >> a >> b;             \
        graph[a].pb(b);            \
        graph[b].pb(a);            \
    }
#define inll(...)   \
    ll __VA_ARGS__; \
    read(__VA_ARGS__);
#define inint(...)   \
    int __VA_ARGS__; \
    read(__VA_ARGS__);
#define instring(s) \
    string s;       \
    cin>>s;
#define inchar(ch) \
    char ch;       \
    cin>>ch;
#define printvec(v) for(ll i=0; i<v.size(); i++){cout<<v[i]<<" ";} cout<<endl;
#define printarr(arr, n) for(ll i=0; i<n; i++) {cout<<arr[i]<<" ";} cout<<endl;
#define printset(s) for(auto it : s) {cout<<it<<" ";} cout<<endl;
#define all(n) n.begin(), n.end()
#define allrev(n) n.rbegin(),n.rend()
#define lb lower_bound
#define ub upper_bound
#define rep(i, k, n) for (ll i = k; i < n; i++)
#define repr(i, k, n) for (ll i = k; i >= n; i--)
#define setval(arr, size, val) rep(i, 0, size) arr[i] = val;
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
template <typename... T>
void read(T &...args){
    ((cin >> args), ...);
}
template <typename... T>
void print(T... args){
    ((cout << args << " "), ...);
    cout << "\n";
}

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

bool comp(pair<ll, ll> &a, pair<ll, ll> &b){
    return (a.se < b.se);
}

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

ll digit(ll n) { return floor(log10(n))+1;}

string decToBinary(ll n){
    string s;
    ll f=0;
    repr(i,31,0){
        ll k = n >> i;
        if (k & 1){
            s = s + '1';
            f=1;
        }
        else  if(f==1) s = s + '0';
    }
    return s;
}

bool ispowtwo(ll n){
    if(n && (!(n&(n-1)))) return true;
    else return false;
}

ll mod(ll a, ll b){
    ll res=((a%b)+b)%b;
    return res;
}

ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0){
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//SEGMENT TREE
void update(ll Tree[], ll idx, ll s, ll e, ll pos, ll X){
    if (s == e) Tree[idx] += X;
    else{
        ll m = (s + e) / 2;
        if (pos <= m) update(Tree, 2 * idx, s, m, pos, X);
        else update(Tree, 2 * idx + 1, m + 1, e, pos, X);
        Tree[idx] = Tree[2 * idx] + Tree[2 * idx + 1];
    }
}
 
ll sum(ll Tree[], ll idx, ll s, ll e, ll ql, ll qr){
    if (ql == s && qr == e) return Tree[idx];
    if (ql > qr) return 0;
    ll m = (s + e) / 2;
    return sum(Tree, 2 * idx, s, m, ql, min(m, qr)) + sum(Tree, 2 * idx + 1, m + 1, e, max(ql, m + 1), qr);
}
//getElement(Tree, ind - 1, n); 
ll getElement(ll Tree[], ll X, ll N){
    return sum(Tree, 1, 0, N - 1, 0, X);
}
//range_Update(Tree, l - 1, r - 1, 1, n);
void range_Update(ll Tree[], ll L, ll R, ll X, ll N){
    update(Tree, 1, 0, N - 1, L, X);
    if (R + 1 < N) update(Tree, 1, 0, N - 1, R + 1, -X);
}
//END

bool isPrime(ll n){
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

bool isSorted(vector <ll> &v){
    ll n = v.size();
    vll v1;
    v1=v;
    sort(all(v1));
    rep(i,0,n){
        if(v[i]!=v1[i]) return false;
    }
    return true;
}

//SIEVE
vector<ll> primes;
void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}

vll primefac(ll n){
    vll fac;
    for(ll i=0;i<primes.size();i++){
        if(primes[i]>n) break;
        while(n%primes[i]==0){
            n/=primes[i];
            fac.pb(primes[i]);
        }
    }
    if(n>0){
        fac.pb(n);
    }
    return fac;
}

ll getfactors(ll n){
    ll ct=0;
    for(ll i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i) ct++;
            else ct+=2;
        }
    }
    return ct;
}

//gcd(a,b) == gcd(b,a-b) == gcd(b, a%b)
//Array is faster than vector

ll modpower(ll x, ll y){
	ll res = 1;
	while (y > 0) {
		if (y % 2 == 1)
			res = (res * x);
		y = y >> 1;
		x = (x * x);
	}
	return res;
}

void solve(){
    inll(n,m);
    invll(v,n);
    ll ans=0;
    if(n<=m){
        ans++;
        rep(i,0,n-1){
            rep(j,i+1,n){
                ans = ans * (abs(v[i]-v[j]));
                ans = ans%m;
            }
        }
    }
    print(ans%m);
}

int main(){
    fast;
    ll tt=1;
    //cin>>tt;
    while (tt){
        tt--;
        solve();
    }
}