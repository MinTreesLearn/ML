// clang-format off
#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "deb/debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else   
#define debug(...) 42
#endif

#define int long long

typedef unsigned long long ull;
typedef long double ld;
  
#define ff first
#define ss second

const int MOD = 1e9 + 7;

int sum(int a, int b) {
    return (a + b) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > dpp(m, vector<int>(n + 1));
    for (int j = 1; j <= n; j++) 
        dpp[0][j] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            dpp[i][j] = sum(dpp[i][j - 1], dpp[i - 1][j]);
        }
    }
    vector< vector< vector<int> > > dp(m + 1, vector< vector<int> >(n + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= n; i++)
        dp[m][i][i] = dpp[m - 1][i];
    for (int s = 1; s <= n; s++) {
        for (int i = m - 1; i >= 0; i--) {
            for (int j = s; j <= n; j++) {
                dp[i][j][s] = sum(dp[i][j - 1][s], dp[i + 1][j][s]);
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int j = k; j <= n; j++) 
            ans = sum(ans, dp[0][j][k]);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    for (;_; --_) {
        solve();
    }
    return 0;
}