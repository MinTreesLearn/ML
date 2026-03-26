#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define IOS ios::sync_with_stdio(0)
#define For(i,a,b) for (int i=(a),_b=(b);i<=_b;i++)
#define FOr For
#define Iter(i,a,b) for (int i=(a),_b=(b);i<_b;i++)
#define Downto(i,a,b) for (int i=(a),_b=(b);i>=_b;i--)
#define set0(a) memset(a,0,sizeof(a))
#define set0n(a,n) memset(a,0,sizeof((a)[0])*(n+1))
#define pb push_back
#define mkp make_pair
#define all(a) (a).begin(),(a).end()
template <class T1, class T2>
inline void getmin(T1& x, const T2& y) {if (y < x) x = y;}
template <class T1, class T2>
inline void getmax(T1& x, const T2& y) {if (x < y) x = y;}
//char NY[2][10]={"NO\n","YES\n"};//capital?

#ifdef DEBUG
	#define SHOW(x) (cerr<<#x"="<<(x)<<endl,(x))
	#define MSG(s) (cerr<<"MESSAGE: "<<(s)<<endl,0)
#else
	#define SHOW(x) (x)
	#define MSG(s) 0
#endif

const int N = 303, NN = N * N, Q = 2e6 + 10;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, q;
int first[Q], last[Q];
int dt[Q];
struct Query {
	int x, y, c;
} a[Q];

vi cover[Q];
int cc[N][N];//current color
int fa[NN];
int find(int x) {return fa[x] == x ? x : (fa[x] = find(fa[x]));}
inline void merge(int x, int y) {fa[find(y)] = find(x);}
#define pt(x,y) ((x)*m+(y))
inline bool in(int x, int y) {return 1 <= x && x <= n && 1 <= y && y <= m;}
inline int add(int x, int y, int c) {
	if (!x && !y) { return 0; }
	int cnt = 0, x2, y2;
	cc[x][y] = c;
	For(d, 0, 3) if (in(x2 = x + dx[d], y2 = y + dy[d]) && cc[x2][y2] == c && find(pt(x, y)) != find(pt(x2, y2))) { cnt++, merge(pt(x, y), pt(x2, y2)); }
	return 1 - cnt;
}

signed main() {
	IOS;
	cin >> n >> m >> q;
	For(i, 1, q) {
		int x, y, c;
		cin >> x >> y >> c;
		if (cc[x][y] == c) {x = y = 0;}
		else { cover[cc[x][y]].pb(i); }
		a[i] = (Query) {x, y, c};
		last[cc[x][y] = c] = i;
		if (c != a[i - 1].c) { first[c] = i; }
	}

	dt[0] = 1, last[0] = -1;
	For(c, 0, a[q].c) {
		if (!last[c]) { continue; }
		if (c) {
			iota(fa, fa + 1 + (n + 1)*m, 0);
			For(i, 1, n) set0n(cc[i], m);
			For(i, first[c], last[c]) {
				dt[i] += add(a[i].x, a[i].y, c);
			}
		}
		iota(fa, fa + 1 + (n + 1)*m, 0);
		reverse(all(cover[c]));
		for (auto i : cover[c]) {
			cc[a[i].x][a[i].y] = -1;
		}
		if (c) { For(i, first[c], last[c]) if (cc[a[i].x][a[i].y] != -1) add(a[i].x, a[i].y, c); } //only merging
		else { For(x, 1, n) For(y, 1, m) if (cc[x][y] != -1) add(x, y, 0); } //beware braces!!!
		for (auto i : cover[c]) {
			dt[i] -= add(a[i].x, a[i].y, c);
		}
	}
	For(i, 1, q) dt[i] += dt[i - 1], cout << dt[i] << '\n';

	return cout << flush, 0;
}