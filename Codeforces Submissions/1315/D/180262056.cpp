#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>  pll;
const ll N=2e5+5;
const ll inf=1e18;
const ll mod=1e9+7;
pll a[N];
priority_queue<ll> mp;
unordered_map<ll,ll> vis;
bool cmp(pll x,pll y){
  if(x.first==y.first) return x.second<y.second;
  return x.first<y.first;
}
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  ll n;cin>>n;
  for(ll i=1;i<=n;i++) cin>>a[i].first,vis[a[i].first]++;
  for(ll i=1;i<=n;i++) cin>>a[i].second;
  sort(a+1,a+1+n,cmp);
  ll ans=0,sum=0;
  for(ll i=1;i<=n;i++){
    for(ll j=i;j<=i+vis[a[i].first]-1;j++){
        mp.push(a[j].second);sum+=a[j].second;
    }
    sum-=mp.top();
    mp.pop();
    ll beg=a[i].first+1;
    while(mp.size()){
      ans+=sum;
      if(mp.empty()||vis[beg]) break;
      sum-=mp.top();
      mp.pop();
      beg++;
    }
    i=i+vis[a[i].first]-1;
  }
  cout<<ans;
}
  
			  	 	   	    		 	   	 	 	 	