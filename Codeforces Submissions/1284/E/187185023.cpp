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
typedef tree<double,null_type,less<double>, rb_tree_tag, tree_order_statistics_node_update> ost;

struct point{
	int x;
	int y;
	bool operator<(point &other) {
		int nx = abs(x);
		int ny = x < 0 ? -y: y;
		int ox = abs(other.x);
		int oy = other.x < 0? -other.y : other.y;
		return ny*ox < nx*oy;
	}
};

vector<ii> sorting(vii &arr) {
	vector<point> neg_x;
	vector<point> pos_x;
	for (auto [x,y]: arr) {
		if (x < 0) {
			neg_x.push_back({x,y});
		} else {
			pos_x.push_back({x,y});
		}
	}
	SORT(neg_x);
	SORT(pos_x);
	//reverse(neg_x.begin(), neg_x.end());
	vii res;
	for (auto [x,y]: pos_x) {
		res.push_back({x,y});
	}
	for (auto [x,y]: neg_x) {
		res.push_back({x,y});
	}
	return res;
}
bool check_valid(ii p1, ii p2) {
	auto [x1,y1] = p1;
	auto [x2, y2] = p2;
	int dz = x1* y2 - x2*y1;
	if (dz < 0) {
		return true;
	}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	vii arr(n);
	REP(i, n) {
		int x,y;cin>>x>>y;
		arr[i] = {x,y};
	}
	auto get_pairing = [&](int ori, int other) {
		auto [x1,y1] = arr[ori];
		auto [x2,y2] = arr[other];
		int dx = x2-x1;
		int dy = y2-y1;
		return make_pair(dx,dy);
	};
	int totgood = 0;
	REP(ori, n) {
		int curbad = 0;
		vii vec;
		REP(i, n) {
			if (i != ori) {
				vec.push_back(get_pairing(ori, i));
			}
		}
		vec = sorting(vec);
		debug(vec);
		int curn = n-1;
		int curidx = 0;
		REP(i, n-1) {
			while (true) {
				if (curidx + 1== curn + i) break;
				ii p2 = vec[(curidx+1)%curn];
				ii p1 = vec[i];
				if (check_valid(p1,p2)) {
					break;
				}
				curidx++;
			}
			int bad_no = curidx - i;
			if (bad_no < 3) {
				continue;
			}
			curbad += (bad_no)*(bad_no-1)*(bad_no-2)/6; 
		}
		//assert(curbad%24==0);
		int curgood = ((n-1)*(n-2)*(n-3)*(n-4)/24 - curbad);
		debug(curgood);
		totgood += curgood;
	}
	cout<<totgood<<"\n";
}