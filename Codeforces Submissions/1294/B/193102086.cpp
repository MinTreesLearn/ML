#include <bits/stdc++.h>
using namespace std;

typedef unsigned int  ui;
typedef long long     ll;
#define all(x)        x.begin(), x.end()
#define F             first
#define S             second
#define rep(x, y, z)  for(int x = y; x <= z; x++)
#define rrep(x, y, z) for(int x = y; x >= z; x--)
#define arep(x, y)    for(auto & x : y)
const int mxN = 1e6 + 5;
int QU = 0;

void solve(){
    int n;
    cin>>n;
    
    vector<pair<int, int>> p(n);
    for(auto & [x, y] : p) cin>>x>>y;
    sort(all(p));
    
    pair<int, int> cur = {0, 0};
    string ans = "";
    bool is = 0;
    for(auto & [x, y] : p){
        if(x - cur.F < 0 || y - cur.S < 0){
            cout<<"NO\n";
            return;
        }
        ans += string(x - cur.F, 'R');
        ans += string(y - cur.S, 'U');
        cur = {x, y};
    }
    cout<<"YES\n";
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout<<fixed<<setprecision(20);
    if(!QU) cin>>QU;
    while(QU--){
        solve();
    }
}