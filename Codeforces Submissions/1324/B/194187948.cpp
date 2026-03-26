//MD SHARIQUE HUSSAIN 2112015
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include<iomanip>
#include<algorithm>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<random>
#include<stdio.h>
#include<complex>
#include<cstring>
#include<chrono>
#include<string>
#include <unordered_map>
//header file ended
using namespace std;
#define INF 1e18
#define pb push_back
#define pll pair <ll,ll>
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define mod1 1000000007
#define mod2 998244353
#define PI 3.141592653589793238462
#define vch vector<char>
#define vll vector<ll>
#define vbb vector<bool>
#define vst vector<string>
#define mll map<ll,ll>
#define mcl map<char,ll>
#define mlc map<ll,char>
#define msl map<string,ll>
#define si set<int>
#define usi unordered_set<int>
#define msi multiset<int>
#define  pqsmall priority_queue <ll,vll,greater<ll> > 
#define  pqlarge priority_queue <ll> 
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define all(x) (x).begin(), (x).end()
//--------------------------------------------------------------//// nCr starts ////---------------------------------------------------------------
ll powerM(ll a,ll b,ll m){ll res = 1;while(b){if(b & 1){res = (res * a) % m;}a = (a * a) % m;b >>= 1;}return res;}
ll modInverse(ll a , ll m){return powerM(a , m - 2 , m);}
ll nCrModPFermat(ll n , ll r , ll p){if(r == 0){return 1;}ll fac[n + 1];fac[0] = 1;for(ll i = 1; i <= n; ++i){fac[i] = (fac[i - 1] * i) % p;}return (fac[n] * modInverse(fac[r] , p) % p * modInverse(fac[n - r] , p) % p) % p;}
//--------------------------------------------------------------//// nCr ends ////-----------------------------------------------------------------
bool cmp(pair<ll,ll> a,pair<ll,ll> b){if (a.ff!=b.ff){return a.ff>b.ff;}else{return a.ss<b.ss;}}
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
ll power(ll a,ll n){ll ct=0;if (!(a%n)){while (a%n==0){a/=n;ct++;}}return ct;}
int computeXOR(int n){if (n % 4 == 0)return n;if (n % 4 == 1)return 1;if (n % 4 == 2)return n + 1;return 0;}
void seive1(bool vb[],ll n) {vb[0]=vb[1]=1;for(int i=2;(i*i)<n;i++){if (vb[i]==0){for (int j = i*i; j < n; j+=i){vb[j]=1;}}}}
ll celi(ll a,ll b){return (a+b-1)/b;}
ll modulas(ll i,ll m){return ((i%m)+m)%m;}
ll flor(ll a,ll b){return (a)/b;}
ll moduler_expo(ll a,ll n,ll m){ll x=1,pow=a%m;while (n){if (n&1){x=(x*pow)%m;}pow=(pow*pow)%m;n=n>>1;}return x;}
void fact(ll n,vector<pll> &vp1){for(ll i=2;i*i<=n;i++){if(n%i==0){ll ct=0;while (n%i==0){ct++;n/=i;}vp1.pb(mp(i,ct));}}if(n>1)vp1.pb(mp(n,1));}
ll multi_inv(ll r1,ll r2){ll q,r,t1=0,t2=1,t,m=r1;while (r2 > 0){q=r1/r2;r=r1%r2;t=1-(q*t2);r1=r2;r2=r;t1=t2;t2=t;}if (t1<0){ll a=abs(t1/m);a++;a=a*m;t1=a+t1;}return t1;}
#define rsort(a) sort(a, a + n, greater<int>())
#define rvsort(a) sort(all(a), greater<int>())
#define FOR(i, a, b) for (auto i = a; i < b; i++)
#define rFOR(a, b) for (auto i = a; i >= b; i--)
#define read(a , n) for(int i = 0  ; i <  n ; i ++){cin >> a[i];}
const ll N=1e7;
void sol()
{
    ll n,flag=0;cin>>n;
    map <ll,vll> m1;
    FOR(i,0,n)
    {
        ll x;cin>>x;
        m1[x].pb(i);
        if(m1[x].size()>2)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"YES\n";
        return;
    }
    if(m1.size()==n)
    {
        cout<<"NO\n";
        return;
    }
    for(auto &val : m1)
    {
        ll sz=val.ss.size();
        FOR(i,0,sz-1)
        {
            if(val.ss[i+1]-val.ss[i]>1)
            {
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}