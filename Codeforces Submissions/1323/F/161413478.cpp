#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

const int inf = 1e9;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> l(n), s(n);
    for (int i = 0; i < n; i ++) cin >> l[i], l[i] --;
    for (int i = 0; i < n; i ++) cin >> s[i];
    reverse(l.begin(), l.end());
    reverse(s.begin(), s.end());

    vector<int> c(n + m);
    for (int i = 0; i < n + m; i ++) cin >> c[i];

    int dp[n + m + 1][n + 1];
    for (int mx = 0; mx <= n + m; mx ++){
        for (int cnt = 0; cnt <= n; cnt ++){
            dp[mx][cnt] = -inf;
            if (cnt == 0) dp[mx][cnt] = 0;
        }
    }

    for (int i = 0; i < n; i ++){
        for (int cnt = n; cnt > 0; cnt --){
            dp[l[i]][cnt] = max(dp[l[i]][cnt], dp[l[i]][cnt - 1] - s[i] + c[l[i]]);
        }
        int to = n;
        for (int mx = l[i]; mx < n + m; mx ++){
            for (int cnt = 0; cnt <= to; cnt ++){
                dp[mx + 1][cnt / 2] = max(dp[mx + 1][cnt / 2], dp[mx][cnt] + c[mx + 1] * (cnt / 2));
            }
            to /= 2;
        }
    }

    cout << dp[n + m][0];
}