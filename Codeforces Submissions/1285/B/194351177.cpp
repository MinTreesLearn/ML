#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#include<bits/stdc++.h>
using namespace std;
 
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rnd(int x, int y) {return (rng() % (y-x +1)) + x;};
 
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ull unsigned long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ff first
#define ss second
#define fio ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define nl "\n"
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define fl(a,x) memset(a,x,sizeof(a));
#define pt(a,x) cout << get<x>(a) << " " ;
#define mt make_tuple
#define vec vector
#define mxe max_element
#define mne min_element
#define present(c, x) (c.find(x) != c.end())
#define printall(a) for(auto i : a) cout << i << " " ; cout << nl ;
 
#define int long long
 
typedef vector<int> vii;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vii> vvi;
typedef vector<vll> vvl;
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll lcm(ll a,ll b){
    ll g =__gcd(a,b);
    return (a*b/g);
}
const int mod = (int) 1e9 + 7 ;
const int MOD = (int) 998244353 ;
const ll INF = (ll) 1e18;

int power(int a, int n) {
    if(n == 0) return 1;
    int p = power(a, n/2) ;
    p = p * p % mod ;    
    return n & 1 ? p * a % mod : p;
}

void ANON7MOUS(){
    int n;  cin >> n;
    vii a(n), pfx(n), sfx(n);
    rep(i,0,n) cin >> a[i];
    pfx[0] = a[0];
    sfx.back() = a.back();
    for(int i = 1; i < n; ++i) pfx[i] = pfx[i - 1] + a[i];
    for(int i = n - 2; i >= 0; --i) sfx[i] = sfx[i + 1] + a[i];
    bool ok1 = 0, ok2 = 0;
    for(auto i : pfx){
        if(i <= 0){
            ok1 = 1;
            break;
        }
    }
    for(auto i : sfx){
        if(i <= 0){
            ok2 = 1;
            break; 
        }
    }
    if(ok1 || ok2) cout << "NO" << endl;
    else cout << "YES" << endl;
}        
int32_t main(){
    fio;
    ll tc = 1;   cin >> tc;  while(tc--)
        ANON7MOUS();    
    // cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;    
}