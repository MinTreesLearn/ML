#include <bits/stdc++.h>
using namespace std;

//hello

#define int long long
#define inf (1ll<<60)
#define pii pair<int,int>
int32_t N = 2e6 + 5;
int32_t mod = 1e9 + 7;

void dfs1(int v, int p, vector<int> &a, vector<vector<int>> &adj, vector<int> &cnt)
{
    cnt[v] = a[v];
    
    for(auto u : adj[v])
    {
        if(u != p)
        {
            dfs1(u,v,a,adj,cnt);
            cnt[v] += max(0ll,cnt[u]);
        }
    }
}

void dfs2(int v, int p, vector<int> &a, vector<vector<int>> &adj, vector<int> &cnt, vector<int> &ans)
{
    ans[v] = cnt[v];
    
    for(auto u : adj[v])
    {
        if(u != p)
        {
            cnt[v] -= max(0ll,cnt[u]);
            cnt[u] += max(0ll,cnt[v]);
            dfs2(u,v,a,adj,cnt,ans);
            cnt[u] -= max(0ll,cnt[v]);
            cnt[v] += max(0ll,cnt[u]);
        }
    }
}

void solveCase()
{
    int n=0;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        a[i] = a[i]==0 ? -1 : a[i];
    }
    
    vector<vector<int>> adj(n+1,vector<int>());
    vector<int> cnt(n+1,0), ans(n+1,0);
    
    for(int i=0; i<n-1; i++)
    {
        int u=0, v=0;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs1(1,-1,a,adj,cnt);
    
    dfs2(1,-1,a,adj,cnt,ans);
    
    for(int i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solveCase();
}