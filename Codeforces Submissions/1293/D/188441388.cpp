#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
#define imax INT_MAX
#define llmax LLONG_MAX
#define precise_cout(a,b) cout<<fixed<<setprecision(b)<<a<<"\n";
#define f(i,a,b) for(int i=a;i<=(int)b;i++)
#define fn(i,b,a) for(int i=b;i>=(int)a;i--)
#define debug(x) cerr << #x<<" : "; _print(x); cerr << endl;
#define vi vector<int>
#define vll vector<ll>
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
// #endif

typedef unsigned long long ull;
typedef long double lld;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(ll t) {cerr << t;}

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

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((0ll + a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((1ll * a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

// binary exponentiation
ll bexp(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
 
// binary exponentiation modulo mod
ll bexpM(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
 
// sieve of eratosthenes for primes
const int P = 10000000;
int prime[P + 1];
void sieve() { prime[0] = 0; prime[1] = 0; for (int i = 2; i <= P; i++) { prime[i] = 1; } for (int i = 2; i * i <= P; i++) { if (prime[i] == 1) { for (int j = i * i; j <= P; j += i) { prime[j] = 0; } } } }
 
// sieve of eratosthenes for 'prime' factorization, O(n(log(log(n)))) for precomputation of spf, O(log(n)) thereafter to factorize each n
ll spf[P + 1];
vector<ll> primefactorize(ll n) { vector<ll> f; while(n>1){ f.pb(spf[n]); n/=spf[n]; } return f; }
void sieve_spf() { spf[0] = 0; spf[1] = 0; for (int i = 2; i <= P; i++) { spf[i] = -1; } for (int i = 2; i <= P; i++) { if (spf[i] == -1) { for (int j = i; j <= P; j += i) { if (spf[j] == -1) { spf[j] = i; } } } } }
 
// extended euclid algorithm
ll extendedgcd(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll x1, y1; ll d = extendedgcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return d; }
 
// modulo multiplicative inverse
ll modInverse(ll a, ll m) { ll x, y; ll g = extendedgcd(a, m, x, y); ll res = (x % m + m) % m; return res; }
 
// nCr (O(n))
ll ncr(ll n, ll k) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res *= (n - i); res /= (i + 1); } return res; }

// nCr with modulo (O(rlogn))
ll ncrMOD(ll n, ll k, ll mod) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res = (res * (n - i)) % mod; res = (res * modInverse(i + 1, mod)) % mod; } return res % mod; }
 
// factorial without modulo 
ll factorial(ll n) { ll res = 1; for (int i = 2; i <= n; i++) res = res * i; return res; }
 
// factorial with modulo 
ll factorialMOD(ll n, ll m) { ll res = 1; for (int i = 2; i <= n; i++) res = ((res % m) * (i % m)) % m; return res % m; }
 
// Check if a number is a Perfect square
bool checkperfectsquare(ll n) { if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) { return true; } else { return false; } }
 
// Divisors of a number in O(sqrt N) -> including 1 and n
vector<ll> factorize(ll n) { vector<ll> v; for(int i=2;i<=sqrt(n);i++) { if (n % i == 0) { v.push_back(i); v.push_back(n / i); } } if (checkperfectsquare(n) == 1) { v.push_back(sqrt(n)); } if (n != 1) { v.pb(n); } return v; }
 
// calculate mex of a set
ll calculateMex(unordered_set<ll> Set) { ll Mex = 0; while (Set.find(Mex) != Set.end()) Mex++; return (Mex); }
 
// count number of set bits in a number
ll countSetBits(ll n) { if (n == 0) return 0; return (n & 1) + countSetBits(n >> 1); }

/*--------------------------------------------------------------------------------------------------------------------------*/
void solve(){
    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
    vector<pair<ll,ll>> points;
    points.pb(mp(x0,y0));
    ll next_x=x0*ax+bx, next_y=y0*ay+by;
    while((next_x<20000000000000010)&&(next_y<20000000000000010)){
        points.pb(mp(next_x,next_y));
        next_x=ax*next_x+bx;
        next_y=ay*next_y+by;
    }
    int len=points.size();
    int ans=0;
    f(i,0,len-1){
        f(j,i,len-1){
            ll dlr=points[j].first-points[i].first+points[j].second-points[i].second;
            ll dsl=abs(xs-points[i].first)+abs(ys-points[i].second);
            ll dsr=abs(xs-points[j].first)+abs(ys-points[j].second);
            if(t>=(dlr+min(dsl,dsr)))
            ans=max(ans,j-i+1);
        }
    }
    cout<<ans<<"\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}
