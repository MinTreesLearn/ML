#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#define int long long
using namespace std;

namespace IO {
    char ibuf[(1 << 20) + 1], *iS, *iT;
#if ONLINE_JUDGE
#define gh() (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin), (iS == iT ? EOF : *iS++) : *iS++)
#else
#define gh() getchar()
#endif
#define reg register
    inline long long read () {
        reg char ch = gh();
        reg long long x = 0;
        reg char t = 0;
        while (ch < '0' || ch > '9') t |= ch == '-', ch = gh();
        while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gh();
        return t ? ~(x - 1) : x;
    }
    inline void write(long long x) {
        if (x < 0) {
            x = ~(x - 1);
            putchar('-');
        }
        if (x > 9)
            write(x / 10);
        putchar(x % 10 + '0');
    }
}

using IO::read;
using IO::write;

const int maxn(2e5 + 500);
int n, a[maxn], p[maxn], b[maxn];

inline int max (const int &x, const int &y) { return x < y ? y : x; }

struct SGT {
    struct SGTNode {
        int v, mx, se, ct, len, tg, fl;
    } tr[maxn << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
    inline void pushup (int p) {
        tr[p].v = tr[ls].v + tr[rs].v, tr[p].len = tr[ls].len + tr[rs].len;
        if (tr[ls].mx == tr[rs].mx) {
            tr[p].mx = tr[ls].mx, tr[p].ct = tr[ls].ct + tr[rs].ct;
            tr[p].se = max(tr[ls].se, tr[rs].se);
        } else if (tr[ls].mx > tr[rs].mx) {
            tr[p].mx = tr[ls].mx, tr[p].ct = tr[ls].ct;
            tr[p].se = max(tr[ls].se, tr[rs].mx);
        } else {
            tr[p].mx = tr[rs].mx, tr[p].ct = tr[rs].ct;
            tr[p].se = max(tr[ls].mx, tr[rs].se);
        }
    }
    // inline void pushmin (int p, int v) {
    //     if (tr[p].mx <= v) return;
    //     tr[p].v += (v - tr[p].mx) * tr[p].ct;
    //     tr[p].mx = tr[p].tg = v;
    // }
    inline void pushmin (int p, int v) {
        tr[p].v += tr[p].ct * v;
        tr[p].mx += v;
        tr[p].tg += v;
    }
    inline void pushadd (int p, int v) {
        tr[p].v += v * tr[p].len;
        tr[p].mx += v, tr[p].se += v;
        tr[p].fl += v;
    }
    inline void pushdown (int p) {
        if (tr[p].fl) {
            pushadd(ls, tr[p].fl);
            pushadd(rs, tr[p].fl);
            tr[p].fl = 0;
        }
        if (tr[p].tg) {
            int tp = max(tr[ls].mx, tr[rs].mx);
            if (tr[ls].mx == tp) pushmin(ls, tr[p].tg);
            if (tr[rs].mx == tp) pushmin(rs, tr[p].tg);
            tr[p].tg = 0;
        }
    }
    inline void build (int l, int r, int p) {
        tr[p].tg = tr[p].fl = tr[p].len = tr[p].ct = tr[p].v = 0, tr[p].mx = tr[p].se = -1;
        if (l == r) return;
        const int mid = (l + r) >> 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        pushup(p);
    }
    inline void updadd (int s, int t, int l, int r, int p, int v) {
        if (s > t) return;
        if (s <= l && r <= t) {
            pushadd(p, v);
            return;
        }
        pushdown(p);
        const int mid = (l + r) >> 1;
        if (s <= mid) updadd(s, t, l, mid, ls, v);
        if (mid < t) updadd(s, t, mid + 1, r, rs, v);
        pushup(p);
    }
    inline void updmin (int s, int t, int l, int r, int p, int v) {
        if (s > t) return;
        if (tr[p].mx <= v) return;
        if (s <= l && r <= t && tr[p].se <= v) {
            pushmin(p, v - tr[p].mx);
            return;
        }
        pushdown(p);
        const int mid = (l + r) >> 1;
        if (s <= mid) updmin(s, t, l, mid, ls, v);
        if (mid < t) updmin(s, t, mid + 1, r, rs, v);
        pushup(p);
    }
    inline void assign (int s, int l, int r, int p, int v) {
        if (l == r) {
            tr[p].mx = tr[p].v = v;
            tr[p].ct = tr[p].len = 1;
            return;
        }
        pushdown(p);
        const int mid = (l + r) >> 1;
        if (s <= mid) assign(s, l, mid, ls, v);
        else assign(s, mid + 1, r, rs, v);
        pushup(p);
    }
    inline int qry (int s, int t, int l, int r, int p) {
        if (s <= l && r <= t) return tr[p].len;
        pushdown(p);
        const int mid = (l + r) >> 1;
        int res = 0;
        if (s <= mid) res += qry(s, t, l, mid, ls);
        if (mid < t) res += qry(s, t, mid + 1, r, rs);
        return res;
    }
} T;

signed main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), p[a[i]] = i;
    for (int o = 0; o < 2; ++o) {
        T.build(1, n, 1);
        for (int i = 1; i <= n; i++) {
            T.assign(p[i], 1, n, 1, i + 1);
            T.updadd(p[i] + 1, n, 1, n, 1, 1);
            int t = T.qry(1, p[i], 1, n, 1);
            T.updmin(1, p[i] - 1, 1, n, 1, t);
            b[i] += T.tr[1].v;
        }
        for (int i = 1; i <= n; i++) p[i] = n - p[i] + 1;
    }
    for (int i = 1; i <= n; i++) write(b[i] - i * (i + 2)), puts("");
}
// I love WHQ!
	 			   	 	 			 		   			 	  		