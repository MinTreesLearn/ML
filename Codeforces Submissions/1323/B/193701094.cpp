#include<iostream>
using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define sst string
#define pb push_back
#define maxco 100000+5
#define lld long double
#define cha ios_base::sync_with_stdio(false);
#define ffl cout.flush();
#define phi acos(-1)
#define mod 1000000007

ll a[200069];
ll b[200069];
int main(){
    cha
    ll n,m,k;
    cin>>n>>m>>k;
    vector <pair<ll,ll>> vec;
    for(ll i=1;i*i<=k;i++){
        if(k%i==0){
            vec.pb({i,k/i});
        }
    }
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=m;i++){
        cin>>b[i];
    }
    vector <ll> up,dw;
    ll sd=0;
    for(ll i=1;i<=n;i++){
        if(a[i]==1){
            sd++;
        }
        else{
            if(sd!=0){
                up.pb(sd);
                sd=0;
            }
            else{
                sd=0;
            }
        }
//        cout<<i<<" ";
//        cout<<sd<<endl;
    }
    if(sd!=0){
        up.pb(sd);
    }
    sd=0;
    for(ll i=1;i<=m;i++){
        if(b[i]==1){
            sd++;
        }
        else{
            if(sd!=0){
                dw.pb(sd);
                sd=0;
            }
            else{
                sd=0;
            }
        }
//        cout<<i<<" ";
//        cout<<sd<<endl;
    }
    if(sd!=0){
        dw.pb(sd);
    }
    sort(up.begin(),up.end());
    sort(dw.begin(),dw.end());
//    for(auto x : up)cout<<x<<" ";
//    cout<<endl;
//    for(auto x : dw)cout<<x<<" ";
//    cout<<endl;
    ll ans=0;
    for(auto x : vec){
//        cout<<x.fi<<"    "<<x.se<<"   :  ";
//        cout<<endl;
        ll sdfi=lower_bound(up.begin(),up.end(),x.fi)-up.begin();
        ll sdse=lower_bound(dw.begin(), dw.end(), x.se)-dw.begin();
//        cout<<sdfi<<" "<<sdse<<endl;
        for(ll i=sdfi;i<up.size();i++){
            for(ll j=sdse;j<dw.size();j++){
                ll val=up[i]-x.fi+1;
                ll val2=dw[j]-x.se+1;
//                cout<<val<<" "<<val2<<endl;
                ans+=val*val2;
            }
        }
        if(x.fi!=x.se){
            sdfi=lower_bound(up.begin(), up.end(), x.se)-up.begin();
            sdse=lower_bound(dw.begin(), dw.end(), x.fi)-dw.begin();
            for(ll i=sdfi;i<up.size();i++){
                for(ll j=sdse;j<dw.size();j++){
                    ll val=up[i]-x.se+1;
                    ll val2=dw[j]-x.fi+1;
//                    cout<<val<<" "<<val2<<endl;
                    ans+=val*val2;
                }
            }
//            cout<<sdfi<<" "<<sdse<<endl;
        }
    }
    cout<<ans<<endl;
}
