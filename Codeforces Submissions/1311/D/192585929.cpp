#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ari2 = array<int, 2>;
using arl2 = array<ll, 2>;
using arl3 = array<ll, 3>;
constexpr ll MOD = 998244353;
void solve();
void precomp();
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	precomp();
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve();
	}
}
constexpr int mxN = 16969, INF = 0x3f3f3f3f;
vector<int> dvsrs[mxN];
void precomp() {
	for (int i = 1; i < mxN; i++) {
		for (int j = i; j < mxN; j += i) {
			dvsrs[j].push_back(i);
		}
	}
}
int dp[mxN][3][2], ar[3];
void solve() {
	cin >> ar[0] >> ar[1] >> ar[2];
	memset(dp, 0x3f, sizeof(dp));
	int C = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < mxN; j++) {
			if (!i) {
				dp[j][i][0] = abs(j-ar[0]);
			} else {
				for (int k : dvsrs[j]) {
					int v = dp[k][i-1][0] + abs(j-ar[i]);
					if (v < dp[j][i][0]) {
						dp[j][i][0] = v;
						dp[j][i][1] = k;
					}
				}
				C = i == 2 && dp[C][2][0] > dp[j][2][0] ? j : C;
			}
		}
	}
	int B = dp[C][2][1], A = dp[B][1][1];
	cout << dp[C][2][0] << '\n';
	cout << A << ' ' << B << ' ' << C << '\n';
}
