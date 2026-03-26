#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		s.insert(x);
	}
	cout << s.size() << '\n';
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}