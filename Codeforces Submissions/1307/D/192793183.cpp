#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=N*2;
struct E {
int v,next;
} e[M];
int n,m,k,u,v,p[N],len,h[N],d1[N],d2[N];
void add(int u,int v) {
e[++len].v=v;
e[len].next=h[u];
h[u]=len;
}
void bfs(int d[],int u) {
queue<int>q;
q.push(u);
memset(d,-1,sizeof(d1));
d[u]=0;
while(!q.empty()) {
u=q.front();
q.pop();
for(int j=h[u]; j; j=e[j].next) {
int v=e[j].v;
if(d[v]==-1)d[v]=d[u]+1,q.push(v);
}
}
}
bool cmp(int u,int v){
return (d1[u]-d2[u])<(d1[v]-d2[v]);
}
int main() {
cin>>n>>m>>k;
for(int i=1;i<=k;i++)cin>>p[i];
for(int i=1;i<=m;i++){
cin>>u>>v;
add(u,v);
add(v,u);
}
bfs(d1,1);
bfs(d2,n);
sort(p+1,p+1+k,cmp);
int ans=0,mx=-1e9;
for(int i=1;i<=k;i++){
v=p[i];
ans=max(ans,mx+d2[v]);
mx=max(mx,d1[v]);
}
cout<<min(ans+1,d1[n]);
return 0;
}