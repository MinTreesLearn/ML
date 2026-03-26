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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int cnt1 = 0, cnt2 = 0, c = 0;
    for (int i = 0; i < n; i++) {
        cnt1 += (a[i] && !b[i]);
        cnt2 += (!a[i] && b[i]);
        c += (a[i] && b[i]);
    }
    if (cnt1 == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << (cnt2 + cnt1) / cnt1 << '\n';
    }
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