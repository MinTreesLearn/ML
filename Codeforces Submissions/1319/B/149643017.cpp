#define _CRT_SECURE_NO_WARNINGS
#define debug(l) cerr<<" smotri huinyi : "<<#l<<' '<<l<<'\n';
#include "bits/stdc++.h"
using namespace std;
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef long double ld;
signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<ll>a(n);
	
	map<ll, ll> k;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		k[a[i] - i] += a[i];
	}
	ll ans = 0;
	for (auto& i : k) {
		ans = max(i.second, ans);
	}
	cout << ans << '\n';
	

}

