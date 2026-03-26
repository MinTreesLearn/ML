#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
int n, k;
deque<int> cur;
void reset() {
	cout << "R" << endl;
	while(!cur.empty()) cur.pop_back();
}
bool add(int x) {
	cur.push_back(x);
	if(cur.size() > k) cur.pop_front();
	cout << "? " << x << endl;
	char c;
	cin >> c;
	return c == 'N';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	vector<vector<int>> lol;
	int Bs = k>1?k/2:1;
	for(int i = 1; i <= n; i++) {
		if(lol.empty() || lol.back().size() == Bs) lol.push_back({});
		lol.back().push_back(i);
	}
	auto update = [&](int i) {
		vector<int> ni;
		for(auto x : lol[i]) if(add(x))
			ni.push_back(x);
		lol[i] = ni;
	};
	int m = lol.size();
	for(int i = 1; i <= m/2; i++) {
		int g = __gcd(m, i);
		for(int j = 0; j < g; j++) {
			vector<int> v { j };
			do {
				v.push_back((v.back() + i)%m);
			} while(v.back() != j);
			v.pop_back();
			for(auto id : v) {
				update(id);
			}
			reset();
			if(v.size() > 2) {
				update(v.back());
				update(v[0]);
				reset();
			}
		}
	}
	
	int ans = 0;
	for(auto i : lol) ans += i.size();
	cout << "! " << ans << endl;
	return 0;
} 