#include<cstdio>
#include<vector>
std::vector<int> v[300010],g[300010];
int f[300010][20],d[300010],n,q[300010];
int find(int x){while(x!=q[x])x=q[x]=q[q[x]];return x;}
void dfs1(int x){
d[x]=d[f[x][0]]+1,q[x]=x;
for(int i=1;i<19;i++)f[x][i]=f[f[x][i-1]][i-1];
for(auto u:v[x])if(u!=f[x][0])f[u][0]=x,dfs1(u);
}
void link(int x,int y){
x=find(x),y=find(y);
for(int i=18;~i;i--) if(d[find(f[x][i])]>d[y]) x=find(f[x][i]);
if(find(f[x][0])==y) x=find(x);
else x=find(y);
printf("%d %d ",x,q[x]=f[x][0]);
}
void dfs2(int x,int fa){
for(auto u:g[x])if(u!=fa) dfs2(u,x),link(x,u),printf("%d %d\n",x,u);
}
int main(){
scanf("%d",&n);
for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
printf("%d\n",n-1);
dfs1(1),dfs2(1,0);
return 0;
}