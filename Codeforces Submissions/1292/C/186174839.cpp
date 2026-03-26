#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
const ll MOD=998244353;
const ll INF=1e18;
 
#define F first
#define S second
 
typedef long double ld;
typedef complex<long double> pt;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vector<ll> al[3001];
vector<vector<ll>> dp(3001, vector<ll> (3001,-1));
vector<vector<ll>> ss(3001, vector<ll> (3001));
vector<vector<ll>> pa(3001, vector<ll> (3001));

void dfs(ll node, ll parent, ll root){
    pa[node][root]=parent;
    ss[node][root]=1;
    for (auto u: al[node]){
        if (u!=parent){
            dfs(u,node,root);
            ss[node][root]+=ss[u][root];
        }
    }
}

ll f(ll u, ll v){
    if (dp[u][v]!=-1) return dp[u][v];
    if (u==v) dp[u][v]=0;
    else dp[u][v]=(ss[u][v]*ss[v][u])+max(f(u,pa[v][u]),f(pa[u][v],v));
    return dp[u][v];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    // for getting input frm input.txt 
    freopen("output.txt", "w", stdout);
    // for getting output frm output.tx
    #else
    #endif
    ll n;cin>>n;
    for (ll i=1; i<n; i++){
        ll a, b;
        cin>>a>>b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    for (ll i=1; i<=n; i++){
        dfs(i,i,i);
    }
    for (ll i=1; i<=n; i++){
        for (ll j=i; j<=n; j++) f(i,j);
    }
    ll fa=0;
    for (ll i=1; i<=n; i++){
        for (ll j=i; j<=n; j++){
            if (al[i].size()==1 && al[j].size()==1){
                fa=max(fa,dp[i][j]);
            }
        }
    }
    cout<<fa;
    return 0;
}
