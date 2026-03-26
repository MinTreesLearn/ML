// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include "complex"

using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define si(n) scanf("%d", &n)
#define dout(n) printf("%d\n", n)
#define sll(n) scanf("%lld", &n)
#define lldout(n) printf("%lld\n", n)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
const long long mod = 1e9 + 7;

void prec() {
}
bool present[(int)2e7];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A;
    if (m > n * n) {
        cout << -1 << endl;
        return;
    }
    A.push_back(1);
    A.PB(2);
    present[1] = present[2] = true;
    int pos = 3;
    int cur = 0;
    while (m > 0 && A.size() < n) {
        int add = 0;
        for (int i = 0; i < A.size(); i++) {
            if (2 * A[i] >= pos) {
                break;
            }
            if (present[pos - A[i]]) {
                add++;
            }
            if (add > m) {
                break;
            }
        }
        if (add <= m) {
            m -= add;
            present[pos] = true;
            A.PB(pos);
        }
        pos++;
    }
    if (m) {
        cout << -1 << endl;
        return;
    }
    int y = pos + pos;
    int s = A.size();
    pos = (int)1e8;
    for (int i = s; i < n; i++) {
        A.PB(pos  + 1e4 * i);
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

signed main() {
    fast_io;
    prec();
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int totalTests = 1;
    // cin >> totalTests;
    for (int testNo = 1; testNo <= totalTests; testNo++) {
        // cout << "Case #" << testNo << ": ";
        solve();
    }
    return 0;
}
