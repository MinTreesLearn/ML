/*  بسم الله الرحمن الرحيم  */
#include <bits/stdc++.h>
using namespace std;
#define Ma3rof ios_base::sync_with_stdio(false);cin.tie(NULL);
void solve() {
    string s;
    cin >> s;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
            v.push_back(i + 1);
        }
    }
    v.push_back(s.size() + 1);
    int ans = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        ans = max(ans, v[i + 1] - v[i]);
    }
    cout << ans << '\n';
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
