#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,rt,u,v,p[3005][3005],s[3005][3005];
LL f[3005][3005],ans;
vector<int> G[3005];
void build(int u)
{
s[rt][u]=1;
for(int v:G[u])
if(v^p[rt][u])
{
p[rt][v]=u;
build(v);
s[rt][u]+=s[rt][v];
}
}
LL dp(int u, int v)
{
if(u==v)return 0;
if(f[u][v])return f[u][v];
return f[u][v]=max(dp(u,p[u][v]),dp(v,p[v][u]))+s[u][v]*s[v][u];
}
signed main()
{
ios::sync_with_stdio(false);
cin>>n;
for(int i=1;i<n;i++)
{
cin>>u>>v;
G[u].push_back(v);
G[v].push_back(u);
}
for(int i=1;i<=n;i++)rt=i,build(i);;
for(int u=1;u<=n;u++)
for(int v=1;v<=n;v++)
ans=max(ans,dp(u, v));
cout<<ans;
return 0;
}