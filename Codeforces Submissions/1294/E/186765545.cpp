#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define all(_) _.begin(), _.end()
#define rall(_) _.rbegin(), _.rend()
#define sz(_) (int)_.size()
#define fs first
#define se second
#define Odd(_x) ((_x) & 1)
using i64 = long long;
using ll = long long;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9 + 10;
const ll mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m ));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        vector<int> cnt(n);
        for (int j = 0; j < n; j++) {
            if (a[j][i] % m == i && a[j][i] < n * m) {
                cnt[(j - a[j][i] / m + n) % n] += 1;
            }
        }
        int res = n;
        for (int i = 0; i < n; i++) {
            res = min(res, n - cnt[i] + i);
        }
        ans += res;
    }
    cout << ans << "\n";
}
//#define MULTI_INPUT

int main() {
#ifndef ONLINE_JUDGE
    freopen(R"(D:\source files\source file2\input.txt)", "r", stdin);
    freopen(R"(D:\source files\source file2\output.txt)", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
#ifdef MULTI_INPUT
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
#else
    solve();
#endif
    return 0;
}