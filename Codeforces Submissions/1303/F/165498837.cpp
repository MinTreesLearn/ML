/*
 * @name Dinic algorithm
 * @description Algorithm for flow searching in O(n^2m)
 * */
/* Includes */
#include <bits/stdc++.h>

/* Using libraries */
using namespace std;

/* Defines */
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ld long double
#define pb push_back
#define vc vector
#define sz(a) (int)a.size()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define pii pair <int, int>
#define vec pt
#define all(a) a.begin(),a.end()
/* Constants */
#define  ll long long
const ld eps = 1e-10;
const int inf = 2e18;
const ll mod = 1e9 + 7;
const int bit = 12;


const int C = 1e6, N = 2e6 + 1;

struct dsu {
    vc <int> p;
    int comp;
    dsu (int n): comp(n) {
        p.resize(n);
        iota(all(p), 0);
    }
    int find (int u) {
        return u == p[u] ? u : p[u] = find(p[u]);
    }
    int unite (int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return 0;
        p[v] = u;
        return 1;
    }
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
int a[400][400];
int ans[N];

void go (vc <pii> &add, int d) {
    dsu t(n * m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = 0;
    for (auto &[crd, j] : add) {
        int x = crd / m, y = crd % m;
        a[x][y] = 1;
        int was = 1;
        for (int i = 0; i < 4; ++i) {
            int kx = x + dx[i], ky = y + dy[i];
            if (kx >= 0 && ky >= 0 && ky < m && kx < n && a[kx][ky] == 1) {
                was -= t.unite(crd, kx * m + ky);
            }
        }
        ans[j] += d * was;
    }
}

vc <pii> add[N], del[N];

void solve () {
    int q;
    cin >> n >> m >> q;
    int ret = 1;
    for (int i = 0; i < q; ++i) {
        int x, y, c;
        cin >> x >> y >> c; --x; --y;
        if (a[x][y] != c) {
            ret = c + 1;
            add[c].pb({x * m + y, i});
            del[a[x][y]].pb({x * m + y, i});
            a[x][y] = c;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            del[a[i][j]].pb({i * m + j, q});
        }
    }
    for (int i = 0; i < ret; ++i) {
        go(add[i], 1);
    }
    for (int i = 0; i < ret; ++i) {
        reverse(all(del[i]));
        go(del[i], -1);
    }
    int comp = 1;
    for (int i = 0; i < q; ++i) {
        comp += ans[i];
        cout << comp << '\n';
    }
}

//dsadas
/* Starting and precalcing */
signed main() {
    fast;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}