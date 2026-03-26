#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, i, j;
vector<pair<int, string>> ans;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	cin >> n >> m >> k;
	if (k > 4 * n * m - 2 * n - 2 * m) {
		cout << "NO";
		return 0;
	}
	ans.push_back({m - 1, "R"});
	ans.push_back({n - 1, "D"});
	ans.push_back({m - 1, "L"});
	ans.push_back({n - 1, "U"});
	for (i = 0; i < n - 2; i++) {
		ans.push_back({1, "D"});
		ans.push_back({m - 1, "R"});
		ans.push_back({m - 1, "L"});
	}
	ans.push_back({1, "D"});
	for (i = 0; i < m - 2; i++) {
		ans.push_back({1, "R"});
		ans.push_back({n - 1, "U"});
		ans.push_back({n - 1, "D"});
	}
	ans.push_back({1, "R"});
	ans.push_back({n - 1, "U"});
	ans.push_back({m - 1, "L"});
	for (i = 0; i < ans.size(); i++) if (!ans[i].first) ans.erase(ans.begin() + i);
	for (i = 0; i < ans.size(); i++) {
		if (k - ans[i].first <= 0) {
			ans[i].first = k;
			cout << "YES\n" << i + 1;
			for (j = 0; j <= i; j++) cout << "\n" << ans[j].first << " " << ans[j].second;
			return 0;
		}
		k -= ans[i].first;
	}
	cout << "YES\n" << ans.size();
	for (j = 0; j < ans.size(); j++) cout << "\n" << ans[j].first << " " << ans[j].second;
}