#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
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
#define f(i,a,b) for(long long i=a;i<=b;i++)
#define fr(i,a,b) for(long long i=a;i>=b;i--)
#define ain(a,n) for(ll i=0;i<n;i++)cin>>(a)[i]
#define vll vector<ll>
#define show(a) for(auto x:a)cout<<x<<" ";
 
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
#define N 50005
ll lis(vector<ll> const& a) {
    ll n = a.size();
    
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (ll i = 0; i < n; i++) {
        ll j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
vector<ll> sieve(ll n)
{
    ll *arr = new ll[n + 1]();
    vector<ll> vect;
    for (ll i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (ll j = (i * i); j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
void google(ll t) { cout << "Case #" << t << ": "; }
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} 
void init_code(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

  
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vll> a(n,vll (m,0));
    f(i,0,n-1)
    {
        f(j,0,m-1)
        cin>>a[i][j];

    }
    ll ans=0;

    f(col,0,m-1)
    {
        map<ll,ll> mp;
        ll curr=col+1;
        f(i,0,n-1)
        {
            ll diff=curr-a[i][col];
            if(diff%m==0)
                mp[diff/m]++;
            curr+=m;

            
        }
        if(col==1)
        {
            debug(mp)
        }
        // if(col==1)
        //     // debug(mp)
        ll best=n-mp[0];
        curr=col+1;
        f(i,0,n-2)
        {
            ll prev_diff=curr-a[i][col];
            if(col==1)
            {
                debug(prev_diff)
            }
            if(prev_diff%m==0)
            {
                mp[prev_diff/m]--;
                mp[(prev_diff+(n-1)*m)/m+1]++;
                if(col==1)
                {
                    debug(mp)
                }
            }
            if(col==1)
            {
                debug(i+1+n-mp[i+1])
            }
            best=min(best,i+1+n-mp[i+1]);
            curr+=m;

        }
        ans+=best;
        // debug(ans)
    }
cout<<ans<<nline;
        
}
 
 
int main() {
#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif
   init_code();
   // ll t;
   // cin>>t;
   // while(t--)
   
     solve();
   
return 0;
  
 
    


}