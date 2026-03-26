#include <iostream>
#include <string>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

signed main() {
	fastio;
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	while (true) {
		char c = 'a' - 1, idx = -1;
		for (int i = 0; i < n; ++i) {
			if (i - 1 >= 0 && s[i - 1] == s[i] - 1 || i + 1 < n && s[i + 1] == s[i] - 1) {
				if (c < s[i]) {
					c = s[i];
					idx = i;
				}
			}
		}
		if (idx == -1)
			break;
		s.erase(s.begin() + idx);
		++ans;
	}
	cout << ans;
}