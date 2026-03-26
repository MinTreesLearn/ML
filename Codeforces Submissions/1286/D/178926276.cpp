// LUOGU_RID: 92552980
#include <bits/stdc++.h>
#define P 998244353ll
#define ll long long
using namespace std;
namespace QYB {
    void exgcd(ll a, ll b, ll &x, ll &y) {
        if (!b) return x = 1, y = 0, void();
        exgcd(b, a % b, y, x); y -= a / b * x;
    } ll inv(ll a) {
        ll x, y; exgcd(a, P, x, y); return (x % P + P) % P;
    } struct matrix {
        ll a[2][2];
        ll *operator[](int x) { return a[x]; }
        matrix(ll _0 = 0, ll _1 = 0, ll _2 = 0, ll _3 = 0) { a[0][0] = _0; a[0][1] = _1; a[1][0] = _2; a[1][1] = _3; }
        matrix operator*(matrix x) {
            return matrix((a[0][0] * x[0][0] + a[0][1] * x[1][0]) % P, (a[0][0] * x[0][1] + a[0][1] * x[1][1]) % P, (a[1][0] * x[0][0] + a[1][1] * x[1][0]) % P, (a[1][0] * x[0][1] + a[1][1] * x[1][1]) % P);
        }
    } s[500005];
    int n; ll ans, d[100005], v[100005], g[2][100005];
    void modify(int p, int l, int r, int x, int a, int b) {
        if (x < l || x > r) return;
        if (l == r) return s[p][a][b] = g[a][x], void();
        int mid = l + r >> 1;
        modify(p << 1, l, mid, x, a, b);
        modify(p << 1 | 1, mid + 1, r, x, a, b);
        s[p] = s[p << 1 | 1] * s[p << 1];
    } matrix query(int p, int l, int r, int L, int R) {
        if (r < L || R < l) return matrix(1, 0, 0, 1);
        if (L <= l && r <= R) return s[p];
        int mid = l + r >> 1;
        return query(p << 1 | 1, mid + 1, r, L, R) * query(p << 1, l, mid, L, R);
    } int main() {
        scanf("%d", &n);
        vector<pair<int, int> > f;
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld%lld", d + i, v + i, &g[1][i]);
            g[0][i] = (P + 1 - ((g[1][i] *= 828542813ll) %= P)) % P;
            i == 1 || v[i - 1] - v[i] >= 0? modify(1, 1, n, i, 0, 0): f.push_back({i, 0});
            i == 1 || v[i - 1] + v[i] <= 0? modify(1, 1, n, i, 0, 1): f.push_back({i, 1});
            i == 1 || v[i - 1] + v[i] >= 0? modify(1, 1, n, i, 1, 0): f.push_back({i, 2});
            i == 1 || v[i - 1] - v[i] <= 0? modify(1, 1, n, i, 1, 1): f.push_back({i, 3});
        } sort(f.begin(), f.end(), [](pair<int, int> x, pair<int, int> y) {
            auto [ix, sx] = x; auto [iy, sy] = y;
            ll vx = (sx & 1? 1: -1) * v[ix - 1] + (sx & 2? -1: 1) * v[ix];
            ll vy = (sy & 1? 1: -1) * v[iy - 1] + (sy & 2? -1: 1) * v[iy];
            return (d[ix] - d[ix - 1]) * vy > (d[iy] - d[iy - 1]) * vx;
        });
        for (auto [i, st]: f) {
            modify(1, 1, n, i, (st >> 1) & 1, (st >> 0) & 1);
            matrix res = query(1, 1, n, i + 1, n) * (st == 0? matrix(g[0][i], 0, 0, 0): (st == 1? matrix(0, g[0][i], 0, 0): (st == 2? matrix(0, 0, g[1][i], 0): matrix(0, 0, 0, g[1][i])))) * query(1, 1, n, 1, i - 1);
            (ans += (d[i] - d[i - 1]) * inv(((st & 1? 1: P - 1) * v[i - 1] % P + (st & 2? P - 1: 1) * v[i] % P) % P) % P * (res[0][0] + res[1][0]) % P) %= P;
        } return !printf("%lld\n", ans);
    }
} int main() {
    return QYB::main();
}