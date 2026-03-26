#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long double ld;
typedef long long ll;
#define el '\n'

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int n, p, k;
const int N = 1e5 + 5;
vector<array<int, 2>> a(N);
int s[N][8];
ll dp[N][1 << 7];

ll solve(int i, int msk) {
    if (i == n && msk == (1 << p) - 1)return 0;
    if (i == n)return -1e15;
    auto &ans = dp[i][msk];
    if (~ans)return ans;
    int cnt = i -  __builtin_popcount(msk);
    if (cnt < k) {
        ans = solve(i + 1, msk) + a[i][0]; // pick audience
    } else {
        ans = solve(i + 1, msk);   //leave audience
    }
    for (int j = 0; j < p; j++) {
        if (((1 << j) & msk) == 0) {
            ans = max(ans, 1ll * solve(i + 1, msk | (1 << j)) + s[a[i][1]][j]);
        }
    }
    return ans;
}

void Tc() {
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)cin >> s[i][j];
    sort(a.rbegin(), a.rend());
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    while (tc--)Tc();
}
 				 				    		 	   	 		 		 	