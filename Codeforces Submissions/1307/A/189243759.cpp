#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tt, tc;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto& u : a) cin >> u;

    int ans = a[0];
    for (int i = 1; i < n; i++) {
        // k * i <= min(d, a[i
        int k = d/i;
        k = min(k, a[i]);
        d -= k * i;
        ans += k;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    tt = 1, tc = 1; cin >> tt;
    while (tt--) solve(), tc++;
}
