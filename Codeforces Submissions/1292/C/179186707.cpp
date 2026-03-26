#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3009;
ll dp[N][N];
int par[N][N],chil[N][N];
int n;
vector<int>a[N];
ll res=0;
void dfs1(int u,int pa,int g){
    chil[g][u]=1;
    for(int v:a[u]){
        if(v!=pa){
            par[g][v]=u;
            dfs1(v,u,g);
            chil[g][u]+=chil[g][v];
        }
    }
}
ll bt(int u,int v){
    if(dp[u][v]!=0||u==v)return dp[u][v];
    dp[u][v]=1LL*chil[u][v]*chil[v][u]+max(bt(u,par[u][v]),bt(v,par[v][u]));
    return dp[u][v];
}
void giai(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++)dfs1(i,i,i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)res=max(res,bt(i,j));
    }
    //for(int i=1;i<=n;i++)dfs2(i,i,i);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<chil[i][j]<<'\n';
    // }
    // cout<<'\n';
    cout<<res;
}
int main(){
    if(fopen("solve.inp","r")){
        freopen("solve.inp","r",stdin);
        freopen("solve.out","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    giai();
}