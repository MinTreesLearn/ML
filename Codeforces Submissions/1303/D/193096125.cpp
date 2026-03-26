#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5 + 5;

#define checkBit(n, i) ((n) & (1LL << (i)))

void solve() {
    ll n, m; cin >> n >> m;

    ll sum = 0;
    vector<ll> a, bc(65);
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        if (n & x) n -= x;
        else {
            a.push_back(x);
            bc[__lg(x)]++;
            sum += x;
        }
    }
    if (!n) {
        cout << "0\n";
        return;
    }
    if (sum < n) {
        cout << "-1\n";
        return;
    }

    ll ans = 0;
    for (int i = 0; i < 62; i++) {
        if (!checkBit(n, i)) {
            bc[i + 1] += bc[i] / 2;
            bc[i] %= 2;
        }
        else {
            if (bc[i]) {
                n -= (1LL << i);
                bc[i]--;
                bc[i + 1] += bc[i] / 2;
                bc[i] %= 2;
            }
            else {
                for (int j = i; j < 62; j++) {
                    if (bc[j]) {
                        for (int k = j; k > i; k--) {
                            bc[k]--;
                            bc[k - 1] += 2;
                            ans++;
                        }
                        break;
                    }
                }
                if (bc[i]) {
                    n -= (1LL << i);
                    bc[i]--;
                    bc[i + 1] += bc[i] / 2;
                    bc[i] %= 2;
                }
                else {
                    ans = -1;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
