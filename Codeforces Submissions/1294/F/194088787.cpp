#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
using namespace std;
typedef long long ll;
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define tp tuple<int,int,int>
#define X first
#define Y second
#define hehehehaw ios::sync_with_stdio(0);cin.tie(0);
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
//---------94i87----------//
const int N=2e5+10;
int pa[N],dep[N];
vector<int> adj[N];
void dfs(int v,int p){
    for(int u:adj[v]) if (u!=p && dep[u]==0){
        dep[u]=dep[v]+1;
        pa[u]=v;
        dfs(u,v);
    }
}
void solve(int n){
    dfs(1,-1);
    int c=0;
    for(int i=1;i<=n;i++){
        if (dep[i]>dep[c]) c=i; 
    }
    memset(dep,0,sizeof(dep));
    dfs(c,-1);
    int d=0,ans=0;
    for(int i=1;i<=n;i++){
        if (dep[i]>dep[d]) d=i;
    }
    int temp=d,ttemp=d;
    ans+=dep[d];
    memset(dep,0,sizeof(dep));
    dep[c]=-1;
    while(d!=c) {dep[d]=-1;d=pa[d];}
    while(temp!=c){
        dfs(temp,-1);
        temp=pa[temp];
    }
    int e=1;
    while(e==c || e==ttemp) e++;
    for(int i=1;i<=n;i++){
        if (dep[i]!=-1 && dep[i]>=dep[e]) e=i;
    }
    cout << ans+dep[e]+1 << '\n';
    cout << c << ' ' << ttemp << ' ' << e << '\n';
}
signed main(signed argc,char** argv){
 
    hehehehaw;

    int n;cin >> n;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    solve(n);
    return 0;   
}