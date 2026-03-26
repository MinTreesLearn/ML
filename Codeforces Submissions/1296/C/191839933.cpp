#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 mod = 1E9 + 7;
//
void solve() {
	i64 n;
	cin >> n;
	string s;
	cin >> s;
	map<i64, int> used;
	int l = 0, r = 2E9 + 10;
 	int x = 0, y = 0; 
	for (int i = 0; i < n; i ++) {
		i64 now = x * mod + y;
		if (used[now]) {
			if (i - used[now] < r - l) {
				r = i;
				l = used[now];
			}
		}
		if (s[i] == 'L') x --;
		else if (s[i] == 'R') x ++;
		else if (s[i] == 'U') y ++;
		else y --;
		used[now] = i + 1;
	}
	i64 now = x * mod + y;
	if (used[now]) {
		if (n - used[now] < r - l) {
			r = n;
			l = used[now];
		}
	}
	if (r - l > 100000000) cout << -1 << "\n";
	else cout << l << " " << r << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int _ = 1;
	cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}