#include <bits/stdc++.h>

#define ll long long

const ll  MM = 998244353, N = 1e5 + 10, MAX = 1e15;
using namespace std;

vector<ll>v[200], v1[200];

int solve() {
	int n; cin >> n;
	string s, t; cin >> s >> t;
	for (int i = 0; i < n; i++) {
		v[s[i]].emplace_back(i + 1);
		v1[t[i]].emplace_back(i + 1);
	}
	vector<pair<ll, ll>>res;
	for (char c = 'a'; c <= 'z'; c++) {
		while (v[c].size() && v1[c].size()) {
			res.emplace_back(v[c].back(), v1[c].back());
			v[c].pop_back();
			v1[c].pop_back();
		}
		while (v[c].size()) {
			v[0].emplace_back(v[c].back());
			v[c].pop_back();
		}
		while (v1[c].size()) {
			v1[0].emplace_back(v1[c].back());
			v1[c].pop_back();
		}
	}
	while (v['?'].size() && v1[0].size()) {
		res.emplace_back(v['?'].back(), v1[0].back());
		v['?'].pop_back();
		v1[0].pop_back();
	}
	while (v1['?'].size() && v[0].size()) {
		res.emplace_back(v[0].back(), v1['?'].back());
		v1['?'].pop_back();
		v[0].pop_back();
	}
	while (v['?'].size() && v1['?'].size()) {
		res.emplace_back(v['?'].back(), v1['?'].back());
		v['?'].pop_back();
		v1['?'].pop_back();
	}
	cout << res.size() << '\n';
	for (auto x : res) {
		cout << x.first << " " << x.second << '\n';
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	int t = 1;//cin >> t;
	int i = 1;
	while (t--) {
		//cout << "Case #" << i++ << ": ";
		solve();
	}
}
/*

*/