#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long INF = 3e18;
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
#define all(x) x.begin(),x.end()
#define int long long

void solve(){
    int maxim = 0;
    int n;
    cin >> n;
    vector<int> b(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++){
        cin >> b[i];
        mp[i-b[i]].push_back(b[i]);
    }
    for (auto i : mp){
        vector<int> now = i.second;
        int cnt = 0;
        for (int j = 0; j < now.size(); j++){
            cnt += now[j];
        }
        maxim = max(maxim, cnt);
    }
    cout << maxim;
}


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(9);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}