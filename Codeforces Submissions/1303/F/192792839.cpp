#include<bits/stdc++.h>
using namespace std;
int n,m,q,fa[4000005],ma[305][305],id[305][305],idx,ans[2000005],cur;
int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
struct P{
int x,y,f,t;
}p[2000005];
void merge(int x,int y){
x=get(x);
y=get(y);
if(x==y)return;
fa[x]=y;
cur--;
}
void solve(int x,int y){
if(ma[x][y]==ma[x-1][y])merge(id[x][y],id[x-1][y]);
if(ma[x][y]==ma[x+1][y])merge(id[x][y],id[x+1][y]);
if(ma[x][y]==ma[x][y-1])merge(id[x][y],id[x][y-1]);
if(ma[x][y]==ma[x][y+1])merge(id[x][y],id[x][y+1]);
}
int main(){
int i,j;
scanf("%d%d%d",&n,&m,&q);
for(i=0;i<=m+1;i++)ma[0][i]=ma[n+1][i]=-1;
for(i=1;i<=n;i++)ma[i][0]=ma[i][m+1]=-1;
for(i=1;i<=q;i++){
scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].t);
p[i].f=ma[p[i].x][p[i].y];
if(p[i].f!=p[i].t){
ma[p[i].x][p[i].y]=p[i].t;
cur=1;
id[p[i].x][p[i].y]=++idx;
fa[idx]=idx;
solve(p[i].x,p[i].y);
ans[i]+=cur;
}
}
idx=0;
for(i=1;i<=n;i++){
for(j=1;j<=m;j++){
id[i][j]=++idx;
fa[idx]=idx;
}
}
for(i=1;i<=n;i++){
for(j=1;j<=m;j++){
solve(i,j);
}
}
for(i=q;i>=1;i--){
if(p[i].f!=p[i].t){
ma[p[i].x][p[i].y]=p[i].f;
cur=1;
id[p[i].x][p[i].y]=++idx;
fa[idx]=idx;
solve(p[i].x,p[i].y);
ans[i]-=cur;
}
}
ans[0]=1;
for(i=1;i<=q;i++){
ans[i]=ans[i-1]+ans[i];
printf("%d\n",ans[i]);
}
return 0;
}
