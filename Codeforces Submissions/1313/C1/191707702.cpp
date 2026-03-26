#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;

	vector<ll> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<ll> res(n + 1);
	int idx;
	ll ans = -1;
	for (int j = 1; j <= n; j++) {
		ll ans1 = a[j];
		ll pre = a[j];
		for (int i = j - 1; i >= 1; --i) {
			pre = min(pre, a[i]);
			ans1 += pre;
		}
		pre = a[j];
		for (int i = j + 1; i <= n; i++) {
			pre = min(pre, a[i]);
			ans1 += pre;
		}
		if (ans < ans1) {
			ans = ans1;
			idx = j;
		}
	}
	ll pre = a[idx];
	for (int i = idx - 1; i >= 1; --i) {
		res[i] = min(pre, a[i]);
		pre = min(pre, a[i]);
	}
	res[idx] = a[idx];
	pre = a[idx];
	for (int i = idx + 1; i <= n; i++) {
		res[i] = min(pre, a[i]);
		pre = min(pre, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
}
	  				 		 		 	  	 					 					