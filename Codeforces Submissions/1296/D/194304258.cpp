#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vs = vector<string>;
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())

#ifdef DLOCAL
#include <local.h>
#else
#define deb(...);
#endif

void solve() {
    ll  n, a, b, k; cin >> n >> a >> b >> k;
    vll monsters(n);
    for (int i = 0; i < n; ++i) {
        cin >> monsters[i];
    }

    deb(monsters);

    ll  c = (a + b);
    vll skips(n);
    for (int i = 0; i < n; ++i) {
        ll total = (monsters[i] + c - 1) / c;
        ll health = max(0ll, monsters[i] - total * c + b);
        ll skips_needed = (health + a - 1) / a;
        skips[i] = skips_needed;
    }
    SORT(skips);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (skips[i] > k) break;
        ans++;
        k -= skips[i];
    }
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //ifstream cin ("puzzle_name.in");
    //ofstream cout ("puzzle_name.out");

    solve();

    return 0;
}
