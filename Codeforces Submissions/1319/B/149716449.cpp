#include <iostream>
#include <map>
#include <vector>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vector<int> b, v;

map<int, int> q;

signed main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		b.push_back(x);
		v.push_back(x);
	}
	for (int i = 0; i < n; ++i)
		v[i] = v[i] - i - 1;
	for (int i = 0; i < n; ++i)
		q[v[i]] += b[i];
	int ans = 0;
	for (auto i : q)
		ans = max(ans, i.second);
	cout << ans;
}