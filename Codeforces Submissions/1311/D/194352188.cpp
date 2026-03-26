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

int main(){
  cha
  ll n;
  // for(auto x : vec[30])cout<<x<<" ";
  // cout<<endl;
  cin>>n;
  while(n--){
    map<ll,vector<ll>> mp;
    ll a,b,c;
    cin>>a>>b>>c;
    ll mn=1e18;
    ll h1,h2,h3;
    for(ll i=1;i<=2*a;i++){
      for(ll j=i;j<=2*b;j+=i){
        for(ll k=0;k<2;k++){
          ll l=(c/j)*j+k*j;
          ll val=abs(i-a)+abs(b-j)+abs(c-l);
          if(mn>val){
            mn=min(mn,val);
            h1=i;
            h2=j;
            h3=l;
          }
        }
      }
    }
    cout<<mn<<endl;
    cout<<h1<<" "<<h2<<" "<<h3;
    cout<<endl;
    
  }
}