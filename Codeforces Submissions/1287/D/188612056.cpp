#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<
        ll,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

void dfs(ll from, const vector<vector<ll>> &graph, ordered_set &have, const vector<ll> &cnt, vector<ll> &res) {
    auto it = have.find_by_order(cnt[from]);
    res[from] = *it;
    have.erase(it);
    for (const auto &to: graph[from]) {
        dfs(to, graph, have, cnt, res);
    }
}

ll dfs1(ll from, const vector<vector<ll>> &graph, const vector<ll> &cnt) {
    ll sz = 1;
    for (const auto &to: graph[from]) {
        sz += dfs1(to, graph, cnt);
    }

    if (sz <= cnt[from]) {
        cout << "NO\n";
        exit(0);
    }

    return sz;
}

void resolve() {
    ll n;
    cin >> n;
    vector<ll> cnt(n);
    vector<vector<ll>> graph(n);
    ll root = 0;
    for (ll v = 0; v < n; ++v) {
        ll p, c;
        cin >> p >> c;
        --p;
        cnt[v] = c;

        if (p != -1) {
            graph[p].push_back(v);
        } else {
            root = v;
        }
    }

    ordered_set have;
    for (ll i = 1; i <= n; ++i) {
        have.insert(i);
    }

    dfs1(root, graph, cnt);
    vector<ll> res(n);
    dfs(root, graph, have, cnt, res);
    cout << "YES\n";
    for (const auto &item: res) {
        cout << item << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    resolve();

    return 0;
}
