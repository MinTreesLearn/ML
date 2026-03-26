#include <iostream>

#define ll long long

using namespace std;

void FAST_IO(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("##.in", "r", stdin);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}

ll x, y, a, b;

ll bs(ll l = 0, ll r = 1e9) {
    if (r - l == 1) return (x + l * a == y - l * b ? l : -1);
    ll mid = (l + r) / 2;
    if (x + mid * a <= y - mid * b)
        return bs(mid, r);
    return bs(l, mid);
}

void solve() {
    cin >> x >> y >> a >> b;
    cout << bs() << "\n";
}

int main() {
    FAST_IO();
    int testcases = 1;
    cin >> testcases;
    while (testcases--)
        solve();
    return 0;
}