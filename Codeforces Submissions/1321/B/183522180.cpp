#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define pb push_back
#define eps 1e-6
#define decimal cout<<fixed; cout<<setprecision(6);
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   //cin>>t;
   t=1;
   while(t--){
       ll n;
       cin>>n;
       map<ll,ll> m;
       vector<pair<ll,ll>> v;
       for(ll i=0;i<n;i++){
           ll x;
           cin>>x;
           ll p=x-(i+1);
            m[p]=m[p]+x;
       }
       ll mx=0;
       for(auto pr:m){
           mx=max(mx,pr.second);
       }
       cout<<mx<<endl;
   }
   return 0;
}