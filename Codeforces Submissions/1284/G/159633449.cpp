/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

typedef std::pair<int, int> PII;
#define fi first
#define se second

const int MAXN = 20, IINF = 0x3f3f3f3f;
const int MOVE[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int n, m, deg[MAXN * MAXN + 5];
char maz[MAXN + 5][MAXN + 5], str[MAXN * 2 + 5][MAXN * 2 + 5];

inline bool inside(const int i, const int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

inline int id(const int i, const int j) {
    return (i - 1) * m + j;
}

struct DSU {
    int fa[MAXN * MAXN + 5], siz[MAXN * MAXN + 5];
    inline void init() { rep (i, 1, n * m) siz[fa[i] = i] = 1; }
    inline int find(const int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    inline bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return false;
        if (siz[x] < siz[y]) x ^= y ^= x ^= y;
        return siz[fa[y] = x] += siz[y], true;
    }
};

namespace MI { // Matroid Intersection.

// M1: deg>=2; M2: no circle.

std::vector<PII> U;
std::vector<int> ans, dis, L, R, T;
std::queue<int> que;
DSU dsu;

inline void initInd() {
    dsu.init();
    rep (i, 1, n) rep (j, 1, m) deg[id(i, j)] = (i + j) & 1 ? -IINF : 0;
    deg[1] = -IINF;
    rep (i, 0, int(U.size()) - 1) if (ans[i]) {
        dsu.unite(U[i].fi, U[i].se), ++deg[U[i].fi], ++deg[U[i].se];
    }
}

inline void build() {
    initInd();
    L.clear(), R.clear();
    T.clear(), T.resize(U.size());
    dis.clear(), dis.resize(U.size(), IINF);
    rep (i, 0, int(U.size()) - 1) {
        if (ans[i]) L.push_back(i);
        else {
            R.push_back(i);
            if (deg[U[i].fi] < 2 && deg[U[i].se] < 2) T[i] = true;
            if (dsu.find(U[i].fi) != dsu.find(U[i].se)) {
                que.push(i), dis[i] = 0;
            }
        }
    }
}

inline std::vector<int> augment() {
    int fin = -1;
    std::vector<int> pre(U.size(), -1);
    while (!que.empty()) {
        int u = que.front(); que.pop();
        if (T[u]) { fin = u; break; }
        if (ans[u]) {
            dsu.init();
            for (int x: L) if (x != u) dsu.unite(U[x].fi, U[x].se);
            for (int v: R) {
                if (dis[v] == IINF && dsu.find(U[v].fi) != dsu.find(U[v].se)) {
                    dis[v] = dis[u] + 1, pre[v] = u, que.push(v);
                }
            }
        } else {
            for (int v: L) if (dis[v] == IINF) {
                ++deg[U[u].fi], ++deg[U[u].se];
                --deg[U[v].fi], --deg[U[v].se];
                if (deg[U[u].fi] <= 2 && deg[U[u].se] <= 2
                  && deg[U[v].fi] <= 2 && deg[U[v].se] <= 2) {
                    dis[v] = dis[u] + 1, pre[v] = u, que.push(v);
                }
                --deg[U[u].fi], --deg[U[u].se];
                ++deg[U[v].fi], ++deg[U[v].se];
            }
        }
    }
    if (!~fin) return {};
    while (!que.empty()) que.pop();
    std::vector<int> ret;
    ret.push_back(fin);
    while (~pre[fin]) ret.push_back(fin = pre[fin]);
    return ret;
}

inline void solve() {
    ans.clear(), ans.resize(U.size());
    while (true) {
        build();
        auto&& res(augment());
        if (res.empty()) break;
        for (int id: res) ans[id] ^= 1;
    }
}

} // namespace MI.

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        rep (i, 1, n) scanf("%s", maz[i] + 1);

        MI::U.clear();
        rep (i, 1, n) rep (j, 1, m) {
            if (~(i + j) & 1 && id(i, j) != 1 && maz[i][j] == 'O') {
                rep (k, 0, 3) {
                    int x = i + MOVE[k][0], y = j + MOVE[k][1];
                    if (inside(x, y) && maz[x][y] == 'O') {
                        MI::U.emplace_back(id(i, j), id(x, y));
                    }
                }
            }
        }

        MI::solve();
        MI::initInd();
        rep (i, 1, n) rep (j, 1, m) {
            if (~(i + j) & 1 && id(i, j) != 1
              && maz[i][j] == 'O' && deg[id(i, j)] != 2) {
                puts("NO"); goto FIN;
            }
        }
        rep (i, 1, 2 * n - 1) {
            rep (j, 1, 2 * m - 1) {
                str[i][j] = i & 1 && j & 1 ? maz[i + 1 >> 1][j + 1 >> 1] : ' ';
            }
            str[i][2 * m] = '\0';
        }

        
        if (maz[1][2] == 'O') {
            MI::U.emplace_back(id(1, 1), id(1, 2)), MI::ans.push_back(0);
        }
        if (maz[2][1] == 'O') {
            MI::U.emplace_back(id(1, 1), id(2, 1)), MI::ans.push_back(0);
        }
        rep (i, 0, int(MI::U.size()) - 1) {
            if (MI::dsu.find(MI::U[i].fi) != MI::dsu.find(MI::U[i].se)) {
                MI::dsu.unite(MI::U[i].fi, MI::U[i].se);
                MI::ans[i] = true;
            }
        }
        rep (i, 1, n) rep (j, 1, m) {
            if (maz[i][j] == 'O' && MI::dsu.find(id(i, j))
              != MI::dsu.find(id(1, 1))) {
                puts("NO"); goto FIN;
            }
        }

        rep (i, 0, int(MI::U.size()) - 1) if (MI::ans[i]) {
            int b = (MI::U[i].fi - 1) % m + 1, a = (MI::U[i].fi - b) / m + 1;
            int d = (MI::U[i].se - 1) % m + 1, c = (MI::U[i].se - d) / m + 1;
            str[a + c - 1][b + d - 1] = 'O';
        }
        puts("YES");
        rep (i, 1, 2 * n - 1) puts(str[i] + 1);
        FIN: ;
    }
    return 0;
}
