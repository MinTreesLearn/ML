
/////////////////////////////////// By Pradeep ///////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define ll                    long long
#define PI                    3.141592653589793
#define MOD                     1000000007
#define all(v)               v.begin(), v.end()
#define fl(k,n)              for(ll i=k;i<n; i++)
#define py                   cout<<"YES"<<endl
#define pn                   cout<<"NO"<<endl
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<ll,ll>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> pbds;

////////////////////////////// Code starts here ////////////////////////////////////////

void  solve(){
   ll n;
   cin>>n;
   vector<ll>v1(n), v2(n);
   pbds s;
   fl(0,n)
    cin>>v1[i]; 
   fl(0, n)
    cin>>v2[i];
    ll ans = 0;
    fl(0, n){
        ll diff = v1[i] - v2[i];
        ans +=  s.order_of_key({diff , -1});
        s.insert({-diff , i});
    }
    cout<<ans<<endl;  
}
 

//////////////////////////////// Main functin /////////////////////////////////////////
int32_t main() {
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   ll t=1;
	// cin>>t;
	while(t--){
      solve();
  }
}
