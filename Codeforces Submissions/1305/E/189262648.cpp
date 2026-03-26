#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tt, tc;

void solve() {
    int n; ll m;
    cin >> n >> m;
    if (m == 0) {
        for (int i = 1; i <= n; i++) cout << 3 * i + 1 << " ";
        cout << "\n";
        return;
    }
    vector<ll> a(n + 1);
    ll sum = 0;
    bool did_find = false;
    for (int i = 1; i <= n; i++) {
        sum += (ll)(i - 1) / 2;
        if (m < sum) {
            did_find = true;
            sum -= (ll)(i - 1) / 2;
            a[i] = 2 * i - 1 - 2 * (m - sum);
            for (int j = i + 1; j <= n; j++) a[j] = (ll)(1e8) + 1 + (ll)(1e4) * 1LL * j;
            break;
        }
        a[i] = i;
    }

    if (!did_find && m > sum) return void(cout << -1 << "\n");
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    tt = 1, tc = 1; // cin >> tt;
    while (tt--) solve(), tc++;
}
