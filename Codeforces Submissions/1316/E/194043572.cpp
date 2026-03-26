#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

const int OO = 0x3f3f3f3f, N = 1e5 + 5, mod = 1e9 + 7;
int n, p, k;
vector<pair<int, int>> a;
int s[N][10];
ll dp[N][1 << 7];

ll go(int idx, int msk) {

    if (idx == n && msk == (1 << p) - 1)
        return 0;

    if (idx == n)
        return INT64_MIN;

    ll &ans = dp[idx][msk];
    if (~ans)
        return ans;

    ans = 0;

    ans = go(idx + 1, msk);
    if (idx - __builtin_popcount(msk) + 1 <= k) {
        ans = go(idx + 1, msk) + a[idx].first;
    }

    for (int j = 0; j < p; j++) {
        if (!((1 << j) & msk)) {
            ans = max(ans, go(idx + 1, msk | (1 << j)) + s[a[idx].second][j]);
        }
    }

    return ans;
}

void solve() {
    cin >> n >> p >> k;

    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < p; i++) {
            cin >> s[j][i];
        }
    }

    sort(a.rbegin(), a.rend());
    memset(dp, -1, sizeof dp);
    cout << go(0, 0) << endl;
}


int main() {
    fast;

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }

}
 				 		 	 	  				 		 	 		   		