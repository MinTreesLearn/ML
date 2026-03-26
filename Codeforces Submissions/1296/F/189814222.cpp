#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pint;
#define MP make_pair
#define MAXN 5069
pint p[MAXN]; vector<int> adj[MAXN];
vector<pint> edges;
vector<pair<pint,int>> updates;
int h[MAXN];
void dfs(int x, int par) {
    p[x] = MP(par, INT_MIN);
    for(auto i: adj[x]) if(i != par) {
        h[i] = h[x] + 1;
        dfs(i, x);
    }
}
void update(int a, int b, int val) {
    if(h[b] < h[a]) swap(a, b);
    while(h[b] > h[a]) {
        p[b].second = max(p[b].second, val);
        b = p[b].first;
    }
    while(a != b) {
        p[a].second = max(p[a].second, val);
        p[b].second = max(p[b].second, val);
        a = p[a].first; b = p[b].first;
    }
}
int check(int a, int b) {
    if(h[b] < h[a]) swap(a, b);
    int ans = INT_MAX;
    while(h[b] > h[a]) {
        ans = min(ans, p[b].second);
        b = p[b].first;
    }
    while(a != b) {
        ans = min(min(p[a].second, p[b].second), ans);
        a = p[a].first; b = p[b].first;
    }
    return ans;
}
int main() {
    int n, m, a, b, g; cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> a >> b; edges.push_back(MP(a, b));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    cin >> m;
    while(m--) {
        cin >> a >> b >> g;
        updates.push_back(MP(MP(a, b),g));
        update(a, b, g);
    }
    bool valid = true;
    for(auto i: updates) {
        if(check(i.first.first, i.first.second) != i.second) {
            valid = false; break;
        }
    }
    if(valid) {
        for(auto i: edges) {
            int child = max(i.first, i.second);
            if(p[child].second == INT_MIN) cout << "69420\n";
            else cout << p[child].second << "\n";
        }
    } else {
        cout << -1;
    }
}