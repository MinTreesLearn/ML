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
int f[110][110][110][2];//这一位
bool vis[110];
int a[110];
int pre[110];
signed main() {
	IOS;
   // memset(vis, 0, sizeof(vis));
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = 1; 
        pre[i] = pre[i - 1];
        if(!a[i]) pre[i]++;
    }
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(i & 1) odd++;
        }
    }
    memset(f, 0x3f, sizeof(f));
    if(a[1]) {
        f[1][0][0][a[1] & 1] = 0;
    }
    else {
        f[1][1][0][1] = f[1][0][1][0] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if(a[i]) {
            for (int j = 0; j <= min(pre[i], odd); j++) {
                int k = pre[i] - j;
                if(a[i] & 1) {
                    f[i][j][k][1] = min({f[i][j][k][1], f[i - 1][j][k][0] + 1, f[i - 1][j][k][1]});
                }
                else {
                    f[i][j][k][0] = min({f[i][j][k][0], f[i - 1][j][k][0], f[i - 1][j][k][1] + 1});
                }
            }
        }
        else {
            for (int j = 0; j <= min(odd, pre[i]); j++) {
                int k = pre[i] - j;
                if(j >= 1) {
                    f[i][j][k][1] = min({f[i - 1][j - 1][k][1], f[i - 1][j - 1][k][0] + 1, f[i][j][k][1]});
                }
                if(k >= 1)
                    f[i][j][k][0] = min({f[i - 1][j][k - 1][0], f[i - 1][j][k - 1][1] + 1, f[i][j][k][0]});
            }
        }
    }
    if(a[n]) {
        cout << f[n][odd][pre[n] - odd][a[n] & 1] << "\n";
    }
    else {
        cout << min(f[n][odd][pre[n] - odd][1], f[n][odd][pre[n] - odd][0]) << "\n";
    }
	return 0;
}