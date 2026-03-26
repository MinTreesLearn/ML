#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
const ll MAXN = 5e5 + 20;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
 
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define endll '\n'

vector <int> adj[MAXN], vec;
bool mark[MAXN];

int ask(int r){
    vec.clear();
    for(int u : adj[r]) if(!mark[u]) vec.pb(u);
    while(Sz(vec) > 1){
        int u = vec.back(), v = vec[Sz(vec) - 2], par;
        vec.pop_back(), vec.pop_back();
        mark[u] = mark[v] = 1;
        cout << "? " << u << " " << v << endl;
        cin >> par;
        if(par != r){
            mark[r] = 1;
            return ask(par);
        }
    }
    if(Sz(vec) == 1){
        int i = 0;
        while(i < Sz(adj[vec[0]]) && (mark[adj[vec[0]][i]] || adj[vec[0]][i] ==  r)) i ++;
        if(i == Sz(adj[vec[0]])){
            mark[vec[0]] = mark[r] = 1;
            cout << "? " << r << " " << vec[0] << endl;
            cin >> r;
            return r;
        }
        else{
            int par;
            mark[adj[vec[0]][i]] = mark[r] = 1;
            cout << "? " << r << " " << adj[vec[0]][i] << endl;
            cin >> par;
            if(par == vec[0]) return ask(par);
            if(par == adj[vec[0]][i]){
                mark[vec[0]] = 1;
                return ask(par);
            } 
        }
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    int rt = ask(1);
    cout << "! " << rt << endl;
    return 0;
}