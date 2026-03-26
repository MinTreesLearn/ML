#include <bits/stdc++.h>

using i64 = long long;

int main() {	
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr);

	int n, h, l, r;
	std::cin >> n >> h >> l >> r;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> dp(h + 1);
	std::vector<int> vis(h);
	vis[0] = true;

	for (int i = 0; i < n; i++) {
		std::vector<int> ndp(h), nvis(h);
		for (int j = 0; j < h; j++) {
			if (vis[j]) {
				int x = (j + a[i]) % h, y = (x - 1 + h) % h;
				ndp[x] = std::max(ndp[x], dp[j] + (x >= l && x <= r));
				ndp[y] = std::max(ndp[y], dp[j] + (y >= l && y <= r));
				nvis[x] = nvis[y] = true;
			}
		}
		std::swap(nvis, vis);
		std::swap(ndp, dp);
	}

	std::cout << *max_element(dp.begin(), dp.end()) << "\n";

	return 0;
}	
