#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int M = 1005;
const int inf = 0x3f3f3f3f;
int read()
{
int x=0,f=1;char c;
while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
return x*f;
}
int n1,n2,m,R,B,s1,t1,S,T,d[M];char sa[M],sb[M];
int tot=1,f[M],dis[M],flow[M],pre[M],lst[M];
struct edge
{
int v,f,c,next;
}e[M*M];
void add(int u,int v,int l,int r,int c)
{
d[u]-=l;d[v]+=l;
e[++tot]=edge{v,r-l,c,f[u]},f[u]=tot;
e[++tot]=edge{u,0,-c,f[v]},f[v]=tot;
}
int bfs()
{
queue<int> q;
for(int i=0;i<=T;i++)
dis[i]=inf,flow[i]=pre[i]=lst[i]=0;
dis[S]=0;flow[S]=inf;q.push(S);
while(!q.empty())
{
int u=q.front();q.pop();
for(int i=f[u];i;i=e[i].next)
{
int v=e[i].v,c=e[i].c;
if(dis[v]>dis[u]+c && e[i].f>0)
{
dis[v]=dis[u]+c;
flow[v]=min(flow[u],e[i].f);
pre[v]=u;lst[v]=i;
q.push(v);
}
}
}
return flow[T]>0;
}
signed main()
{
n1=read();n2=read();m=read();R=read();B=read();
scanf("%s%s",sa+1,sb+1);
s1=n1+n2+1;t1=s1+1;S=t1+1;T=S+1;
for(int i=1;i<=m;i++)
{
int u=read(),v=read();
add(u,v+n1,0,1,R);
add(v+n1,u,0,1,B);
}
for(int i=1;i<=n1;i++)
{
if(sa[i]=='R') add(s1,i,1,inf,0);
else if(sa[i]=='B') add(i,t1,1,inf,0);
else add(s1,i,0,inf,0),add(i,t1,0,inf,0);
}
for(int i=1;i<=n2;i++)
{
if(sb[i]=='R') add(i+n1,t1,1,inf,0);
else if(sb[i]=='B') add(s1,i+n1,1,inf,0);
else add(s1,i+n1,0,inf,0),add(i+n1,t1,0,inf,0);
}
add(t1,s1,0,inf,0);
int ans=0,cost=0,sum=0;
for(int i=1;i<=t1;i++)
{
if(d[i]>0) sum+=d[i],add(S,i,0,d[i],0);
if(d[i]<0) add(i,T,0,-d[i],0);
}
while(bfs())
{
ans+=flow[T];int nw=T;
cost+=flow[T]*dis[T];
while(nw!=S)
{
e[lst[nw]].f-=flow[T];
e[lst[nw]^1].f+=flow[T];
nw=pre[nw];
}
}
if(ans<sum) {puts("-1");return 0;}
printf("%d\n",cost);
for(int i=2;i<=4*m;i+=4)
{
if(!e[i].f) putchar('R');
else if(!e[i+2].f) putchar('B');
else putchar('U');
}
puts("");
}