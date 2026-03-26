#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n, m, k;
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
        k = min(k,m-1);
		int ans = 0;
		for (int i = 0; i <= k; i++) {
			int minx = 1e18;
			for (int j = 0; j <= m - k - 1; j++)
				minx = min(minx, max(a[1 + i + j], a[n + i - m + 1 + j]));
				       ans = max(ans, minx);
		}
		cout << ans << endl;
	}
signed main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
	   		  	 			 	 	   	  	   		