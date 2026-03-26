/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(s) (int)s.size()
#define maxn 100005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], pre[maxn], suf[maxn];
int main() {
	n = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, n) pre[i] = pre[i - 1] | a[i];
	rd(i, n, 1) suf[i] = suf[i + 1] | a[i];
	int ans = -1, mx = 0;
	ru(i, 1, n) {
		int t = pre[n]  - (pre[i - 1] | suf[i + 1]);
		if(ans < t) {
			ans = t;
			mx = i;
		}
	}
	printf("%d ", a[mx]);
	ru(i, 1, n) if(mx != i) printf("%d ", a[i]);
	return 0;
}
