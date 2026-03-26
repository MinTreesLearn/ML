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
//#define int ll
using namespace std;
int32_t main () {
    //freopen ("points.in", "r", stdin);
    //freopen ("points.out", "w", stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        st s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += int(s [i] - '0');
        }
        //cout << sum << "\n";
        if (sum % 2 == 0 && (int(s [n-1] - '0') % 2) == 1) {
            cout << s << "\n";
        }
        else {
            if (int(s [n-1] - '0') % 2 == 0) {
                while (int(s [n-1] - '0') % 2 == 0 && n) {
                    sum -= int(s [n-1] - '0');
                    s.erase(n-1, 1);
                    n --;
                }
            }
            if (sum % 2 == 1) {
                for (int i = 0; i < n; i ++) {
                    if (int(s [i] - '0') % 2 == 1) {
                        sum -= int(s [i] - '0');
                        s.erase(i, 1);
                        n --;
                        break;
                    }
                }
            }
            while (s [0] == '0') {
                s.erase(0, 1);
                n --;
            }
            if (sum % 2 == 0 && int(s [n-1] - '0') % 2 == 1) {
                cout << s << "\n";
            }
            else cout << "-1\n";
        }
    }
    return 0;
}

