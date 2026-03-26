#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef LOCAL
#include "debug.h"
#endif
const int64_t mod = (1 > 0 ? 998244353 : 1e9 + 7);
const int inf32 = 0x3f3f3f3f;
const int64_t inf64 = (int64_t) 4e18;
#define fi first
#define se second
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; 
    cin >> t; 
    while (t--) {
        int n, d; 
        cin >> n >> d; 
        vector <int> a(n); 
        for (int i = 0;i < n;i++) {
            cin >> a[i]; 
        }
        for (int i = 1;i < n;i++) {
            int add = min(d / i, a[i]); 
            d -= add * i; 
            a[i] -= add; 
            a[0] += add; 
        }
        cout << a[0] << '\n'; 
    }
}