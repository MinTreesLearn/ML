#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
typedef priority_queue<int,vector<int>,greater<int>> min_priority_queue;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const string YES = "YES";
const string NO = "NO";


void solve() {
    ll n, m;
    cin >> n >> m;
    ll low = m, high = m;
    vector<array<ll, 3>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    sort(A.begin(), A.end());
    ll prev = 0;
    for (int i = 0; i < n; ++i) {
        ll t =A[i][0], l = A[i][1], r = A[i][2];
        ll d =  t - prev;
        if (low - d > r || high + d < l) {
            cout << NO << endl;
            return;
        }
        prev = t;
        low = max(l, low - d);
        high = min(r, high + d);
    }

    cout << YES << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}