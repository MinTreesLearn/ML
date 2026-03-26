#include <bits/stdc++.h>
using namespace std;
#define line cout << "\n";
const int N = 2e5 + 2;

set<int> adj[N];
int vis[N];
void dfs(int u, int p)
{
    char c = u + 'a';
    vis[u] = 1;
    cout << c;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        if (vis[v] == 1)
            continue;
        dfs(v, u);
    }
}
void solve()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        int x = s[i - 1] - 'a';
        int y = s[i] - 'a';
        adj[x].insert(y);
        adj[y].insert(x);
    }
    int root = 0;
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < 26; i++)
    {
        if (adj[i].size() == 1)
        {
            cnt++;
            ok = true;
            root = i;
        }
        if (adj[i].size() > 2)
        {
            ok = ok & false;
        }
    }
    if (cnt != 2)
        ok = false;
    if (s.size() == 1)
        ok = true;

    if (ok)
    {
        cout << "YES";
        line;
        dfs(root, -1);
        for (int i = 0; i < 26; i++)
        {
            if (vis[i] == 0)
            {
                char c = i + 'a';
                cout << c;
            }
            vis[i] = 0;
            adj[i].clear();
        }
        line;
    }
    else
    {
        cout << "NO";
        line;
        for (int i = 0; i < 26; i++)
        {
            vis[i] = 0;
            adj[i].clear();
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}