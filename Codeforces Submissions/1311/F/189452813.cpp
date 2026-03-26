#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

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
	
	ordered_set s;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = s.order_of_key(make_pair(p[i].second + 1, -1));
		ans += cnt * 1ll * p[i].first;
		s.insert(make_pair(p[i].second, i));
	}
	s.clear();
	for (int i = n - 1; i >= 0; --i) {
		int cnt = int(s.size()) - s.order_of_key(make_pair(p[i].second - 1, n));
		ans -= cnt * 1ll * p[i].first;
		s.insert(make_pair(p[i].second, i));
	}
	
	cout << ans << endl;
	
	return 0;
}