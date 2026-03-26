#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 300001


int parent[N], Size[N], val[N];
int c[2][N];
vector<int> Comp[N];
int st[N];
int tot = 0;

void init_dsu(int n){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        Comp[i].push_back(i);
        Size[i] = 1;
        val[i] = 0;
        c[0][i] = 1;
        c[1][i] = 0;
        st[i] = -1;
    }
}

bool union_sets(int a, int b, int w){
    int pa = parent[a], pb = parent[b];
    if (pa == pb){
        return !(val[a] ^ val[b] ^ w);
    }
    int offset = val[a] ^ val[b] ^ w;
    if (Size[pa] > Size[pb]){
        swap(pa, pb);
    }
    if (st[pa] == -1) tot -= min(c[0][pa], c[1][pa]);
    else tot -= c[st[pa]][pa];
    if (st[pb] == -1) tot -= min(c[0][pb], c[1][pb]);
    else tot -= c[st[pb]][pb];

    for (int v : Comp[pa]){
        Comp[pb].push_back(v);
        parent[v] = pb;
        val[v] ^= offset;
    }
    Comp[pa].clear();
    c[0][pb] += c[0 ^ offset][pa];
    c[1][pb] += c[1 ^ offset][pa];
    Size[pb] += Size[pa];
    if (st[pa] != -1) st[pa] ^= offset;
    st[pb] = max(st[pa], st[pb]);
    if (st[pb] == -1) tot += min(c[0][pb], c[1][pb]);
    else tot += c[st[pb]][pb];
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k; cin >> n >> k;
    char s[n + 1];
    for (int i = 1; i <= n; i++) cin >> s[i];
    init_dsu(k);
    vector<int> adj[n + 1];
    for (int i = 0; i < k; i++){
        int c; cin >> c;
        for (int j = 0; j < c; j++){
            int idx; cin >> idx;
            adj[idx].push_back(i + 1);
        }
    }
    for (int i = 1; i <= n; i++){
        if (adj[i].empty());
        else if (adj[i].size() == 1){
            int v = adj[i][0];
            int pv = parent[v];
            if (st[pv] == -1){
                tot -= min(c[0][pv], c[1][pv]);
                st[pv] = (s[i] != '0') ^ val[v];
                tot += c[st[pv]][pv];
            }
        }
        else{
            int a = adj[i][0], b = adj[i][1];
            union_sets(a, b, s[i] == '0');
        }
        cout << tot << endl;
    }
    // cout << endl;
    // for (int i = 1; i <= k; i++) cout << parent[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= k; i++) cout << st[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= k; i++) cout << val[i] << ' ';
    // cout << endl;

}