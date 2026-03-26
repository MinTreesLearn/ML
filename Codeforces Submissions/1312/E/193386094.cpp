#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

#define all(a) a.begin(), a.end()

using namespace std;

#define int int64_t


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 1e5})); // 1-значение 2-размер
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            int r = l + len - 1;
            if (len == 1) {
                dp[l][r].first = s[l];
                dp[l][r].second = 1;
            } else {
                for (int m = l; m < r; m++) {
                    if (dp[l][m].first == dp[m + 1][r].first && dp[l][m].first != -1) {
                        dp[l][r] = {dp[l][m].first + 1, 1};
                    } else if (dp[l][m].second + dp[m + 1][r].second < dp[l][r].second) {
                        dp[l][r]={-1,dp[l][m].second + dp[m + 1][r].second};
                    }
                }
            }
        }
    }
    cout << dp[0][n-1].second;
}