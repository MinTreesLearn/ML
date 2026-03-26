#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#include<iterator>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


///Defines.....
#define ll              long long
#define lli             long long int
#define pb              push_back
#define mp              make_pair
#define RIP(i,n)        for(ll i=0; i<n; i++)
#define F(i,a,b)        for(int i=a; i<b; i++)
#define RIP1(i,n)       for(int i=(n-1); i>=0; i--)
#define FOR(i,a,b)      for(int i=a;i<(b); i++)
#define FOR1(i,a,b)     for(int i=a; i>=(b); i--)
#define sc(a)           scanf("%lld",&a)
#define SC(a)           scanf("%d",&a)
#define cin(a)          cin >> a
#define cout(a)         cout << a
#define PI              acos(-1)
#define pr(a)           printf("%lld\n",a)
#define PR(a)           printf("%lld ",a)
#define s(a,b)          sort(a,b)
#define nl              '\n'

using namespace std;
using namespace __gnu_pbds;
//#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


///Constants........
const ll mod = 1e9 + 7;
const ll Max = 1e6+5;
const ll inf = 2e18+5;


///Chess moves.........
 int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
 int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;}
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;}
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;}

///Functions..........
ll bigmod(ll a, ll p, ll M)
{
    p %= (M-1);

    ll result = 1LL;
    while(p>0LL){
        if(p&1LL) result = result * a % M;
        a = a * a % M;
        p>>=1LL;

    }
    return result;
}

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}

ll inverse(ll a, ll M){
    if(gcd(a, M)==1) return bigmod(a, M-2, M) % M;
    return 1;
}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K % mod; ans = ans * inverse(L, mod) % mod;} return ans;}


void Fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

///*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*         WELCOME TO BATTLEFIELD         *=*=*=*=*=**=*=*==*=*=*=*=*==*=*///
///*==============================================================================================*///


int main() {
    Fast_IO();

    /*#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/

    int t=1;

    cin >> t;

    while(t--)
    {
        ll n,a,b;
        cin >> n >> a >> b;
        ll p = a+b+1;

        ll q = p-n;
        ll e = n-q+1;

        if(q <= a || q <= b) e--;
        cout << max(1ll,n-e) << ' ';

        cout << min(a+b-1ll,n) << nl;

    }


   ///...............................................................................///
}
