// Don't Quit  O_O

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define INF LLONG_MAX
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007

// Will become Master  ^_^

vector<vector<lli>> adj(200005);
lli vis[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t = 1, n, i;
    // cin>>t;
    while (t--)
    {
        lli m, k;
        cin >> n >> m >> k;
        lli sp[k];
        set<lli> special;
        for (i = 0; i < k; i++)
        {
            cin >> sp[i];
            special.insert(sp[i]);
        }
        lli u[m], v[m];
        for (i = 0; i < m; i++)
        {
            cin >> u[i] >> v[i];
            adj[u[i]].pb(v[i]);
            adj[v[i]].pb(u[i]);
        }
        lli dist[n + 1];
        queue<pair<lli, lli>> q;
        q.push({1, 0});
        dist[1] = 0;
        vis[1] = 1;
        while ((int)q.size())
        {
            pair<lli, lli> p = q.front();
            q.pop();
            for (auto &x : adj[p.ff])
            {
                if (!vis[x])
                {
                    q.push({x, p.ss + 1});
                    dist[x] = p.ss + 1;
                    vis[x] = 1;
                }
            }
        }
        for (i = 1; i <= n; i++)
            vis[i] = 0;
        q.push({n, 0});
        lli distn[n + 2];
        distn[n] = 0;
        vis[n] = 1;
        while ((int)q.size())
        {
            pair<lli, lli> p = q.front();
            q.pop();
            for (auto &x : adj[p.ff])
            {
                if (!vis[x])
                {
                    q.push({x, p.ss + 1});
                    distn[x] = p.ss + 1;
                    vis[x] = 1;
                }
            }
        }
        bool flag = false;
        for (i = 0; i < m; i++)
        {
            if (special.count(u[i]) && special.count(v[i]))
                flag = true;
        }
        if (flag)
        {
            cout << dist[n];
            continue;
        }
        else
        {
            lli mx = 0, ans = 0;
            vector<pair<lli, lli>> v;
            for (i = 0; i < k; i++)
                v.pb({dist[sp[i]], distn[sp[i]]});
            sort(v.begin(), v.end());
            lli suff[k];
            suff[k - 1] = v[k - 1].ss;
            for (i = k - 2; i >= 0; i--)
                suff[i] = max(suff[i + 1], v[i + 1].ss);
            for (i = 0; i < k - 1; i++)
                ans = max(ans, v[i].ff + 1 + suff[i]);
            ans = min(ans, dist[n]);
            cout << ans;
        }
    }
}