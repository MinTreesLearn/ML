#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop1(i,n) for(ll i=0;i<n;++i)
#define loop2(i,n) for(ll i=n-1;i>=0;--i)
#define NO cout<<"NO"<<endl; 
#define YES cout<<"YES"<<endl;
#define out(x) cout<<x<<endl;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ll t;cin>>t;
    while(t--)
    {
      ll n,m,k;cin>>n>>m>>k;

      ll arr[n];

      loop1(i,n)
      {
        cin>>arr[i];
      }

      k=min(k,m-1);
      ll ans=0;
      for(ll i=0;i<=k;i++)
      {
        ll p=i,q=i+n-k-1,ansx=1e18,z=m-k-1,w=q-p+1-z;

        for(ll j=p;j<=p+z;j++)
        {
           ansx=min(ansx,max(arr[j],arr[j+w-1]));
        }
        ans=max(ans,ansx);
      }

      cout<<ans<<endl;
    } 
}