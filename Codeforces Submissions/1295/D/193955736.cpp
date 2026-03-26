/* Code by Amaan Parvez (amaan0016) */

#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define sz(x) ((int)(x).size())
#define vi vector<ll>
#define mkp make_pair
#define PI 3.141592653589793238462
#define all(v) v.begin(), v.end()
using namespace std;
const ll M = 1e9+7;
const ll MOD =1e18;
const ll N=100000000;
const ll mod=998244353;

#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<" ";_print_(x);cerr<<endl;
#else
#define dbg(x)
#endif
 
void _print_(ll t) { cerr << t; }
void _print_(int t) { cerr << t; }
void _print_(string t) { cerr << t; }
void _print_(char t) { cerr << t; }
void _print_(long double t) { cerr << t; }
void _print_(double t) { cerr << t; }
 
template <class T, class V> void _print_(pair <T, V> p);
template <class T, class V> void _print_(pair <T, V> p) { cerr << "{"; _print_(p.first); cerr << ","; _print_(p.second); cerr << "}"; }
template <class T> void _print_(set <T> v);
template <class T> void _print_(set <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print_(map <T, V> v);
template <class T, class V> void _print_(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T> void _print_(multiset <T> v);
template <class T> void _print_(multiset <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T> void _print_(vector <T> v);
template <class T> void _print_(vector <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }

/*---------------------------------------------------------------------------------------------------------------------------*/

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

/*---------------------------------------------------------------------------------------------------------------------------*/ 
const int Number=10000005;
vector<bool> Prime(Number,true);
vector<int> spf(Number, Number);
void Sieve(){
  Prime[0]=false;Prime[1] =false;
  for (int i=2;i<Number;i++) {
      if(Prime[i]){
      spf[i]=i;
      for (int j=i*2;j<Number;j+=i){
          Prime[j]=false;
          spf[j]=min(spf[j], i);
      }
    }
  }
}
ll power(ll x,ll y,ll p){
    ll res = 1;
    x = x % p;
    while (y>0){
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (res + p) % p;
}

ll modinv(ll x){
    return power(x, M - 2, M);
}

ll sum(ll n){
    // sum 1 to n = (n*(n+1))/2
    ll retval = ((((n % M) * ((n + 1) %
        M)) % M) * modinv(2)) % M;
    return retval;
}
// divisors

vi div(ll n){
    vi num;
    for (ll i=1; i*i<=(n); i++){
        if (n%i==0){
            if (n/i == i)
                num.pb(i);
            else{
                num.pb(i);
                num.pb(n/i);
            }
        }
    }
    return num;
}

// TC --> O(sqrt(n)) 
// To calculate sum of divisors of a number

ll divisorSum(ll n){
    ll l = 1;
    ll ans = 0;
    while (l <= n){
        ll k = n / l;
        ll r = n / k;
        k %= M;
        ans += ((sum(r) - sum(l - 1) %M) * k) % M;
        ans %= M;
        l = r + 1;
    }
    ans = ans % M;
    if (ans < 0){
        return ans+M;
    }else{
        return ans;
    }
}

// Factorial Calcultion

ll inverse(int n,int m){
    if(n==1){
        return 1;
    }else{
        return inverse(m%n,m)*(m-m/n)%m;
    }
}

// Change Acc. to constraints

const ll fac_size=200005;
ll fac[fac_size+1],inv[fac_size+1];
void Cal_Factorial(){
    fac[0]=1;
    for(ll i=1;i<=fac_size;i++)
        fac[i]=mod_mul(fac[i-1],i,M);
    inv[fac_size]=inverse(fac[fac_size],M);
    for(int i=fac_size;i>0;i--)
        inv[i-1]=mod_mul(inv[i],i,M);
}
ll C(ll n,ll r){
    return 1LL*(fac[n]*inv[r]%M*inv[n-r]%M);
}
// nCr --> 1LL*(fac[a]*inv[b]%M*inv[a-b]%M)

// Euler Totient 

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void solve(){
        ll a,m;
        cin >> a >> m;
        ll val = gcd(a,m);
        a/=val;
        m/=val;
        
        ll M = phi(m);
        ll A = phi(a);

        ll Val = phi(val);

        dbg(mkp(A,M));
        dbg(val)

        cout << M << endl;

}   
int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--){
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
        solve();
    }
   return 0;
}