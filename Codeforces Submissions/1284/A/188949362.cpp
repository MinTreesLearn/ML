#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define nl endl
#define pb push_back
const int N=1e5+10;
#define uniq(v) (v).erase(unique(v.begin(),v.end()),(v).end())
 
void solve(){
ll n,m;
cin>>n>>m;
// cout<<m<<" "<<n<<nl;
vector<string>v1(n),v2(m);
for(ll i=0;i<n;i++){
    cin>>v1[i];
}
for(ll i=0;i<m;i++){
    cin>>v2[i];
}

ll q;
cin>>q;
for(ll i=0;i<q;i++){
    ll x;
    cin>>x;
    ll a=x,b=x;
    if(a%n==0){
a=(n-1);
    }
    else{
        a=(a%n)-1;
    }
     if(b%m==0){
b=(m-1);
    }
    else{
        b=(b%m)-1;
    }
    cout<<v1[a]+v2[b]<<nl;
}


}
int main(){
  // ll t;cin>>t;while(t--)
    solve();
}