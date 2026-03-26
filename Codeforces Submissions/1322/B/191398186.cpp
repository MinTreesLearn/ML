// LUOGU_RID: 101016299
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	auto cal = [&](vector<int> &v, int b) {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			int l = lower_bound(v.begin() + i + 1, v.end(), (1 << b) - v[i]) - v.begin(), r = upper_bound(v.begin() + i + 1, v.end(), (1 << (b + 1)) - 1 - v[i]) - v.begin() - 1;
			cnt ^= (r - l + 1) % 2;
			//cout << i << ' ' << l << ' ' << r << '\n';
		}
		for(int i = 1; i <= n; i++) {
			int l = lower_bound(v.begin() + i + 1, v.end(), (1 << b) + (1 << (b + 1)) - v[i]) - v.begin(), r = upper_bound(v.begin() + i + 1, v.end(), (1 << (b + 2)) - 1 - v[i]) - v.begin() - 1;
			cnt ^= (r - l + 1) % 2;
			//cout << i << ' ' << l << ' ' << r << '\n';
		}
		if(cnt & 1)
			return 1 << b;
		else 
			return 0;
	};
	for(int i = 0; i < 28; i++) {
		vector<int> b(n + 1);
		for(int j = 1; j <= n; j++)
			b[j] = a[j] % (1 << (i + 1));
		sort(b.begin() + 1, b.end());
		ans += cal(b, i);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	
	while(t--) {
		solve();
	}
}