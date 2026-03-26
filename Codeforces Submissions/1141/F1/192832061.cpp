#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define out(x) cout << #x << '=' << x << endl;
#define lowbit(x) (x & -x);

struct fenwick {
	map<int, pair<int, pii>> mp;
	int n;
	fenwick() : n(100000 * 50 + 1) {
	}
	
	void update(int x, int v, pii rng) {
		while (x <= n) {
			pair<int, pii> &pir = mp[x];
			if (pir.first < v) {
				pir.first = v;
				pir.second = rng;
			}
			x += lowbit(x);
		}
	}
	
	pair<int, pii> query(int x) {
		pair<int, pii> ans = {0, {0, 0}};
		while (x > 0) {
			if (mp.count(x)) {
				pair<int, pii> cnt = mp[x];
				if (cnt.first > ans.first) {
					ans = cnt;
				}
			}
			x -= lowbit(x);
		}
		return ans;
	}
};


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> a(n + 1);
    	for (int i = 1; i <= n; i++) {
    		cin >> a[i];
		}
		map<int, fenwick> mp;
		vector<vector<pii>> back(n + 1, vector<pii>(n + 1));
		int maxv = 0;
		int maxi = 0;
		int maxj = 0;
		for (int i = 1; i <= n; i++) {
			ll sum = 0;
			for (int j = i; j > 0; j--) {
				sum += a[j];
				pair<int, pii> ans = mp[sum].query(j - 1);
				back[i][j] = ans.second;
				ans.first++;
				mp[sum].update(i, ans.first, {j, i});
				if (ans.first > maxv) {
					maxv = ans.first;
					maxi = i;
					maxj = j;
				}
			}
		}
		vector<pii> ans;
		
		while (maxi > 0) {
			ans.push_back({maxj, maxi});
			pii bck = back[maxi][maxj];
			maxi = bck.second;
			maxj = bck.first;
		}
		cout << maxv << endl;
		for (pii rng : ans) {
			cout << rng.first << ' ' << rng.second << endl;
		}
	}
}
