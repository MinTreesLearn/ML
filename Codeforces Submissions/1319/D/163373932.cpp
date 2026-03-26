#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), g_rev(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> p(k);
    for (auto &v: p) {
        cin >> v;
        --v;
    }

    int s = p[0], t = p[k - 1];
    vector<int> dist_t(n, n);
    queue<int> q;
    q.push(t);
    dist_t[t] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: g_rev[u])
            if (dist_t[v] == n) {
                dist_t[v] = dist_t[u] + 1;
                q.push(v);
            } 
    }

    int ans_min = 0, ans_max = 0, r_min = s, r_max = s, d_min = 0, d_max = 0;
    for (int i = 0; i + 1 < k; i++) {
        if (d_min + 1 + dist_t[p[i + 1]] != dist_t[r_min]) {
            ans_min++;
            r_min = p[i + 1];
            d_min = 0;
        } else {
            d_min++;
        }
        
        for (int v: g[p[i]])
            if (v != p[i] && v != p[i + 1] && d_max + 1 + dist_t[v] == dist_t[r_max]) {
                ans_max++;
                r_max = p[i + 1];
                d_max = 0;
                break;
            }

        if (r_max != p[i + 1])
            d_max++;
    }

    cout << ans_min << " " << ans_max << "\n";
}