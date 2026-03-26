#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
int n,m,k,col[N];vector<int>d[N];
inline int id(int x,int y,int z){return (x-1)*m*k+(y-1)*k+z;}
void ins(int x,int y,int z,int c,int tp)
{
if(x<1||x>n||y<1||y>m||z<1||z>k)
{
if(c)puts("-1"),exit(0);
return;
}
int now=id(x,y,z);
if(col[now]==-1||col[now]==c)
{
col[now]=c;d[now].push_back(tp);
if(!c)ins(x+dx[tp],y+dy[tp],z+dz[tp],c,tp);
return;
}
if(col[now]>0)
while(!d[now].empty())
{
int o=d[now].back();
d[now].pop_back();
ins(x+dx[o],y+dy[o],z+dz[o],col[now],o);
}
col[now]=0;
ins(x+dx[tp],y+dy[tp],z+dz[tp],c,tp);
}
int main()
{
memset(col,-1,sizeof col);
scanf("%d%d%d",&n,&m,&k);
for(int i=1,t;i<=m;++i)for(int j=1;j<=k;++j)scanf("%d",&t),ins(1,i,j,t,0);
for(int i=1,t;i<=m;++i)for(int j=1;j<=k;++j)scanf("%d",&t),ins(n,i,j,t,1);
for(int i=1,t;i<=n;++i)for(int j=1;j<=k;++j)scanf("%d",&t),ins(i,1,j,t,2);
for(int i=1,t;i<=n;++i)for(int j=1;j<=k;++j)scanf("%d",&t),ins(i,m,j,t,3);
for(int i=1,t;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&t),ins(i,j,1,t,4);
for(int i=1,t;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&t),ins(i,j,k,t,5);
for(int i=1;i<=n*m*k;++i)printf("%d ",col[i]<0?0:col[i]);
return 0;
}