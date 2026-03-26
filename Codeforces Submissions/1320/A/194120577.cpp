#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> 

using namespace std; 
using namespace __gnu_pbds; 

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

#define ll long long int 
#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define cin(arr,n) for(int i=0; i<n;i++){cin>>arr[i];}
#define endl "\n"
#define cin1(vec,n) forn(i,n){ll x;cin>>x;vec.push_back(x);} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
        map<ll,ll>mp;
        ll n;
        cin>>n;
        ll arr[n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            mp[arr[i]-i]+=arr[i];
        }
        ll ans=0;
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        cout<<ans<<endl;

    return 0;
}