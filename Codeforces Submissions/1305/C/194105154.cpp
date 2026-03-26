#include <bits/stdc++.h>

#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define pii pair < int , int >
#pragma GCC optimize("Ofast")
#define ld long double
#define pb push_back
#define ll long long
#define endl '\n'
#define S second
#define F first
#define sz size
#define int ll
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree <T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int32_t main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    int x = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < i && x != 0; j++) {
            x = x * abs(a[j] - a[i]) % m;
        }
    }
    cout << x % m;
return 0;
}
