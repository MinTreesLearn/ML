#include <bits/stdc++.h>

using namespace std;

using LL = long long;
#define endl '\n'
using db = double;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> fa(n + 1), c(n + 1);
    int root;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> fa[i] >> c[i];
        if (fa[i] == 0)
            root = i;
        else
            g[fa[i]].push_back(i);
        // cout << "i = " << i << " fa[i] = " << fa[i] << "  c[i] = " << c[i] << endl;
    }

    bool ok = 1;
    vector<int> sz(n + 1);
    function<void(int)> dfs = [&](int u) -> void
    {
        sz[u] = 1;
        for (auto to : g[u])
        {
            dfs(to);
            sz[u] += sz[to];
        }
        if (c[u] >= sz[u])
            ok = 0;
    };
    dfs(root);

    if (ok == 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> a(n + 1), in(n + 1), out(n + 1);
    int id = 0;
    function<void(int)> dfs2 = [&](int u) -> void
    {
        in[u] = ++id;
        int pre = 0;
        for (auto to : g[u])
        {
            dfs2(to);
            for (int i = in[to]; i <= out[to]; ++i)
                a[i] += pre;
            pre += sz[to];
        }
        out[u] = id;
        a[in[u]] = c[u];
        for (int i = in[u] + 1; i <= out[u]; ++i)
            if (a[i] >= a[in[u]])
                a[i]++;
        // for (auto to : g[u])
        // {
        // }
    };
    dfs2(root);
    cout << "YES" << endl;
    // for (int i = 1; i <= n; ++i)
    //     cout << "i = " << i << " in[i] = " << in[i] << " out[i] = " << out[i] << endl;
    for (int i = 1; i <= n; ++i)
        cout << a[in[i]] + 1 << " ";
    cout << endl;
    return 0;
}