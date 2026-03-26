#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> func(vector<vector<int>> &roads, int x)
{
    int n = roads.size();
    queue<int> q;
    vector<int> dist(n, 1e9);
    q.push(x);
    dist[x] = 0;
    while (q.size())
    {
        int a = q.front(); q.pop();
        int d = dist[a];
        for (int child : roads[a])
        {
            if (dist[child] < 1e9) continue;

            dist[child] = d + 1;
            q.push(child);
        }
    }
    return dist;
}

// long loooooooooooooooong;
void solve(ll kkkk, ll tttt)
{
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> roads(n);
    vector<int> ks(k);
    for (int i = 0; i < k; i++) cin >> ks[i], ks[i]--;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y; x--, y--;
        roads[x].push_back(y);
        roads[y].push_back(x);
    }
    vector<int> d1 = func(roads, 0);
    vector<int> d2 = func(roads, n - 1);

    vector<pair<int, int>> v1(k); for (int i = 0; i < k; i++) v1[i].first = d1[ks[i]], v1[i].second = ks[i];

    sort(v1.begin(), v1.end());
    map<int, int> mapp;
    for (int i = 0; i < k; i++) mapp[d2[v1[i].second]]++;
    int ans = 0;
    for (int i = 0; i < k - 1; i++)
    {
        int f = v1[i].second;
        mapp[d2[f]]--; if (mapp[d2[f]] == 0) mapp.erase(d2[f]);
        ans = max(ans, d1[f] + mapp.rbegin()->first + 1);
    }
    ans = min(ans, d2[0]);
    cout << ans << endl;
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
    fast();
    int t = 0, i = 0;
//    int t; cin >> t;
//    for (int i = 1; i <= t; i++)

        solve(t, i);
    return 0;
}

