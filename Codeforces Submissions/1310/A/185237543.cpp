#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define fi first
#define se second
#define pb push_back
#define endl '\n'
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	rep(i, 0, n) {
		cin >> v[i].fi;
	}
	rep(i, 0, n) {
		cin >> v[i].se;
	}
	sort(v.begin(), v.end());
	int now = v[0].fi, j = 0, sum = v[0].se, ans = 0;
	multiset<int> cc;
	cc.insert(v[j].se);
	while (1) {
		while (j + 1 < n&&v[j + 1].fi == now) {
			j++;
			cc.insert(v[j].se);
			sum += v[j].se;
		}
		auto it = cc.end();
		it--;
		ans += sum - *it;
		sum -= *it;
		cc.erase(it);
		if (cc.size()) {
			now++;
		}
		else {
			if (j + 1 >= n) break;
			j++;
			now = v[j].fi;
			cc.insert(v[j].se);
			sum += v[j].se;
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
}

	  		  	   			 	  	 	      	