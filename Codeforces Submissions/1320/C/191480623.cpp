#include <bits/stdc++.h>
using namespace std;

struct segtree {
    long long mx[4000005], tg[4000005];
    segtree(int n) {
        for(int i = 1; i <= 4 * n; i++) {
            mx[i] = tg[i] = 0;
        }
    }
    void add_tag(int v, int z) {
        mx[v] += z;
        tg[v] += z;
    }
    void push_down(int v) {
        if(tg[v] != 0) {
            add_tag(v << 1, tg[v]);
            add_tag(v << 1 | 1, tg[v]);
            tg[v] = 0;
        }
    }
    void push_up(int v) {
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }
    void modify(int x, int y, int z, int v, int l, int r) {
        if(y < l || r < x) return;
        if(x <= l && r <= y) {
            add_tag(v, z);
            return;
        }
        push_down(v);
        int mid = (l + r) >> 1;
        modify(x, y, z, v << 1, l, mid);
        modify(x, y, z, v << 1 | 1, mid + 1, r);
        push_up(v);
    }
    long long query(int x, int y, int v, int l, int r) {
        if(y < l || r < x) return INT_MIN;
        if(x <= l && r <= y) {
            return mx[v];
        }
        push_down(v);
        int mid = (l + r) >> 1;
        return max(query(x, y, v << 1, l, mid), query(x, y, v << 1 | 1, mid + 1, r));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p; cin >> n >> m >> p;
    segtree tree = segtree(m);
    vector<pair<int, int>> a, b;
    for(int i = 0; i < n; i++) {
        int at, ca; cin >> at >> ca;
        a.push_back({at, ca});
    }
    for(int i = 0; i < m; i++) {
        int bt, cb; cin >> bt >> cb;
        b.push_back({bt, cb});
    }
    vector<tuple<int, int, int>> mon;
    for(int i = 0; i < p; i++) {
        int x, y, z; cin >> x >> y >> z;
        mon.push_back({x, y, z});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(mon.begin(), mon.end());
    for(int i = 0; i < m; i++) {
        tree.modify(i + 1, i + 1, -b[i].second, 1, 1, m);
    }
    int ptr = 0;
    long long ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        vector<pair<int, int>> new_mon;
        while(ptr < p && get<0>(mon[ptr]) < a[i].first) {
            new_mon.push_back({get<1>(mon[ptr]), get<2>(mon[ptr])});
            ptr++;
        }
        sort(new_mon.begin(), new_mon.end());
        int j = 0;
        for(auto [min_b, cost] : new_mon) {
            j = upper_bound(b.begin(), b.end(), make_pair(min_b, (int) 1e9)) - b.begin();
            if(j + 1 <= m) tree.modify(j + 1, m, cost, 1, 1, m);
        }
        ans = max(ans, tree.query(1, m, 1, 1, m) - a[i].second);
    }
    cout << ans << '\n';
}