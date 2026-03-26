#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
const int M = 400005;
int read()
{
int x=0,f=1;char c;
while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
return x*f;
}
int n,m,k,q,p[M],d[M],dep[M],fa[M][20];
vector<int> g[M];
void dfs(int u,int p)
{
fa[u][0]=p;
dep[u]=dep[p]+1;
for(int i=1;i<20;i++)
fa[u][i]=fa[fa[u][i-1]][i-1];
for(auto v:g[u]) if(v^p) dfs(v,u);
}
int lca(int u,int v)
{
if(dep[u]<dep[v]) swap(u,v);
for(int i=19;i>=0;i--)
if(dep[fa[u][i]]>=dep[v])
u=fa[u][i];
if(u==v) return u;
for(int i=19;i>=0;i--)
if(fa[u][i]^fa[v][i])
u=fa[u][i],v=fa[v][i];
return fa[u][0];
}
int jump(int x,int y)
{
for(int i=19;i>=0;i--)
if(y&(1<<i)) x=fa[x][i];
return x;
}
int find(int x)
{
if(x!=p[x]) p[x]=find(p[x]);
return p[x];
}
void bfs()
{
queue<int> q;
for(int i=1;i<2*n;i++)
p[i]=i,d[i]=-1;
for(int i=1;i<=k;i++)
{
int u=read();
d[u]=0;q.push(u);
}
while(!q.empty())
{
int u=q.front();q.pop();
if(d[u]==m) break;
for(int v:g[u])
{
p[find(v)]=find(u);
if(d[v]==-1)
{
d[v]=d[u]+1;
q.push(v);
}
}
}
}
signed main()
{
n=read();m=read();k=read();
for(int i=1;i<n;i++)
{
int u=read(),v=read();
g[u].push_back(n+i);g[n+i].push_back(u);
g[v].push_back(n+i);g[n+i].push_back(v);
}
dfs(1,0);bfs();
q=read();
while(q--)
{
int u=read(),v=read(),x=lca(u,v);
int d=dep[u]+dep[v]-2*dep[x];
if(d<=2*m) {puts("YES");continue;}
int A=dep[u]-dep[x]>=m?find(jump(u,m)):find(jump(v,d-m));
int B=dep[v]-dep[x]>=m?find(jump(v,m)):find(jump(u,d-m));
if(A==B) puts("YES");
else puts("NO");
}
}