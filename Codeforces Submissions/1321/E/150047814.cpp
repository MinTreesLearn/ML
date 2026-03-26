#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

using namespace std;

const int maxn = 1e6 + 5;
const int INF = 1e18;

struct st {
    vector<int> tree, md;
    int sz = 1;
    st(int n) {
        while (sz < n)
            sz *= 2;
        tree.resize(2 * sz + 1, -INF);
        md.resize(2 * sz + 1);
    }
    void upd(int i, int x, int v, int tl, int tr) {
        if (tl + 1 == tr) {
            tree[v] = max(tree[v], x);
            return;
        }
        int tm = (tl + tr) / 2;
        if (i < tm)
            upd(i, x, 2 * v + 1, tl, tm);
        else
            upd(i, x, 2 * v + 2, tm, tr);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
    void push(int v, int l, int r) {
        if (!md[v] || l + 1 == r)
            return;
        int p = md[v];
        tree[2 * v + 1] += p;
        tree[2 * v + 2] += p;
        md[2 * v + 1] += p;
        md[2 * v + 2] += p;
        md[v] = 0;
    }
    void add(int l, int r, int x, int v, int tl, int tr) {
        push(v, tl, tr);
        if (tl >= r || tr <= l)
            return;
        if (tl >= l && tr <= r) {
            tree[v] += x;
            md[v] = x;
            return;
        }
        int tm = tl + tr >> 1;
        add(l, r, x, 2 * v + 1, tl, tm);
        add(l, r, x, 2 * v + 2, tm, tr);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
};

signed main() {
    fastio;
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i].push_back(x);
        a[i].push_back(y);
    }
    sort(a.begin(), a.end());
    st t(maxn);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        b[i].push_back(x);
        b[i].push_back(y);
        t.upd(x, -y, 0, 0, t.sz);
    }
    vector<vector<int>> v(p);
    for (int i = 0; i < p; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        v[i].push_back(x);
        v[i].push_back(y);
        v[i].push_back(z);
    }
    sort(v.begin(), v.end());
    int res = -INF, idx = 0;
    for (int i = 0; i < n; ++i) {
        while (idx < p && a[i][0] > v[idx][0]) {
            t.add(v[idx][1] + 1, maxn, v[idx][2], 0, 0, t.sz);
            ++idx;
        }
        res = max(res, t.tree[0] - a[i][1]);
    }
    cout << res;
}