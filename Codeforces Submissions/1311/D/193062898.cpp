#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N = 1e5 + 2;
    vector<vector<int>> v(N);
    for (int i = 1; i < N; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                v[i].push_back(j);
                v[i].push_back(i / j);
            }
        }
    }
    cout << '\n';
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 1e9;
        for (int i = 1; i <= 1e5; i++) {
            int d = abs(b - i);
            if (i > c) {
                d += i - c;
            } else {
                d += min(c % i, i - c % i);
            }
            if (i < a) {
                d += a - i;
            } else {
                int mn = 1e9;
                for (int j : v[i]) {
                    mn = min(mn, abs(a - j));
                }
                d += mn;
            }
            ans = min(ans, d);
        }
        for (int i = 1; i <= 1e5; i++) {
            int d = abs(b - i);
            if (i > c) {
                d += i - c;
            } else {
                d += min(c % i, i - c % i);
            }
            if (i < a) {
                d += a - i;
            } else {
                int mn = 1e9;
                for (int j : v[i]) {
                    mn = min(mn, abs(a - j));
                }
                d += mn;
            }
            if (ans == d) {
                cout << d << '\n';
                if (i < a) {
                    a = i;
                } else {
                    int x = 1e9;
                    for (int j : v[i]) {
                        if (abs(a - x) > abs(a - j)) {
                            x = j;
                        }
                    }
                    a = x;
                }
                cout << a << " " << i << " ";
                if (i > c) {
                    c = i;
                } else {
                    if (c % i < i - c % i) {
                        c -= c % i;
                    } else {
                        c += i - c % i;
                    }
                }
                cout << c;
                break;
            }
        }
        cout << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio( false ); cin.tie( nullptr ); cout.tie( nullptr );
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
        cout << '\n';
    }
}