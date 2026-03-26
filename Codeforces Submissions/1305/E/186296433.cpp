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
const int maxM = 250000001;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;cin>>n>>m;
	int tot = 0;
	REP(i, n) {
		int x = i/2;
		tot += x;
	}
	if (tot < m) {
		cout<<-1<<"\n";return 0;
	}
	if (n <= 2) {
		REP(i, n) {
			cout<<i+1<<" ";
		}return 0;
	}
	bitset<maxM> covered;
	covered.reset();
	vi curarr = {1,2};
	while (m != 0) {
		int nxt = curarr.size();
		int grp = nxt/2;
		//debug(grp);
		if (grp <= m) {
			curarr.push_back(curarr.back() + 1);
			m -= grp;
		} else {
			int tode = 2*m;
			int curmx = curarr.back();
			int curlw = curmx - tode + 1;
			curarr.push_back(curmx + curlw);
			m = 0;
		}
	}
	debug(curarr);
	int curs = curarr.size();
	covered[0] = 1;
	REP(i, curs) {
		covered[curarr[i]] = 1;
		REPL(j, i+1, curs) {
			int x = curarr[i] + curarr[j];
			if (x < maxM) {
				covered[x] = 1;
			}
		}
	}
	int currentmex = -1;
	REP(i, maxM) {
		if (!covered[i]) {
			currentmex = i;break;
		}
	}
	assert(currentmex != -1);
	while ((int)curarr.size() != n) {
		//debug(currentmex);
		int y = currentmex;
		for (auto x: curarr) {
			covered[y+x] = 1;
		}
		covered[y] = 1;
		curarr.push_back(y);
		while (true) {
			currentmex++;
			if (!covered[currentmex])break;
		}
	}
	for (auto x: curarr) {
		cout<<x<<" ";
	}
	
}