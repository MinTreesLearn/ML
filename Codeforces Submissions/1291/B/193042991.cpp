#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int64_t> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    // vector<vector<ll>> dp(n, vector<ll>(2, 0));
    // for(int i = 0; i < n; ++i) {
    //     if(i == 0) {
    //         dp[i][0] = v[i];
    //     }
    //     else {
    //         if(v[i] > v[i - 1]) {
    //             dp[i][0] = dp[i - 1][0];
    //         }
    //         else {
    //             int toDec = v[i - 1] - v[i] + 1;
    //             dp[i][0] = dp[i - 1][0] - toDec;
    //         }
    //     }
    // }
    // for(int i = n - 1; i >= 0; --i) {
    //     if(i == n - 1) {
    //         dp[i][1] = v[i];
    //     }
    //     else {
    //         if(v[i] > v[i + 1]) dp[i][1] = dp[i + 1][1];
    //         else {
    //             int toDec = v[i + 1] - v[i] + 1;
    //             dp[i][1] = dp[i + 1][1] - toDec;
    //         }
    //     }
    // }
    // if(n == 1) {
    //     cout << "Yes";
    //     return 0;
    // }
    // for(int i = 0; i < n; ++i) {
    //     int before = dp[i][0];
    //     int after = dp[i][1];
    //     if(min(before, after) >= 0) {
    //         cout << "Yes"; return 0;
    //     }
    // }
    // cout << "No";
    int pref = -1, suff = n;
    for(int i = 0; i < n; ++i) {
        if(v[i] < i) break;
        pref = i;
    }
    for(int i = n - 1; i >= 0; --i) {
        if(v[i] < (n - 1 - i)) break;
        suff = i;
    }
    if(suff <= pref) cout << "Yes";
    else cout << "No";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        #ifdef LOCAL
            cout << "##################" << '\n';
        #endif
        if (solve()) {
            break;
        }
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
// -> Keep It Simple Stupid!