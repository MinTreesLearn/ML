// LUOGU_RID: 102062552
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
const int N=3e5+5;
struct edge{
	int v,nx;
}e[N<<1],g[N<<1];
int n,ne,cnt,fe[N],fg[N],p[N],sz[N],son[N],deep[N],fa[N],top[N],id[N],rev[N];
vector<P> fv,gv;
void read(edge *eg,int *f,int u,int v)
{	eg[++ne]=(edge){v,f[u]};
	f[u]=ne;
}
int find(int x)
{	if(x==p[x])return x;
	return p[x]=find(p[x]);
}
void dfs(int u,int ffa)
{	deep[u]=deep[ffa]+1,fa[u]=ffa,sz[u]=1;
	for(int i=fe[u];i;i=e[i].nx)
	{	int v=e[i].v;
		if(v==ffa)continue;
		dfs(v,u),sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int tops)
{	top[u]=tops,id[u]=++cnt,rev[cnt]=u;
	if(son[u])dfs2(son[u],tops);
	for(int i=fe[u];i;i=e[i].nx)
	{	int v=e[i].v;
		if(v!=fa[u]&&v!=son[u])dfs2(v,v);
	}
}
void lca(int u,int v)
{	while(top[u]!=top[v])
	{	if(deep[top[u]]<deep[top[v]])gv.push_back(make_pair(id[top[v]],id[v])),v=fa[top[v]];
		else fv.push_back(make_pair(id[top[u]],id[u])),u=fa[top[u]];
	}
	if(deep[u]<deep[v])gv.push_back(make_pair(id[u],id[v]));
	else fv.push_back(make_pair(id[v],id[u]));
}
void link(int u,int v)
{	printf("%d %d ",rev[u],rev[v]);
	p[find(u)]=find(v);
}
void del(int u,int v)
{	fv.clear(),gv.clear(),lca(u,v),reverse(gv.begin(),gv.end());
	int h=0,fl=0,oo=find(id[u]);
	for(auto k:fv)
	{	int l=k.first,r=k.second;
		if(find(r)!=oo)link(r,h),fl=1;
		if(!fl&&find(l)!=oo)
		{	for(int i=18;i>=0;i--)if(r-(1<<i)>l&&find(r-(1<<i))==oo)r-=(1<<i);
			link(r,r-1),fl=1;
		}
		if(fl){printf("%d %d\n",u,v);return;}
		h=l;
	}
	for(auto k:gv)
	{	int l=k.first,r=k.second;
		if(find(l)!=oo)link(l,h),fl=1;
		if(!fl&&find(r)!=oo)
		{	for(int i=18;i>=0;i--)if(l+(1<<i)<r&&find(l+(1<<i))==oo)l+=(1<<i);
			link(l,l+1),fl=1;
		}
		if(fl){printf("%d %d\n",u,v);return;}
		h=r;
	}
}
void solve(int u,int ffa)
{	for(int i=fg[u];i;i=g[i].nx)
	{	int v=g[i].v;
		if(v!=ffa)solve(v,u);
	}
	if(ffa)del(u,ffa);
}
int main()
{	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{	scanf("%d%d",&u,&v);
		read(e,fe,u,v),read(e,fe,v,u);
	}
	ne=0;
	for(int i=1,u,v;i<n;i++)
	{	scanf("%d%d",&u,&v);
		read(g,fg,u,v),read(g,fg,v,u);
	}
	for(int i=1;i<=n;i++)p[i]=i;
	dfs(1,0),dfs2(1,1);
	printf("%d\n",n-1);
	solve(1,0);
	return 0;
}