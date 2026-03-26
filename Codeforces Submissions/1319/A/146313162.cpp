//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define pii pair <int, int>
#define F first
#define S second
//#define int int64_t

using namespace std;

const int N = 3000, M = 1e9+7;

mt19937 gen(chrono::system_clock().now().time_since_epoch().count());



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n],q[n];
    for (int i=0;i<n;++i) {
        cin>> p[i];
    }
    int k1 = 0, k2 = 0;
    for (int i=0;i<n;++i) {
        cin>> q[i];
        if (p[i] == 1 && q[i] == 0) {
            k1++;
        }
        if (q[i] == 1 && p[i] == 0) {
            k2++;
        }
    }
    int l = 0, r = 100000;
    while (l < r) {
        int m = (l+r)/2;
        if (k1 * m > k2) {
            r = m;
        }
        else {
            l = m+1;
        }
    }
    if (l == 100000) l = -1;
    cout << l;
    return 0;
}
