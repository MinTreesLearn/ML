#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define nl '\n'
#define sp ' '

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int n, p[105], ne, no;
int dp[100][100][100][2];

int f(int pos, int ue, int uo, int l) {
	if(pos == n)
		return 0;
	if(dp[pos][ue][uo][l] != -1)
		return dp[pos][ue][uo][l];
	if(p[pos] != 0)
		return dp[pos][ue][uo][l] = (pos ? l != p[pos] % 2 : 0) + f(pos + 1, ue, uo, p[pos] % 2);

	int res = 300;

	if(ue < ne)
		res = min(res, (pos ? l == 1 : 0) + f(pos + 1, ue + 1, uo, 0));
	if(uo < no)
		res = min(res, (pos ? l == 0 : 0) + f(pos + 1, ue, uo + 1, 1));

	return dp[pos][ue][uo][l] = res;
} 

signed main() {
	#ifdef DBG
	freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ce = 0, co = 0;
	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>p[i];
		if(p[i] == 0)
			continue;

		if(p[i] % 2)
			++co;
		else
			++ce;
	}

	ne = n / 2 - ce;
	no = n / 2 + n % 2 - co;

	memset(dp, -1, sizeof dp);
	cout<<f(0, 0, 0, 0)<<nl;
    return 0;
}