#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr);
#define int long long int

void GETAC(){
    int n, s(0), s2(0);
    cin>>n;
    vector<int>v(n),v2(n);
    for(int&i:v)cin>>i; for(int&i:v2)cin>>i;
    for(int i(0); i<n; ++i)
        s+=(v[i]>v2[i]),s2+=(v[i]<v2[i]);
    if(!s)
        return cout<<-1, void();
    cout<<s2/s+1;
}

signed main() {
    fastio
    int t(1);//cin>>t;
    while(t--) GETAC(), cout<<'\n';
}
