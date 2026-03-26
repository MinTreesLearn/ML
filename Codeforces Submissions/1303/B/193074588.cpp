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
    ll num = (n + 1) / 2, leftOut = n - num;
    ll how1 = num / g, how2 = num % g;
    ll ans = 0;
    if(how2 == 0) {
        ll ok = (how1 - 1) * b;
        leftOut = max(0LL, leftOut - ok);
        ans += ok + how1 * g;
        ans += leftOut;
    }
    else {
        if(how1 == 0) {
            ans = n;
        }
        else {
            ll ok = (how1) * b;
            leftOut = max(0LL, leftOut - ok);
            ans += ok + how1 * g;
            ans += how2;
            ans += leftOut;
        }
    }
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