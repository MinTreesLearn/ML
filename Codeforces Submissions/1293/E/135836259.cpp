#include<bits/stdc++.h>
using namespace std;
const int maxn=3005; 
typedef long long ll; 
ll dp[maxn][maxn]; 
int fa[maxn][maxn],n;
ll cnt[maxn][maxn]; 
vector<int>g[maxn];
void dfs(int x,int f,int rt){
     cnt[rt][x]=1; 
     fa[rt][x]=f; 
     for(auto v:g[x]){
          if(v==f)continue; 
         dfs(v,x,rt);
         cnt[rt][x]+=cnt[rt][v]; 
     }
}
ll sovle(int x,int y){
      if(x==y)return 0; 
      if(dp[x][y]!=-1)return dp[x][y];
     dp[x][y]=cnt[x][y]*cnt[y][x]+max(sovle(fa[y][x],y),sovle(x,fa[x][y])); 
     return dp[x][y]; 
}
int main(){
        cin.sync_with_stdio(false);    //取消stdio同步

    cin>>n;
    for(int i=1;i<n;i++){
         int x,y;
         cin>>x>>y;
         x--,y--; 
         g[x].push_back(y);
         g[y].push_back(x); 
    }
    for(int i=0;i<n;i++)dfs(i,-1,i); 
    memset(dp,-1,sizeof(dp)); 
    ll ans=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
     {
         ans=max(ans,sovle(i,j)); 
     }
     cout<<ans<<endl; 
    return 0; 
}