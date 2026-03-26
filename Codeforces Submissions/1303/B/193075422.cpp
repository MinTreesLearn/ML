#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    ll n, g, b; cin >> n >> g >> b;
    ll num = (n + 1) / 2;
    ll how1 = num / g, how2 = num % g;
    ll ans = how1 * (g + b);
    if(!how2) {
        ans -= b;
    } else ans += how2;
    ans += (max(0LL, n - ans));
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        #ifdef LOCAL
            cout << "##################" << '\n';
        #endif
        if (solve()) {
            break;
        }
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
// -> Keep It Simple Stupid!