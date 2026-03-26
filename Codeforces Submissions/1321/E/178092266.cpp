#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, V = 1e6;
int w[N << 2], lzy[N << 2];
inline void pushup(int u) { w[u] = max(w[u << 1], w[u << 1 | 1]); }
inline void maketag(int u, int v) { w[u] += v, lzy[u] += v; }
inline void pushdown(int u) { maketag(u << 1, lzy[u]), maketag(u << 1 | 1, lzy[u]), lzy[u] = 0; }
void update(int u, int L, int R, int l, int r, int v) {
    if (L >= l && R <= r) return maketag(u, v);
    if (L > r || R < l) return;
    int M = L + R >> 1;
    pushdown(u);
    update(u << 1, L, M, l, r, v), update(u << 1 | 1, M + 1, R, l, r, v);
    pushup(u);
}
int val[V + 10];
int n, m, p;
pair<int, int> a[N], b[N];
pair<pair<int, int>, int> mon[N];
int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].first, &a[i].second);
    for (int i = 1; i <= m; i++) scanf("%d %d", &b[i].first, &b[i].second);
    for (int i = 1; i <= p; i++) scanf("%d %d %d", &mon[i].first.first, &mon[i].first.second, &mon[i].second);
    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1), sort(mon + 1, mon + p + 1);
    // memset(val, -0x7f, sizeof(val));
    for (int i = 1; i <= V; i++) val[i] = -2000000000;
    for (int i = 1; i <= m; i++) val[b[i].first] = max(val[b[i].first], -b[i].second);
    for (int i = 1; i <= V; i++) update(1, 1, V, i, i, val[i]);
    int r = 1;
    int ans = -0x7f3f3f3f;
    for (int i = 1; i <= n; i++) {
        while (r <= p && mon[r].first.first < a[i].first) update(1, 1, V, mon[r].first.second + 1, V, mon[r].second), r++;
        ans = max(ans, w[1] - a[i].second);
    }
    cout << ans;
    return 0;
}