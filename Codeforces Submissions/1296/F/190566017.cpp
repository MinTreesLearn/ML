#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define N 5005
// #define mod 998244353
#define endl '\n'
// #define int long long
// #define ll long long
// #define ll __int128
// #define double long double
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

int n, mp[N][N], x[N], y[N], a[N], b[N], c[N], m, dep[N];
int tot, head[N], nxt[N << 1], to[N << 1], val[N << 1];
void add(int x, int y, int z)
{
    nxt[tot] = head[x], to[tot] = y, val[tot] = z, head[x] = tot++;
}
void dfs(int fa, int cur)
{
    dep[cur] = dep[fa] + 1;
    for (int p = head[cur]; ~p; p = nxt[p])
        if (!dep[to[p]])
            dfs(cur, to[p]);
}
void work(int x, int y, int z)
{
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] != dep[y])
    {
        for (int p = head[x]; ~p; p = nxt[p])
        {
            if (dep[to[p]] + 1 == dep[x])
            {
                val[p] = val[p ^ 1] = max(val[p], z);
                x = to[p];
                break;
            }
        }
    }
    while (x != y)
    {
        for (int p = head[x]; ~p; p = nxt[p])
        {
            if (dep[to[p]] + 1 == dep[x])
            {
                val[p] = val[p ^ 1] = max(val[p], z);
                x = to[p];
                break;
            }
        }
        for (int p = head[y]; ~p; p = nxt[p])
        {
            if (dep[to[p]] + 1 == dep[y])
            {
                val[p] = val[p ^ 1] = max(val[p], z);
                y = to[p];
                break;
            }
        }
    }
}
bool check(int x, int y, int z)
{
    int res = 2e6;
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] != dep[y])
    {
        for (int p = head[x]; ~p; p = nxt[p])
        {
            if (dep[to[p]] + 1 == dep[x])
            {
                res = min(res, val[p]);
                x = to[p];
                break;
            }
        }
    }
    while (x != y)
    {
        for (int p = head[x]; ~p; p = nxt[p])
        {
            if (dep[to[p]] + 1 == dep[x])
            {
                res = min(res, val[p]);
                x = to[p];
                break;
            }
        }
        for (int p = head[y]; ~p; p = nxt[p])
        {
            if (dep[to[p]] + 1 == dep[y])
            {
                res = min(res, val[p]);
                y = to[p];
                break;
            }
        }
    }
    return res == z;
}
void solve()
{
    cin >> n;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++)
    {
        cin >> x[i] >> y[i];
        add(x[i], y[i], 1);
        add(y[i], x[i], 1);
    }
    dfs(0, 1);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        work(a[i], b[i], c[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (!check(a[i], b[i], c[i]))
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < tot; i += 2)
        cout << val[i] << " ";
}
signed main()
{
    fastio;
    // freopen("data.in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    // fclose(stdin);
}