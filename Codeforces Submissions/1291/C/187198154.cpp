#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define el "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
const ll N = 3e5 + 5;
const ll mod = 1e9 + 7;
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
ll n, m, k, y, x, l, r;
int a[N];
bool canl[N], canr[N];

void dowork() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    k = min(k, m - 1);
    int ans = 0, tmp = 1e9, l, r;
    for (int i = 0; i <= k; ++i) {
        tmp = 1e9;
        for (int j = 0; j <= m - 1 - k; ++j) {
            l = i + j;
            r = n - 1 - (k - i) - (m - 1 - k - j);
            tmp = min(tmp, max(a[l], a[r]));
        }
        ans = max(tmp, ans);
    }
    cout << ans << el;
}

int main() {
    fast
    //freopen("cowland.in", "r", stdin);
    //freopen("cowland.out", "w", stdout);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        dowork();
    }
}