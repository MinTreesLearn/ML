#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vdb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef set<int> si;
typedef set<long long> sl;
typedef set<double> sdb;
typedef set<string> ss;
typedef set<char> sc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define ftb(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define ft(i, a, b) for (int i = a, _b = b; i < _b; i++)
#define fgb(i, a, b) for (int i = a, _b = b; i >= _b; i--)
#define fg(i, a, b) for (int i = a, _b = b; i > _b; i--)
#define endl "\n"
ll mx(ll z, vl &a) {
    ll mn = 0;
    for (int i = 0;i < a.size() - 1;i++) {
        ll q = a[i];
        ll k = a[i + 1];
        if (a[i] == -1) {
            q = z;
        }
        if (a[i + 1] == -1) {
            k = z;
        }
        mn = max(mn, abs(q - k));
    }
    return mn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vl a(n);
        ft(i, 0, n) {
            cin >> a[i];
        }
        int l = 0, r = 1e9;
        while (l <= r) {
            if (r - l < 3) break;
            int z = (2 * l + r) / 3;
            int k = (l + 2 * r) / 3;
            ll temp1 = mx(z, a), temp2 = mx(k, a);
            if (temp1 < temp2) {
                r = k;
            }
            else l = z;
        }
        int ans = 1e9, num = 0;
        ftb(i, l, r) {
            int temp = mx(i, a);
            if (ans > temp) {
                ans = temp;
                num = i;
            }
        }
        cout << ans << " " << num << endl;
    }
    return 0;
}
