// LUOGU_RID: 101817286
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vpi vector<pii>
#define all(x) (x).begin(),(x).end()
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,m,k,l[M],r[M],p[M],id[M],dp[M][256],vis[M];
vi e[M],tmp[M];

signed main()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read()+1;
		p[i*2-1]=l[i],p[i*2]=r[i];
	}
	sort(p+1,p+1+2*n);int L=unique(p+1,p+1+2*n)-p-1;
	for (int i=1;i<=n;i++)l[i]=lower_bound(p+1,p+1+L,l[i])-p,r[i]=lower_bound(p+1,p+1+L,r[i])-p;
//	for (int i=1;i<=n;i++)cerr<<l[i]<<' '<<r[i]<<'\n';
//	cerr<<L<<'\n';
	for (int i=1;i<=n;i++)
	{
		for (int j=l[i];j<r[i];j++)e[j].pb(i);
		tmp[l[i]].pb(i);
	}
	memset(vis,-1,sizeof(vis));
	for (int i=1;i<=L-1;i++)
	{
		int cnt=p[i+1]-p[i],S=0;
		for (int j=0;j<(int)(e[i].size());j++)vis[e[i][j]]=j;
		for (auto x:tmp[i])S|=1ll<<vis[x];
		for (int j=0;j<(1<<e[i-1].size());j++)
		{
			int s=0;
			for (int w=0;w<(int)(e[i-1].size());w++)
				if ((j>>w&1)&&vis[e[i-1][w]]!=-1)s|=1<<vis[e[i-1][w]];
//			cerr<<"change:"<<i<<' '<<j<<' '<<s<<'\n';
			for (int tmp=S;;tmp=(tmp-1)&S)
			{
				ckmax(dp[i][tmp|s],dp[i-1][j]);
				if (tmp==0)break;
			}
		}
		for (int j=0;j<(1<<e[i].size());j++)
		{
			if (__builtin_popcount(j)&1)dp[i][j]+=cnt;
//			cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
		for (int j=0;j<(int)(e[i].size());j++)vis[e[i][j]]=-1;
	}
	int ans=0;
	for (int i=0;i<256;i++)ckmax(ans,dp[L-1][i]);
	cout<<ans<<'\n';
	return 0;
}