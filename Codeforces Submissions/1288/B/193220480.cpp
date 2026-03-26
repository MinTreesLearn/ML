#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define pbds                                               \
//     tree<pair<int, int>, null_type, less<pair<int, int> >, \
//          rb_tree_tag, tree_order_statistics_node_update>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF LLONG_MAX
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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
/****************************************************************************************************************************/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> primeFactors(ll n){vector<ll>ret;while (n % 2 == 0){ret.pb(2);n = n/2;}for (ll i = 3; i <= sqrt(n); i = i + 2){while (n % i == 0){ret.pb(i);n = n/i;}}if (n > 2){ret.pb(n);}return ret;}
vector<ll> prime(ll n) {ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
vector<ll>divisor(ll n){vector<ll>res;for (ll i=1; i<=sqrt(n); i++){if (n%i == 0){if (n/i == i)res.pb(i);else{res.pb(i);res.pb(n/i);} }}return res;}
vector<ll>sieve(){ll MAXN=1e7;vector<ll>spf(MAXN);spf[1] = 1;for (ll i=2; i<MAXN; i++)spf[i] = i;for (ll i=4; i<MAXN; i+=2)spf[i] = 2;for (ll i=3; i*i<MAXN; i++){if (spf[i] == i){for (ll j=i*i; j<MAXN; j+=i)if (spf[j]==j)spf[j] = i;}}return spf;}
vector<ll> Divisors(ll n){vector<ll>res; for(ll i=1;i<=sqrt(n);i++){if (n%i == 0){if (n/i == i)res.pb(i);else{res.pb(i);res.pb(n/i);}}}return res;}
// vector<ll>countSmallerRight(vector<ll>arr){pbds s;ll n = arr.size();vector<ll> ans;for (ll i = n - 1; i >= 0; i--) {if (i == n - 1) { ans.push_back(0);}else {ans.push_back(s.order_of_key({ arr[i], i }));}s.insert({ arr[i], i });}reverse(ans.begin(), ans.end());return ans;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll modPower(ll x,ll y){ll res = 1;x = x % MOD;if (x == 0)return 0;while (y > 0) {if (y & 1)res = (res * x) % MOD;y = y / 2;x = (x * x) % MOD;}return res;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll modFact(ll n){if (n >= MOD)return 0;ll result = 1;for (ll i = 1; i <= n; i++)result = (result * i) % MOD;return result;}
ll power(ll x,ll y){ll res = 1;while (y > 0) {if (y & 1)res = res * x;y = y >> 1;x = x * x;}return res;}
void precision(ll a) {cout << setprecision(a) << fixed;}
/*prime-O(n*log(log(n)));
 smallest prime factor-O(log(n));
 a%(b+c)=0 <=> a%c = b%c */
/*--------------------------------------------------------------------------------------------------------------------------*/
const int N = 1e5+1;
vector<ll>vec(11ll);
void se()
{
  
  for(ll i=1;i<11ll;i++)
  {
    vec[i]=power(10,i)-1;
  }
  debug(vec);
}
void solve()
{
  ll a,b; cin>>a>>b;
  ll lb = lower_bound(all(vec),b)-vec.begin();
  if(vec[lb]!=b)lb--;
  cout<<a*lb<<endl;



}
int main() 
{
  #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
  #endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fastio();
    se();
    ll test; cin>>test; while(test--) {solve();}
    // solve();
  return 0;

}