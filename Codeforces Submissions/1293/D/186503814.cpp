#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
#define fastio          ios_base::sync_with_stdio(0); cin.tie(0);
int32_t main()
{
    int lim = (((long long)1)<<62)-1;
    // cout<<lim<<" "<<((long long)1<<62)-1;
    int x0,y0,ax,ay,bx,by,t,xs,ys;
    vector<pii> arr;
    cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
    arr.pb({x0,y0});
    while( ((lim-bx)/ax) >=arr.back().ff && ((lim-by)/ay)>=arr.back().ss){
        int x = arr.back().ff,y=arr.back().ss;
        arr.pb({x*ax+bx,y*ay+by});
    }
    int ans=0;
    // for(int i=0;i<arr.size();i++) cout<<arr[i].ff<<" "<<arr[i].ss<<"\n";
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int dl = abs(xs-arr[i].ff) + abs(ys-arr[i].ss);
            int dr = abs(xs-arr[j].ff) + abs(ys-arr[j].ss);
            int dist = abs(arr[j].ff-arr[i].ff) + abs(arr[j].ss-arr[i].ss);
            if(dist<=t-dl || dist<=t-dr) ans = max(ans,j-i+1);
        }
    }
    cout<<ans<<"\n";
return 0;
}