#include <bits/stdc++.h>

using namespace std;

long long get(vector<long long> &f, int pos) {
	long long res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

void upd(vector<long long> &f, int pos, int val) {
	for (; pos < int(f.size()); pos |= pos + 1) {
		f[pos] += val;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &pnt : p) cin >> pnt.first;
	for (auto &pnt : p) cin >> pnt.second;
	sort(p.begin(), p.end());
	
	vector<int> vs;
	for (auto &pnt : p) vs.push_back(pnt.second);
	sort(vs.begin(), vs.end());
	vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
	
	long long ans = 0;
	vector<long long> cnt(vs.size()), xs(vs.size());
	for (auto &pnt : p) {
		int pos = lower_bound(vs.begin(), vs.end(), pnt.second) - vs.begin();
		ans += get(cnt, pos) * 1ll * pnt.first - get(xs, pos);
		upd(cnt, pos, 1);
		upd(xs, pos, pnt.first);
	}
	
	cout << ans << endl;
	
	return 0;
}