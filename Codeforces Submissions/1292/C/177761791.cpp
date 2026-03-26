// LUOGU_RID: 91372592
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=4000;
int siz[maxn],dfn[maxn],idn=0;
int tot=0,pre[maxn<<1],son[maxn<<1],now[maxn];
int n,u,v;
short dis[maxn][maxn];
int f[maxn][maxn],g[maxn][maxn];
queue<pair<int,int> > q;
void put(int x,int y)
{
	pre[++tot]=now[x];
	now[x]=tot;
	son[tot]=y;
}
void dfs(int x,int fa)
{
	siz[x]=1;dfn[x]=++idn;
	for(int p=now[x];p;p=pre[p])
	{
		int t=son[p];
		if(t==fa)
			continue;
		dfs(t,x);
		siz[x]+=siz[t];
	}
}
int calc(int x,int y)
{
	if(x==y)
		return 0;
	if(g[x][y])
		return g[x][y];
	if(dfn[x]<dfn[y])
		swap(x,y);
	if(dfn[x]<=dfn[y]+siz[y]-1)
	{
		for(int p=now[y];p;p=pre[p])
		{
			int t=son[p];
			if(dis[x][t]+1==dis[x][y])
				return g[x][y]=g[y][x]=siz[x]*(n-siz[t]);
		}
	}
	return g[x][y]=g[y][x]=siz[x]*siz[y];
}
void bfs()
{
	memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0,q.emplace(i,i);
	int ans=0;
	while(!q.empty())
	{
		auto [x,y]=q.front();
		f[x][y]+=calc(x,y);
		ans=max(ans,f[x][y]);
		q.pop();
		for(int p=now[x];p;p=pre[p])
		{
			int t=son[p];
			if(dis[t][y]==-1||dis[t][y]==dis[x][y]+1)
			{
				if(dis[t][y]==-1)
					q.emplace(t,y);
				dis[t][y]=dis[x][y]+1;
				f[t][y]=max(f[t][y],f[x][y]);
			}
		}
		for(int p=now[y];p;p=pre[p])
		{
			int t=son[p];
			if(dis[x][t]==-1||dis[x][t]==dis[x][y]+1)
			{
				if(dis[x][t]==-1)
					q.emplace(x,t);
				dis[x][t]=dis[x][y]+1;
				f[x][t]=max(f[x][t],f[x][y]);
			}
		}
	}
	printf("%lld\n",ans);
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
		scanf("%lld%lld",&u,&v),put(u,v),put(v,u);
	dfs(1,0);
	bfs();
	
	return 0;
}