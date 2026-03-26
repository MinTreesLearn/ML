#ifdef MY_LOCAL
#include "D://competitive_programming/debug/debug.h"
#define debug(x) cerr << "[" << #x<< "]:"<<x<<"\n"
#else
#define debug(x) 
#endif
#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e18
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef double ld;
typedef tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x0,y0,ax,ay,bx,by;cin>>x0>>y0>>ax>>ay>>bx>>by;
	const int MX = 2e16+1;
	vii pts = {{x0,y0}};
	while (true) {
		auto [x,y] = pts.back();
		int nx = x*ax + bx;
		int ny = y*ay + by;
		if (nx >= MX || ny >= MX) break;
		pts.push_back({nx,ny});
	}
	int xs,ys,t;cin>>xs>>ys>>t;
	int bst = 0;
	int n = pts.size();

	auto ditbetween = [&](int x, int y) {
		auto [x1,y1] = pts[x];
			auto [x2,y2] = pts[y];
			return abs(x1-x2) + abs(y1-y2);
	};
	auto totdist = [&](int x, int y) {
		int tot = 0;
		REPL(i, x, y) {
			auto [x1,y1] = pts[i];
			auto [x2,y2] = pts[i+1];
			tot += abs(x1-x2) + abs(y1-y2);
		}
		return tot;
	};
	REP(i, n) {
		auto [xx,yy] = pts[i];
		int inid = abs(xx - xs) + abs(yy - ys);
		if (inid <= t) {
			bst = max(bst, 1LL);
		}
		for (int j = i - 1; j >= 0; j--) {
			REPL(k, i+1, n) {
				int d1 = totdist(j, i);
				int d2 = totdist(i, k);
				if (inid + d1 <= t) {
					bst = max(1LL + abs(j-i), bst);
				}
				if (inid + d2 <= t) {
					bst = max(1 + abs(k-i), bst);
				}
				int excess = d1 + d2 + min(d1,d2);

				if (excess + inid <= t) {
					bst = max(abs(k-j) + 1, bst);
				}
			}
		}
	}
	auto [xx,yy] = pts[0];
	auto [xx1,yy1] = pts[n-1];
	int inid = abs(xx - xs) + abs(yy - ys);
	int inid2 = abs(xx1-xs) + abs(yy1 - ys);
	REP(i, n) {
		if (inid + ditbetween(0,i) <= t) {
			bst = max(bst, i+1);
		}
		if (inid2 + ditbetween(n-1, i) <= t) {
			bst = max(bst, n-i);
		}
	}

	cout<<bst;
}