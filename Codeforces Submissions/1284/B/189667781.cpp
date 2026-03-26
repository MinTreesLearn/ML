#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
#ifndef ONLINE_JUDGE
#include "dbg.hpp"
#else
#define debug(...) 8
#endif

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<int> tmp(k);
        for(int j=0;j<k;j++){
            cin>>tmp[j];
        }
        debug(tmp);
        bool ascent = false;
        for(int j=0;j<k-1;j++){
            if(tmp[j] < tmp[j+1]){
                ascent = true;
            }
        }
        if(!ascent){
            v.push_back({tmp[0],tmp[k-1]});
        }
    }
    v.push_back({1e13,1e13});
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<v.size()-1;i++){
        ans += (int) (lower_bound(v.begin(),v.end(),make_pair(v[i].second,(int)1e13)) - v.begin());
    }
    debug(ans);
    cout<< n*n - ans<<'\n';

}

signed main() { 
   #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
      solve();
    }
}
