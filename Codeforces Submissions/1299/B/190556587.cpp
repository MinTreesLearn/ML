#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
ll n;
cin>>n;
vector<pair<ll,ll>>a(n);
for(ll j=0;j<n;j++){
    cin>>a[j].first>>a[j].second;
}
if(n%2==1){
    cout<<"NO\n";
}
else{
    ll p,q;
    p=a[0].first+a[n/2].first;
    ll f=1;
    q=a[0].second+a[n/2].second;
    for(ll j=0;j<n/2;j++){
        if(p==a[j].first+a[j+n/2].first&&q==a[j].second+a[j+n/2].second){
            continue;
        }
        else{
            f=-1;
            break;
        }
    }
    if(f==-1){
        cout<<"NO\n";

    }
    else{
        cout<<"YES\n";
    }
}
}