#include <bits/stdc++.h>

using namespace std;

bool ck(double x) {
    return double(int(x)) != x;
}

void solve() {
    double a, b, c, n;
    cin >> a >> b >> c >> n;
    double mid = (a + b + c + n) / 3;
    if (a > mid || b > mid || c > mid || ck(mid)) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}