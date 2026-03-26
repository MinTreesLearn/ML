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
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO\n";
        return ;
    }
    YES;
    vector<pair<int, string>> ans;
    for (int i = 1; i < n && k; i++, k--) {
        if (sz(ans) && ans.back().second == "D") ans.back().first++;
        else ans.push_back({1, "D"});
    }
    for (int i = n - 1; i > 0 && k; i--, k--) {
        if (ans.back().second == "U") ans.back().first++;
        else ans.push_back({1, "U"});
    }
    if (k <= 0) {
        cout << sz(ans) << "\n";
        for (auto &[x, y] : ans) {
            cout << x << " " << y << "\n";
        }
        return ;
    }
    ans.push_back({1, "R"}), k--;
    for (int i = 1; i < m && k; i++) {
        int op = 0;
        for (int j = 1; j < n && k; k--) {
            if (op == 0) {
                ans.push_back({1, "D"});
            } else if (op == 1) {
                ans.push_back({1, "L"});
            } else if (op == 2) {
                ans.pop_back();
                ans.pop_back();
                if (ans.back().second == "DLR") ans.back().first += 1;
                else ans.push_back({1, "DLR"});
                j++;
            }
            (op += 1) %= 3;
        }
        for (int j = n - 1; j > 0 && k; j--, k--) {
            if (ans.back().second == "U") ans.back().first++;
            else ans.push_back({1, "U"});
        }
        if (k && i + 1 < m) ans.push_back({1, "R"}), k--;
    }
    for (int i = m - 1; i > 0 && k; i--, k--) {
        if (ans.back().second == "L") ans.back().first++;
        else ans.push_back({1, "L"});
    }
    cout << sz(ans) << "\n";
    int sum = 0;
    for (auto &[x, y] : ans) {
        cout << x << " " << y << "\n";
        sum += x * sz(y);
    }
//    cout << sum << "\n";
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