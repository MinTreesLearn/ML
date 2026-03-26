#include <bits/stdc++.h>
using namespace std;

#define ll long long int


ll f(ll bit,vector<ll> &a){
    if(bit==-1){
        return 0;
    }
    vector<ll> pre,ab;
    ll n=a.size();
    for(ll i=0;i<n;i++){
        if(((1<<bit)&a[i])>0){
            pre.push_back(a[i]);
        }
        else{
            ab.push_back(a[i]);
        }
    }

    if(pre.size()==0){
        return f(bit-1,ab);
    }
    if(ab.size()==0){
        return f(bit-1,pre);
    }

    return min(f(bit-1,pre),f(bit-1,ab)) + (1<<bit);

}
void solve(){

    ll n;
    cin >> n;

    vector<ll> a (n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout<<f(30,a)<<endl;

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