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
    	string l, r;
    	cin >> l >> r;
    	vector<vector<int>> lc(256), rc(256);
    	for (int i = 0; i < n; i++) {
    		lc[l[i]].push_back(i + 1);
    		rc[r[i]].push_back(i + 1);
		}
		vector<pii> ans;
		for (int i = 0; i < 256; i++) {
			for (int j : rc[i]) {
				if (i == '?') continue;
				if (!lc[i].empty()) {
					ans.push_back({lc[i].back(), j});
					lc[i].pop_back();
				} else if (!lc['?'].empty()) {
					ans.push_back({lc['?'].back(), j});
					lc['?'].pop_back();
				}
			}
		}
		int i = 0;
		for (int j : rc['?']) {
			while (i < 256 && lc[i].empty()) i++;
			if (i < 256) {
				ans.push_back({lc[i].back(), j});
				lc[i].pop_back();
			}
		}
		cout << ans.size() << endl;
		for (pii p : ans) {
			cout << p.first << ' ' << p.second << endl;
		}
		
	}
}

