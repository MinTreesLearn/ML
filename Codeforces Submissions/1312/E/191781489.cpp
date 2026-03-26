// LUOGU_RID: 101282622
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define max_n 500
#define inf 0x3f3f3f3f
int n;
int a[max_n+2];
int w[max_n+2][max_n+2];
int dp[max_n+2][max_n+2];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("CF1312E_1.in","r",stdin);
	freopen("CF1312E_1.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	memset(dp,inf,sizeof(dp));
	for(int i=1;i<=n;++i){
		w[i][i]=a[i];
		dp[i][i]=1;
	}
	for(int p=1;p<=n;++p){
		for(int l=1,r;l+p-1<=n;++l){
			r=l+p-1;
			for(int k=l;k<r;++k){
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				if(dp[l][k]==1&&dp[k+1][r]==1&&w[l][k]==w[k+1][r]){
					w[l][r]=w[l][k]+1;
					dp[l][r]=1;
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}
