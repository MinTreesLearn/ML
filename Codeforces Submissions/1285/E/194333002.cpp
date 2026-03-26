#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 2e5 + 10;
struct line{
	ll l,r;
}a[mm];
map<ll,int>mp;
int d[mm<<2],dd[mm<<2];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		mp[a[i].l]++,mp[a[i].r]++;
	}
	int ma=0;
	for(auto &[x,y]:mp){
		y=(++ma)*2;
	}ma<<=1;
	for(int i=1;i<=n;i++){
		a[i].l=mp[a[i].l],a[i].r=mp[a[i].r];
		d[a[i].l]++,d[a[i].r+1]--;
	}
	for(int i=1;i<=ma+5;i++){
		d[i]+=d[i-1];
	}
	int ans0=0;
	for(int i=0;i<=ma+5;i++){
		ans0+=(d[i]&&!d[i+1]);
	}
	for(int i=0;i<=ma+5;i++){
		if(d[i]!=1&&d[i+1]==1)dd[i+1]++;
	}
	for(int i=1;i<=ma+5;i++){
		if(d[i]!=1&&d[i-1]==1)dd[i-1]++;
	}
	for(int i=1;i<=ma+5;i++)dd[i]+=dd[i-1];
	int ans=-10000;
	for(int i=1;i<=n;i++){
		int k=(dd[a[i].r]-dd[a[i].l-1])/2;
		if(d[a[i].l]==1)k--;
		if(d[a[i].r]==1)k--;
		ans=max(k,ans);
	}cout<<ans+ans0<<'\n';
	for(int i=0;i<=ma+10;i++){
		d[i]=dd[i]=0;
	}mp.clear();
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
