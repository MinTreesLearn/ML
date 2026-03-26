#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int n;
const int LOG = 20;
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];
int LCA[N][LOG];

void dfs(int node, int parent) {
    depth[node] = depth[parent] + 1;
    LCA[node][0] = parent;
    for(int child : g[node]) {
        if(child == parent) {
            continue;
        }
        dfs(child, node);
    }
}

void build() {
    for(int j = 1; j < LOG; j++) {
        for(int i = 1; i <= n; i++) {
            LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
        }
    }
}

int find(int a, int b) {
    if(depth[b] < depth[a]) {
        swap(a, b);
    }
    int diff = depth[b] - depth[a];
    for(int j = 0; j < LOG; j++) {
        if((diff & (1 << j))) {
            b = LCA[b][j];
        }
    }
    if(a == b) {
        return a;
    }
    for(int j = LOG - 1; j >= 0; j--) {
        if(LCA[a][j] != LCA[b][j]) {
            a = LCA[a][j];
            b = LCA[b][j];
        }
    }
    return LCA[a][0];
}

int dist(int a, int b) {
    int lca = find(a, b);
    return depth[a] + depth[b] - 2 * depth[lca];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth[0] = -1;
    dfs(1, 0);
    build();

    int q;
    cin >> q;
    while(q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int without = dist(a, b);
        if((without & 1) == (k & 1) && without <= k) {
            cout << "YES\n";
            continue;
        }
        int with = dist(a, x) + dist(b, y) + 1;
        if((with & 1) == (k & 1) && with <= k) {
            cout << "YES\n";
            continue;
        }
        with = dist(a, y) + dist(b, x) + 1;
        if((with & 1) == (k & 1) && with <= k) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }

    return 0;
}