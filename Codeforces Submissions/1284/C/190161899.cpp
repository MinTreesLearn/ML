#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, j, k) for (int i = j; i <= k; i++)
#define FORR(i, j, k) for (int i = j; i >= k; i--)
ll inf = 0x3f3f3f3f, linf = LLONG_MAX/2;
ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> v(n+1); v[0] = 1;
    FOR (i, 1, n) {
        v[i] = v[i-1]*i%m;
    }
    ll ans = 0;
    FOR (l, 1, n) {
        ans = (ans + (n-l+1) * v[l]%m * v[n-l+1]%m) % m;
    }
    cout << ans << '\n';

    return 0;
}

// (n-l+1) * l! * (n-l+1)!
// https://www.cnblogs.com/scnucjh/p/12153516.html