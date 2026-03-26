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
#define maxn 1000005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n; ll a[maxn]; int sta[maxn], top;
int chk(int x, int y, int z) {
	return (ll)(a[z] - a[y]) * (z - x) <= (ll)(a[z] - a[x]) * (z - y);
}
int main() {
	n = read();
	ru(i, 1, n) a[i] = read() + a[i - 1];
	ru(i, 1, n) {
		while(top > 0 && chk(sta[top - 1], sta[top], i)) top--;
		sta[++top] = i;
	} 
//	ru(i, 1, top) printf("%d ", sta[i]); printf("\n");
	ru(i, 1, top) {
		ru(j, sta[i - 1] + 1, sta[i]) {
			printf("%.10f\n", (double)(a[sta[i]] - a[sta[i - 1]]) / (sta[i] - sta[i - 1]));
		}
	}
	return 0;
}
