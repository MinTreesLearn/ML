#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
template <typename T> bool chkmax(T &x, T y) { if (y > x) {x = y; return true;} return false;}
template <typename T> bool chkmin(T &x, T y) { if (y < x) {x = y; return true;} return false;}

const ll INF = 0x3f3f3f3f3f3f3f3f;

#ifdef ANSWERER
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector <vector<int>> f(n + 1, vector <int> (k + 1));
    f[0][0] = 1;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (f[i - 1][(j - a[i] + k) % k]) f[i][j] = max(f[i][j], f[i - 1][(j - a[i] + k) % k] + (j >= l && j <= r));
            if (f[i - 1][(j + 1 - a[i] + k) % k]) f[i][j] = max(f[i][j], f[i - 1][(j - a[i] + 1 + k) % k] + (j >= l && j <= r));
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        chkmax(ans, f[n][i]);
    }

    cout << max(0, ans - 1) << "\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifdef ANSWERER
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    clock_t start = clock();
#endif
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
#ifdef ANSWERER
    clock_t ends = clock();
    cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return EXIT_SUCCESS;
}
//#endif