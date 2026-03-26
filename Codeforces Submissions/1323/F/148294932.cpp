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
// #define int i64
#define double ld

signed main() {
    oio;
    frr;

    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    vector<int> s(n);
    vector<int> c(n + m + 1);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        l[i]--;
    }
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n + m; i++) cin >> c[i];
    reverse(l.begin(), l.end());
    reverse(s.begin(), s.end());
    constexpr int inf = 1e9;
    vector<vector<int>> f(n + m + 1, vector<int>(n + 1, -inf));

    for (int j = 0; j <= n + m; j++) f[j][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int cnt = n; cnt >= 1; cnt--) {
            f[l[i]][cnt] = max(f[l[i]][cnt], f[l[i]][cnt - 1] + c[l[i]] - s[i]);
        }
        int lim = n;
        for (int lev = l[i]; lev < n + m; lev++) {
            for (int cnt = 0; cnt <= lim; cnt++) {
                f[lev + 1][cnt >> 1] = max(f[lev + 1][cnt >> 1], f[lev][cnt] + c[lev + 1] * (cnt >> 1));
            }
            lim >>= 1;
        }
    }
    cout << f[n + m][0];
    return 0;
}
  		 			 				  	  						 	 	  	