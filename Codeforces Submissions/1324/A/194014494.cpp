/*  بسم الله الرحمن الرحيم  */
#include <bits/stdc++.h>
using namespace std;
#define Ma3rof ios_base::sync_with_stdio(false);cin.tie(NULL);
void solve() {
    int n;
    cin >> n;
    bool odd = false, even = false;
    while (n--) {
        int x;
        cin >> x;
        if(x&1)
            odd = true;
        else
            even = true;
    }
    if (even && odd)
        cout << "NO\n";
    else
        cout << "YES\n";
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
