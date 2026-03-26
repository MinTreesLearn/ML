// CALL ME DADDY
//	Whispering makes everything sound way sexier,
//	unless you're like 'Can you pass the salt' 
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mod 1000000007
#define nl '\n' 
#define vll vector<ll>
#define scanit(vvv,nnn) for(ll i=0; i<nnn; i++) cin>>vvv[i];
#define ff first
#define ss second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename K, typename V, typename Comp = less<K>> using indexed_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename Comp = less<K>> using indexed_set = indexed_map<K, null_type, Comp>;
 
 
 void solve(){
             int n;cin>>n;
             vector<int> v(n);scanit(v,n);
             vector<vector<int>> adj(n+1);
             for(int i=0;i<n-1;i++){
                 int a,b;cin>>a>>b;
                 a--;b--;
                 adj[a].pb(b);
                 adj[b].pb(a);
             }
             vector<int> dis(n,0);
             rep(i,n){
                 if(v[i]==1) v[i] = 1;
                 else v[i] = -1;
             }
             function<void(int,int)> dfs1 = [&](int x,int y){
                 dis[x] += v[x];
                 for(auto i : adj[x]){
                     if(i==y) continue;
                     dfs1(i,x);
                     dis[x] += max(0,dis[i]);
                 }
             };
             dfs1(0,-1);
            //  for(auto i : dis){
            //      cout<<i<<" ";
            //  }cout<<nl;
             function<void(int,int)> dfs = [&](int x,int y){
                 
                 for(auto i : adj[x]){
                     if(i==y) continue;
                     dis[i] += max(dis[x] - max(0,dis[i]) ,0);
                     dfs(i,x);
                 }

             };
             dfs(0,-1);
             for(auto i : dis){
                 cout<<i<<" ";
             }cout<<nl;
             
    }

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    ll testcase = 1;
    // cin >> testcase;
    while (testcase--){
        solve();
    }
    return 0;
}