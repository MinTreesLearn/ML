// LUOGU_RID: 101673521
#include<bits/stdc++.h>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

ll n,m;

void solve()
{
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<set<int>> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        s[v].insert(u);
    }
    map<set<int>, ll> mp;
    for (int i = 1; i <= n; i++) {
      if(!s[i].empty())  mp[s[i]] += a[i];
    }
    ll ans = 0;
    for (auto i : mp) {
        if (ans) ans = gcd(ans, i.second);
        else ans = i.second;
    }
    
    cout << ans << '\n';
}



signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tt = 1;

    cin >> tt;
    while (tt--) solve();

    return 0;
}
/*



*/