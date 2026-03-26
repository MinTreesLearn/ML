#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
using namespace std ;

void solve() {

     ll n,g,b ;
     cin>>n>>g>>b ;


     ll good_days = n/2/g*g + (ll)(ceil(n/2.0) - n/2/g*g);
     ll bad_days = ((n/2/g-1)*b) + (ceil(n/2.0) - n/2/g*g != 0 ? b : 0);
     ll rem_days = max(0LL,(n-good_days-bad_days)) ;

     cout<<good_days+bad_days+rem_days<<endl;
//      cout<<good_days<<" "<<bad_days<<endl;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);  
   ll T ;
   cin>>T ;
   while(T--){
      solve() ;
   }
}
bool isPowerOfTwo (int x)
{
 return x && (!(x&(x-1))); 
}