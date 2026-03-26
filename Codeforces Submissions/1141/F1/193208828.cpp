// LUOGU_RID: 101967699
#include <bits/stdc++.h>

using i64 = long long;

int main() {	
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> s(n + 1);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}

	std::map<int, std::vector<std::pair<int, int>>> rag;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			rag[s[j] - s[i - 1]].emplace_back(j, i);
		}
	}

	std::vector<std::pair<int, int>> ans;
	for (auto [x, v] : rag) {
		std::sort(v.begin(), v.end());
		int l = 0, r = 0;
		std::vector<std::pair<int, int>> res;
		for (auto p : v) {
			if (res.empty() || p.second > res.back().first) {
				res.emplace_back(p);
			}
		}
		if (res.size() > ans.size()) ans = res;
	}

	std::cout << ans.size() << "\n";
	for (auto [r, l] : ans) {
		std::cout << l << " " << r << "\n";
	}
	


	return 0;
}	