#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k;
	
	int all = 4 * n * m - 2 * n - 2 * m;
	
	if (k > all) {
		cout << "NO\n";
		return 0;
	}
	
	n--;
	m--;
	
	// else there is always a way
	vector<pair<int, string>> ans;
		
	{ // first row
		if (m / 4) ans.push_back({m / 4, "RRRR"});
		if (m % 4) ans.push_back({1, string(m % 4, 'R')});
		if (m / 4) ans.push_back({m / 4, "LLLL"});
		if (m % 4) ans.push_back({1, string(m % 4, 'L')});
	}
	
	for (int i = 1; i <= n; i++) {
		ans.push_back({1, "D"});
		if (m / 4) ans.push_back({m / 4, "RRRR"});
		if (m % 4) ans.push_back({1, string(m % 4, 'R')});
		if (m) ans.push_back({m, "UDL"});	
	}
	
	if (n / 4) ans.push_back({n / 4, "UUUU"});
	ans.push_back({1, string(n % 4, 'U')});
	
	vector<pair<int, string>> res;
	for (auto i : ans) {
		int len = (int)i.second.size() * i.first;
		if (len >= k) {
			if (k / (int)i.second.size()) res.push_back({k / (int)i.second.size(), i.second});
			if (k % (int)i.second.size()) res.push_back({1, i.second.substr(0, k % (int)i.second.size())});
			break;
		} else {
			k -= len; 
			res.push_back(i);
		}
	}
	
	cout << "YES\n";
	cout << res.size() << '\n';
	for (auto i : res) {
		cout << i.first << ' ' << i.second << '\n';
	}
}
