// LUOGU_RID: 101865513
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100001
ll n,k;
inline bool gt(ll x){
	cout<<"? "<<x<<'\n';
	char tem;
	cout.flush();cin>>tem;
	if(tem=='N')return 0;
	return 1;
}
inline void clear(){
	cout<<'R'<<'\n';
	return ;
}
ll an[N];
int main()
{
//	freopen("test1.in","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	if(k==1){
		ll ans=n;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				gt(j);ll o=gt(i);an[i]|=o;
			}
			if(an[i])ans--;
		}cout<<"! "<<ans;
		return 0;
	} 
	ll ji=k/2,g=n/ji,ans=n;
	for(int i=1;i<=g;i++){
		for(int j=1;j<=i;j++){
			if(j>g-i)continue;
			for(int k=j;k<=g;k+=i){
				for(int p=(k-1)*ji+1;p<=k*ji;p++)an[p]|=gt(p);
			}clear();
		}
	} 
	for(int i=1;i<=n;i++)if(an[i])ans--;
	cout<<"! "<<ans;
	return 0;
}
