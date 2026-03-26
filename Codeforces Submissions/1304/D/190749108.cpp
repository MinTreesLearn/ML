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
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> small(n, -1), big(n, -1);
        ll off = n, st = 1;
        for (ll x = 0; x < n - 1; x++) {
            if (s[x] == '>') {
                small[x] = off;
                big[x] = off;
                off--;
            }
        }
        for (ll x = n - 1; x >= 0; x--) {
            if (small[x] == -1) {
                ll y = x;
                while (small[y] == -1) {
                    y--;
                }
                for (ll z = y + 1; z <= x; z++) {
                    small[z] = st++;
                }
            }
        }
        for (auto x : small) {
            cout << x << " ";
        }
        cout << '\n';
        st = 1;
        for (auto &x : big) {
            if (x == -1) {
                x = st++;
            }
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}