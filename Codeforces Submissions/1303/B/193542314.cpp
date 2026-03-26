#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int 
#define endl "\n"
bool debugg = false;
#define dbg if(debugg)
#define ff first 
#define ss second 
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
  

int n,a,b;
bool f(int mid)
{
        int req = (n+1)/2;
        int cycle = (mid)/(a+b);
        int rem = (mid)%(a+b);
        int good = cycle*a + min(a,rem);

        return (good>=req && mid>=n);

}

void solve()
{
        
        cin>>n>>a>>b;

        
        int ans , lo = 0 , hi = 1e18;
        while(lo <= hi){
                int mid = (lo+hi)/2;

                if(f(mid)){
                        ans = mid;
                        hi = mid-1;
                }

                else lo = mid+1;
        }

        cout<<ans<<"\n";
}



int32_t main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
           
        int t  = 1;
        cin>>t;

        while(t--){

                solve();

        }

        return 0;

}