#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<int> A(N); for (auto &a : A) cin >> a;
	sort(A.rbegin(), A.rend());
	map<int, int> cnt;
	vector<int> nums;
	int res = 1;
	for (auto a : A) {
		a %= M;
		if (cnt[a]) res = 0;
		else {
			nums.push_back(a);
			cnt[a]++;
		}
	}
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i+1; j < nums.size(); ++j) {
			res *= (nums[i] - nums[j]); res %= M;
		}
	}
	if (res < 0) res += M;
	cout << res << endl;
	return 0;
}