#include <bits/stdc++.h>
#define SQ(a) (a)*(a)
#define all(a) (a).begin(), (a).end()

using namespace std;
using i64 = long long int;
using pi = pair<int, int>;

constexpr int INF{ numeric_limits<int>::max() / 2 };
constexpr int MOD{ 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector adj(n + 1, vector<int>());
    vector<int> v(k);
    for (auto& x : v)
        cin >> x;

    for (int i{ 0 }; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist_1(n + 1, -1), dist_n(n + 1, -1);
    auto bfs = [&](int s, vector<int>& d) {
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int t{ q.front() };
            q.pop();
            for (auto x : adj[t])
                if (d[x] == -1) {
                    d[x] = d[t] + 1;
                    q.push(x);
                }
        }
    };

    bfs(1, dist_1);
    bfs(n, dist_n);

    sort(all(v), [&](int& x, int& y) {
        return dist_1[x] - dist_n[x] < dist_1[y] - dist_n[y];
        });

    int res{ 0 }, t{ -INF };
    for (auto x : v) {
        res = max(res, dist_n[x] + t + 1);
        t = max(t, dist_1[x]);
    }

    cout << min(res, dist_1[n]);
    return 0;
}