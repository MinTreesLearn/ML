// LUOGU_RID: 102570642
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

int a[N];
int main() {
    int _;
    cin >> _;
    while (_--) {
        int n, m;
        cin >> n >> m;
        int mx = 0;
        int ok = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == m) ok = 1;
            mx = max(mx, a[i]);
        }
        int ans = max(2, (m + mx - 1) / mx);
        if (ok) ans = 1;
        cout << ans << endl;
    }
    return 0;
}
