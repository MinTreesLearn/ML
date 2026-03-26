#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int st[N];
int rs[N],dp[N];
int e[N][27];
vector<pair<int,int>> stk;
int Rank;
void dfs(int u)
{ 
      Rank+=st[u]; 
    if(stk.size()&&st[u])
    dp[u]=min(dp[u],stk.back().second+Rank);
    //if(u==1)cout<<stk.size()<<endl;
    //if(u)
   // if(u!=5)
    if(stk.empty()||stk.back().second>=dp[u]-Rank+st[u])
    stk.push_back({u,dp[u]-Rank+st[u]});
        //if(u==7){cout<<stk.back().second<<" "<<stk.back().second+Rank+1<<" "<<dp[u]<<endl;}
    
    //cout<<stk.size()<<endl;
    for(int i=0;i<26;++i)
    {
        if(!e[u][i])continue;
        int v=e[u][i];
        dp[v]=dp[u]+1;
        dfs(v);
    }
    if(stk.size()&&stk.back().first==u)stk.pop_back();
}
int main()
{
    int n,m;scanf("%d",&n);
    char op[3];
    for(int i=1,fa;i<=n;++i)
    {
        scanf("%d%s",&fa,op);e[fa][op[0]-'a']=i;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i)scanf("%d",&rs[i]),st[rs[i]]=1;
    dfs(0);
    for(int i=1;i<=m;++i)printf("%d%c",dp[rs[i]]," \n"[i==m]);
    // cout<<stk.size();
}