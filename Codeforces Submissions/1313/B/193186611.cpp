#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    cout<<max(1ll,min(x+y-n+1,n))<<' ';
    cout<<min(x+y-1,n)<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    for (int i=1;i<=t;i++){
        solve();
    }
    return 0;
}