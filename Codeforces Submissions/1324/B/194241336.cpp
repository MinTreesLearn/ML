#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fst first
#define sec second
#define mod (ll)(1e9+7)
void solve(){
        ll n;cin >> n;
        map<ll,vector<ll> > mp;
        for(ll i=0;i<n;i++) {
            ll data;
            cin >> data;
            mp[data].push_back(i);
        }
        for(auto v:mp){
            vector<ll> tmp=v.second;
            if(tmp.size()>1){
                if(tmp[tmp.size()-1]-tmp[0]>1){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
 }
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t=1;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}