#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

ll ans = 0;

ll dfs(ll x, vector<vector<ll>> &roads, vector<ll> &visited)
{
    if (visited[x]) return 0;
    visited[x] = true;

    ll depth = 0;

    for (ll child : roads[x])
        depth = max(depth, dfs(child, roads, visited));

    ans += ++depth;
    ans %= MOD;
    return depth;
}

// long loooooooooooooooong;
void solve(ll kkkk, ll tttt)
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];

    k = min(k, m - 1);
    int rest = m - k - 1;
    int ans = -1;
    for (int i = 0; i <= k; i++)
    {
        int newstart = i, newend = n - 1 - (k - i);
        int current = 1e9 + 5;
        for (int j = 0; j <= rest; j++)
        {
            int s = newstart + j, e = newend - (rest - j);
            int c = max(arr[s], arr[e]);
            current = min(current, c);
        }
        ans = max(ans, current);
    }
    cout << ans << endl;
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
    fast();
//    int t = 0, i = 0;

    int t; cin >> t;
    for (int i = 1; i <= t; i++)

    solve(t, i);
    return 0;
}

