#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
void iosbase(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll p,a,b;
string s;
bool get(ll pos){
    ll ans=0;
    vector<char> v;
    v.push_back(s[pos-1]);
    for(ll i=pos+1; i<s.size(); i++){
        if(v[v.size()-1] != s[i-1]) v.push_back(s[i-1]);
    }
    for(auto to: v){
        if(to == 'A') ans+=a;
        else ans+=b;
    }
    if(ans <= p) return true;
    else return false;
}
void solve(){
    cin>>a>>b>>p>>s;
    ll l=1,r=s.size();
    ll res=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(get(mid)){
            res=mid;
            r=mid-1;
        } else{
            l=mid+1;
        }
    }
    if(res == -1){
        cout<<s.size();
    } else{
        cout<<res;
    }
}       
int main() {
    iosbase();  
    ll t=1;
    cin>>t;    
    for(ll i=1; i<=t; i++){
        solve();
        cout<<'\n';
    }
}