#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

namespace rn = ranges;
namespace vw = rn::views;

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
    #define debug if constexpr (false)
#endif // LOCAL

template<typename T, typename merge_t>
struct sparse_table {
    std::vector<std::vector<T>> sparse;
    const merge_t merge;

    sparse_table(const merge_t &merge) : merge(merge) {}

    sparse_table(const std::vector<T> &a, const merge_t &merge) : merge(merge) {
        if (a.empty())
            return;

        const int n = int(a.size()), lg = std::__lg(n);
        sparse.reserve(lg + 1);
        sparse.push_back(a);

        for (int level = 1; level <= lg; level++) {
            sparse.push_back(std::vector<T>(n - (1 << level) + 1));
            for (int i = 0; i < int(sparse[level].size()); i++)
                sparse[level][i] = merge(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
        }
    }

    sparse_table& operator=(const sparse_table<T, merge_t> &another) {
        sparse = another.sparse;
        return *this;
    }

    T query(int l, int r) const {
        assert(l < r);
        const int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

template<typename T = int>
struct lca_tree {
    int n;
    std::vector<std::vector<std::pair<int, T>>> g;
    std::vector<int> tin, tout;
    std::vector<std::pair<int, int>> order;
    std::vector<T> depth;

    inline static auto merge_min = [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> std::pair<int, int> {
        return a < b ? a : b;
    };
    using sparse_table_t = sparse_table<std::pair<int, int>, decltype(merge_min)>;
    sparse_table_t sparse;

    lca_tree(int n = 0) : n(n), g(n), sparse(merge_min) {}

    lca_tree(const std::vector<std::vector<std::pair<int, T>>> &graph) :
        n(graph.size()), g(graph), sparse(merge_min)
    {}

    lca_tree(const std::vector<std::vector<int>> &graph) : n(graph.size()), g(n), sparse(merge_min) {
        for (int v = 0; v < int(graph.size()); v++) {
            g[v].reserve(graph[v].size());
            for (int u : graph[v])
                g[v].emplace_back(u, 1);
        }
    }

    lca_tree(int n, const std::vector<std::pair<int, int>> &edges) : n(n), g(n), sparse(merge_min) {
        for (const auto &[v, u] : edges)
            add(v, u);
    }

    void add(int v, int u, T w = 1) {
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }

    int size() const {
        return n;
    }

    void build(int root = 0) {
        tin.resize(n);
        tout.resize(n);
        order.reserve(n - 1);
        depth.resize(n);
        int timer = 0;

        std::function<void(int, int, int)> dfs = [&](int v, int p, int dep) {
            tin[v] = timer++;
            for (auto &[u, w] : g[v]) {
                if (u == p)
                    continue;

                depth[u] = depth[v] + w;
                order.emplace_back(dep, v);
                dfs(u, v, dep + 1);
            }
            tout[v] = timer;
        };
        dfs(root, -1, 0);

        sparse = sparse_table_t(order, merge_min);
    }

    int lca(int v, int u) const {
        if (v == u)
            return v;
        
        auto [l, r] = std::minmax(tin[v], tin[u]);
        return sparse.query(l, r).second;
    }

    T dist(int v, int u) const {
        return depth[v] - 2 * depth[lca(v, u)] + depth[u];
    }

    bool is_ancestor(int v, int u) const {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    lca_tree<int> lca(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        lca.add(v, u);
    }
    lca.build(0);

    vector<pair<int, int>> dist(n);
    vector<vector<int>> g(n);
    auto add_edge = [&](int v, int u) {
        dprint("add edge", v, u);
        g[v].push_back(u);
        g[u].push_back(v);
    };

    int q;
    cin >> q;
    while (q--) {
        dprint();
        dprint("solving");

        int k, m;
        cin >> k >> m;
        static vector<int> vers;
        vers.clear();
        vector<pair<int, int>> a(k);
        for (auto &[v, s] : a) {
            cin >> v >> s, v--;
            vers.push_back(v);
        }

        vector<int> queries(m);
        for (auto &v : queries) {
            cin >> v, v--;
            vers.push_back(v);
        }

        rn::sort(vers, less{}, [&](int v) { return lca.tin[v]; });
        int prev_size = len(vers);
        for (int i = 0; i < prev_size - 1; i++) {
            vers.push_back(lca.lca(vers[i], vers[i + 1]));
        }

        rn::sort(vers);
        vers.resize(rn::unique(vers).begin() - vers.begin());
        rn::sort(vers, less{}, [&](int v) { return lca.tin[v]; });

        for (auto v : vers) {
            g[v].clear();
            dist[v] = {1e9, -1};
        }

        static vector<int> st;
        st.clear();
        for (auto v : vers) {
            while (!st.empty() && !lca.is_ancestor(st.back(), v)) {
                st.pop_back();
            }
            if (!st.empty()) add_edge(st.back(), v);
            st.push_back(v);
        }

        static priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>> pq;
        for (int i = 0; i < k; i++) {
            int v = a[i].first;
            dist[v] = {0, i};
            pq.emplace(dist[v], v);
        }

        while (!pq.empty()) {
            auto [cur_dist, v] = pq.top();
            pq.pop();
            if (cur_dist != dist[v]) continue;

            for (auto u : g[v]) {
                int d = lca.dist(a[cur_dist.second].first, u);
                pair<int, int> to_update{(d + a[cur_dist.second].second - 1) / a[cur_dist.second].second,
                                        cur_dist.second};
                dbg(cur_dist, v, u, to_update);
                if (dist[u] > to_update) {
                    dist[u] = to_update;
                    pq.emplace(dist[u], u);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            cout << dist[queries[i]].second + 1 << " \n"[i == m - 1];
        }
    }
}
