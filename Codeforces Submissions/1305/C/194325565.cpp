#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>
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

int main(){
  ll n;
  cin>>n;
  ll m;
  cin>>m;
  for(ll i=1;i<=n;i++){
    cin>>a[i];
  }
  if(n>m){
    cout<<0<<endl;
  }
  else{
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
      a[i]=(a[i]+m)%m;
    }
    ll ans=1;
    for(ll i=1;i<n;i++){
      for(ll j=i+1;j<=n;j++){
        ll val=(m+a[j]%m-a[i]%m)%m;
        // cout<<val<<" ";
        ans*=val;
        ans%=m;
      }
    }
    cout<<ans<<endl;
  }
}