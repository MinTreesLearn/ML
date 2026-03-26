#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
const int N=5e3+10,logn=15;

pii f[logn+1][N<<1];
int dep[N],tot,first_pos[N];
vector<int>e[N];
int g[N][N];
int par[N];
void dfs(int u,int fa)
{
    first_pos[u]=++tot;
    dep[u]=dep[fa]+1;
    f[0][tot]={dep[u],u};
    par[u]=fa;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        f[0][++tot]={dep[u],u};
    }
}
void init(int root)
{
    dfs(root,0);
    for(int i=1;i<=logn;++i)
        for(int j=1;j<=tot;++j)
        f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
}
int LCA(int a,int b)
{
    int l=first_pos[a],r=first_pos[b];
    if(l>r)swap(l,r);
    int len=31-__builtin_clz(r-l+1);
    return min(f[len][l],f[len][r-(1<<len)+1]).second;
}

void modify(int u,int v,int col)
{
    int lca=LCA(u,v);
    while(u!=lca){int fa=par[u];g[fa][u]=g[u][fa]=col;u=fa;}
    while(v!=lca){int fa=par[v];g[fa][v]=g[v][fa]=col;v=fa;}
}
int query(int u,int v)
{
    int lca=LCA(u,v);
    int rs=1e6;
    while(u!=lca){int fa=par[u];rs=min(rs,g[u][fa]);u=fa;}
    while(v!=lca){int fa=par[v];rs=min(rs,g[v][fa]);v=fa;}
    return rs;
}
void solve()
{
    int n;scanf("%d",&n);
    vector<array<int,2>>edge(n-1);
    for(auto &[u,v]:edge)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
    for(auto &[u,v]:edge)g[u][v]=g[v][u]=1e6;
    init(1);
    int m;scanf("%d",&m);
    vector<array<int,3>>p(m);
    for(auto &[w,u,v]:p)scanf("%d%d%d",&u,&v,&w);
    sort(p.begin(),p.end());
    for(auto [w,u,v]:p)
    {
        modify(u,v,w);
    }
     for(auto [w,u,v]:p)if(query(u,v)!=w){printf("-1\n");return ;}
     for(auto &[u,v]:edge)printf("%d ",g[u][v]);
}
int main()
{
    int T=1;
    while(T--)solve();
}