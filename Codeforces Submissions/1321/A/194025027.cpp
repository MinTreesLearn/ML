#include<bits/stdc++.h>
#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#include<math.h>
#include<algorithm>
#include<vector>
#include<stdbool.h>
using std::cout;
const int N = 3000008;
using namespace std;
 
int main(){
     ll n;
     cin>>n;
ll a[n],b[n];
for(int i=0;i<n;i++){
     cin>>a[i];
}
for(int i=0;i<n;i++){
     cin>>b[i];
}
ll x=0,y=0;
 for(int i=0;i<n;i++){
     
      if(a[i]==1 && b[i]==0) ++x;
      if(a[i]==0 && b[i]== 1) ++y;
 
 }
 if(x==0) cout<<-1;
 else cout<<y/x+1;
} 