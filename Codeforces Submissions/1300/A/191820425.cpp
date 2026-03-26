#include <bits/stdc++.h>
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#define ll long long
#define st string
#define ull unsigned ll
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define ins insert
#define F first
#define S second
#define int ll
using namespace std;
int32_t main () {
    //freopen ("points.in", "r", stdin);
    //freopen ("points.out", "w", stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while (t --) {
        int n, kol = 0, sum = 0;
        cin >> n;
        vector <int> v;
        for (int i = 0; i < n; i ++) {
            int a;
            cin >> a;
            v.pb(a);
            if (!a) kol ++;
            sum += a;
        }
        sum += kol;
        if (sum && !kol) {
            cout << "0\n";
        }
        else {
            if (!sum && kol) {
                cout << kol + 1 << "\n";
            }
            else if (!sum) {
                cout << "1\n";
            }
            else if (kol) {
                cout << kol << "\n";
            }
        }
    }
    return 0;
}
