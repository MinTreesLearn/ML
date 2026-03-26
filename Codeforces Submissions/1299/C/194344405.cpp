#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

typedef long long ll;

inline int read() {
	register int s = 0, f = 1; register char ch = getchar();
	while (!isdigit(ch)) f = (ch == '-' ? -1 : 1), ch = getchar();
	while (isdigit(ch)) s = (s * 10) + (ch & 15), ch = getchar();
	return s * f;
}

inline int min_(int a, int b) {
	return a < b ? a : b;
}

inline int max_(int a, int b) {
	return a > b ? a : b;
}

struct node {
	int l, r;
	long long sum;
	inline node(int L, int R, long long S) : l(L), r(R), sum(S) { }
	inline node() { }
	inline void merge(const node& c) {
		l = min_(l, c.l);
		r = max_(r, c.r);
		sum += c.sum;
	}
	inline bool operator > (const node &c) {
		return 1.0 * sum / (r - l + 1) > 1.0 * c.sum / (c.r - c.l + 1);
	}
	inline bool operator < (const node &c) {
		return 1.0 * sum / (r - l + 1) < 1.0 * c.sum / (c.r - c.l + 1);
	}
} stk[N];

int n, a[N], top;
double b[N];
long long sum[N];

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		node tmp = node(i, i, a[i]);
		while (top && stk[top] > tmp) tmp.merge(stk[top--]);
		stk[++top] = tmp;
	}
	for (int i = 1; i <= top; ++i)
		for (int j = stk[i].l; j <= stk[i].r; ++j)
			printf("%.9lf\n", 1.0 * (sum[stk[i].r] - sum[stk[i].l - 1]) / (stk[i].r - stk[i].l + 1));
	return 0;
}