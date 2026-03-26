// LUOGU_RID: 95932192
#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=5e5+10;
int c[N];
set<int>a[N];
map< set<int>,int >mp;
inline void solve(){
    mp.clear();
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>c[i],a[i].clear();
    while (m--){
        int u,v;cin>>u>>v;
        a[v].insert(u);
    }
    for (int i=1;i<=n;++i) if (!a[i].empty()) mp[a[i]]+=c[i];
    int res=0;
    for (auto i:mp) res=__gcd(res,i.second);
    cout<<res<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while (t--) solve();
    return 0;
}