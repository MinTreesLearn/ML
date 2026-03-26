#include <bits/stdc++.h>
#define up(i, j, n, k) for (int i = j; i <= n; i += k)
#define dw(i, j, n, k) for (int i = j; i >= n; i -= k)
#define int long long
using namespace std;

typedef pair<int, int> PII;
const int mod = 998244353;
const int mn = 2e6 + 1000;
const int INF = 0x3f3f3f3f;
const int LINF = 9223372036854775806;

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = n * (n + 1) / 2;
    int x = (n - m) / (m + 1);
    int y = (n - m) % (m + 1);
    if (y == 0) 
        ans -= x * (x + 1) * (m + 1) / 2;
    else    
        ans -= (x * (x + 1) * (m + 1 - y) / 2 + y * (x + 1) * (x + 2) / 2);
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    cin >> t;
    while (t --) 
        solve();
    return 0;
}