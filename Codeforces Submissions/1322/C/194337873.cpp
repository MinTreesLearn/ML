// LUOGU_RID: 102607059
#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'
#define int long long
using pll = std::pair<int,int>;


void solv(){
    int n, m;
    cin >> n >> m;
    vector<int>a(n + 7);
    vector<set<int>>g(n + 8);
    map<set<int>, int>mp;
    for (int i = 1;i <= n;++i)cin >> a[i];
    for (int i = 1;i <= m;++i) {
        int u, v;
        cin >> u >> v;
        g[v].insert(u);
    }
    for (int i = 1;i <= n;++i) {
        if (g[i].size())mp[g[i]] += a[i];
    }
    int ans = mp.begin()->second;
    for (auto [x, y] : mp) {
        ans = gcd(ans, y);
        // cout << y << ' ';
    }
    cout << ans << '\n';



}


signed main(){
//#ifdef LOCAL
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//#endif
    IOS;
    int T=1;
    cin >> T;
    while (T--){
        solv();
    }
    return 0;
}