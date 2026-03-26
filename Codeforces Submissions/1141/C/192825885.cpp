#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define out(x) cout << #x << '=' << x << endl;
#define lowbit(x) (x & -x);


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> a(n + 1);
    	for (int i = 2; i <= n; i++) {
    		cin >> a[i];
		}
		auto build = [&](int start) -> vector<int> {
			vector<int> ans(n + 1);
			for (int i = 1; i <= n; i++) {
				start += a[i];
				ans[i] = start;
			}
			return ans;
		};
		vector<int> b(build(1));
		set<int> vis;
		int ch = 1;
		for (int i = 1; i <= n; i++) {
			if (vis.count(b[i])) {
				cout << -1 << endl;
				ch = 0;
				break;
			}
			vis.insert(b[i]);
		}
		if (ch) {
			int mi = 1 - *min_element(b.begin() + 1, b.end());
			b = build(1 + mi);
			vector<int> bb(b);
			sort(bb.begin() + 1, bb.end());
			for (int i = 1; i <= n; i++) {
				//out(bb[i]);
				if (bb[i] != i) {
					ch = 0;
					cout << -1 << endl;
					break;
				}
			}
			if (ch) {
				for (int i = 1; i <= n; i++) {
					cout << b[i] << ' ';
				}
				cout << endl;
			}
		}
	}
}