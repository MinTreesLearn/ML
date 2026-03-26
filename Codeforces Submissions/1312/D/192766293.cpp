#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


typedef tree<int,null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update>order_set;
typedef pair<int,int>pr;
#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb push_back


#define en "\n"
#define dbg cout<<"rony\n";

#define MAXN 200010
#define inf 1e8
const int mod = 998244353;
vector<int>g[MAXN];

ll fact[MAXN];
ll bigmod(ll a,ll n)
{
    ll rs = 1;
    while(n)
    {
        if(n%2 == 0){
             n /= 2;
             a = a * a; a %= mod;
        }
        else{
            n--;
            rs *= a; rs %= mod;
        }
    }
    return rs;
}
void factorial(ll n)
{
    fact[0] = fact[1] = 1;
    for(ll i = 2;i <= n;i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
}
ll nCr(ll n,ll r)
{
    ll an = fact[n];

    an *= bigmod(fact[n - r],mod - 2);
    an %= mod;
    an *= bigmod(fact[r], mod - 2); an%=mod;
    return an;
}
void solve()
{
   ll n,m;
   cin >> n >> m;

   if(n == 2){
    cout<<0<<en;return;
   }
   
   factorial(m);

   ll an = nCr(m,n-1);
   
   an *= (n - 2); an %= mod;
   an *= bigmod(2,n-3);
   an %= mod;
   cout<<an<<en;
}
int main()
{
    IOS;
   int t;
   t = 1;

   
   // cin >> t;
   int c = 0;
    while ( t-- )
    {
        //cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}   