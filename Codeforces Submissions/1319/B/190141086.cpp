#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr);
#define int long long int

void GETAC(){
    
    int n, ans(0);
    map<int, int>mp;
    cin>>n;
    vector<int>v(n), pre(n);
    for(int&i:v)cin>>i;
    for(int i(0); i<n; ++i)
    {
        (mp[v[i]-i])? pre[i]=v[i]+pre[mp[v[i]-i]-1] : pre[i]=v[i];
        mp[v[i]-i] = i+1;
        ans=max(ans, pre[i]);
    }
    cout<<ans;
}

signed main() {
    fastio
    int t(1); //cin>>t;
    while(t--) GETAC(), cout<<'\n';
}
