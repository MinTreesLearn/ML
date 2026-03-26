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
// assume n is odd....
map<int, vi> ask(int l, int r) {
	int ln = r - l+1;
	int totc = ln*(ln+1)/2;
	cout<<"? "<<l+1<<" "<<r+1<<endl;
	map<int,vi> mp;
	REP(i, totc) {
		string s;cin>>s;
		int l = s.size();
		if (mp.find(l) == mp.end()) {
			mp[l] = vi(26,0);
		}
		for (auto x: s) {
			mp[l][x - 'a']++;
		}
	}
	return mp;
}
vi mins(vi v1, vi v2) {
	vi res(26);
	REP(i, 26) {
		res[i] = v1[i] - v2[i];
	}return res;
}
vi unflatten(vi &arr) {
	vi cur;
	REP(i, 26) {
		REP(j, arr[i]) {
			cur.push_back(i);
		}
	}
	return cur;
}

vector<tuple<int,int,vi>> getedges(int n, bool mid = true) {
	vector<tuple<int,int,vi>> edges;
	map<int, vi> mp = ask(0, n-1);
	//debug(mp);
	vi tominus;
	if (mid) {
		int md = n/2;
		vi res(n,-1);
		vi curres = mins(mp[md+1], mp[md+2]);
		REP(i, 26) {
			if (curres[i] == 1) {
				res[md] = i;
				edges.push_back({md,md,{i}});
				break;
			}
		}
		tominus.push_back(res[md]);
	}
	int curln, curL, curR;
	if (mid) {
		curln = n/2+2;
		curL = n/2-1;
		curR = n/2+1;
	} else {
		curln = n/2+1;
		curL = n/2-1;
		curR = n/2;
	}
	while (curL != 0) {
		vi cres = mins(mp[curln], mp[curln+1]);
		//debug(cres);
		//debug(curln);
		for (auto x: tominus) {
			cres[x]--;
		}
		//debug(cres);
		vi cc = unflatten(cres);
		edges.push_back({curR, curL, cc});
		for (auto x: cc) {
			tominus.push_back(x);
		}
		curL--;
		curR++;
		curln++;
	}
	vi curr = mp[n];
	REP(i, 26) {
		curr[i] *= 2;
	}
	curr = mins(curr, mp[n-1]);
	edges.push_back({0, n-1, unflatten(curr)});
	return edges;
}

string trysolve(int n) {
	if (n == 1) {
		cout<<"? "<<1<<" "<<1<<endl;
		string s;cin>>s;
		return s;
	}
	vector<tuple<int,int,vi>> e1 = getedges(n);
	vector<tuple<int,int,vi>> e2 = getedges(n-1, false);
	vi res(n,-1);
	int st;
	vector<vector<pair<int,vi>>> adj(n);
	for (auto &[a,b, cc]: e1) {
		if (cc.size() == 1) {
			st = a;
			res[a] = cc[0];
		} else {
			adj[a].push_back({b, cc});
			adj[b].push_back({a, cc});
		}
	}
	for (auto &[a,b, cc]: e2) {
		adj[a].push_back({b, cc});
		adj[b].push_back({a, cc});
	}
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		auto u = q.front();q.pop();
		for (auto &[v,tt]: adj[u]) {
			if (res[v] != -1) continue;
			if (tt[0] == res[u]) {
				res[v] = tt[1];
			} else {
				res[v] = tt[0];
			}
			q.push(v);
		}
	}
	string s;
	for (auto x: res) {
		s += (char)('a' + x);
	}return s;
}
signed main()
{
	int n;cin>>n;
	string res;
	if (n%2 == 1) {
		res = trysolve(n);
	} else{
		res= trysolve(n-1);
		cout<<"? "<<n<<" "<<n<<endl;
		string s;cin>>s;
		res += s;
	}
	cout<<"! "<<res<<endl;
}