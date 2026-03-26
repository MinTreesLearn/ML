#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize ("unroll-loops,Ofast,O3")
#pragma GCC target("avx,avx2,fma")

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(x) (x).begin(),(x).end()
#define int long long
#define rs(p) (p<<1|1)
#define ls(p) (p<<1)
#define pb push_back
#define endl '\n'
#define sz size()
#define F first
#define S second
#define SlimShady ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const long double eps = 1e-10;
const int MIN = LLONG_MIN;
const int M = 2e9 + 100;
const int N = 1e5 + 100;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n + 2];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i < n; ++i) {
		while(k >= i and a[i] != 0) {
			if(k >= i) {		
				k -= i;
				a[i]--;
				a[0]++;
			}
		}
	}
	cout << a[0] << endl;
}
signed main ()
{
	SlimShady
    int test = 1;
    cin >> test;
    while(test--) {
	    solve();
	}
}