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

const int N = 2025;
const ll P = 998244353;

ll sub1(ll n) {
	// 求 \sum_1^n 分拆数
	ll f[N] {1}; // 划分数
	U (i, 1, n)
		U (j, i, n)
			(f[j] += f[j - i]) %= P;
	ll ans = 0;
	U (i, 1, n) (ans += f[i]) %= P;
	return ans;
}

ll sub2(ll n) {
	// 构造集合使得 i*t_i <= n，计数
    // 差分则不需要考虑 t_i 减的限制
    // 这样一个 c_i=t_i - t_{i-1}=1 对和的右移为 sum 1..i = i(i-1)/2
    ll f[N] {1};
    for (int i = 1; i * (i + 1) >> 1 <= n; ++i)
        for (int j = i * (i + 1) >> 1; j <= n; ++j)
            (f[j] += f[j - i * (i + 1) / 2]) %= P;
    ll ans = 0;
    U (i, 1, n) (ans += f[i]) %= P;
    return ans;
}

int n, k;
bool extend(int k, vector<int> v) {
    vector<int> g;
    for (int j = 1; j < k; ++j) {
        int sum = 0;
        sort(v.rbegin(), v.rend());
        U (i, 0, v.size() - 1) sum += (i + 1) * v[i];
        if (sum > n) return 0;
        // if (j + 3 < k && sum > 23) return 0;
        U (i, 0, v.size() - 1)
            U (j, 1, v[i])
                g.push_back(i + 1);
        v.swap(g);
        vector<int>().swap(g);
    }
    return 1;
}
vector<int> v;
ll ans = 0;
bool dfs(int lim) { // 随便嗯分
    if (!extend(k, v)) return 0;
    // clog << lim << ' ' << v.size() << endl;
    ++ans;
    // meow("x");
    // for (int x : v) meow("%d ", x);
    // meow("\n");
    for (int i = lim, flag; ; ++i) {
        v.push_back(i);
        flag = dfs(i);
        v.pop_back();
        if (!flag) return 1;
    }
    return 1;
}
ll sub3() {
    dfs(1);
    return ans - 1;
}

int main() {
    // Sol::main();
    // return 0;
	rd(n, k);
	if (k == 1) exit(printf("%lld", sub1(n)) & 0);
    if (k == 2) exit(printf("%lld", sub2(n)) & 0);
    printf("%lld", sub3());
}