// LUOGU_RID: 97931742
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

const int MAXN = 1e5 + 5;

int n, m, k;
int vis[MAXN << 1];
int f[1000];

int tot;
struct Seg {
    int x, id;
    Seg() {}
    Seg(const int& X, const int& I) {
        x = X, id = I;
    }
    bool operator< (const Seg& A) const {
        return x == A.x ? id < A.id : x < A.x;
    }
} seg[MAXN << 1];

int main() {

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        seg[++tot] = Seg(l, i);
        seg[++tot] = Seg(r + 1, -i);
    }
    std::sort(seg + 1, seg + tot + 1);
    memset(f, 0xcf, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= tot; ++i) {
        int len = 0, p;
        if (i < tot) len = seg[i + 1].x - seg[i].x;
        if (seg[i].id > 0) {
            for (int k = 0; k < 8; ++k) {
                if (!vis[k]) {
                    vis[p = k] = seg[i].id; break;
                }
            }
            for (int k = (1 << 8) - 1; k >= 0; --k) {
                if (k >> p & 1) f[k] = f[k ^ 1 << p] + len * __builtin_parity(k);
                else f[k] = f[k] + len * __builtin_parity(k);
            }
        } else {
            for (int k = 0; k < 8; ++k) {
                if (vis[k] == -seg[i].id) {
                    vis[p = k] = 0; break;
                }
            }
            for (int k = 0; k < 1 << 8; ++k) {
                if (k >> p & 1) f[k] = 0xcfcfcfcf;
                else f[k] = max(f[k], f[k ^ 1 << p]) + len * __builtin_parity(k);
            }
        }
    }
    printf("%d\n", f[0]);

    return 0;
}