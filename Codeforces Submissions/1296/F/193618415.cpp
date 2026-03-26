#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < n - 1; i++ ){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
    }

    vector<int> fa(n, -1), dep(n), edge(n);
    function<void(int)> dfs = [&](int x){
        for(auto [u, id] : adj[x]){
            if(u == fa[x]) continue;
            dep[u] = dep[x] + 1;
            fa[u] = x;
            edge[u] = id;
            dfs(u);
        }
    };
    dfs(0);

    int m;
    cin >> m;
    vector<int> ans(n - 1, -1);
    int ok = 1;
    vector<tuple<int, int, int>> e;
    for(int i = 0; i < m; i++ ){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        if(x > y) swap(x, y);
        e.emplace_back(w, x, y);
    }
    sort(e.rbegin(), e.rend());
    
    for(int i = 0; i < m; i++ ){
        auto [w, x, y] = e[i];
        vector<int> c;
        int f = 0;
        while(x != y){
            if(dep[x] > dep[y]){
                if(ans[edge[x]] == -1){
                    c.push_back(edge[x]);
                }
                if(ans[edge[x]] == w){
                    f = 1;
                }
                x = fa[x];
            } else {
                if(ans[edge[y]] == -1){
                    c.push_back(edge[y]);
                }
                if(ans[edge[y]] == w){
                    f = 1;
                }
                y = fa[y];
            }
        }
        if(c.empty() && !f){
            ok = 0;
        } else {
            for(auto x : c){
                ans[x] = w;
            }
        }
    }
    if(!ok){
        cout << -1 << "\n";
        return 0;
    }
    for(int i = 0; i < n - 1; i++ ){
        if(ans[i] == -1) cout << 1 << " ";
        else cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}