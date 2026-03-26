#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(v) ((v).begin()), ((v).end())
#define siz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < siz(v); ++i)
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fp(i, j, n) for (long long i = (j); i <= (long long)(n); ++i)
#define fn(i, j, n) for (int i = (j); i >= (int)(n); --i)
#define fvec(i, vec) for (auto i : vec)
#define pb push_back
#define MP make_pair
#define mine(x, y, z) min(x, min(y, z))
#define maxe(x, y, z) max(x, max(y, z))
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;

typedef vector<pll> vp;
typedef vector< long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef tree< pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define setp(item) cout<<fixed<<setprecision(item);
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
const ll OO =1e18, mod = 1e9+7,mod2=1e9+9, N =2e5+5,M=30,MOD=998244353, minOO=LLONG_MIN;
///   هذا الحل من وحي خيال المؤلف واي تشابه بينه و بين اي حل اخر ما هو الا محض الصدفة
ll add ( ll a , ll b)
{
    return (a + b) % mod;
}
ll mul ( ll a , ll b)
{
    return 1LL * a * b % mod;
}
ll fop( ll b , ll p)
{
        if(!p)
        return 1;
        ll temp = fop(b,p/2)%mod;
        temp = mul(temp,temp);
        if(p&1)
        temp = mul(temp,b);
        return temp%mod;
}
ll fact[N], inv[N];
ll nCr( ll n , ll r)
{
    return mul(fact[n],mul(inv[n-r],inv[r]));
}
ll nPr( ll n , ll r)
{
    return mul(nCr(n,r),fact[r]);
}

void testCase(ll n) {
    fact[0] = inv[0] = 1;
    for ( ll i = 1 ; i <= n ; i++)
    {
        fact[i] = mul(i,fact[i-1]);
        inv[i] = fop(fact[i],mod-2);
    }

}
void func(int inde) {
    ll num,m;cin>>num>>m;
    cout<<nCr(num+2*m-1,2*m);

}

int main() {
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t=1;
//    cin>>t;
    testCase(N-3);
    ll index=1;
    while (t--){
        func(index++);
    }
    return 0;
}