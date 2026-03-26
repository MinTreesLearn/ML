#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> intervals;
	vector<int> nums;
	for(int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		nums.push_back(l);
		nums.push_back(r);
		intervals.push_back({l, r});
	}
	sort(nums.begin(), nums.end());
	nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
	int sz = (int) nums.size();
	vector<vector<int>> add(sz), del(sz);
	for(int i = 0; i < n; i++) {
		auto [l, r] = intervals[i];
		l = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
		r = lower_bound(nums.begin(), nums.end(), r) - nums.begin();
		add[l].push_back(i);
		del[r].push_back(i);
	}
	set<int> curr;
	vector<int> change(n);
	for(int i = 0; i < sz; i++) {
		if(!add[i].empty()) sort(add[i].begin(), add[i].end());
		if(!del[i].empty()) sort(del[i].begin(), del[i].end());
		if(curr.size() == 1) {
			change[*curr.begin()]++;
		}
		for(int j : add[i]) {
			curr.insert(j);
		}
		if(curr.size() > 1) {
			for(int j : add[i]) {
				change[j]++;
			}
			for(int j : del[i]) {
				change[j]++;
			}
		}
		if(curr.size() == 1) { // edge case
		    for(int j : del[i]) {
		        auto it = lower_bound(add[i].begin(), add[i].end(), j);
		        if(it != add[i].end() && *it == j) {
		            change[j]++;
		        }
		    }
		}
		for(int j : del[i]) {
			curr.erase(j);
		}
	}
	curr.clear();
	int initial = 0;
	for(int i = 0; i < sz; i++) {
		for(int j : add[i]) {
			curr.insert(j);
		}
		for(int j : del[i]) {
			if(curr.size() == 1) initial++;
			curr.erase(j);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, initial + change[i] - 2);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		solve();
	}
}