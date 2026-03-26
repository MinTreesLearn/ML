// #pragma comment(linker,"/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;

// #define DEBUG
// #define OIO
// #define FR

#ifdef DEBUG
#define debug(x) cout << #x << ": " << (x) << "  "
#define debugl cout << "\n"
#define debug_function printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#else
#define debug(x)
#define debugl
#define debug_function
#endif

#ifdef OIO
#define oio
#else
#define oio { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); }
#endif

#ifdef FR
#define frr freopen("1.in","r",stdin)
#define frw freopen("1.out","w",stdout)
#else
#define frr
#define frw
#endif

using i64 = long long;
using ld = long double;
#define int i64
#define double ld

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> b(n);
    vector<set<int>> bb(n);
    map<set<int>, int> mp;
    vector<bool> p(n);
    int ans = 0;
    for (int i = 0; i < m;i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (!p[y]) ans += a[y], p[y] = 1;
        b[x].push_back(y);

        bb[y].emplace(x);
    }
    for (int i = 0; i < n; i++){
        if (bb[i].size()) mp[bb[i]] += a[i];
    }
    for (auto x : mp) {
        ans = __gcd(ans, x.second);
    }

    cout << ans << "\n";
}

signed main() {
    oio;
    frr;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}