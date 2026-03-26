#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a, b[200001] = {}, c, res = 0, now = 0;
	cin >> a;
	for (ll i = 0; i < a; i++)
		cin >> b[i];
	for (ll i = 0; i < a; i++) {
		cin >> c;
		b[i] -= c;
	}
	sort(b, b + a);
	for (ll i = a - 1; i >= 0; i--) {
		if (b[i] <= 0)
			break;
		while (b[i] + b[now] <= 0)
			now++;
		res += (i - now);
	}
	cout << res << endl;
	return 0;
}