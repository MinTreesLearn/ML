#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 1000 +10;

int n, q;
int dp[N][22], st[N], ft[N], t, h[N];
int k, m, vir[N], S[N], is_vir[N], added[N];
int ans[N];
long long ans_time[N];

vector<int>vertex;
vector<int> adj[N];
set<pair<int,int>> vertex_st;
set<pair<int,long long>> s;

bool cmp(int u, int v){return (st[u] < st[v]);}

void dfs(int parent, int u)
{
    dp[u][0] = parent;
    for(int j=1; j<20 && dp[u][j-1]; j++)
        dp[u][j] = dp[dp[u][j-1]][j-1];
    st[u] = ++t;
    for(auto v : adj[u])
        if(v != parent)
            h[v] = h[u] + 1, dfs(u, v);
    ft[u] = ++t;
}

int LCA(int u, int v)
{
    if(h[u] < h[v])
        swap(u, v);
    for(int j=19; j>=0; j--)
        if(h[u] - h[v] >= (1 << j))
            u = dp[u][j];
    if(u == v)
        return u;
    for(int j=19; j>=0; j--)
        if(dp[u][j] != dp[v][j])
            u = dp[u][j], v = dp[v][j];
    return dp[u][0];
}

long long dist(int u, int viruse)
{
    int v = vir[viruse];
    if(u == v)
        return 0;

    int lca = LCA(u, v);
    int d = (h[u] - h[lca]) + (h[v] - h[lca]);
    int round = d/S[viruse] + (d%S[viruse] == 0 ? -1 : 0);
    long long ret = ((long long)round * (long long)k) + (long long)viruse;
    return ret;
}

bool in_sub(int v, int u)
{
    if(st[u] <= st[v] && st[v] <= ft[u])
        return true;
    else
        return false;
}

bool check(int u, int j)
{
    auto au1 = s.lower_bound({st[dp[u][j]], -10});
    int mn = 0;
    if(au1 != s.end() && st[au1 -> second] < ft[dp[u][j]])
        mn = au1 -> second;

    auto au = s.upper_bound({ft[dp[u][j]], -10});
    int mx = 0;
    if(au != s.begin())
    {
        au --;
        if(st[dp[u][j]] < st[au -> second])
            mx = au -> second;
    }
    return !((mx == 0 || in_sub(mx, u)) && (mn == 0 || in_sub(mn, u)));
}

int first_up(int u)
{
    for(int j=19; j>=0;j--)
        if(dp[u][j] != 0 && check(u, j) == false)
            u = dp[u][j];
    return (u == 1 ? -1 : dp[u][0]);
}

int pnt = 0;
void dfs_down(int u)
{
    if(is_vir[u])
        ans[u] = is_vir[u], ans_time[u] = 0;

    while(++pnt < vertex.size())
    {
        int v = vertex[pnt];
        if(in_sub(v, u) == false)
        {
            pnt--;
            break;
        }

        dfs_down(v);
        long long d = dist(u, ans[v]);
        if(ans_time[u] == -1 || d < ans_time[u])
            ans[u] = ans[v], ans_time[u] = d;
    }
}

void dfs_up(int parent, int u)
{
    if(parent && (ans_time[u] == -1 || dist(u, ans[parent]) < ans_time[u]))
        ans[u] = ans[parent];

    while(++pnt < vertex.size())
    {
        int v = vertex[pnt];
        if(in_sub(v, u) == false)
        {
            pnt --;
            break;
        }
        dfs_up(u, v);
    }
}

int query(int u)
{
    long long mn = -1;
    int ansasli = 0;

    auto au = vertex_st.lower_bound({st[u], -10});
    if(au != vertex_st.end() && au -> first <= ft[u])
        mn = dist(u, ans[au -> second]), ansasli = ans[au -> second];

    int up = first_up(u);
    if(up == -1)
        return ansasli;
    if(added[up])
    {
        long long d = dist(u, ans[up]);
        if(mn == -1 || d < mn)
            ansasli = ans[up];
    }
    else
    {
        int v = query(up);
        long long d = dist(u, v);
        if(mn == -1 || d < mn)
            ansasli = v;
    }
    return ansasli;
}

void Main()
{
    cin>>k>>m;
    for(int i=1;i<=k;i++)
    {
        cin>>vir[i]>>S[i];
        is_vir[vir[i]] = i;

        s.insert({st[vir[i]], vir[i]});
    }

    for(int i=1;i<=k;i++)
    {
        int u = vir[i];
        while(u != -1 && added[u] == 0)
        {
            vertex.push_back(u), added[u] = 1;
            u = first_up(u);
        }
    }
    sort(vertex.begin(), vertex.end(), cmp);
    pnt = 0, dfs_down(vertex[0]);
    pnt = 0, dfs_up(0, vertex[0]);
    for(auto u : vertex)
        vertex_st.insert({st[u], u});

    while(m--)
    {
        int u; cin>>u;
        cout<<query(u)<<" ";
    }
    cout<<'\n';

    for(auto u : vertex)
    {
        is_vir[u]   =  0;
        added[u]    =  0;
        ans_time[u] = -1;
    }
    s.clear();
    vertex.clear();
    vertex_st.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);

    fill(ans_time, ans_time+n+1, -1);
    cin>>q;
    while(q--)
        Main();
    return 0;
}
