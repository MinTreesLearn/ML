// LUOGU_RID: 102109617
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

	std::vector<int> dp(h, -1);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		std::vector<int> ndp(h, -1);
		for (int j = 0; j < h; j++) {
			if (dp[j] != -1) {
				for (int x = a[i] - 1; x <= a[i]; x++) {
					int y = (j + x + h) % h;
					ndp[y] = std::max(ndp[y], dp[j] + (l <= y && y <= r));
				}
			}
		}
		std::swap(ndp, dp);
	}

	std::cout << *max_element(dp.begin(), dp.end()) << "\n";

	return 0;
}	
