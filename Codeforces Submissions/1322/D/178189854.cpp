#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 8845946851
#define fi first
#define se second
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int N = 4001;
int n, l[N], s[N], c[N], m;
int f[N][N], t[N];
// f(i, j) last chosen item = i, and state = j, the reason is an item most advances log steps, j = 2^{log_2 n} = n level.
// but we can not achieve succinct transformation.
// so, f(i, j) last chosen val = i, state = j. but we need to for every item, O(n^3) sad.
// what we've found? log steps, and no others?
// look back our first dp. f(i, j) = max_{k < i, a_k < a_i, S} f(k, S) + c(a_i) - s_i
// attention that if j != 0, the useful a_k's sorts is less than log V.That's mean we just need to make max to useful S.
// if j == 0, that can be deal easily. It seems to could be finished in O(n^2\log n) times. Even O(n^2) times.
// we can change it ---- S is subset of S'. That is hard.
/* ---------------------------------------------------------------------------*/

int main() {
	n = read(); m = read(); m += n;
	for(int i = 1; i <= n; ++i) l[i] = read();
	for(int i = 1; i <= n; ++i) s[i] = read();
	for(int i = 1; i <= m; ++i) c[i] = read();
	reverse(l + 1, l + n + 1); 
	reverse(s + 1, s + n + 1);
	memset(f, -0x3f, sizeof f);
	for(int i = 0; i <= m; ++i) f[i][0] = 0;
	t[0] = n;
	for(int i = 1; i <= m; ++i) t[i] = t[i - 1] >> 1;
	for(int i = 1; i <= n; ++i) {
		int v = l[i];
		for(int j = n; j; --j) f[v][j] = max(f[v][j], f[v][j - 1] + c[v] - s[i]);
		for(int j = v; j <= m; ++j) {
			for(int k = 0; k <= t[j - v]; ++k) {
				f[j + 1][k / 2] = max(f[j + 1][k / 2], f[j][k] + (k >> 1) * c[j + 1]);
			}
		} 
	}
	cout << f[m][0] << '\n';
	return 0;
}