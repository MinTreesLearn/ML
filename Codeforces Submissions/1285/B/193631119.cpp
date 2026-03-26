//Athour : 7amok4a
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace  std;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define mod_mul(a,b,m) ((a%m)*(b%m))%m
#define mod_add(a,b,m) ((a%m)+(b%m))%m
#define mod_sub(a,b,m) ((a%m)-(b%m))%m
#define gcd(a,b)  __gcd(a, b)
#define lcm(a,b)  a/__gcd(a, b )*b
#define fixed(n) cout<<fixed<<setprecision(n)
#define all(x) x.begin(),x.end()
#define el "\n"
int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = { 0, 1, -1, 0, -1, 1, 1, -1};
const ll N = 100, M = 100 , mod = 1e9 + 7 , OO = 2 * 1e9 , OOLL = 6 * 1e18,sz=1e6+1; 
const double pi=3.1415926535897932384626433832795028841971693993751058;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif
//\//\//\//\//\//\//\//\//\//\//\//\//\//\//\//
void A7med_YU(){
   ll n; cin>>n;
   vector<ll>v(n+5);
   vector<ll>pref(n+7);
   for(ll i=1;i<=n;++i){
       cin>>v[i];
   }
   for(ll i=1;i<=n;++i){
       pref[i]=pref[i-1]+v[i];
   }
   for(ll i=1;i<=n;i++){
       if(pref[i]<=0) return void(cout<<"NO"<<el);
   }
   for(ll i=1;i<n;++i){
       if(pref[i]>=pref[n])return void(cout<<"NO"<<el);
   }
  cout<<"YES"<<el;
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    Matter();
    #endif
    ll t = 1;  cin >> t;
    while (t--) {
      A7med_YU();
    }
    #ifndef ONLINE_JUDGE
      end_clock();
    #endif
}