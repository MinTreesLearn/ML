// In His Name
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e5 +5;
 
int n , dis[maxn] , a , b , c , dadi[maxn];
vector<int> masir;
bool mark[maxn];
vector<int> adj[maxn];
queue<int> q;
 
void dfs(int u , int dad){
    mark[u] = true;
    dis[u] = dis[dad]+1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!mark[v]){
            dadi[v] = u;
            dfs(v , u);
        }
    }
}
 
void bfs(){
   while(q.size()){
       int u = q.front();
       q.pop();
       for (auto v : adj[u]) {
           if (!mark[v]){
               q.push(v);
               mark[v] = true;
 
               dis[v] = dis[u] + 1;
           }
       }
   }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u , v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1 , 0);
 
    for (int i = 1; i <= n; ++i) {
        dis[i]--;
    }
    int maxi = 0;
    int f = 0;
    for (int i = 1; i <=n ; ++i) {
        if (dis[i] > maxi){
            maxi = dis[i];
            f = i;
        }
    }
    a = f;
    for (int i = 1; i <= n; ++i) {
        dis[i] = 0;
        mark[i] = false;
        dadi[i] = 0;
    }
 
    dfs(a , 0);
 
    maxi = 0;
    f = 0;
 
    for (int i = 1 ; i <= n ; i++){
        if (dis[i] > maxi){
            maxi = dis[i];
            f = i;
        }
    }
    b = f;
    int B = b;
    masir.push_back(B);
    while(B != a){
        masir.push_back(dadi[B]);
        B = dadi[B];
    }
 
    for (int i = 0; i <= n; ++i) {
        mark[i] = false;
        dis[i] = 0;
    }
 
    for (int i = 0; i < masir.size(); ++i) {
        mark[masir[i]] = true;
        q.push(masir[i]);
        dis[masir[i]] = 0;
 
    }
 
 
    bfs();
 
 
    maxi = -1;
    f = 0;
    for (int i = 1; i <= n; ++i) {
        if (maxi < dis[i] and i!= a and i!= b){
            maxi = dis[i];
            f = i;
        }
    }
    c = f;
    cout << masir.size() + maxi-1 << endl;
    cout << a << " " << b << " " << c;
 
 
 
}