#include <bits/stdc++.h>

using namespace std;

const int inf = 1e15;

#define int long long

mt19937_64 rnd(441225); //ddly

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int f = 0, s = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
            f++;
        else if (b[i] > a[i])
            s++;
    }
    if (f == 0) {
        cout << -1;
    } else {
        cout << s / f + 1;
    }
}
