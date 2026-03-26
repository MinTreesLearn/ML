#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define pb push_back
#define ff first
#define ss second
#define oo 100000000000000L

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    int n,s,k,cur,ans1=oo,ans2=oo; cin >> n >> s >> k;
    map<int,int> mp;
    for(int i=0;i<k;++i) {
        int cur; cin >> cur;
        mp[cur]++;
    }
    cur=s;
    while(mp[cur]>0&&cur<=n){
        ++cur;
    }
    if(cur<=n) {
        ans1=cur-s;
    }
    cur=s-1;
    while(cur>0&&mp[cur]){
        --cur;
    }
    if(cur>0){
        ans2=s-cur;
    }
    cout << min(ans1,ans2);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
    return 0;
}
