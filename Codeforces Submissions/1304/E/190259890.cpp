/**
 *      Author:  Richw818
 *      Created: 01.23.2023 16:53:05
**/

#include <bits/stdc++.h>
using namespace std;
struct blift{
    int N, LOG;
    vector<vector<int>> adj, up;
    vector<int> dep;
    blift(int _n){
        N = _n;
        LOG = 0;
        int curr = 1;
        while(curr <= N){
            LOG++;
            curr <<= 1;
        }
        adj.resize(N); dep.resize(N);
        up.resize(LOG, vector<int>(N, -1));
    }
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int n, int p, int d){
        up[0][n] = p;
        dep[n] = d;
        for(int next : adj[n]){
            if(next != p) dfs(next, n, d + 1);
        }
    }
    void build(int r){
        dfs(r, -1, 0);
        for(int i = 1; i < LOG; i++){
            for(int j = 0; j < N; j++){
                int p = up[i-1][j];
                if(p != -1) up[i][j] = up[i-1][p];
            }
        }
    }
    int lca(int a, int b){
        if(dep[a] < dep[b]) swap(a, b);
        int diff = dep[a] - dep[b];
        for(int i = 0; i < LOG; i++){
            if((1 << i) & diff) a = up[i][a];
        }
        if(a == b) return a;
        for(int i = LOG - 1; i >= 0; i--){
            if(up[i][a] != up[i][b]){
                a = up[i][a];
                b = up[i][b];
            }
        }
        return up[0][a];
    }
    int kth(int a, int k){
        for(int i = 0; i < LOG; i++){
            if(a == -1) return -1;
            if((1 << i) & k) a = up[i][a];
        }
        return a;
    }
    int dist(int a, int b){
        return dep[a] + dep[b] - 2 * dep[lca(a, b)];
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    blift bl(n);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        bl.add_edge(u, v);
    }
    bl.build(0);
    auto valid = [&](int d, int k) -> bool {
        return d <= k && d % 2 == k % 2;
    };
    int q; cin >> q;
    while(q--){
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
        x--, y--, a--, b--;
        int d1 = bl.dist(a, b);
        int d2 = bl.dist(a, x) + 1 + bl.dist(y, b);
        int d3 = bl.dist(a, y) + 1 + bl.dist(x, b);
        cout << (valid(d1, k) || valid(d2, k) || valid(d3, k) ? "YES" : "NO") << '\n';
    }
    return 0;
}