#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
using namespace std ;

void solve() {

     ll n ;
     cin>>n ;

     vector<ll>dp(n,0);

     map<ll,ll>mp ;

     vector<ll>v(n,0);
     for(ll i = 0 ; i < n ; i++){
         cin>>v[i];
         mp[i-v[i]] += v[i] ;
     }

     ll maxi = 0 ;

     for(auto it : mp) maxi = max(maxi,it.second) ;
     cout<<maxi<<endl;



     

}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);  
   // ll T ;
   // cin>>T ;
   // while(T--){
      solve() ;
   // }
}
bool isPowerOfTwo (int x)
{
 return x && (!(x&(x-1))); 
}