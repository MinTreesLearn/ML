#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//priority_queue <int, vector<int>, greater<int>> q;

queue <int> q;
vector <int> v[200005], iv[200005];
int viz[200005], d[200005], path[200005], minn, maxx, k;

void bfs(int nod){
    q.push(nod);
    d[nod] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto& y: iv[x]){
            if(d[y] == 0){
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
}

void solve(int i){
    if(i < k){
        int nr = 0, nod = path[i];
        bool ok = false;
        for(auto& x: v[nod]){
            if(d[x] == d[nod] - 1){
                nr++;
                if(x == path[i + 1]) ok = true;
            }
        }
        if(ok == false) minn++, maxx++;
        else if(nr > 1) maxx++;
        solve(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        iv[y].push_back(x);
        v[x].push_back(y);
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> path[i];
    }
    bfs(path[k]);
    solve(1);
    cout << minn << " " << maxx;
    return 0;
}