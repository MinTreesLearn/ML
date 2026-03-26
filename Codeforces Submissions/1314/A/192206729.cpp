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
	int n;cin>>n;
	vi arrA(n);
	vi arrB(n);
	REP(i, n) {
		cin>>arrA[i];
	}
	REP(i, n) {
		cin>>arrB[i];
	}
	vii arr(n);
	REP(i, n) {
		arr[i] = {arrA[i], arrB[i]};
	}
	SORT(arr);
	int curlw = 0;
	int curtot = 0;
	int tot_in_set = 0;
	priority_queue<int> pq;
	
	int curidx = 0;
	while (curidx < n) {
		if (curlw == arr[curidx].first) {
			tot_in_set += arr[curidx].second;
			pq.push(arr[curidx].second);
			curidx++;
			continue;
		} 
		if (!pq.empty()) {
			auto tt = pq.top();
			pq.pop();
			tot_in_set -= tt;
			curtot += tot_in_set;
			curlw++;
			continue;
		}
		assert(tot_in_set == 0);
		curlw = arr[curidx].first;
		tot_in_set = arr[curidx].second;
		pq.push(arr[curidx].second);
		curidx++;
	}
	while (!pq.empty()) {
		auto tt = pq.top();
		pq.pop();
		tot_in_set -= tt;
		curtot += tot_in_set;
	}
	cout<<curtot<<"\n";
}