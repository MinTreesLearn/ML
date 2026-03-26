#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T> inline void read(T &F) {
    int R = 1; F = 0; char CH = getchar();
    for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
    for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
    F *= R;
}
inline void file(string str) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
}
const int N = 4e5 + 10, Log = 19;
int n, m, k, co[N], anc[N], dep[N], fa[N][Log], dis[N]; vector<int> edge[N];
int getfa(int x) {
    return anc[x] == x ? x : anc[x] = getfa(anc[x]);
}
int skp(int x, int d) {
    while(d) x = fa[x][__builtin_ctz(d)], d -= (d & -d);
    return x;
}
int getlca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    x = skp(x, dep[x] - dep[y]);
    if(x == y) return x; 
    for(int i = 31 - __builtin_clz(dep[x]); i >= 0; i--)
        if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
void predfs(int x) {
    dep[x] = dep[fa[x][0]] + 1;
    for(int i = 1; i < Log; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(int i : edge[x]) {
        if(i == fa[x][0]) continue;
        fa[i][0] = x; predfs(i);
    }
}
void add(int x, int y) {
    edge[x].emplace_back(y), edge[y].emplace_back(x);
}
void merge(int x, int y) {
    x = getfa(x), y = getfa(y); anc[x] = y;
}
void bfs() {
    queue<int> q; memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; i++) if(co[i]) q.push(i), dis[i] = 0;
    while(!q.empty()) {
        int p = q.front(); q.pop(); if(dis[p] == k / 2) continue;
        for(int i : edge[p]) {
            if(dis[p] + 1 < dis[i])
                dis[i] = dis[p] + 1, co[i] = co[p], q.push(i);
            else merge(co[i], co[p]);
        }
    }
}
int main() {
    //file("");
    read(n), read(k), read(m); k *= 2;    
    for(int i = 1; i < n; i++) {
        int x, y; read(x), read(y);
        add(i + n, x), add(i + n, y);
    }
    for(int i = 1; i <= m; i++) {
        int x; read(x); co[x] = i;
        anc[i] = i;
    }
    n = 2 * n - 1; predfs(1); bfs();
    int q; read(q);
    for(int i = 1; i <= q; i++) {
        int x, y; read(x), read(y);
        const int z = getlca(x, y), d = dep[x] + dep[y] - 2 * dep[z];
        if(d <= k) {
            puts("YES"); continue;
        }
        if(dep[x] < dep[y]) swap(x, y);
        const int a = skp(x, k / 2), b = (dep[y] - dep[z] < k / 2 ? skp(x, d - k / 2) : skp(y, k / 2));
        if(co[a] && co[b] && getfa(co[a]) == getfa(co[b])) puts("YES");
        else puts("NO");
    }
    #ifdef _MagicDuck
        fprintf(stderr, "# Time: %.3lf s", (double)clock() / CLOCKS_PER_SEC);
    #endif
    return 0;
}