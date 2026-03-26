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
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
int N;
int mod = 998244353;
bool obr(vector<int> x, int k) {
    int sm = 0;
    for (auto i : x)
        sm += i;
    if (k == 1) {
        return sm <= N;
    }
    vector<int> y;
    int vl = 0;
    for (int i = 0; i < x.size(); ++i) {
        int t = x.size() - i;
        vl += x[i] * t;
    }
    if (vl > N)
        return 0;
    for (int i = 0; i < x.size(); ++i) {
        int t = x.size() - i;
        for (int j = 0; j < x[i]; ++j) {
            y.push_back(t);
        }
    }
    reverse(all(y));
    return obr(y, k - 1);
}
int cnt = 0;
void recrec(int k, vector<int> a, int lst) {
    for (int i = lst; i <= N; ++i) {
        vector<int> b = a;
        b.push_back(i);
        if (obr(b, k)) {
            cnt++;
            recrec(k, b, i);
        } else {
            break;
        }
    }
}
void solve() {
    cnt=  0;
    int n, k;
    cin >> n >> k;
    if (k >= 3) {
        N = n;
        recrec(k, {}, 1);
        cout << cnt << '\n';
        return;
    }
    if (k == 1) {
        int sm = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 2));
        dp[0][1] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j + 1] += dp[i][j];
                if (dp[i][j + 1] >= mod)
                    dp[i][j + 1] -= mod;
                if (i + j <= n) {
                    dp[i + j][j] += dp[i][j];
                    if (dp[i + j][j] >= mod)
                        dp[i + j][j] -= mod;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            sm += dp[i][n];
            if (sm >= mod)
                sm -= mod;
        }
        cout << sm << '\n';
        return;
    }
    if (k == 2) {
        vector<vector<vector<int>>> beba(n + 1, vector<vector<int>>(n + 1));
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int l = 0; l <= n / j; ++l) {
                    beba[i][j].push_back(0);
                }
            }
        }
        beba[0][n][0] = 1;
        int res = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = n; j > 0; --j) {
                for (int l = 0; l <= n / j; ++l) {
                    if (beba[i][j][l] == 0)
                        continue;
                    if (i+j*(l + 1) <= n) {
                        beba[i + j * (l + 1)][j][l + 1] += beba[i][j][l];
                        if (beba[i + j * (l + 1)][j][l + 1] >= mod)
                            beba[i + j * (l + 1)][j][l + 1] -= mod;
                    }
                    if (j != 1) {
                        beba[i][j - 1][l] += beba[i][j][l];
                        if (beba[i][j - 1][l] >= mod)
                            beba[i][j - 1][l] -= mod;
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < beba[i][1].size(); ++j) {
                res += beba[i][1][j];
                if (res >= mod)
                    res -= mod;
            }
        }
        cout << res << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}
