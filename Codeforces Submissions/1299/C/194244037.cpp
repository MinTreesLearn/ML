#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n;
	cin >> n;
	vector<int>f(n);
	for(auto &i : f) cin >> i;
	vector<pair<double , int>>a;

	for(int i = 0 ; i < n ; i++) {
		pair<double , long long> kur = make_pair(f[i] , 1);

		while(!a.empty()) {
			if((a.back().first + kur.first) / (a.back().second + kur.second) < a.back().first / a.back().second) {
				kur.first += a.back().first , kur.second += a.back().second;
				a.pop_back();
			} else {
				break;
			}
		}

		a.push_back(kur);
	}

	for(auto [sum , knt] : a) {
		for(int i = 0 ; i < knt ; i++) 
			cout << fixed << setprecision(10) << sum / knt << '\n';
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt = 1;
	// cin >> tt;
	while(tt--) {
		solve();
	}

    return 0;
} 
