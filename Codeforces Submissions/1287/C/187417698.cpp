#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>
using ll = long long;
const int mod = 998244353;
const int N = 110;
int f[N][51][51][2];
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    f[0][0][0][0] = 0;
    f[0][0][0][1] = 0;
    for (int k = 1; k <= n; k++) {
        int aim = std::min((n + 1) / 2, k);
        if ((a[k] & 1) || a[k] == 0) {
            for (int i = 0; i <= aim; i++) {
                f[k][i + 1][k - 1 - i][1] =
                    std::min({f[k][i + 1][k - 1 - i][1],
                                f[k - 1][i][k - 1 - i][0] + 1,
                                f[k - 1][i][k - 1 - i][1]});
            }
        } 
        if ((a[k] & 1) == 0) {
            for (int i = 0; i <= aim; i++) {
                f[k][i][k - i][0] =
                    std::min({f[k][i][k - i][0],
                                f[k - 1][i][k - 1 - i][1] + 1,
                                f[k - 1][i][k - 1 - i][0]});
            }
        }
    }
    int res = std::min(f[n][(n + 1) >> 1][n >> 1][0], f[n][(n + 1) >> 1][n >> 1][1]);
    std::cout << res << '\n';
}
int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
}