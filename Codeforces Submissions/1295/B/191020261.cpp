#include<bits/stdc++.h>
using namespace std;

#define X ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int  long long

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr(n);
    int one = 0;
    int zero = 0;
    for (int e = 0; e < n; e++) {
        if (s[e] == '0')zero++;
        else one++;
        arr[e] = zero - one;
    }
    int ans = 0;
    if (m == 0)ans++;
    int ans1 = 0;
    for (int e = 0; e < n; e++) {
        if (s[e] == '0')ans1++;
        else ans1--;
        if (ans1 == m && arr[n - 1] == 0) {
            ans = -1;
            break;
        }
        if (ans1 == m || (((m - ans1) * arr[n - 1] > 0) && ((m - ans1) % arr[n - 1] == 0)))ans++;
    }
    cout << ans << "\n";
}
int32_t main() {
    X;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
