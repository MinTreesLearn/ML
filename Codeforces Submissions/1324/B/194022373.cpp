/*  بسم الله الرحمن الرحيم  */
#include <bits/stdc++.h>
using namespace std;
#define Ma3rof ios_base::sync_with_stdio(false);cin.tie(NULL);
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            if (a[i] == a[j])
                ok = true;
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}
signed main() {
    Ma3rof
    int t = 1;
    cin >> t;
    while (t--) {
        /*       وما تدري نفس ماذا تکسب غدا وما تدري نفس باي ارض تموت      */
        solve();
    }
    return 0;
}
