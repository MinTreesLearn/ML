#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define float long double
#define double long double
#define endl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f(i,a,b) for(int i = a; i <= b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define vec vector<int>
#define dvec vector<vector<int>>
#define pb push_back
//************Nitin1605************
vector<int> colour(200001,-1);
dvec g(200001);
vec dp(200001,-10);vector<bool> vis(200001,false);
int answer(int n,int p)
{
    int ok=0;
    for(auto i:g[n])
    {
        if(i==p)continue;
        if(dp[i]==-10)answer(i,n);
        if(dp[i]>0)ok=ok+dp[i];
    }
    if(colour[n]==1)ok++;
    else ok--;
    dp[n]=ok;
    return ok;
}
void dfs(int p,int c)
{
    if(dp[c]>0)
    {
        if((dp[p]-dp[c])>0 && dp[c]>0)dp[c]=dp[p];
    }
    else 
    {
        if(dp[p]>0)dp[c]+=dp[p];
    }
    vis[c]=true;
    for(auto i:g[c])if(!vis[i])dfs(c,i);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cout << fixed << setprecision(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int TESTCASES=1,n;
    //cin>>TESTCASES;
    f(test,1,TESTCASES)
    {
        cin >> n;
        f(i,1,n)cin >> colour[i];
        f(i,1,n-1)
        {
            int x,y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        answer(1,0);vis[1]=true;
        for(auto i:g[1])dfs(1,i);
        f(i,1,n)cout << dp[i] << " ";
    }
}