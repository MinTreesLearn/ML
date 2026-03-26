#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
    ll n,cou=0,ans=0;
    cin >> n;
    vector<ll> arr1,arr2;
    for(ll i=0;i<n;i++){
        ll x,mx=-1,mn=1000000,f=0;
        cin >> x;
        vector<ll> a(x+100);
        for(ll i=0;i<x;i++){
            ll y;
            cin >> a[i];
            if(a[i]>mn)f=1;
            mx= max(mx,a[i]);
            mn= min(mn,a[i]);
        }
        if(!f){
            arr1.push_back(mn);
            arr2.push_back(mx);
        }
        else {
            cou++;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for(ll i=0;i<arr2.size();i++){
        ll p= lower_bound(arr1.begin(),arr1.end(),arr2[i])- arr1.begin();
        if(arr1[p]>arr2[i])
        ans+= p;
        else ans+= p;
    }
    ans+= arr1.size()*cou*2 + cou*cou;
    cout << ans << endl;
    return 0;
}