#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#endif
#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())

template <class T, class V> ostream & operator << (ostream & os, pair<T, V> const& p) { return os << "{" << p.first << "," << p.second << "}"; }
template <class T, class V, class Container> basic_ostream <T, V> & operator << (basic_ostream <T, V> & os, Container const& x) { os << "\n[ "; for (auto& y : x) os << y << " "; return os << "]"; }
template <typename T> bool chmin(T &a, T b) { return (b < a) ? a = b, 1 : 0; }
template <typename T> bool chmax(T &a, T b) { return (b > a) ? a = b, 1 : 0; }

#ifdef LOCAL
void deb_out() { cerr << endl; }
template <typename Head, typename... Tail> void deb_out(Head H, Tail... T) { cerr << " " << H; deb_out(T...); }
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", deb_out(__VA_ARGS__)
#else
#define deb(...) 1
#endif

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a) {
        cin >> x;
        if (x)
            b[x - 1]++;
    }
    int cntEven = 0, cntOdd = 0;
    for (int i = 0; i < n; ++i) {
        if (!b[i]) {
            if (i & 1)
                cntEven++;
            else
                cntOdd++;
        }
    }
    const int INF = 2e8;
    vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(cntEven + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= cntEven; ++j)
            dp[i][j][0] = dp[i][j][1] = INF;
    }
    if (a[0]) {
        dp[1][0][a[0] & 1] = 0;
    } else {
        if (cntEven)
            dp[1][1][0] = 0;
        if (cntOdd)
            dp[1][0][1] = 0;
    }
    int left = cntEven + cntOdd;
    if (!a[0])
        left--;
    for (int i = 2; i <= n; ++i) {
        if (!a[i - 1])
            left--;
        for (int j = 0; j <= min(cntEven, i); ++j) {
            if (a[i - 1]) {
                dp[i][j][a[i - 1] & 1] = dp[i - 1][j][0] + ((a[i - 1] & 1) == 1);
                chmin(dp[i][j][a[i - 1] & 1], dp[i - 1][j][1] + ((a[i - 1] & 1) == 0));
            } else {
                if (j) {
                    dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
                }
                if (left >= cntEven - j) {
                    dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);
                }
            }
        }
    }
    int res = INF;
    for (int i = 0; i <= cntEven; ++i) {
        chmin(res, min(dp[n][i][0], dp[n][i][1]));
    }
    // deb(dp);
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        solve_test();
        #ifdef LOCAL
        cout << "_____________________" << endl;
        #endif
    }
    #ifdef LOCAL
    cerr << endl << "Elapsed time: " << 1. * clock() / CLOCKS_PER_SEC << '\n';
    #endif
    return 0;
}
