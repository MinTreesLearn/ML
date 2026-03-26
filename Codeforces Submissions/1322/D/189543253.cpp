// LUOGU_RID: 100118329
#include <cstdio>
#include <cstring>
#include <algorithm>
using std :: max;
namespace nagisa{
	const int maxn = 2005;
	int n,m,l[maxn],c[maxn],p[maxn*2],dp[maxn*2][maxn];
	int main(){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&l[i]);		
		for(int i=1;i<=n;++i)scanf("%d",&c[i]);		
		for(int i=1;i<=n+m;++i)scanf("%d",&p[i]);
		std :: reverse(l+1,l+n+1),std :: reverse(c+1,c+n+1);
		memset(dp,0xcf,sizeof(dp)),dp[0][0] = 0;
		for(int i=0;i<=n;++i){
			for(int j=n-1;~j;--j)dp[l[i]][j+1] = max(dp[l[i]][j+1],dp[l[i]][j]-c[i]+p[l[i]]);
			for(int j=l[i],b=n;j<n+m;++j,b/=2)
				for(int k=0;k<=b;++k)dp[j+1][k/2] = max(dp[j+1][k/2],dp[j][k]+(k/2)*p[j+1]);
		}
		int ans = 0;for(int i=0;i<=n+m;++i)for(int j=0;j<=1;++j)ans = max(ans,dp[i][j]);printf("%d\n",ans);
		return 0;
	}
}
int main(){return nagisa::main();}
