/**
 *    author:  longvu
 *    created: 01/20/23 13:07:20
**/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = 1e15;
const int nax = (int)(109);
const int mod = 1e9 + 7;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

int a[nax], mp[nax], dp[nax][2][nax][nax];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]] = 1;
        if (a[i]) {
            a[i] %= 2;
        } else {
            a[i] = -1;
        }
    }
    int cntodd = 0, cnteven = 0;
    for (int i = 1; i <= n; ++i) {
        if (!mp[i]) {
            if (i % 2) {
                cntodd++;
            } else {
                cnteven++;
            }
        }
    }
    function<int(int, int, int, int)> solve = [&](int i, int j, int e, int f) {
        if (i == n + 1) {
            return 0LL;
        }
        if (dp[i][j][e][f] != -1) {
            return dp[i][j][e][f];
        }
        int res = INF;
        if (!a[i]) {
            minimize(res, (i > 1 && j) + solve(i + 1, 0, e, f));
        }
        if (a[i] == 1) {
            minimize(res, (i > 1 && !j) + solve(i + 1, 1, e, f));
        }
        if (a[i] == -1) {
            if (e) {
                minimize(res, (i > 1 && !j) + solve(i + 1, 1, e - 1, f));
            }
            if (f) {
                minimize(res, (i > 1 && j) + solve(i + 1, 0, e, f - 1));
            }
        }
        return dp[i][j][e][f] = res;
    };
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0, cntodd, cnteven) << '\n';
    return 0;
}