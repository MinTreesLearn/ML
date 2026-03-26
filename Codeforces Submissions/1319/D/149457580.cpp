#include <bits/stdc++.h>
using namespace std;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define int long long
#define mid (l+r)/2
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
#define pi pair<int, int>
#define x first
#define y second
#define dorand mt19937 rng(123123); uniform_int_distribution<> randint(0, 1e9);
#define rnd randint(rng)

int s, t;
const int inf = 1e9;
const int N = 3e5;
vector<vector<int>> g(N);
vector<vector<int>> gr(N);
vector<int> dst(N, inf);
vector<int> ways(N, 0);
vector<int> used(N, 0);

void bfs() {
    queue<int> q;
    q.push(t);
    dst[t]=0;
    while(!q.empty()) {
        int v =q.front();
        q.pop();
        for(int u: gr[v]) {
            if(!used[u]) {
                used[u]=1;
                q.push(u);
                dst[u]=dst[v]+1;
            }
        }
    }
}

signed main() {
    fast
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    int k; cin >> k;
    vector<int> path(k);
    forn(i, 0, k) { cin >> path[i];}
    s = path[0];
    t = path[k-1];

    dst[t]=0;
    ways[t]=1;
    used[t]=1;
    bfs();
    

    int mn=0, mx = 0, len=k;
    forn(i, 0, k-1) {
        len--;
        int v = path[i];
        int nxt = path[i+1];
        if(dst[nxt]+1 > dst[v]) {
            //cout << nxt << ": " << dst[nxt] << " " << v << ": " << dst[v] << "\n";
            mn++;
        }
        for(int u: g[v]) {
            if(dst[u]+1 == dst[v] && u!=nxt) {
                mx++;break;
            }
        }
    }
    cout << mn << " " << mx;

}
