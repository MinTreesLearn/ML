#include <bits/stdc++.h>
#define ms(x, v) memset(x, v, sizeof(x))
#define il __attribute__((always_inline))
#define U(i,l,r) for(int i(l),END##i(r);i<=END##i;++i)
#define D(i,r,l) for(int i(r),END##i(l);i>=END##i;--i)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
template <typename T> using BS = basic_string<T>;

//const int SZ(1 << 23);
//unsigned char buf[SZ], *S, *Q;
//#define getchar() ((S==Q)&&(Q=buf+fread(S=buf,1,SZ,stdin)),S==Q?EOF:*S++)
template <typename T>
void rd(T& s) {
	int c = getchar();
	T f = 1; s = 0;
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { s = s * 10 + (c ^ 48); c = getchar(); }
	s *= f;
}
template <typename T, typename... Y>
void rd(T& x, Y&... y) { rd(x), rd(y...); }
template <typename T>
void pr(T s, bool f = 1) {
    if (s < 0) { printf("-"); s = -s; }
    if (!s) return void(f ? printf("0") : 0);
    pr(s / 10, 0);
    printf("%d", (signed)(s % 10));
}
#define meow(...) fprintf(stderr, __VA_ARGS__)

// 将区间离散化为 [)
// 枚举相等段长进行转移
const ll P = 998244353;
const int N = 505;
ll fac[N], ifac[N], inv[N];
ll qpow(ll x, ll t) { ll v = 1; while (t) { if (t & 1) (v *= x) %= P; (x *= x) %= P; t >>= 1; } return v; }
void genFac() {
	fac[0] = ifac[0] = inv[0] = 1;
	U (i, 1, N - 1) fac[i] = fac[i - 1] * i % P;
	ifac[N - 1] = qpow(fac[N - 1], P - 2);
	D (i, N - 2, 1) ifac[i] = ifac[i + 1] * (i + 1) % P;
	U (i, 1, N - 1) inv[i] = fac[i - 1] * ifac[i] % P;
}
ll C(ll n, ll m) {
    if (n < 0 || m < 0 || m > n) return 0;
    ll v = ifac[m];
    D (i, n, n - m + 1) (v *= i) %= P;
    return v;
}

#define A(n, m) (C(n, m) * fac[m] % P)
#define IA(n, m) (IC(n, m) * ifac[m] % P)
#define Inv(x) qpow(x, P - 2)
int n, m;
int v[N * 2];
int l[N], r[N];
ll prod[N];

// pair<ll, ll> approx(ll q, ll A) {
// 	ll x = q, y = P, a = 1, b = 0;
//     while (x > A) {
// 		swap(x, y); swap(a, b);
//         a -= x / y * b;
//         x %= y;
//     }
//     return {x, a};
// }
// void print(ll x, ll A = 80000) {
//     auto f = approx(x, A);
//     meow("%lld/%lld\n", f.first, f.second);
// }

int main() {
    genFac();
    rd(n);
    prod[0] = 1;
    U (i, 1, n) {
        rd(l[i], r[i]); ++r[i];
        v[i * 2 - 1] = l[i];
        v[i * 2] = r[i];
        prod[i] = prod[i - 1] * (r[i] - l[i]) % P;
    }
    sort(v + 1, v + 2 * n + 1);
    m = unique(v + 1, v + 2 * n + 1) - v - 1;
    // 离散化为 [l, r) 的区间
    U (i, 1, n) {
        l[i] = lower_bound(v + 1, v + m + 1, l[i]) - v;
        r[i] = lower_bound(v + 1, v + m + 1, r[i]) - v;
        // clog << l[i] << ' ' << r[i] << endl;
    }
    // 段数同理左闭右开
    static ll f[N * 2][N * 2];
    U (i, 1, m + 1) f[0][i] = 1;
    // clog << "m" << ' ' << m << endl;
    U (i, 1, n) {
        D (k, r[i] - 1, l[i]) { // 同区间，要求不增
            // 插板，共有 v[k+1]-v[k] 个球，截成 i-j+1 段
            D (j, i, 1) // 要求从 [j..i] 在同一区间
                if (k >= l[j] && k < r[j]) {
                    ll iv = Inv(prod[i] * Inv(prod[j - 1]) % P);
                    ll c = iv * C(v[k + 1] - v[k] + i - j, i - j + 1) % P * f[j - 1][k + 1] % P;
                    (f[i][k] += c) %= P;
                } else break;
            // meow("f[%d][%d]=%lld :: ", i, k, f[i][k]); print(f[i][k]);
        }
        D (k, m, 1)
            (f[i][k] += f[i][k + 1]) %= P;
    }
    ll ans = f[n][1];
    printf("%lld", ans);
    // print(ans);
}