#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <numeric>
#define nl "\n"
#define te cin >> t
#define ts to_string
#define pb push_back
#define pob pop_back
#define np next_permutation
#define rv reverse
#define inn insert
#define ff first
#define ss second
#define srt(x,y) sort((x),(x)+(y))
#define cnt(x,y,z) count((x),(x)+(y),z)
#define st for(int z=1;z<=t;z++)
#define ll long long int
#define cnt_bit(x) __builtin_popcount(x)
#define YES cout<<"YES"<<nl;
#define yes cout<<"Yes"<<nl;
#define NO cout<<"NO"<<nl;
#define no cout<<"No"<<nl;
#define forn(x) for(ll i=0;i<(x);i++)
#define pi 2*acos(0.0)
#define mod(x) ((x)%N+N)%N
#define sz(x) x.size()
#define llu long long unsigned int
#define vect(type1,name) vector<type1>name
#define full(x) x.begin(),x.end()
#define cntt(x,y) count((x).begin(),(x).end(),(y))
#define amx  *max_element
#define amn  *min_element
#define gcd(x,y) (ll)(__gcd(x,y))
#define lcm(x,y) (ll)((x/gcd(x,y))*y)
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef pair<ll,ll>pr;
typedef vector<char>vc;
typedef vector<ll>vi;
typedef vector<string>vs;
typedef map<ll,ll>mp;
typedef map<char,ll>mpc;
typedef map<string,ll>mps;
typedef set<ll>si;
typedef set<char>sc;
typedef deque<ll>dq;
typedef set<string>ss;
typedef vector<pair<char,ll>>vp;
typedef unordered_set<ll>us;
typedef unordered_set<string>ust;
typedef multiset<ll>mst;
typedef multiset<string>mss;
typedef unordered_map<ll,ll>ump;
typedef unordered_map<string,ll>umps;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const ll N = 1e6;
const ll mod = 1e9+7;

//void c(ll n)
//{
//    if(n==4){
//        //cout <<1<<'\n';
//        return;
//    }
//    c(n+1);
//    cout <<n<< '\n';
//    c(n+1);
//}
//void B_T_P(string s,ll l,ll r){
//
//   if(l==r){
//      str.push_back(s);
//   }
//   else{
//   for(ll i=l;i<=r;i++){
//   swap(s[l],s[i]);
//   bt(s,l+1,r);
//   swap(s[l],s[i]);
//   }
//   }
//}
//ll fact[N];
//void factorial()
//{
//    ll ff=1;
//    for(ll i=1;i<=N;i++)
//    {
//        ff*=i;
//        ff%=mod;
//        fact[i]=ff;
//    }
//}
//bool is_prime(ll x)
//{
//    for(ll i=2;i*i<=x;i++)
//    {
//        if(x%i==0)return 0;
//    }
//    return 1;
//}
//ll spf[N];
//void seive()
//{
//    for(ll i=1;i<=N;i++){
//        spf[i]=i;
//    }
//    for(ll i=2;i*i<=N;i++){
//        if(spf[i]==i){
//            for(ll j=i*i;j<=N;j+=i){
//                if(spf[j]==j)spf[j]=i;
//            }
//        }
//    }
//}
//ll ncr(ll c[],ll n,ll r)
//{
//    for(ll i=1;i<=n;i++)
//    {
//        for(ll j=min(i,r);j>0;j--)
//        {
//            c[j]=(c[j]+c[j-1])%mod;
//        }
//    }
//    return c[r];
//}
//ll B_E_R(ll a,ll b,ll m)
//{
//    if(b==0)return 1;
//    ll res=B_E_R(a,b/2,m);
//    if(b&1)
//        return (a*((res*1ll*res)%m)%m);
//    else
//        return (res*1ll*res)%m;
//}
//ll B_E_I(ll a,ll b,ll m)
//{
//    ll ans=1;
//    while(b)
//    {
//        if(b&1)
//            ans=(ans*1ll*a)%m;
//        a=(a*1ll*a)%m;
//        b >>= 1;
//    }
//    return ans;
//}
void hello()
{
    ll n;
    cin >> n;
    ll a=0,b=0;
    for(ll i=1;i*i<n;i++){
        if(n%i==0&&i!=n/i&&lcm(i,n/i)==n){
            a=i;
            b=n/i;
        }
    }
    cout<<max(a,1LL)<<' '<<max(b,1LL)<<nl;
}
int main()
{
    FIO
    ll t;
    //te;st
    hello();
    return 0;
}
