#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fst first
#define sec second
#define mod (ll)(1e9+7)
void solve(){
        string s;cin >> s;
        ll ans=0;
        ll ct=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='L') ct++;
            else{
                ans=max(ans,ct);
                ct=0;
            }
        }
        ans=max(ans,ct);
        cout << ans+1 << endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}