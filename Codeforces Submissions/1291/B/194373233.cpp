/*  بسم الله الرحمن الرحيم  */
#include <bits/stdc++.h>
using namespace std;
#define Ma3rof ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
void solve() {
    int n, l, r;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= c) {
            l = i;
            c++;
        } else {
            break;
        }
    }
    c = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= c) {
            r = i;
            c++;
        } else {
            break;
        }
    }
    if (l >= r) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
signed main() {
    Ma3rof
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        /*       وما تدري نفس ماذا تکسب غدا وما تدري نفس باي ارض تموت      */
        solve();
    }
    return 0;
}
				   			  	 			    	 	 	  	 	