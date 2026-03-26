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
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int x[1000005], y[1000005];
int main() {
	int n = read();
	ru(i, 1, n) {
		x[i] = read(), y[i] = read();
	}
	if(n & 1) {
		printf("NO\n");
		return 0;
	}
	ru(i, 1, n / 2) if(x[i] + x[i + n / 2] != x[1] + x[1 + n / 2]) {
		printf("NO\n");
		return 0;
	}
	ru(i, 1, n / 2) if(y[i] + y[i + n / 2] != y[1] + y[1 + n / 2]) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}
