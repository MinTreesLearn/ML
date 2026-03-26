// LUOGU_RID: 100021307
#include<iostream>
#include<cstdio>
using namespace std;
namespace fastio {
inline char get_char() {
	static char buf[1000001], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
	char ch;
	int x = 0, ff = 1;
	do {
		ch = get_char();
	} while ((ch < '0' || '9' < ch) && ch != '-');
	if (ch == '-')ff = -1, ch = get_char();
	while ('0' <= ch && ch <= '9') {
		x = 10 * x + ch - '0';
		ch = get_char();
	}
	return x * ff;
}
inline void read(int &x) {
	x = 0;
	char ch;
	int ff = 1;
	do {
		ch = get_char();
	} while ((ch < '0' || '9' < ch) && ch != '-');
	if (ch == '-')ff = -1, ch = get_char();
	while ('0' <= ch && ch <= '9') {
		x = 10 * x + ch - '0';
		ch = get_char();
	}
	x *= ff;
}
inline write(int x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
}
using namespace fastio;
namespace lyx {
const int N = 2e5 + 5;
int n;
int p[N], a[N];
struct tree {
	long long min, max, tag;
} t[N << 2];
void update(int p) {
	t[p].min = min(t[p << 1].min, t[p << 1 | 1].min);
	t[p].max = max(t[p << 1].max, t[p << 1 | 1].max);
}
void pushdown(int p) {
	if (!t[p].tag) return;
	t[p << 1].min += t[p].tag;
	t[p << 1].max += t[p].tag;
	t[p << 1].tag += t[p].tag;
	t[p << 1 | 1].min += t[p].tag;
	t[p << 1 | 1].max += t[p].tag;
	t[p << 1 | 1].tag += t[p].tag;
	t[p].tag = 0;
}
void change(int p, int l, int r, int x, int y, int k) {
	if (x <= l && r <= y) {
		t[p].tag += k, t[p].min += k, t[p].max += k;
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if (x <= mid) change(p << 1, l, mid, x, y, k);
	if (y > mid) change(p << 1 | 1, mid + 1, r, x, y, k);
	update(p);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		change(1, 0, n, p[i], n, a[i]);
	}
	long long ans = 9e18;
	for (int i = 1; i < n; ++i) {
		change(1, 0, n, p[i], n, -a[i]);
		change(1, 0, n, 0, p[i] - 1, a[i]);
		ans = min(ans, t[1].min);
	}
	cout << ans << '\n';
	return 0;
}
}
int main() {
	return lyx::main();
}