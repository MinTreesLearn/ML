#include <bits/stdc++.h>
using namespace std;
const int N = 600+10;
const int MOD = 1e9 + 7;
typedef long long ll;
int n, k;
int dis[N], e[N][N], tmp[N];
int c[N];
void dp() {
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	for (int turns = 1; turns <= k; turns++) {
		memset(tmp, 0x3f, sizeof tmp);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[i] == c[j]) continue;
				tmp[j] = min(tmp[j], dis[i] + e[i][j]);
				// cout << e[i][j] << " \n" [j==n];
			}
			
		}
		for (int i = 1; i <= n; i++) {
			dis[i] = tmp[i];
		}
	}
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> e[i][j];
		}
		e[i][i] = 1e9;
	}
	int cnt = 0, ans = 1e9;
	while (++cnt <= 512 * 10) {
		for (int i = 1; i <= n; i++) {
			c[i] = rand() % 2;
		}
		dp();
		ans = min(ans, dis[1]);
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	srand(time(0));
	while (t--) solve();
}
