#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tc = 1;
    // cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        vector<vector<ll>> v(n);
        vector<pair<ll, vector<ll>>> ddd;
        for (ll z = 0; z < n; z++) {
            ll l, prev = 1e18, f = 1;
            cin >> l;
            for (ll t, x = 0; x < l; x++) {
                cin >> t;
                v[z].push_back(t);
                if (t > prev) {
                    f = 0;
                }
                prev = t;
            }
            if (f) {
                ddd.push_back({v[z][0], v[z]});
            }
        }

        ll sub = 0;
        sort(rall(ddd));
        for (ll x = 0; x < ddd.size(); x++) {
            ll low = 0, high = ddd.size() - 1, idx = ddd.size();
            ll last = ddd[x].second[ddd[x].second.size() - 1];
            while (low <= high) {
                ll mid = (low + high) / 2;
                if (ddd[mid].first <= last) {
                    high = mid - 1;
                    idx = mid;
                } else {
                    low = mid + 1;
                }
            }
            sub += (ddd.size() - idx);
        }
        ll res = n * n - sub;
        cout << res << '\n';
    }
    return 0;
}