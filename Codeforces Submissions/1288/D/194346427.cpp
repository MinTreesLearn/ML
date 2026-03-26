#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 1e9+7;
const int mm = 3e5 + 10;
ll a[mm][10];
ll n,m;
map<ll,pair<ll,ll>>anss;
bool check(ll x){
	map<ll,ll>mp;
	for(int i=1;i<=n;i++){
		ll bj=0;
		int jj=1;
		for(int j=1;j<=m;j++){
			if(a[i][j]>=x)bj+=(1ll<<(j-1));
			else jj=0;
		}
		mp[bj]=i;
		if(jj){
			anss[x].first=anss[x].second=i;
			return 1;
		}
	}
	ll xx=(1ll<<m)-1;
	for(auto [i,y]:mp){
		for(auto [z,w]:mp){
			if((i|z)==xx){
				anss[x].first=y;
				anss[x].second=w;
				return 1;
			}
		}
	}return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m;
	ll ma=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			ma=max(ma,a[i][j]);
		}
	}
	ll l=0,r=ma;
	ll ans=0;
	while(l<=r){
		int m=(l+r)>>1;
		if(check(m))l=m+1,ans=m;
		else r=m-1;
	}cout<<anss[ans].first<<' '<<anss[ans].second;
}
