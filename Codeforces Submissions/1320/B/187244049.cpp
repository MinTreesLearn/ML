#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class key, class cmp = std::less<key>>
using op_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef thunder
#include "bug.h"
#else
#define bug(...) 
#endif

#define ll long long
#define lld double
#define all(x) x.begin(), x.end()
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define goog(tno) cout << "Case #" << tno <<": "

const ll INF=2e18;
const ll mod=1000000007;
const ll maxn=2e5+5;

ll n,m;
vector<ll> g[maxn];
vector<ll> rev_g[maxn];
ll k;
vector<ll> a(maxn);
vector<ll> vis(maxn,0);
vector<ll> dis(maxn,INF);
vector<ll> ways(maxn,0);
vector<ll> par(maxn,-1);

void solve(){
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        rev_g[y].push_back(x);
    }
    cin>>k;
    for(ll i=1;i<=k;i++)    cin>>a[i];
    queue<ll> q;
    q.push(a[k]);
    ways[a[k]]=0;
    vis[a[k]]=1;
    dis[a[k]]=0;
    while(q.size()){
        auto node=q.front();
        q.pop();
        for(auto &to:rev_g[node]){
            if(!vis[to]){
                q.push(to);
                vis[to]=1;
            }
            if(dis[to]>dis[node]+1){
                dis[to]=dis[node]+1;
                ways[to]=1;
                par[to]=node;
            }else if(dis[to]==dis[node]+1){
                ways[to]+=ways[node];
            }
        }
    }
    bug(dis[a[1]]);
    ll mx=0,mn=0;
    for(ll i=1;i+1<=k;i++){
        if(dis[a[i]]!=dis[a[i+1]]+1){
            mn++;
            mx++;
            continue;
        }
        if(ways[a[i]]>1){
            mx++;
        }
    }
    cout<<mn<<" "<<mx<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}