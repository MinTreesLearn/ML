#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<set>
using namespace std;
using LL = long long;
const int maxn = 2e5 + 5;
int a[maxn], t[maxn];
int st[maxn], ed[maxn];

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    map<int, vector<int> > mp;
    for(int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]].push_back(i);
    for(int i = 1; i <= n; i++) cin >> t[i];
    set<pair<int, int> > s;
    int last = 0;
    for(auto &[x, v] : mp){
        for(int i = 0; i < x - last && !s.empty(); i++){
            auto [c, id] = *prev(s.end());
            ed[id] = last + i;
            s.erase(prev(s.end()));
        }
        for(auto id : v)
            s.insert({t[id], id}), st[id] = x;
        last = x;
    }
    for(int i = 0; !s.empty(); i++){
        auto [c, id] = *prev(s.end());
        ed[id] = last + i;
        s.erase(prev(s.end()));       
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        ans += 1LL * (ed[i] - st[i]) * t[i];
    cout << ans << '\n';

}