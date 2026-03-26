#include <bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int lcp[1005][1005];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	int L=lcp[x.first][y.first];
	int px=x.first+L,py=y.first+L;
	if(px>x.second||py>y.second) return x.second-x.first<y.second-y.first;
	return s[px]<s[py];
}
pair<int,int> p[510005];
int cntp=0;
int rk[1005][1005],pos[1005];
int dp[1005][1005],n,m,k;
int cal()
{
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>1)for(int j=0;j<=m;j++) dp[i][j]+=dp[i-1][j],dp[i][j]=min(dp[i][j],k);
		for(int j=0;j<=m;j++)
			dp[pos[i]][j+1]+=dp[i-1][j],dp[pos[i]][j+1]=min(dp[pos[i]][j+1],k); 
	}
	return dp[n][m];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k >> s;
	s=' '+s;
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
			else lcp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) p[++cntp]={i,j};
	sort(p+1,p+cntp+1,cmp);
	for(int i=1;i<=cntp;i++) rk[p[i].first][p[i].second]=i;
	int l=1,r=cntp;
	string ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		for(int i=1;i<=n;i++)
		{
			pos[i]=i;
			while(pos[i]<=n&&rk[i][pos[i]]<mid) ++pos[i];
		}
	//	cout << mid << " " << p[mid].first << " " << p[mid].second << " " << s.substr(p[mid].first,p[mid].second-p[mid].first+1) << "\n";
	//	for(int i=1;i<=n;i++)
	//		cout << pos[i] << " ";
	//	cout << "\n";
		if(cal()>=k) ans=s.substr(p[mid].first,p[mid].second-p[mid].first+1),l=mid+1;
		else r=mid-1;
	}
	cout << ans;
	return 0;
}