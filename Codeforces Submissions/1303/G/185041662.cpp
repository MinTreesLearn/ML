#include <bits/stdc++.h>

using i64 = std::int64_t;
using namespace std;

struct dp_hull {
    // dp_hull enables you to do the following two operations in amortized O(log
    // n) time:
    // 1. Insert a pair (a_i, b_i) into the structure
    // 2. For any value of x, query the maximum value of a_i * x + b_i
    // All values a_i, b_i, and x can be positive or negative.
    struct point {
        i64 x, y;
        point() : x(0), y(0) {}
        point(i64 _x, i64 _y) : x(_x), y(_y) {}
    };
    struct segment {
        point p;
        mutable point next_p;
        segment(point _p = {0, 0}, point _next_p = {0, 0})
            : p(_p), next_p(_next_p) {}
        bool operator<(const segment &other) const {
            if (p.y == std::numeric_limits<i64>::max() / 2)
                return p.x * (other.next_p.x - other.p.x) <=
                       other.p.y - other.next_p.y;
            return make_pair(p.x, p.y) < make_pair(other.p.x, other.p.y);
        }
    };
    set<segment> segments;
    int size() const { return segments.size(); }
    set<segment>::iterator prev(set<segment>::iterator it) const {
        return it == segments.begin() ? it : --it;
    }
    set<segment>::iterator next(set<segment>::iterator it) const {
        return it == segments.end() ? it : ++it;
    }
    static i64 floor_div(i64 a, i64 b) {
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }
    static bool bad_middle(const point &a, const point &b, const point &c) {
        return floor_div(a.y - b.y, b.x - a.x) >=
               floor_div(b.y - c.y, c.x - b.x);
    }
    bool bad(set<segment>::iterator it) const {
        return it != segments.begin() && next(it) != segments.end() &&
               bad_middle(prev(it)->p, it->p, next(it)->p);
    }
    void insert(const point &p) {
        set<segment>::iterator next_it = segments.lower_bound(segment(p));
        if (next_it != segments.end() && p.x == next_it->p.x) return;
        if (next_it != segments.begin()) {
            set<segment>::iterator prev_it = prev(next_it);
            if (p.x == prev_it->p.x)
                segments.erase(prev_it);
            else if (next_it != segments.end() &&
                     bad_middle(prev_it->p, p, next_it->p))
                return;
        }
        set<segment>::iterator it = segments.insert(next_it, segment(p, p));
        while (bad(prev(it))) segments.erase(prev(it));
        while (bad(next(it))) segments.erase(next(it));
        if (it != segments.begin()) prev(it)->next_p = it->p;
        if (next(it) != segments.end()) it->next_p = next(it)->p;
    }

    void insert(i64 a, i64 b) { insert(point(a, b)); }
    // Queries the maximum value of ax + b.
    i64 query(i64 x) const {
        assert(size() > 0);
        set<segment>::iterator it = segments.upper_bound(
            segment(point(x, std::numeric_limits<i64>::max() / 2)));
        return it->p.x * x + it->p.y;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<i64> val(n);

    for (int i = 0; i < n; i++) cin >> val[i];

    vector<int> siz(n), vis(n), maxSiz(n);
    dp_hull hull;

    int subtSiz = n;
    int root = -1;

    i64 ans = 0;

    auto dfs1 = [&](auto self, int u, int fa) -> void {
        siz[u] = 1;
        maxSiz[u] = 0;

        for (auto v : adj[u]) {
            if (v == fa || vis[v]) continue;
            self(self, v, u);
            maxSiz[u] = max(maxSiz[u], siz[v]);
            siz[u] += siz[v];
        }

        maxSiz[u] = max(maxSiz[u], subtSiz - siz[u]);
        if (root == -1) root = u;
        if (maxSiz[u] < maxSiz[root]) root = u;
    };

    auto dfs2 = [&](auto self, int u) -> void {
        vis[u] = 1;
        hull.segments.clear();

        auto in = [&](auto self, int u, int fa, i64 sum, i64 psum,
                      int dep) -> void {
            dep += 1;
            sum += val[u];
            psum += 1LL * dep * val[u];
            int sumv = 0;

            for (auto v : adj[u]) {
                if (vis[v] || v == fa) continue;
                sumv++;
                self(self, v, u, sum, psum, dep);
            }
            if (sumv == 0) hull.insert(sum, psum);
        };
        auto out = [&](auto self, int u, int fa, i64 sum, i64 psum,
                       int dep) -> void {
            dep += 1;
            sum += val[u];
            psum += sum;
            int sumv = 0;

            for (auto v : adj[u]) {
                if (vis[v] || v == fa) continue;
                sumv++;
                self(self, v, u, sum, psum, dep);
            }

            if (hull.size() != 0 && sumv == 0)
                ans = max(ans, hull.query(dep) + psum);
            if (hull.size() == 0 && sumv == 0) {
                ans = max(ans, psum);
            }
        };

        for (auto v : adj[u]) {
            if (vis[v]) continue;
            out(out, v, u, val[u], val[u], 1);
            in(in, v, u, 0, 0, 0);
        }

        if (hull.size() != 0)
            ans = max(ans, hull.query(1) + val[u]);
        else
            ans = max(ans, val[u]);

        hull.segments.clear();

        for (auto it = adj[u].rbegin(); it != adj[u].rend(); it++) {
            auto v = *it;
            if (vis[v]) continue;
            out(out, v, u, val[u], val[u], 1);
            in(in, v, u, 0, 0, 0);
        }

        for (auto v : adj[u]) {
            if (vis[v]) continue;
            root = -1;
            subtSiz = siz[v];
            dfs1(dfs1, v, -1);
            self(self, root);
        }
    };

    dfs1(dfs1, 0, -1);
    dfs2(dfs2, root);

    cout << ans << endl;

    return 0;
}