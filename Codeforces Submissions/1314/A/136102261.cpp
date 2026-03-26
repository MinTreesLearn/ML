#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define PRECISION cout.precision(3); cout.setf(ios::fixed);

#define infinite 9123456789
#define db cout << "Debug" << "\n";
#define dbg(x)  cout << #x << " = " << x << "\n"

int n, a[300010], t[300010];
map< int, vector<int> > M;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 1; i <= n; i++) M[a[i]].pb(t[i]);

    int cur = 0, ans = 0;
    multiset<int> num;

    int i = 0, foi = 0;
    while(true){
        // pego o proximo
        if(num.size() == 0 or M.find(i) != M.end()){
            auto it = M.lower_bound(i);
            // dbg(it->first);
            // for(auto u : it->second) cout << u << " ";
            if(it == M.end()) break;
            i = it->first;
            for(auto u : it->second) num.insert(u), cur += u;
        }
        // tiro o mais caro
        auto tiro = *--num.end();
        cur -= tiro;
        num.erase(num.find(tiro));
        ans += cur;
        i++;
    }
    cout << ans << "\n";
}

signed main(){
    // IOS; int t; cin >> t;
    // for(int i = 1; i <= t; i++)
    IOS;
        solve();
}