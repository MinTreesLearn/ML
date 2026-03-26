#include <bits/stdc++.h>
using namespace std;

void solve() {

	string s , t;
	cin >> s >> t;

	int N = s.length();
	deque<char>a , b;

	for(auto i : t) b.push_back(i);
	bool Alive = true;

	while(Alive) {

		a.push_back(b.front());	
		b.pop_front();
		int n = a.size() , m = b.size();

		vector<vector<int>>dp(N + 1 , vector<int>(n + 1 , -1));
		dp[0][0] = 0;

		for(int i = 0 ; i <= N ; i++) {
			for(int j = 0 ; j <= n ; j++) {

				/*
				if(dp[i][j] == -1 && i < N && j == 0 && s[i] == a[j]) {
					dp[i + 1][j] = max(dp[i + 1][j] , 0);
				}
				*/

				int extra = 0;

				if(i < N && dp[i][j] >= 0 && dp[i][j] < m && b[dp[i][j]] == s[i]) extra = 1;
				if(i < N) dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j] + extra);

				if(j < n && i < N && s[i] == a[j]) 
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1] , dp[i][j]); 

				if(i < N) dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
			}
		}

		if(dp[N][n] == m) {
			cout << "YES\n";
			return;
		}

		if(b.empty()) Alive = false;
	}

	cout << "NO\n";

	return;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt = 1;
	cin >> tt;
	while(tt--) {
		solve();
	}

    return 0;
} 
