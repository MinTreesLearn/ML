#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, M = 20;

vector<int> adj[N];
int dep[N], Par[N][M], path[N];
 
void dfs(int cur, int par) 
{
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;
    for (int j = 1; j < M; j++) Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    for (auto x : adj[cur]) if (x != par)  dfs(x, cur);
}
 
int LCA(int u, int v) 
{
    if (u == v) return u;
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int j = M - 1; j >= 0; j--) 
    {
        if ((diff >> j) & 1) u = Par[u][j];
    }
 
    for (int j = M - 1; j >= 0; j--) 
    {
        if (Par[u][j] != Par[v][j]) {
            u = Par[u][j];
            v = Par[v][j];
        }
    }
 
    return (u != v ? Par[u][0] : u);
}
 
int distance(int a, int b)
{
    int c = LCA(a, b);
    return dep[a] + dep[b] - 2*dep[c];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    int q; cin >> q;

    for(int i = 1; i <= q; i++)
    {
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
        int path1 = distance(a, b);
        int path2 = distance(a, x) + distance(y, b) + 1;
        int path3 = distance(a, y) + distance(x, b) + 1;
        if(path1 <= k && path1%2 == k%2) cout << "YES\n";
        else if(path2 <= k && path2%2 == k%2) cout << "YES\n";
        else if(path3 <= k && path3%2 == k%2) cout << "YES\n";
        else cout << "NO\n";
    }
}