#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
        cin >> x;
    for (auto &[x, y] : v)
        cin >> y;

    sort(ALL(v));
    multiset<ll, greater<ll>> s;
    ll cur = -1, i = 0, sum = 0, ans = 0;
    while (i < n || !s.empty())
    {
        if (s.empty())
            cur = v[i].first;
        while (i < n && v[i].first == cur)
        {
            sum += v[i].second;
            s.insert(v[i].second);
            ++i;
        }
        sum -= *s.begin();
        s.erase(s.begin());
        ans += sum;
        ++cur;
    }

    cout << ans;

    return 0;
}
			  			  	  	 	  		 					 	