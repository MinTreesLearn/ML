#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, u, v;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    int color[n + 1];
    int ans[n + 1];
    int dp[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
        if (color[i] == 0) color[i] = -1;
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int u, int p) -> void {
        dp[u] = color[u];
        for (int v : tree[u]) {
            if (v != p) {
                dfs(v, u);
                dp[u] += max(dp[v], 0);
            }
        }
    };
    dfs(1, 0);

    function<void(int, int)> dfs2 = [&](int u, int p) -> void {
        ans[u] = dp[u];
        for (int v : tree[u]) {
            if (v != p) {
                dp[u] -= max(0, dp[v]);
                dp[v] += max(0, dp[u]);
                dfs2(v, u);
                dp[v] -= max(0, dp[u]);
                dp[u] += max(0, dp[v]);
            }
        }
    };
    dfs2(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}