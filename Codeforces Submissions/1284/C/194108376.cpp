#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ss string
#define loop1(i,n) for(ll i=0;i<n;++i)
#define loop2(i,n) for(ll i=n-1;i>=0;--i)
#define loop3(i,a,b) for(ll i=a;i<b;i++)
#define loop4(i,a,b) for(ll i=a;i>=b;i--)
#define NO cout<<"NO"<<endl; 
#define YES cout<<"YES"<<endl;
#define No cout<<"No"<<endl; 
#define Yes cout<<"Yes"<<endl;
#define out(x) cout<<x<<endl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    ll n,m;cin>>n>>m;ll ans=0;

    vector<ll>dp(255001,1);

    for(ll i=1;i<255000;i++)
    {
       dp[i]=(dp[i-1]*i)%m;
    }

    for(ll i=1;i<=n;i++)
    {
        ll p=dp[n-i+1];
        p*=dp[i];
        p%=m;
        p*=(n-i+1);
        p%=m;

        ans+=p;
        ans%=m;
    }
    cout<<ans<<endl;
}
