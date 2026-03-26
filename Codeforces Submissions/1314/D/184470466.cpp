//  ↘ ⬇ ⬇ ⬇ ⬇ ⬇ ↙
//  ➡ @roadfromroi ⬅
//  ↗ ⬆ ⬆ ⬆ ⬆ ⬆ ↖
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "queue"
#include "array"
#include "random"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
int g[81][81];
int dp[81][11];
int typ[81];
mt19937 rnd(493);
void solve() {
    int n, k;
    cin >> n >> k;
    int res = 1e9 + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    while (1) {
        for (int i = 0; i < n; ++i) {
            for (int l = 0; l <= k; ++l) {
                dp[i][l] = -1;
            }
        }
        priority_queue<array<int, 3>> que;
        que.push({0, 0, 0});
        for (int i = 0; i < n; ++i) {
            typ[i] = rnd() % 2;
        }
        while (!que.empty()) {
            auto [prc, v, t] = que.top();
            prc = -prc;
            if (prc > res)
                break;
            que.pop();
            if (dp[v][t] != -1)
                continue;
            dp[v][t] = prc;
            if (t == k and v == 0)
                break;
            if (t == k)
                continue;
            for (int i = 0; i < n; ++i) {
                if (typ[i] != typ[v] and dp[i][t+1] == -1)
                    que.push({-(prc + g[v][i]), i, t+1});
            }
        }
        //cout << dp[0][k] << '\n';
        if (dp[0][k] != -1)
            res = min(res, dp[0][k]);
        if (clock() > CLOCKS_PER_SEC * 2.97) {
            break;
        }
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}
