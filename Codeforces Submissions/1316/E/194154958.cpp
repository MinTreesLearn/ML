#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(v) v.begin(), v.end()
#define F first
#define S second
#define ll long long
#define el '\n'
#define hanou2a ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 3, mod = 1e9 + 7, M = 1e3 + 2;
const double E = 2.718281828459, pi = 3.14159265359;
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, p, k, s[N][8];
vector<pair<int, int>> v;
ll dp[N][1 << 8];

ll solve(int idx, int msk, int cnt) {
    if (idx >= n) {
        if (msk == (1 << p) - 1) return 0;
        else return INT_MIN;
    }
    ll &ret = dp[idx][msk];
    if (~ret)return ret;
    ret = solve(idx + 1, msk, cnt);
    for (int i = 0; i < p; i++) {
        if (msk & (1 << i))continue;
        ret = max(ret, solve(idx + 1, msk | (1 << i), cnt + 1) + s[v[idx].second][i]);
    }
    if (idx - cnt < k)
        ret = max(ret, solve(idx + 1, msk, cnt) + v[idx].first);
    return ret;
}

void func() {
    memset(dp, -1, sizeof dp);
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(all(v), greater<>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++)cin >> s[i][j];
    }
    cout << solve(0, 0, 0);
}


int main() {
    hanou2a
    int tst;
    tst = 1;
//    cin >> tst;
    for (int i = 1; i <= tst; i++) {
//        cout << "Case " << i << ": ";
        func();
    }
    return 0;
}
 	 	 				    	 		 			   	   			