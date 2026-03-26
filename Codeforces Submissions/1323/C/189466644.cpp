// babyshadow

#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int a = 0;
	for (char val : s) if (val == '(') a++;

	if (a != n / 2 or n % 2) {
		cout << -1 ; return;
	}

	int ans = 0, chk = 0, lst = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') chk++;
		else chk--;

		if (chk < 0) ans++;
		else if (chk == 0 and lst < 0) {
			ans++;
		}
		lst = chk;
	}

	cout << ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}