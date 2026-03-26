#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tc = 1, p = 1;
    vector<ll> pow2;
    map<ll, ll> rev_pow2;
    pow2.push_back(1);
    rev_pow2[1] = 0;
    for (ll x = 1;; x++) {
        p *= 2;
        if (p > 1e9) {
            break;
        }
        pow2.push_back(p);
        rev_pow2[p] = x;
    }
    ll msz = pow2.size();
    cin >> tc;
    while (tc--) {
        ll n, m, s = 0;
        cin >> n >> m;
        vector<ll> v(msz + 1, 0);
        for (ll t, x = 0; x < m; x++) {
            cin >> t;
            s += t;
            v[rev_pow2[t]]++;
        }
        if (s < n) {
            cout << -1 << '\n';
            continue;
        }
        ll res = 0;

        // for (ll x = 0; x <= 5; x++) {
        //     cout << v[x] << " ";
        // }
        // cout << '\n';
        for (ll z = 0; z <= 30; z++) {
            if ((1LL << z) & n) {
                ll req = 1LL << z;
                // reverse_check
                for (ll x = z; x >= 0; x--) {
                    ll q = min(req / (1LL << x), v[x]);
                    req -= q * (1LL << x);
                }
                if (req == 0) {
                    //  reverse smu
                    req = 1LL << z;
                    for (ll x = z; x >= 0; x--) {
                        ll q = min(req / (1LL << x), v[x]);
                        v[x] -= q;
                        req -= q * (1LL << x);
                    }
                } else {
                    // forward check
                    req = 1LL << z;
                    for (ll x = z + 1; x <= msz; x++) {
                        if (v[x]) {
                            ll bit = x, chunk = 1LL << x;
                            while (chunk != req) {
                                res++;
                                v[bit]--;
                                chunk /= 2;
                                bit--;
                                v[bit] += 2;
                            }
                            v[bit]--;
                            req = 0;
                            break;
                        }
                    }
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}