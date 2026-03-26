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
int b[500000];
int n;
int get (int x, int y) {
    if (x > y) return 0;
    int kl = 0;
    int l = 1, r = 1;
    for (int i = n; i; i--) {
        while (l <= n && b[i] + b[l] < x) l++;
        while (r <= n && b[i] + b[r] <= y) r++;
        kl += (r - l) - (l <= i && i < r);
    }
    return (kl / 2) ;
}
int32_t main() {
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a[n + 2];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i <= 25; i++){
        for (int j = 1; j <= n; j++){
            b[j] = (a[j] % (1 << (i + 1)));
        }
        sort(b + 1, b + 1 + n);
        int cnt = get((1 << i), (1 << (i + 1)) - 1) + get(((1 << (i + 1)) + (1 << i)), ((1 << (i + 1)) + (1 << (i + 1)) - 1));
        if (cnt % 2) ans += (1 << i);
    }
    cout << ans;
return 0;
}
