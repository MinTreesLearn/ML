//  ███████╗███╗   ██╗███████╗██╗  ██╗
//  ██╔════╝████╗  ██║██╔════╝██║  ██║
//  ███████╗██╔██╗ ██║█████╗  ███████║
//  ╚════██║██║╚██╗██║██╔══╝  ██╔══██║
//  ███████║██║ ╚████║███████╗██║  ██║
//  ╚══════╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝
//#pragma GCC optimize("O3, Ofast, unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define ll long long int
#define surpass_your_limits           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define mod 1000000007
#define mod1 998244353
#define endl '\n'
#define fo(i, o, n) for (int i = o; i < n; i++)
#define rfo(i, o, n) for (int i = n - 1; i >= o; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vll vector<ll>
#define vvl(x, n, m) vector<vll> x(n, vll(m))
#define vvll(x, n, m, y) vector<vll> x(n, vll(m, y))
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define miv map<int, vector<int>>
#define set_bits __builtin_popcountll
#define no_bits(v) (ll) log2(v)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define google(x) cout << "Case #" << x << ": ";
#define ha cout << "YES" << endl;
#define na cout << "NO" << endl;
#define debug(x) cout << x << ' ';
#define debug2(x, y) cout << x << ' ' << y << ' ';
#define debug3(x, y, z) cout << x << ' ' << y << ' ' << z << ' ';
#define debuglp(x)                     \
    for (int i = 0; i < x.size(); i++) \
        cout << x[i] << ' ';           \
    cout << endl;
// typedef tree< pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;  // order_of_key, find_by_key
// typedef tree< pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;  // order_of_key, find_by_key
const int M = (int)1e6;
vll fact(M),inversefact(M);
vll isprime(M, 1);
 
ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
ll divi(ll a, ll b) { return (a + b - 1) / b; }
ll pwr(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll mod_exp(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = mod_exp(a, b / 2);
    x = mod_mul(x, x);
    if (b % 2)
        x = mod_mul(x, a);
    return x;
}
ll mod_inv(ll a) { return mod_exp(a, mod - 2); }
ll mod_div(ll a, ll b) { return mod_mul(a, mod_inv(b)); }
 
void checkprime()
{
    isprime[0] = 0, isprime[1] = 0;
    for (ll i = 2; i * i <= 1000005; i++)
    {
        if (isprime[i] && i * i <= 1000005)
        {
            for (ll j = i * i; j <= 1000005; j += i)
                isprime[j] = 0;
        }
    }
}
 
void factorial(){
    fact[0] = inversefact[0] = 1;
    for(int i = 1;i < M;i++){
        fact[i] = mod_mul(i,fact[i - 1]);
        inversefact[i] = mod_inv(fact[i]);
    }
}
 
int ncr(int n,int r){
    return mod_mul(fact[n],mod_mul(inversefact[n - r],inversefact[r]));
}

// unique(s.begin(),s.end())-s.begin();
//(i>>j)&1, first shifts the number i by j bits, then checks if the first bit of the new number is set or not. This will produce 1 if the first bit is set, and 0 otherwise.
//(i<<j)&-1, first shifts the number i by j bits, then checks if the last bit of the new number is set or not. This will produce -1 if the last bit is set, and 0 otherwise.
// accumulate(s.begin(),s.end(),0); //Returns the sum of array vector with sum initiaze to 0
//  __builtin_popcount(unsigned int) //It returns the numbers of set bits in an integer (the number of ones in the binary representation of the integer).
// string binary = bitset<8>(n).to_string(); // it will convert into decimal to binary
// int n = bitset<8>(binary).to_ulong(); // it will convert into binary to decimal
// IF USE OF LEAST / MIN  ANYWHERE IN THE STATEMENT FIRST THOUGHT SHOULD BE BINARY SEARCH
// THINK DP WHENEVER N*M<=1000000 AT MAX
// WRITE DOWN EVERYTHING
// CHECK FOR GCD , LCM APPROACH . HARD TO SPOT
// ll dp[3501][3501][2];


int main(){
    surpass_your_limits;
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif // ONLINE_JUDGE
    ll t;
    t=1;
    cin>>t;
    while(t--){
        ll n,m,k; cin>>n>>m>>k;
        vll a(n);
        fo(i,0,n) cin>>a[i];
        k = min(k,m-1);
        ll ans = 0;
        fo(i,0,k+1){
            ll temp =INT_MAX;
            fo(j,0,m-k){
                temp = min(temp,max(a[i+j],a[i+j+n-m]));
            }
            ans = max({ans,temp});
        }
        cout<<ans<<endl;
    }
    return 0;
}
