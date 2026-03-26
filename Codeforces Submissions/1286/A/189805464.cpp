#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#define setIO(...)
#endif

using ll = long long;
#define pb push_back
#define all(x) (x).begin(), (x).end()
int MOD = (int)1e9 + 7;
ll INF  = 1e18 + 7;

int dp[101][2][101][101];
int res = MOD;
int dfs(vector<int>&a, int idx, int n, bool isEven, int odd, int even, int diff){
	if ((even > (n / 2)) || (odd > ((n+1) / 2))) return MOD;
	if (idx == n){
		res = min(diff, res);
		return diff;
	}
	if (dp[idx][isEven][odd][even] != MOD && dp[idx][isEven][odd][even] <= diff) return dp[idx][isEven][odd][even];
	int ans = 0;
	if (a[idx] != 0) {
		bool currEven = a[idx]%2 == 0;
		if (currEven){
			ans += dfs(a, idx+1, n, true, odd, even+1, diff + !isEven);
		}
		else {
			ans += dfs(a, idx+1, n, false, odd+1, even, diff + isEven);
		}
	}
	else {
		ans += dfs(a, idx+1, n, true, odd, even+1, diff + !isEven);
		ans += dfs(a, idx+1, n, false, odd+1, even, diff + isEven);
	}
	return dp[idx][isEven][odd][even] = min(diff, ans);
}

void reset(){
	for (int i = 0; i < 101; i++){
		for (int j = 0; j < 2; j++){
			for (int k = 0;k < 101; k++){
				for (int l = 0; l < 101; l++){
					dp[i][j][k][l] = MOD;
				}
			}
		}
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &a : v){
		cin >> a;
	}
	reset();
	dfs(v, 0, n, false, 0, 0, 0);
	reset();
	dfs(v, 0, n, true, 0, 0, 0);
	cout << res << endl;
	
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	setIO();
	
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}