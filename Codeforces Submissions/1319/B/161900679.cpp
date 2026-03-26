#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const long long mod = 998244353;
const long long inf = 999999999999999999;
const long long nmax = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector <int> less(4e5 + 5), more( 4e5 + 5);
    for (int i = 0; i < n; i++) {
        if (arr[i] - i >= 0)
            more[arr[i] - i] += arr[i];
        else
            less[i - arr[i]] += arr[i];
    }
    int ans = 0;
    for (int i = 0; i < 4e5 + 5; i++) {
        ans = max(ans, max(less[i], more[i]));
    }
    cout << ans;
}

signed main() {
//    freopen("e.in", "r", stdin);
//    freopen("e.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
//    cin >> t;
    while(t--) {
        solve();
    }
}