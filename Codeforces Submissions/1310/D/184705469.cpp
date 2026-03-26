// LUOGU_RID: 97142796
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=85;
int n,k,Map[INF][INF],p[INF],f[INF][INF],ans;
mt19937 rnd(20080209);
int gen(int l,int r) {return rnd()%(r-l+1)+l;}
void solve() {
	memset(f,63,sizeof f);
	for (int i=1;i<=n;i++) p[i]=gen(0,1);
	f[1][0]=0;
	for (int i=0;i<k;i++)
		for (int j=1;j<=n;j++) {
			for (int l=1;l<=n;l++) {
				if (p[j]==p[l]) continue;
				f[l][i+1]=min(f[j][i]+Map[j][l],f[l][i+1]);
			}
		}
	ans=min(ans,f[1][k]);
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;ans=1e18;
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++)
			cin>>Map[i][j];
	int T=5000;
	while (T--) solve();
	cout<<ans<<"\n";
	return 0;
}