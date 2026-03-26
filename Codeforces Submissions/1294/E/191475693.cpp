#include "bits/stdc++.h"
#define pf printf
#define sf scanf
#define db double 
#define ll  long long
#define siz 20000001
#define MAXN 100001
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
ll mod=1000000007;
ll gcd(ll a, ll b)
{
if (b == 0)
return a;
return gcd(b, a % b);
}
ll powerwithmod(ll a, ll b){
ll res=1;
    while(b){
    if(b&1) res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
        }
        return res;
        }
using namespace std;
int main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    ll arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    ll ans=0;

    for (int i = 0; i < m; i++)
    {
        vector<ll>v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(arr[j][i]);
        }

        ll x=i+1;
        map<ll,ll>ma;

        for (int j = 0; j < v.size(); j++)
        {
            ll val=v[j]-x;
            if(val%m!=0){
                continue;
            }
            val/=m;
            if(val>=n)
            {
                continue;
            }
            
            if(val>j)
            {
                ma[j+n-val]++;
            }
            else
            {
                ma[j-val]++;
            }
        }
        
        ll temp=n;

        for(auto it:ma)
        {
            temp=min(it.first+(n-it.second),temp);
        }
        ans+=temp;
    }
    
    cout<<ans<<"\n";
    
    return 0;
}