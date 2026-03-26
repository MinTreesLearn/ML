// @cvtrana
#include <bits/stdc++.h>
using namespace std;

#define jai__Bhawanii   ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif
map<int,vector<int>> m;
vector<int> v(200005);
vector<int> dp(200005);
vector<int> ans(200005);
void dfs(int node,int par){
    dp[node] = v[node];
    for(auto x:m[node]){
        if(x==par)continue;
        dfs(x,node);
        dp[node]  +=  max((int)0,dp[x]);
    }
}
// to get rid of rollbacks , we can also create a new DP
void dfs2(int node,int par){
    ans[node] = dp[node];
    for(auto x:m[node]){
        if(x==par)continue;
        // reroot the adjacent node
        dp[node] -= max((int)0,dp[x]);
        dp[x] += max((int)0,dp[node]);
        dfs2(x,node);
        // rollback for others
        dp[x]-= max((int)0,dp[node]);
        dp[node] += max((int)0,dp[x]);
    }
}
void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i]; // colors;
        if (v[i] == 0) v[i] = -1;
    }
    int t = n-1;
    while(t--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        m[a].pb(b);
        m[b].pb(a);

    }
    //de(m);
    dfs(0,-1);
    dfs2(0,-1);
    for(int i=0;i<n;i++){
        cout << ans[i] <<" ";
    }
    cout << endl;



}

signed main()
{
    jai__Bhawanii;
    // int t; cin >> t;

    // while (t--)
    // {
    solve();
    // }
}

 


