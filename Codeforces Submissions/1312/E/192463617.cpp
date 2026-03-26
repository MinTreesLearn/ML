#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=500+3;
int a[N],f[N][N],dp[N];
//区间DP
//求出f[l,r]表示[l,r]区间向左合并的最小可能数。然后dp一遍枚举区间划分即可。 
void solve() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	map<int ,int >mp;
	for(int i=1; i<=n; i++) {
		int cnt=0;
		for(int j=i; j<=n; j++) {
			int x=a[j];
			while(cnt&&mp[cnt]==x) cnt--,x++;
			mp[++cnt]=x;
			f[i][j]=cnt;
		}
	}
	memset(dp,INF,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<i;j++) {
			dp[i]=min(dp[i],dp[j]+f[j+1][i]);
		}
	}
	cout<<dp[n]<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	int t;	cin>>t;	while(t--)
	solve();
	return 0;
}


