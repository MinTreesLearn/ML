#pragma GCC optimize("O3,unroll-loops")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
#define int long long
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
// #define mp make_pair
#define ff first
#define ss second
#define pl pair<ll,ll>
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi  vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vll vector<ll>
#define prDouble(x) cout << fixed << setprecision(10) << x<<" ";
 
#define vpi vector<pair<int,int>>
#define vpl vector<pl>
#define pi pair<int,int>
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
void _print(ll t) {cerr << t;}
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
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll>fact(1e6+100,1LL);
long long mod=1e9+7;
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i*i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<ll> prefixSum(vector<ll> A){vector<ll> res(A.size()+1);res[0]=0;res[1]=A[0];for(int i=1;i<A.size();i++){res[i+1]=A[i]+res[i];} return res;}
vector<ll> suffixSum(vector<ll> A){vector<ll> res(A.size()+1);int n=A.size();res[n]=A[n-1];for(int i=n-2;i>=0;i--){res[i]=A[i]+res[i+1];}return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll ncr(ll n, ll r, ll mod) {return mod_div(fact[n],(mod_mul(fact[n-r],fact[r],mod)),mod);}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
static bool comp(pi a,pi b){ return a.ff+a.ss<b.ff+b.ss;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}
void indexsort(vector<int>&v,vpi &ans){for(int i=0;i<v.size();i++){ans.push_back({v[i],i});} sort(all(ans));}
void factorial(int n){ for(long long i=1;i<n;i++)fact[i]=mod_mul(fact[i-1],i,mod);}
ll __lcm(int i,int j){ll gcd=__gcd(i,j);return (i/gcd)*j;}
bool isPrime(int n){for(int i=2;i<=sqrt(n);i++){ if(n%i==0){return false;}}return true;}
map<int,int> factors(int n){map<int,int>mp;int m=n;for(int i=2;i<=sqrt(n);i++){while(n%i==0){mp[i]++;n/=i;}}if(n>=2)mp[n]++; return mp;}
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};unordered_map<long long, int, custom_hash> safe_map;
/*--------------------------------------------------------------------------------------------------------------------------*/
 
 
 



void solve(){
int n;
cin>>n;
vi b(n);
cin>>b;

vi a(2*n);
set<int>st;
for(int i=1;i<=2*n;i++)st.insert(i);
int j=0;
for(int i=0;i<n;i++){
    a[j]=b[i];
    st.erase(b[i]);
    j+=2;
}

for(int i=0;i<2*n;i+=2){
    int val=a[i];
    if(st.upper_bound(val)==st.end()){cout<<-1;return;}
    a[i+1]=*st.upper_bound(val);
    st.erase(a[i+1]);
}
for(auto &i:a){cout<<i<<" ";}
}
    
  
 
 
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // int tc=1;
    int tc=1;
    cin>>tc;
    while(tc--){
    solve();
    cout<<endl;
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}
 
 
//Do not use lower_bound(st.begin(),st.end(),x)->uses O(n) TC,instead use
// st.lower_bound(x);
//s+='a'; not s=s+'a';
//log(2) gives double value so if necessary convert to (int)log2.
// After all MOD operation check all variable values are >=0 and <MOD