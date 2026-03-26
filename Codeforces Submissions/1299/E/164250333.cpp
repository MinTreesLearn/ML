#include <bits/stdc++.h>
using namespace std;
const int N = 805;
#define ha putchar(' ')
#define he putchar('\n')
inline int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x;
}
inline void write(int x) {
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + 48);
}
int n, p[N], id[N], rd[N];
int ask(vector<int> v) {
	putchar('?'), ha, write(v.size());
	for (int x : v) ha, write(x);
	he;
	fflush(stdout);
	return read();
}
int qry(int x) {
	vector<int> v;
	for (int i = 1; i <= n; i++)
		if (i != x && !p[i]) v.push_back(i);
	return ask(v);
}
void get(int x, int a, int y, int b) {
	for (int i = 1; i <= n; i++) {
		if (!p[i] && !id[x] && rd[i] == a) {
			if (qry(i)) id[x] = i;
		} else if (!p[i] && !id[y] && rd[i] == b) {
			if (qry(i)) id[y] = i;
		}
	}
	p[id[x]] = x, p[id[y]] = y;
}
signed main() {
	n = read();
	get(1, 0, n, 0);
	for (int t = 2, l = 2, r = n - 1; l <= r; t <<= 1) {
		for (int i = 1; i <= n; i++) if (!p[i]) {
			vector<int> v;
			for (int j = 1; j <= t; j++)
				if (j % t != rd[i]) v.push_back(id[j]);
			v.push_back(i);
			if (ask(v)) rd[i] += t >> 1;
		}
		while (l <= 2 * t && l <= r)
			get(l, l % t, r, r % t), l++, r--;
	}
	if (p[1] > n / 2) for (int i = 1; i <= n; i++)
		p[i] = n - p[i] + 1;
	putchar('!');
	for (int i = 1; i <= n; i++) ha, write(p[i]);
	he;
	fflush(stdout);
	return 0;
}