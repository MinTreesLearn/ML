#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>  pll;
const ll N=1e6+5;
const ll mod=1e9+7;
const ll inf=1e18;
#define  endl "\n"
ll a[N],b[N],p,q,dp[N];
ll ans;
unordered_map<ll,ll> vis;
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  ll n;cin>>n;
  for(ll i=1;i<=n;i++) cin>>a[i];
  for(ll i=1;i<=n;i++){
    vis[a[i]-i]+=a[i];
    ans=max(ans,vis[a[i]-i]);
  }
  cout<<ans;
}
  					   		 			 			   					  	