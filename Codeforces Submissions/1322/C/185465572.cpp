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

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vi p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}
const int MOD1 = 7909287493;
const int MOD2 = 4302840181;
void solve() {
	int n,m;cin>>n>>m;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}

	vi indeg(n,0);
	vi hsh1(n,1);
	vi hsh2(n,1);
	REP(i, m) {
		int u,v;cin>>u>>v;u--;v--;
		indeg[v]++;
		int pr = p[u];
		hsh1[v] = hsh1[v]*pr%MOD1;
		hsh2[v] = hsh2[v]*pr%MOD2;
	} 
	map<ii, vi> mpping;
	REP(i, n) {
		if (indeg[i] == 0) continue;
		mpping[make_pair(hsh1[i], hsh2[i])].push_back(i);
	}

	vi nos;
	for (auto [ppp, aarr]: mpping) {
		int cur = 0;
		for (auto idx: aarr) {

			cur += arr[idx];
		}

		nos.push_back(cur);
	}

	int gd = nos[0];
	for (auto x: nos) {
		gd = __gcd(x, gd);
	}
	cout<<gd<<"\n";

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	sieve(10000000);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}