// LUOGU_RID: 102594414
#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define endl '\n' 
using ll = long long;
#define int long long
using pll = std::pair<int, int>;
using namespace std;

signed main()
{
//#ifdef LOCAL
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//#endif
    IOS;
    int n;
    cin >> n;
    vector<int>a(n + 7), b(n + 7);
    for (int i = 1;i <= n;++i)cin >> a[i];

    auto calc = [&](int L, int R) ->bool {
        if (L > R) return 0;
        ll ret = 0;
        for (int i = n, l = 1, r = 1; i; i--) {
            while (l <= n && b[i] + b[l] < L) ++l;
            while (r <= n && b[i] + b[r] <= R) ++r;
            ret += r - l - (l <= i && i < r);
        }
        return (ret >> 1) & 1;
    };
    int ans = 0;

    for (int k = 0;k <= 26;++k) {
        for (int i = 1;i <= n;++i) {
            b[i] = a[i] & ((1 << (k + 1) ) - 1);
        }
        sort(&b[1], &b[1 + n]);
        int g = (calc(1 << k, (1 << (k + 1)) - 1) ^ calc(3 << k, (1 << (k + 2)) - 2));
        ans |= (g << k);
    }
    cout << ans << '\n';

    return 0;
}