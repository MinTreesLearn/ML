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
     ll t;
     cin>>t;
     while(t--){
     ll n;
     cin>>n;
     set<ll> b;
     while(n--){
          int a;
          cin>>a;
         b.insert(a); 
     }
     cout<<b.size()<<"\n";
     }
} 