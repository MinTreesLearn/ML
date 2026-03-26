#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef pair<ll,ll> pi;
const int N=2e5+10;
pi isinter(pi a,pi b) {
    if (a.first > b.first)swap(a, b);
    if (a.first == b.first && b.second >= a.second)swap(a, b);
    // nested
    if (a.second >= b.second) {
        return b;
    }
    // inter
    if (a.second >= b.first) {
        return {max(a.first, b.first), min(a.second, b.second)};
    }
    return {-1e18, -1};
}
void solve() {
    ll n;
    pi now;
    cin >> n >> now.first;
    now.second = now.first;
    ll t = 0;
    bool can = true;
    for (int i = 0; i < n; ++i) {
        ll time;
        pi me, bounds;
        cin >> time >> me.first >> me.second;
        bounds.first = now.first - (time - t);
        bounds.second = now.second + (time - t);
        pi inter = isinter(bounds, me);
        if (inter.first == -1e18)can = false;
        now = {max(bounds.first, me.first), min(bounds.second, me.second)};
        t = time;
    }
    if (can) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}