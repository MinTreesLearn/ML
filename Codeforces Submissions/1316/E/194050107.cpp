#include<bits/stdc++.h>
#define ll long long
#define el '\n'
#define all(a) a.begin(),a.end()

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N=2e5+5,mod=1e9+7;

int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};
ll n,p,k,dp[N][1<<7];
pair<int,vector<int>>v[N];
ll solve(int indx,int mask){
    if(indx==n){
        if(mask==(1<<p)-1)
            return 0;
        return -1e9;
    }
    ll &sol=dp[indx][mask];
    if(~sol)
        return sol;
    sol=solve(indx+1,mask);
    if(indx-__builtin_popcount(mask)<k)
        sol=max(sol,solve(indx+1,mask)+v[indx].first);

    for(int i=0;i<p;i++){
        if(mask&(1<<i))
            continue;
        sol=max(sol,solve(indx+1,mask|(1<<i))+v[indx].second[i]);
    }
    return sol;
}
inline void Lessgo() {
   cin>>n>>p>>k;
   for(int i=0;i<n;i++)
       cin>>v[i].first;
   for(int i=0;i<n;i++){
       for(int j=0;j<p;j++){
           int x;
           cin>>x;
           v[i].second.push_back(x);
       }
   }
    sort(v,v+n,greater<pair<int,vector<int>>>());
    ::memset(dp,-1,sizeof dp);
   cout<<solve(0,0);
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc=1;
//    cin>>tc;
    while(tc--){
        Lessgo();
    }
}

