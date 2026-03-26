#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pt;

pt operator - (const pt& a, pt& b) {
	return pair((a.first - b.first), (a.second - b.second));
}

pt operator - (const pt& a) {
	return pair(-a.first, -a.second);
}

int main() {
	fast_io;

	int n;
	cin >> n;

	if (n % 2) {
		cout << "NO\n";
		return 0;
	}

	vector<pt> points(n);
	for (auto &[x, y] : points) cin >> x >> y;

	vector<pt> sides;
	for (int i = 0; i < n; i++) {
		sides.push_back(points[(i + 1) % n] - points[i]);
	}

	bool ok = true;
	for (int i = 0; i < n; i++)
		ok &= sides[i] == -sides[(i + n/2) % n];

	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}
