#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

struct Vec {
	ll x, y;
	Vec(ll x = 0, ll y = 0): x(x), y(y) {}
	Vec operator - (const Vec& o) const
	{ return Vec(x - o.x, y - o.y); }
	ll operator ^ (const Vec& o) const
	{ return x * o.y - y * o.x; }
	bool up() { return y > 0 or (y == 0 and x > 0); }
};

bool cmp(Vec a, Vec b) {
	if (a.up() != b.up())
		return a.up() > b.up();
	return (a ^ b) > 0;
}

ll C(int n, int k) {
	if (n < k) return 0;
	ll r = 1;
	for (int i = 1; i <= k; ++i) {
		r *= n + 1 - i;
		r /= i;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<Vec> pts(n);
	for (auto& [x, y]: pts)
		cin >> x >> y;

	ll ans = 0;

	vector<Vec> a;
	for (int i = 0; i < n; ++i) {
		a = pts;
		swap(a[i], a.back());
		a.pop_back();
		for (Vec& v: a)
			v = v - pts[i];
		sort(begin(a), end(a), cmp);

		for (int l = 0, r = 1; l < n-1; ++l) {
			while (r < l + n-1 and (a[l] ^ a[r - (r >= n-1 ? n-1 : 0)]) >= 0) ++r;
			ans += C(r - l - 1, 3);
		}
	}

	cout << 5 * C(n, 5) - ans << '\n';

	return 0;
}
