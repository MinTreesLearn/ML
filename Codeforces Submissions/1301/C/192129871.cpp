#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m= 998244353;

ll mod (ll x){
return ((x%m+m)%m);
}

ll add(ll a , ll b){
return mod(mod(a)+mod(b));
}

ll mul(ll a, ll b){
return mod(mod(a)*mod(b));
}
 
int main(){
   
     int t;
     cin>>t;
     
     while(t--){
     ll n,m;
     cin>>n>>m;
     
     ll zeroes= n-m;
     ll t= m+1;
     ll ingrp1= zeroes/t;
     ll ingrp2= zeroes % t;
     ll in2= ingrp1+1;
     ll countingrp1= (t-ingrp2)*(ingrp1*(ingrp1+1))/2;
     ll countingrp2= (ingrp2)*(in2*(in2+1))/2;
     cout<< (n*(n+1))/2 - (countingrp1+countingrp2)<<endl;
     
     
    
     }
}
