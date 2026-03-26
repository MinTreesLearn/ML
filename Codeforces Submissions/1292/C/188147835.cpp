#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep3(i,m,n) for(int i=(m);i<(n);i++)
#define foreach(x,a) for(auto& (x) : (a) )

#define endl '\n'
#define dump(x)  cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl

#define pb(a) push_back(a)

#define sz(x) ((int)(x).size())
#define in(a,us) (us).find(a)!=(us).end()

template<typename S>
using Vec = vector<S>;

template<typename S, typename T>
using P = pair<S,T>;

template<typename S, typename T, typename U>
using Tpl = tuple<S,T,U>;

using ll = long long;
using ld = long double;

using Pii = P<int, int>;
using Pll = P<ll,ll>;

using Tiii = Tpl<int,int,int>;
using Tll = Tpl<ll,ll,ll>;

using Vi = Vec<int>;
using VVi = Vec<Vi>;

template<typename S, typename T>
using umap = unordered_map<S,T>;

template<typename S>
using uset = unordered_set<S>;

using Graph = VVi;

int depth[3002][3002];
int par[3002][3002];
int childn[3002][3002];
ll DP[3002][3002];

void dfs(int v, int root, Graph &g){
    childn[root][v] = 1;
    for(auto v1: g[v]){
        if (v1!=par[root][v]){
            depth[root][v1] = depth[root][v]+1;
            par[root][v1] = v;
            dfs(v1, root, g);
            childn[root][v] += childn[root][v1];
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    Graph g(n,Vi());
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,n) {
        par[i][i] = -1;
        depth[i][i] = 0;
        dfs(i, i, g);
    }
    Vec<Vec<Pii>> p(n, Vec<Pii>());
    rep(i,n) rep3(j,i+1,n){
        p[depth[i][j]].push_back({i,j});
    }
    rep(i,n) DP[i][i] = 0;
    ll ans = 0;
    rep(i,n){
        for(auto [u,v]: p[i]){
            DP[u][v] = max(DP[u][par[u][v]],DP[par[v][u]][v]) + childn[u][v]*childn[v][u];
            DP[v][u] = DP[u][v];
            ans = max(ans, DP[u][v]);
        }
    }
    cout << ans << endl;
}
