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
    int n;
    cin >> n;
    vector g(n, vector<array<int, 2>>(n));
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    string DIR = "RDUL", invDIR = "LUDR";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j][0] >> g[i][j][1];
        }
    }

    vector<string> ans(n, string(n, '#'));
    function<void(int, int)> dfs = [&](int x, int y) {
        for (int i = 0; i < 4; i++) {
            int cx = x + dir[i][0], cy = y + dir[i][1];
            if (cx < 0 || cy < 0 || cx >= n | cy >= n) continue;
            if (ans[cx][cy] != '#' || g[cx][cy][0] != -1) continue;
            if (ans[x][y] == '#') {
                ans[x][y] = DIR[i];
            }
            ans[cx][cy] = invDIR[i];
            dfs(cx, cy);
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j][0] == -1 && ans[i][j] == '#') {
                dfs(i, j);
                if (ans[i][j] == '#') {
                    cout << "INVALID\n";
                    return ;
                }
            }
        }
    }
    function<void(int, int)> dfs2 = [&](int x, int y) {
        for (int i = 0; i < 4; i++) {
            int cx = dir[i][0] + x, cy = dir[i][1] + y;
            if (cx < 0 || cy < 0 || cx >= n | cy >= n) continue;
            if (g[cx][cy] != g[x][y] || ans[cx][cy] != '#') continue;
            ans[cx][cy] = invDIR[i];
            dfs2(cx, cy);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == '#') {
                int x = g[i][j][0] - 1, y = g[i][j][1] - 1;
                if (g[x][y][0] != x + 1 || g[x][y][1] != y + 1 || ans[x][y] != '#') {
                    cout << "INVALID\n";
                    return ;
                }
                ans[x][y] = 'X';
                dfs2(x, y);
            }
        }
    }
    cout << "VALID\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
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