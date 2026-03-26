// Author: yukito8069

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
typedef long long ll;
typedef double dd;
typedef pair<int, int> pii;
int f[55][20010];
int n, m, k;
int a[55][20010];
int pre[55][20010];
int mxl[20010];
int mxr[20010];
signed main() {
	IOS;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= m - k + 1; i++) {
        f[1][i] = pre[1][i + k - 1] - pre[1][i - 1] + pre[2][i + k - 1] - pre[2][i - 1];
        mxl[i] = max(mxl[i - 1], f[1][i]);
    }
    for (int i = m -k + 1; i >= 1; i--) {
        mxr[i] = max(mxr[i + 1], f[1][i]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            int xx = pre[i][j + k - 1] - pre[i][j - 1] + pre[i + 1][j + k - 1] - pre[i + 1][j - 1];
            int mx = max(mxl[j - k], mxr[j + k]);
            f[i][j] = mx + xx;
            for (int z = j - k + 1; z <= j + k - 1; z++) {
                int jr = j + k - 1;
                int zr = z + k - 1;
                int l = max(j, z), r = min(j + k - 1, z + k - 1);
                f[i][j] = max(f[i][j], f[i - 1][z] + xx - (pre[i][r] - pre[i][l - 1]));
            }
        }
        for (int j = 1; j <= m - k + 1; j++) {
            mxl[j] = max(mxl[j - 1], f[i][j]);
        }
        for (int j = m - k + 1; j >= 1; j--) {
            mxr[j] = max(mxr[j + 1], f[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m - k + 1; i++) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << "\n";
	return 0;
}