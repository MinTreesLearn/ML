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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        bool ok = true;
        ft(i, 0, a.size()) {
            if (a[i] != c[i] && b[i] != c[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}
