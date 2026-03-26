// LUOGU_RID: 102570640
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

int a[105];
int main() {
    int _;
    cin >> _;
    while (_--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = a[0];
        for (int i = 1; i < n; i++) {
            int t = min(m, i * a[i]);
            m -= t;
            ans += t / i;
        }
        cout << ans << endl;
    }
    return 0;
}
