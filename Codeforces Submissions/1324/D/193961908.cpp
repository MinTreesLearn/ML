// Problem: D. Pair of Topics
// Contest: Codeforces - Codeforces Round #627 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1324/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#define mod (int)(1e9+7)
using namespace std;
const int N=1e5+5;
void solve(){
	int n;
	cin >> n;
	vector<int> v(n), a(n);
	for ( int &e:v ) cin >> e;
	for ( int i=0; i<n; i++ ){
		int x;
		cin >> x;
		a[i]=v[i]-x;
	}
	sort(begin(a),end(a));
	int ans=0;
	for ( int i=0; i<a.size(); i++ ){
		if ( a[i]<=0 ) continue;
		int l=lower_bound(begin(a),end(a),-a[i]+1)-a.begin();
		ans+=i-l;
	}
	cout << ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=1; //cin >> t;
    while ( t-- ){
        solve(); cout << '\n';
    }
}
/*
*/