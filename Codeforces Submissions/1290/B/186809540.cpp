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
	string s;cin>>s;
	int n = s.size();
	int q;cin>>q;
	vvi prect(n);
	vi ini(26,0);
	ini[s[0]-'a']++;
	prect[0] = ini;
	REPL(i, 1, n) {
		prect[i] = prect[i-1];
		prect[i][s[i] - 'a']++;
	}
	REP(i, q) {
		int l; int r;cin>>l>>r;l--;r--;
		if (l == r) {
			cout<<"Yes\n";continue;
		}
		if (s[l] != s[r]) {
			cout<<"Yes\n";continue;
		}
		vi curp(26);
		REP(x, 26) {
			curp[x] = prect[r][x] - (l == 0 ? 0 : prect[l-1][x]);
		}
		int diff =0 ;
		REP(x, 26) {
			if (curp[x] == 0) continue;
			if (x != s[l] - 'a') {
				diff++;
			}
		}
		if (diff >=2) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}
}