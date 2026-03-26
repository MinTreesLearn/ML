// LUOGU_RID: 90343523
#include<cstdio>
#include<cstdlib>
#include<utility>
#include<algorithm>
int n,m,lcp[1005][1005];
long long dp[1005][1005],sf[1005][1005],cnt,k;
std::pair<int,int> s[1000005];
char st[1005];
long long adjust(long long x){return std::min(x,2000000000000000000ll);}
int cmp(std::pair<int,int> x,std::pair<int,int> y)
{
	int l=lcp[x.first][y.first],ml=std::min(x.second,y.second);
	if (l<ml) return st[x.first+l]<st[y.first+l];
	else return x.second<y.second;
}
int ask(int k,int i)
{
	int l=lcp[s[k].first][i];
	if (l>s[k].second) l=s[k].second;
	if (l==s[k].second) return i+l-1;
	if (i+l-1==n) return 0;
	if (st[s[k].first+l]<st[i+l]) return i+l;
	return 0;
}
long long solve(int k)
{
	for (int i=0;i<=n+1;i++) for (int j=0;j<=m+1;j++) dp[i][j]=sf[i][j]=0;
	sf[n+1][0]=dp[n+1][0]=1;
	for (int i=n;i>=1;i--)
	{
		int ret=ask(k,i);
		if (ret) for (int s=1;s<=m;s++) dp[i][s]=sf[ret+1][s-1];
		for (int s=0;s<=m;s++) sf[i][s]=adjust(sf[i+1][s]+dp[i][s]);
	}
	return dp[1][m];
}
int bs(int l,int r)
{
	if (l==r) return l;
	int mid=(l+r+1)/2;
	if (solve(mid)<k) return bs(l,mid-1);
	return bs(mid,r);
}
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",st+1);
	for (int i=n;i>=1;i--) for (int j=n;j>=1;j--) lcp[i][j]=(st[i]==st[j])*(lcp[i+1][j+1]+1);
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) s[++cnt]=std::make_pair(i,j-i+1);
	std::sort(s+1,s+cnt+1,cmp);
	int k=bs(1,cnt);
	for (int i=s[k].first;i<=s[k].first+s[k].second-1;i++) printf("%c",st[i]);
	puts("");
	return 0;
}