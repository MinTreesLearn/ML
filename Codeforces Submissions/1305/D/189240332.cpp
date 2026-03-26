#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

int main() 
{
    
    int n;
    cin >> n;
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++ ){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    vector<int> vis(n);
    while(1){
        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++ ){
            if(deg[i] == 1){
                p.emplace_back(deg[i], i);
            }
        }
        sort(p.begin(), p.end());
        if(accumulate(vis.begin(), vis.end(), 0) == n - 1){
            for(int i = 0; i < n; i++ ){
                if(!vis[i]){
                    cout << "! " << i + 1 << endl;
                    return 0;   
                }
            }
        }
        auto ask = [&](int x, int y){
            cout << "? " << x + 1 << " " << y + 1 << endl;
            int res;
            cin >> res;
            return res - 1;
        };

        int sc = ask(p[0].se, p[1].se);
        if(sc == p[0].se){
            cout << "! " << p[0].se + 1 << endl;
            return 0;
        }
        if(sc == p[1].se){
            cout << "! " << p[1].se + 1 << endl;
            return 0;
        }
        deg[p[0].se]--;
        deg[p[1].se]--;
        vis[p[0].se] = 1;
        vis[p[1].se] = 1;
        for(auto u : adj[p[0].se]){
            deg[u]--;
        }
        for(auto u : adj[p[1].se]){
            deg[u]--;
        }
    }   
    return 0;
}