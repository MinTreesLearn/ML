// LUOGU_RID: 90825835
#include<cstdio>
#include<vector>
#include<queue>
const int maxn=20;
struct dsu
{
	int n,fa[400005];
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void pre(int n){this->n=n;for (int i=1;i<=n;i++) fa[i]=i;}
	void merge(int x,int y){/*printf("Merge %d %d\n",x,y);*/fa[find(x)]=find(y);}
};
dsu ss;
int n,k,c,q,fa[400005][25],col[400005],dep[400005],d[400005],cnt;
std::vector<int> a[400005],p;
void add(int x,int y){a[x].push_back(y);a[y].push_back(x);}
void dfs(int v,int x,int d)
{
//	printf("dfs %d %d %d\n",v,x,d);
	dep[v]=d;
	fa[v][0]=x;
	for (int i=1;i<=maxn;i++) fa[v][i]=fa[fa[v][i-1]][i-1];
	for (int i=0;i<(int)a[v].size();i++)
	{
		int u=a[v][i];
//		printf("Edge %d %d\n",v,u);
		if (u==x) continue;
		dfs(u,v,d+1);
	}
}
void bfs(std::vector<int> s)
{
	std::queue<int> q;
	for (int i=1;i<=n;i++) d[i]=0;
	for (int i=0;i<(int)s.size();i++) col[s[i]]=i+1,q.push(s[i]);
	while (!q.empty())
	{
		int v=q.front();q.pop();
		if (d[v]==k) continue;
//		printf("v = %d\n",v);
		for (int i=0;i<(int)a[v].size();i++)
		{
			int u=a[v][i];
			if (col[u]) ss.merge(col[v],col[u]);
			else col[u]=col[v],d[u]=d[v]+1,q.push(u);
		}
	}
}
int getfa(int x,int k)
{
	for (int i=maxn;i>=0;i--) if (k&(1<<i)) x=fa[x][i];
	return x;
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) std::swap(x,y);
	for (int i=maxn;i>=0;i--) if ((dep[x]-dep[y])&(1<<i)) x=fa[x][i];
	if (x==y) return x;
	for (int i=maxn;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int getdis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
void getstp(int &x,int y,int k)
{
	int d=lca(x,y);
	if (dep[x]-dep[d]>=k) x=getfa(x,k);
	else x=getfa(y,getdis(x,y)-k);
}
int solve(int x,int y)
{
	if (getdis(x,y)<=2*k||col[x]==col[y]&&col[x]&&col[y]) return 1;
//	printf("%d %d %d\n",x,y,getdis(x,y));
	getstp(x,y,k),getstp(y,x,k);
//	printf("%d %d\n",x,y);
	int px=col[x],py=col[y];
	return (px&&py&&px==py);
}
int main()
{
	scanf("%d%d%d",&n,&k,&c);cnt=n;
	for (int i=1;i<n;i++){int x,y,p=++cnt;scanf("%d%d",&x,&y);add(x,p),add(p,y);}
	ss.pre(n);
	n=cnt;
	for (int i=1;i<=c;i++){int x;scanf("%d",&x);p.push_back(x);}
	bfs(p);
	dfs(1,1,1);
	for (int i=1;i<=n;i++) col[i]=ss.find(col[i]);
//	for (int i=1;i<=n;i++) printf("%d ",col[i]);puts("");
	scanf("%d",&q);
	while (q--){int x,y;scanf("%d%d",&x,&y);solve(x,y)?puts("YES"):puts("NO");}
	return 0;
}