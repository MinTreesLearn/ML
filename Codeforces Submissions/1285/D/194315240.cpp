#include <bits/stdc++.h>
using namespace std;

#define ll long long int

//<min, x>
pair<ll, ll> f(ll c, vector<ll> &a){

    if(a.size() == 0 || c == 0){
        return pair<ll, ll>(0, 0);
    }
    vector<ll> setBit;
    vector<ll> unsetBit;

    for(ll i = 0; i<a.size(); i++){
        if((a[i] & c) == c){
            setBit.push_back(a[i]);
        }
        else{
            unsetBit.push_back(a[i]);
        }
    }

    pair<ll, ll> ansSet = f(c/2, setBit);
    pair<ll, ll> ansUnset = f(c/2, unsetBit);

    pair<ll, ll> ans = ansUnset;

    if(unsetBit.size() == 0){
        ans = ansSet;
        ans.second += c;
        return ans;
    }
    else if(setBit.size() == 0){
        ans = ansUnset;
        return ans;
    }
    if(ansSet.first < ansUnset.first){
        ans = ansSet;
        ans.second += c;
    }

    if(setBit.size() != 0 && unsetBit.size() != 0){
        ans.first += c;
    }

    return ans;
}

void solve(){

    ll n;
    cin >> n;

    vector<ll> a (n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll c = powl(2, 30);

    pair<ll, ll> ans = f(c, a);

    cout << ans.first << endl;
}

int main() { 

    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    
    while (T--)
    {
        solve();
    }
    
    return 0;

}