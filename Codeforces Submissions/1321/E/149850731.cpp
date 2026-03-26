#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <iomanip>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define file_in freopen("input.txt", "r", stdin);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define fi first
#define se second

template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &el : v) { in >> el; } return in; }
template<typename T> ostream& operator<<(ostream &out, const vector<T> &v) { for (auto &el : v) { out << el << " "; } return out; }
template<typename T1, typename T2> istream& operator>>(istream &in, pair<T1, T2> &v) { in >> v.fi >> v.se; return in; }
template<typename T1, typename T2> ostream& operator<<(ostream &out, const pair<T1, T2> &v) { out << v.fi << " " << v.se; return out; }

const ll inf = 1e18;

struct Node {
    ll ext = -inf, add = 0;
    Node() {}
};

struct segtree {
    vector<Node> t;
    segtree(vector<ll> &a) { t.resize(4 * sz(a)); build(0, 0, sz(a), a); }
    void push(int id) {
        t[id].ext += t[id].add;
        t[id * 2 + 1].add += t[id].add;
        t[id * 2 + 2].add += t[id].add;
        t[id].add = 0;
    }
    ll get(int id) {
        return t[id].ext + t[id].add;
    }
    void build(int id, int l, int r, vector<ll> &a) {
        if (l + 1 == r) { t[id].ext = a[l]; return; }
        build(id * 2 + 1, l, l + r >> 1, a);
        build(id * 2 + 2, l + r >> 1, r, a);
        t[id].ext = max(get(id * 2 + 1), get(id * 2 + 2));
    }
    void upd(int id, int l, int r, int lq, int rq, int x) {
        if (lq >= r || l >= rq) return;
        if (lq <= l && r <= rq) { t[id].add += x; return; }
        push(id);
        upd(id * 2 + 1, l, l + r >> 1, lq, rq, x);
        upd(id * 2 + 2, l + r >> 1, r, lq, rq, x);
        t[id].ext = max(get(id * 2 + 1), get(id * 2 + 2));
    }
    void write(int id, int l, int r) {
        if (l + 1 == r) {
            cout << get(id) << " ";
            return;
        }
        push(id);
        write(id * 2 + 1, l, l + r >> 1);
        write(id * 2 + 2, l + r >> 1, r);
    }
    void print() {
        write(0, 0, sz(t) / 4); cout << '\n';
    }
};

void upd(vector<pii> &a) {
    vector<pii> cur;
    for (auto el : a) {
        if (cur.empty() || el.fi != cur.back().fi) cur.push_back(el);
    }
    swap(a, cur);
}

int main() {
    fast
    // file_in

    int n, m, p;
    cin >> n >> m >> p;
    vector<pii> a(n), b(m);
    vector<vector<int>> mt(p, vector<int>(3));
    cin >> a >> b >> mt;
    sort(all(a)); sort(all(b)); sort(all(mt));
    upd(a); upd(b);
    const int k = 1e6 + 1;
    vector<ll> c(k, -inf);
    for (int i = 0; i < sz(b); ++i) {
        c[b[i].fi] = -b[i].se;
    }
    segtree sg(c);
    ll ans = -inf;
    for (int i = 0, j = 0; i < sz(a); ++i) {
        while (j < p && mt[j][0] < a[i].fi) { sg.upd(0, 0, k, mt[j][1] + 1, k, mt[j][2]); ++j; }
        ans = max(ans, sg.get(0) - a[i].se);
    }
    cout << ans << '\n';
    return 0;
}