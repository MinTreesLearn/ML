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

const int N = 1005;
int n, m; ll k; char s[N];

// n^2 个子串排序
// 求 LCP 后比较下一位
int lcp[N][N], ord[N][N];
void getLCP() {
	D (i, n, 1) D (j, n, 1)
		if (s[i] == s[j])
			lcp[i][j] = lcp[i + 1][j + 1] + 1;
}
pair<int, int> sub[N * N]; int sCnt;
bool cmp(pair<int, int> l, pair<int, int> r){
	int cp = lcp[l.first][r.first];
    if (cp >= l.second - l.first + 1) return l.second - l.first < r.second - r.first;
    if (cp >= r.second - r.first + 1) return 0;
    return s[l.first + cp] < s[r.first + cp];
}

bool check(int mid) { // 选定代表串大于等于第 mid 个，个数是否满足大于等于 k
	int term[N]{1}; __int128 f[N]{}; // term[i] = j that ord[i][j] >= mid
	const __int128 INF = (__int128(0x3f3f3f3f3f3f3f3f) << 64) | 0x3f3f3f3f3f3f3f3f;
	U (i, 0, n) {
		term[i] = n + 1;
		U (j, i + 1, n)
			if (ord[i + 1][j] >= mid)
				{ term[i] = j; break; }
	}
	
	f[0] = 1;
	U (p, 1, m) {
		__int128 g[N];
		U (i, 0, n) g[i] = f[i];
		ms(f, 0);
		U (i, 0, n) { f[term[i]] += g[i]; f[term[i]] = min(INF, f[term[i]]); }
		U (i, 1, n) { f[i] += f[i - 1]; f[i] = min(INF, f[i]); }
	}
	
	return f[n] >= k;
}

int main() {
	rd(n, m, k);
	scanf("%s", s + 1);
	getLCP();
	U (i, 1, n)
		U (j, i, n)
			sub[++sCnt] = {i, j};
	
	// int fk = 0;
	// U (i, 2, sCnt) U (j, 1, i - 1)
    //     if (!cmp(sub[i], sub[j]) && !cmp(sub[j], sub[i])) {
    //         ++fk;
    //         meow("(%d,%d), (%d,%d)\n", sub[i].first, sub[i].second, sub[j].first, sub[j].second);
    //     }
	// clog << fk << endl << endl;
	
	sort(sub + 1, sub + sCnt + 1, cmp);
    // U (i, 1, sCnt) {
    //     meow("[%d, %d]", sub[i].first, sub[i].second);
    //     U (j, sub[i].first, sub[i].second) meow("%c", s[j]);
    //     meow("\n");
    // }
	// sCnt = unique(sub + 1, sub + sCnt + 1, cmp) - sub - 1;
	U (i, 1, n) U (j, i, n)
		ord[i][j] = lower_bound(sub + 1, sub + 1 + sCnt, pair<int, int>{i, j}, cmp) - sub;
    // clog << sCnt << endl;
	
	int l = 0;
	D (k, 30, 0) if (l + (1 << k) <= sCnt) 
        if (check(l + (1 << k))) l += 1 << k;
    // clog << l << endl;
	auto pr = sub[l];
	s[pr.second + 1] = 0;
	puts(s + pr.first);
}