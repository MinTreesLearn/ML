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
	vector<ll>a(n), b(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll j = 0; j < n; j++) {
		cin >> b[j];
	}
	ll cnt1 = 0, cnt2 = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] == 1 && b[i] == 0) {
			cnt1++;
		}
		else if (a[i] == 0 && b[i] == 1) {
			cnt2++;
		}
	}
	if (cnt1 == 0) {
		cout << "-1\n";
	}
	else {
		cout << (cnt2 + cnt1) / cnt1 << "\n";
	}

}

