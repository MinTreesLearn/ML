// LUOGU_RID: 101859300
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1100
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
	//freopen(".in","r",stdin);
	//freopen("test1.out","w",stdout);
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
		ll l=(i-1)*ji+1,r=i*ji;
		for(int j=1;j<i;j++){
			for(int q=(j-1)*ji+1;q<=j*ji;q++)gt(q);
			for(int q=l;q<=r;q++)an[q]|=gt(q);
			clear();
		}
		for(int j=l;j<=r;j++)an[j]|=gt(j);
		for(int j=l;j<=r;j++)if(an[j])ans--;
		clear();
	}cout<<"! "<<ans; 
	return 0;
}
