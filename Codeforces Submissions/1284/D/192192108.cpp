#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T> using pbds = tree<T, null_type,
	less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define endl '\n'
#define inf 2e18
#define vi vector<int>
#define pii pair<int, int>
#define sz(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }
int __gcd(int x, int y) { return y == 0 ? x : __gcd(y, x % y); }

void solve() {
	int n;
	cin >> n;
	vector<vi> a(n, vi(4));
	pbds<int> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		s.insert(a[i][0]);
		s.insert(a[i][1]);
		s.insert(a[i][2]);
		s.insert(a[i][3]);
	}
	for(int i = 0; i < n; i++) {
		a[i][0] = s.order_of_key(a[i][0]);
		a[i][1] = s.order_of_key(a[i][1]);
		a[i][2] = s.order_of_key(a[i][2]);
		a[i][3] = s.order_of_key(a[i][3]);
	}
	sort(all(a), [&](auto& x, auto& y) {
		if(x[0] == y[0]) return x[1] < y[1];
		return x[0] < y[0];
	});
	priority_queue<vi, vector<vi>, greater<vi>> q;
	multiset<int> mn, mx;
	for(int t = 0, i = 0; t <= 4 * n; t++) {
		while(i < n) {
			if(a[i][0] == t) {
				q.push({a[i][1], a[i][2], a[i][3]});
				mx.insert(a[i][2]);
				mn.insert(a[i][3]);
				i++;
			} else break;
		}
		while(!q.empty()) {
			vi p = q.top();
			if(p[0] < t) {
				q.pop();
				mx.erase(mx.find(p[1]));
				mn.erase(mn.find(p[2]));
			} else break;
		}
		if(sz(mn) == 0) continue;
		if(*mn.begin() < *mx.rbegin()) return void(cout << "NO");
	}
	for(int i = 0; i < n; i++) {
		swap(a[i][0], a[i][2]);
		swap(a[i][1], a[i][3]);
	}
	sort(all(a), [&](auto& x, auto& y) {
		if(x[0] == y[0]) return x[1] < y[1];
		return x[0] < y[0];
	});
	assert(q.empty());
	assert(mn.empty());
	assert(mx.empty());
	for(int t = 0, i = 0; t <= 4 * n; t++) {
		while(i < n) {
			if(a[i][0] == t) {
				q.push({a[i][1], a[i][2], a[i][3]});
				mx.insert(a[i][2]);
				mn.insert(a[i][3]);
				i++;
			} else break;
		}
		while(!q.empty()) {
			vi p = q.top();
			if(p[0] < t) {
				q.pop();
				mx.erase(mx.find(p[1]));
				mn.erase(mn.find(p[2]));
			} else break;
		}
		if(sz(mn) == 0) continue;
		if(*mn.begin() < *mx.rbegin()) return void(cout << "NO");
	}
	cout << "YES";
}

int32_t main() {
	int t = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cin >> t;
	while(t--) {
		solve();	
		cout << endl;
		cerr << endl;
	}
	return 0;
}