#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 1e9+7;
const int mm = 2e5 + 10;
ll up[1005][15],down[1005][15];
ll qian[1005],hou[1005];
ll ansh[1005];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)up[i][1]=down[i][1]=1;
	for(int j=2;j<=m;j++){
		qian[0]=0;
		for(int i=1;i<=n;i++){
			qian[i]=qian[i-1]+up[i][j-1];
			qian[i]%=mod;
		}
		for(int i=1;i<=n;i++){
			up[i][j]=qian[i];
		}
	}
	for(int j=2;j<=m;j++){
		hou[n+1]=0;
		for(int i=n;i>=1;i--){
			hou[i]=hou[i+1]+down[i][j-1];
			hou[i]%=mod;
		}
		for(int i=1;i<=n;i++){
			down[i][j]=hou[i];
		}
	}
	for(int i=n;i>=1;i--){
		ansh[i]=ansh[i+1]+down[i][m];
		ansh[i]%=mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+up[i][m]*ansh[i]%mod)%mod;
	}cout<<ans;
}
