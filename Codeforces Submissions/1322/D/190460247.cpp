#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

#define eb emplace_back
#define vv vector
#define fi first
#define se second

using pii = pair<int, int>;
using ll = long long;

const int N = 4005;
int n, m;
int l[N], s[N], c[N], f[N][N];

void Mx(int &a, int b) {if (a < b) a = b;}

// f[x][i][j] 前 x 个，攻击力为 i 的有 j 个
signed main() {
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif  
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> l[i];
    for (int i = 1; i <= n; ++ i) cin >> s[i];
    for (int i = 1; i <= n + m; ++ i) cin >> c[i];
    memset(f, 0xcf, sizeof f);
	for (int i = 1; i <= n + m; ++ i) f[i][0] = 0;
	for (int i = n; i >= 1; -- i) {
		for (int j = n; j >= 1; -- j) Mx(f[l[i]][j], f[l[i]][j - 1] + c[l[i]] - s[i]);
		for (int j = l[i]; j <= n + m; ++ j) {
			for (int k = 0; k <= (n >> (j - l[i])); ++ k) {
				Mx(f[j + 1][k >> 1], f[j][k] + (k >> 1) * c[j + 1]);
			}
		}
	}
	cout << f[n + m][0] << '\n';
	return 0;
}

